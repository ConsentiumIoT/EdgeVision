// webpage.h
const char main_page[] PROGMEM = R"rawliteral(
<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="UTF-8" />
  <meta name="viewport" content="width=device-width, initial-scale=1.0"/>
  <title>EdgeVision Capture Hub</title>
  <script src="https://cdnjs.cloudflare.com/ajax/libs/jszip/3.7.1/jszip.min.js"></script>
  <link href="https://fonts.googleapis.com/css2?family=Inter:wght@400;600&display=swap" rel="stylesheet">
  <link rel="icon" type="image/png" href="https://consentiumiot.com/static/img/logo.png">

  <style>
    :root {
      --primary: #007bff;
      --success: #28a745;
      --danger: #dc3545;
      --text-dark: #1a1a1a;
      --bg-light: #f0f2f5;
    }

    html, body {
      height: 100%;
      margin: 0;
      display: flex;
      flex-direction: column;
    }

    body {
      font-family: 'Inter', sans-serif;
      background: linear-gradient(145deg, #e4ebf0, #f0f2f5);
      color: var(--text-dark);
    }

    header, footer {
      background: linear-gradient(to right, #1f1c2c, #533bcd 50%, #1f1c2c);
      color: white;
      padding: 1.5rem 2rem;
      text-align: center;
    }

    header {
      font-size: 1rem;
      font-weight: 700;
      letter-spacing: 1px;
      box-shadow: 0 4px 12px rgba(0,0,0,0.2);
    }

    footer {
      font-size: 0.9rem;
      box-shadow: 0 -2px 12px rgba(0,0,0,0.15);
    }

    .container {
      flex: 1;
      text-align: center;
      max-width: 750px;
      margin: 40px auto;
      background: rgba(255, 255, 255, 0.6);
      backdrop-filter: blur(12px);
      border-radius: 20px;
      padding: 35px;
      box-shadow: 0 8px 25px rgba(0,0,0,0.08);
      animation: fadeIn 0.8s ease-in-out;
    }

    img {
      border-radius: 12px;
      width: 100%;
      max-width: 520px;
      margin-bottom: 25px;
      box-shadow: 0 6px 18px rgba(0,0,0,0.15);
      transition: transform 0.3s ease;
    }

    img:hover {
      transform: scale(1.01);
    }

    .controls {
      text-align: center;
    }

    label {
      font-weight: 600;
      margin-right: 10px;
    }

    input[type=number], input[type=text] {
      padding: 10px 12px;
      font-size: 16px;
      border-radius: 8px;
      border: 1px solid #ccc;
      outline: none;
      transition: border 0.3s;
    }

    input[type=number]:focus, input[type=text]:focus {
      border: 1px solid var(--primary);
    }

    .button-group {
      display: flex;
      flex-wrap: wrap;
      justify-content: center;
      gap: 14px;
      margin-top: 20px;
    }

    button {
      position: relative;
      padding: 12px 20px;
      font-size: 16px;
      border: none;
      border-radius: 10px;
      cursor: pointer;
      font-weight: 600;
      min-width: 140px;
      transition: transform 0.2s, box-shadow 0.3s;
      color: white;
    }

    button:hover {
      transform: translateY(-3px);
      box-shadow: 0 8px 20px rgba(0,0,0,0.1);
    }

    .capture {
      background: linear-gradient(135deg, #34ce57, #28a745);
    }

    .stop {
      background: linear-gradient(135deg, #e55039, #dc3545);
    }

    .download {
      background: linear-gradient(135deg, #3498db, #007bff);
    }

    .tooltip {
      position: relative;
    }

    .tooltip::after {
      content: attr(data-tooltip);
      position: absolute;
      opacity: 0;
      background: #333;
      color: white;
      padding: 5px 10px;
      border-radius: 6px;
      font-size: 0.75rem;
      white-space: nowrap;
      bottom: 125%;
      left: 50%;
      transform: translateX(-50%);
      transition: opacity 0.3s;
      pointer-events: none;
    }

    .tooltip:hover::after {
      opacity: 1;
    }

    #count {
      font-weight: bold;
      font-size: 1.2rem;
      margin-top: 25px;
      color: #222;
    }

    @keyframes fadeIn {
      from { opacity: 0; transform: translateY(20px); }
      to { opacity: 1; transform: translateY(0); }
    }

    @media (max-width: 600px) {
      .container {
        margin: 20px 15px;
        padding: 25px;
      }

      button {
        min-width: 100px;
        font-size: 14px;
      }

      input[type=number], input[type=text] {
        width: 100%;
        margin-top: 10px;
      }
    }
  </style>
</head>
<body>
  <header>Welcome to EdgeNeuron - ESP32-CAM Snap Studio</header>

  <div class="container">
    <img id="stream" src="/stream" alt="Camera stream">
    <div class="controls">
      <div style="margin-bottom: 15px;">
        <label for="intervalInput">Capture interval (ms):</label>
        <input type="number" id="intervalInput" value="1500" min="10" step="10">
      </div>
      <div style="margin-bottom: 25px;">
        <label for="zipNameInput">ZIP file name:</label>
        <input type="text" id="zipNameInput" placeholder="class A" style="width: 200px;">
      </div>
      <div class="button-group">
        <button class="capture tooltip" onclick="startCapturing()" data-tooltip="Start auto image capture">▶ Start</button>
        <button class="stop tooltip" onclick="stopCapturing()" data-tooltip="Stop capturing images">⏹ Stop</button>
        <button class="stop tooltip" onclick="resetCaptures()" data-tooltip="Clear captured images">🗑 Reset</button>
        <button class="download tooltip" onclick="download()" data-tooltip="Download all images as ZIP">⬇ Download</button>
      </div>
      <div id="count">Images captured: 0</div>
    </div>
  </div>

  <footer>© Copyright EdgeNeuron. All Rights Reserved.</footer>

  <script>
    let capturedImages = [];
    let intervalId = null;
    let captureInterval = 1500;

    function capture() {
      const canvas = document.createElement('canvas');
      const video = document.getElementById('stream');
      canvas.width = 320;
      canvas.height = 240;
      const ctx = canvas.getContext('2d');
      ctx.drawImage(video, 0, 0, canvas.width, canvas.height);
      canvas.toBlob((blob) => {
        capturedImages.push(blob);
        document.getElementById('count').innerText = 'Images captured: ' + capturedImages.length;
      }, 'image/jpeg');
    }

    function startCapturing() {
      if (intervalId) return;
      const userInterval = parseInt(document.getElementById("intervalInput").value);
      captureInterval = (userInterval >= 100) ? userInterval : 1500;
      intervalId = setInterval(capture, captureInterval);
    }

    function stopCapturing() {
      if (intervalId) {
        clearInterval(intervalId);
        intervalId = null;
      }
    }

    function resetCaptures() {
      capturedImages = [];
      document.getElementById('count').innerText = 'Images captured: 0';
    }

    function download() {
      if (capturedImages.length === 0) {
        alert("No images to download!");
        return;
      }

      const zip = new JSZip();
      capturedImages.forEach((blob, index) => {
        zip.file(`image_${index + 1}.jpg`, blob);
      });

      const zipNameInput = document.getElementById("zipNameInput").value.trim();
      const fileName = zipNameInput !== "" ? zipNameInput : "edgeNeuron_images";

      zip.generateAsync({ type: "blob" }).then(function(content) {
        const link = document.createElement('a');
        link.href = URL.createObjectURL(content);
        link.download = `${fileName}.zip`;
        link.click();
      });
    }
  </script>
</body>
</html>
)rawliteral";
