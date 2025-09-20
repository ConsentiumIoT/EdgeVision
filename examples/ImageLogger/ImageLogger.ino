/***************************************************
  Consentium IoT - EdgeVision Camera Streaming Example
  -----------------------------------------------------
  This example demonstrates how to stream video using 
  Consentium's EdgeVision SDK. It initializes the onboard 
  camera and starts a lightweight MJPEG server accessible 
  over local Wi-Fi.

  Features:
  - Compatible with AI Tinkerer ESP32-CAM and Consentium IoT's EdgeVision board
  - Easy Wi-Fi setup for live LAN streaming
  - MJPEG video stream over HTTP (port 5000)
  - Modular EdgeVision SDK for simplified deployment
  - Useful for real-time visual inference, monitoring, or surveillance

  How It Works:
  - Initializes Wi-Fi connection with given SSID and password
  - Configures and activates onboard camera
  - Starts HTTP stream server on local IP address (shown in Serial Monitor)
  - Stream accessible at: http://<device_ip>:5000/stream

  Tutorials and Documentation:
  Visit us at:
  - EdgeVision SDK: https://docs.consentiumiot.com
  - Consentium GitHub: https://github.com/ConsentiumIoT

  For Support:
  Email: official@consentiumiot.com

  MIT license - Redistribution must include this header.
 ****************************************************/

#include <EdgeVision.h>

// Replace these with your actual WiFi credentials
const char* ssid = "YOUR_WIFI_SSID";
const char* password = "YOUR_WIFI_PASSWORD";

// Create an instance of the EdgeSense class
EdgeVision edgeVision;

void setup() {
  // Start serial communication
  Serial.begin(115200);

  // Initialize WiFi
  edgeVision.initWiFi(ssid, password);

  // Initialize the camera
  edgeVision.initCamera();

  // Start the web streaming server
  edgeVision.startCameraServer();

  Serial.println("Camera server started.");
}

void loop() {
  // Keep the HTTP server running
  edgeVision.keepServerAlive();
}
