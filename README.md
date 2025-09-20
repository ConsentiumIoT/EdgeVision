# EdgeSense

**EdgeSense** is a modular, Arduino-compatible library developed by **Consentium IoT** for ESP32-based boards. It enables high-performance, real-time data logging from a wide range of edge sensors, making it ideal for edge AI and TinyML workflows.

---

## ⚡ Quick Start

To use EdgeSense in your Arduino sketch, simply include the main header:

```cpp
#include <EdgeSense.h>
```

This single include gives you access to all core components, such as `EdgeStream`, `EdgeSensor`, and `EdgeVision`:

```cpp
#include <EdgeSense.h>

EdgeStream stream;

void setup() {
  stream.begin();
}
```

---

## 🔧 Supported Sensor Modes

- 📷 **Image Logging** using ESP32-CAM or OV2640-compatible modules  
- 🎤 **Audio Capture** using I2S microphones (e.g., INMP441)  
- 📊 **General Sensor/Data Logging** (analog/digital sensors, I2C, etc.) to SD card or flash memory  

---

## 🚀 Features

- Modular components for image, audio, and sensor data capture  
- Lightweight and optimized for ESP32 platforms  
- Supports real-time and offline data collection  
- Seamless integration with [EdgeModelKit](https://github.com/ConsentiumIoT/edgemodelkit)  
- Ideal for TinyML, fall detection, activity recognition, and field monitoring use-cases  

---

## 📚 Documentation & Tutorials

- 📘 Library Docs: [https://docs.consentiumiot.com](https://docs.consentiumiot.com)  
- 🧠 Model Training Toolkit: [EdgeModelKit on GitHub](https://github.com/ConsentiumIoT/edgemodelkit)  
- 🧪 Example Sketches and Workflows: See `examples/` folder in this repo  

---

## 🛠️ Supported Architectures

- ✅ `esp32` (Tested on ESP32 DevKit v1, Consentium Nexus/EdgeVision boards)

---

## 📨 Support

For feature requests, bug reports, or integration help:  
📧 **Email**: [official@consentiumiot.com](mailto:official@consentiumiot.com)

---

## 📝 License

**MIT License**  
© 2025 Consentium IoT Labs Pvt. Ltd.  
Redistribution and use in source and binary forms must retain this header.

---

> Empowering smart sensing at the edge — built by [Consentium IoT](https://www.consentiumiot.com)