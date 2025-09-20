# EdgeVision

**EdgeVision** is a modular, Arduino-compatible library by **Consentium IoT** for ESP32-based boards, enabling high-performance, real-time video streaming and image capture from edge cameras. It is ideal for edge AI, TinyML, surveillance, and visual monitoring workflows.

---

## ⚡ Quick Start

To use EdgeVision in your Arduino sketch, simply include the main header:

```cpp
#include <EdgeVision.h>
```

Example usage for live camera streaming:

```cpp
#include <EdgeVision.h>

const char* ssid = "YOUR_WIFI_SSID";
const char* password = "YOUR_WIFI_PASSWORD";

EdgeVision edgeVision;

void setup() {
  Serial.begin(115200);
  edgeVision.initWiFi(ssid, password);
  edgeVision.initCamera();
  edgeVision.startCameraServer();
}

void loop() {
  edgeVision.keepServerAlive();
}
```

---

## 📷 Features

- **Live MJPEG Video Streaming** over HTTP (LAN)
- **Image Capture** and storage to SD card or flash
- **Easy Wi-Fi Setup** for ESP32-CAM and compatible boards
- **Modular API** for rapid prototyping and deployment
- **Optimized for ESP32** (AI Tinkerer, Consentium EdgeVision, and similar boards)
- **Ideal for**: Visual inference, surveillance, remote monitoring, and TinyML vision projects

---

## 🧪 Example Sketches

Find ready-to-use examples in the `examples/` folder, such as:

- `ImageLogger`: Stream live video to your browser
- `Snapshot`: Capture and save images on demand

---

## 📚 Documentation

- 📘 Library Docs: [https://docs.consentiumiot.com](https://docs.consentiumiot.com)
- 🧪 Example Workflows: See `examples/` folder

---

## 🛠️ Supported Hardware

- ✅ ESP32-CAM (AI Tinkerer, Consentium EdgeVision, and OV2640-compatible modules)
- ✅ ESP32 DevKit (with camera modules)

---

## 📨 Support

For feature requests, bug reports, or integration help:  
📧 **Email**: [official@consentiumiot.com](mailto:official@consentiumiot.com)

---

## 📝 License

**MIT License**  
© 2025 Consentium IoT.  
Redistribution and use in source and binary forms must retain this header.

---

> Empowering smart vision at the edge — built by [Consentium IoT](https://www.consentiumiot.com)