# Smart-Grid-Outage-Monitor
An Arduino-based I2C system for real-time power grid fault detection and localized reporting.

# Smart Outage Management System (SOMS) ⚡
**A Prototype for Intelligent Grid Monitoring**

## 📌 Overview
This project was developed to simulate real-time fault detection in an urban power distribution network. It focuses on the bridge between embedded systems and electrical utility management, inspired by the technical environment at **HIT Haldia** and the **IETE Students' Forum**.

## 🛠️ Features
- **I2C Protocol Integration:** Efficient communication with a 16x2 LCD using address mapping (0x20).
- **Dynamic Fault Mapping:** Automated reporting of specific outage zones (A01, A02 etc...) using array-based randomization.
- **Visual Diagnostics:** Real-time LED alerts and a system "Boot-up" sequence for control-room simulation.

## 📂 Project Structure
- `Outage_Monitor.ino`: Main source code.
- `Circuit_Diagram.png`: The circuit for the task 

## 🚀 How It Works
1. The system polls the grid status via a digital input.
2. If voltage is lost, the interrupt logic triggers a "Fault Routine."
3. A randomized location is pulled from the database to identify the failure point.
4. Alerts are displayed on the LCD and signaled via a Red LED.

## 🎓 Acknowledgments
Developed with insights gained from the **IETE HIT Students' Branch** and aimed at addressing modern challenges in power distribution.
