<p align="center">
  <img src="gfx/hitmarker.gif" alt="Hitmarker" style="width:400px;" />
</p>

## Hitmarker NodeMCU Project

  <a href="https://www.arduino.cc/" target="_blank">
    <img src="https://custom-icon-badges.demolab.com/badge/Arduino-00969C?logo=arduino&logoColor=white" alt="Arduino" />
  </a>
  <a href="https://platformio.org/" target="_blank">
    <img src="https://img.shields.io/badge/PlatformIO-FF7F00?logo=data:image/svg+xml;base64,PHN2ZyB3aWR0aD0iMjUwMCIgaGVpZ2h0PSIyNTAwIiB2aWV3Qm94PSIwIDAgMjU2IDI1NiIgeG1sbnM9Imh0dHA6Ly93d3cudzMub3JnLzIwMDAvc3ZnIiBwcmVzZXJ2ZUFzcGVjdFJhdGlvPSJ4TWlkWU1pZCI+PHBhdGggZD0iTTEyOCAwQzkzLjgxIDAgNjEuNjY2IDEzLjMxNCAzNy40OSAzNy40OSAxMy4zMTQgNjEuNjY2IDAgOTMuODEgMCAxMjhjMCAzNC4xOSAxMy4zMTQgNjYuMzM0IDM3LjQ5IDkwLjUxQzYxLjY2NiAyNDIuNjg2IDkzLjgxIDI1NiAxMjggMjU2YzM0LjE5IDAgNjYuMzM0LTEzLjMxNCA5MC41MS0zNy40OUMyNDIuNjg2IDE5NC4zMzQgMjU2IDE2Mi4xOSAyNTYgMTI4YzAtMzQuMTktMTMuMzE0LTY2LjMzNC0zNy40OS05MC41MUMxOTQuMzM0IDEzLjMxNCAxNjIuMTkgMCAxMjggMCIgZmlsbD0iI0ZGN0YwMCIvPjxwYXRoIGQ9Ik0yNDkuMzg2IDEyOGMwIDY3LjA0LTU0LjM0NyAxMjEuMzg2LTEyMS4zODYgMTIxLjM4NkM2MC45NiAyNDkuMzg2IDYuNjEzIDE5NS4wNCA2LjYxMyAxMjggNi42MTMgNjAuOTYgNjAuOTYgNi42MTQgMTI4IDYuNjE0YzY3LjA0IDAgMTIxLjM4NiA1NC4zNDYgMTIxLjM4NiAxMjEuMzg2IiBmaWxsPSIjRkZGIi8+PHBhdGggZD0iTTE2MC44NjkgNzQuMDYybDUuMTQ1LTE4LjUzN2M1LjI2NC0uNDcgOS4zOTItNC44ODYgOS4zOTItMTAuMjczIDAtNS43LTQuNjItMTAuMzItMTAuMzItMTAuMzJzLTEwLjMyIDQuNjItMTAuMzIgMTAuMzJjMCAzLjc1NSAyLjAxMyA3LjAzIDUuMDEgOC44MzdsLTUuMDUgMTguMTk1Yy0xNC40MzctMy42Ny0yNi42MjUtMy4zOS0yNi42MjUtMy4zOWwtMi4yNTggMS4wMXYxNDAuODcybDIuMjU4Ljc1M2MxMy42MTQgMCA3My4xNzctNDEuMTMzIDczLjMyMy04NS4yNyAwLTMxLjYyNC0yMS4wMjMtNDUuODI1LTQwLjU1NS01Mi4xOTd6TTE0Ni41MyAxNjQuOGMtMTEuNjE3LTE4LjU1Ny02LjcwNi02MS43NTEgMjMuNjQzLTY3LjkyNSA4LjMyLTEuMzMzIDE4LjUwOSA0LjEzNCAyMS41MSAxNi4yNzkgNy41ODIgMjUuNzY2LTM3LjAxNSA2MS44NDUtNDUuMTUzIDUxLjY0NnptMTguMjE2LTM5Ljc1MmE5LjM5OSA5LjM5OSAwIDAgMC05LjM5OSA5LjM5OSA5LjM5OSA5LjM5OSAwIDAgMCA5LjQgOS4zOTkgOS4zOTkgOS4zOTkgMCAwIDAgOS4zOTgtOS40IDkuMzk5IDkuMzk5IDAgMCAwLTkuMzk5LTkuMzk4em0yLjgxIDguNjcyYTIuMzc0IDIuMzc0IDAgMSAxIDAtNC43NDkgMi4zNzQgMi4zNzQgMCAwIDEgMCA0Ljc0OXoiIGZpbGw9IiNFNTcyMDAiLz48cGF0aCBkPSJNMTAxLjM3MSA3Mi43MDlsLTUuMDIzLTE4LjkwMWMyLjg3NC0xLjgzMiA0Ljc4Ni01LjA0IDQuNzg2LTguNzAxIDAtNS43LTQuNjItMTAuMzItMTAuMzItMTAuMzItNS42OTkgMC0xMC4zMTkgNC42Mi0xMC4zMTkgMTAuMzIgMCA1LjY4MiA0LjU5MiAxMC4yODkgMTAuMjY3IDEwLjMxN0w5NS44IDc0LjM3OGMtMTkuNjA5IDYuNTEtNDAuODg1IDIwLjc0Mi00MC44ODUgNTEuODguNDM2IDQ1LjAxIDU5LjU3MiA4NS4yNjcgNzMuMTg2IDg1LjI2N1Y2OC44OTJzLTEyLjI1Mi0uMDYyLTI2LjcyOSAzLjgxN3ptMTAuMzk1IDkyLjA5Yy04LjEzOCAxMC4yLTUyLjczNS0yNS44OC00NS4xNTQtNTEuNjQ1IDMuMDAyLTEyLjE0NSAxMy4xOS0xNy42MTIgMjEuNTExLTE2LjI4IDMwLjM1IDYuMTc1IDM1LjI2IDQ5LjM2OSAyMy42NDMgNjcuOTI0em0tMTguODItMzkuNDZhOS4zOTkgOS4zOTkgMCAwIDAtOS4zOTkgOS4zOTggOS4zOTkgOS4zOTkgMCAwIDAgOS40IDkuNCA5LjM5OSA5LjM5OSAwIDAgMCA5LjM5OC05LjQgOS4zOTkgOS4zOTkgMCAwIDAtOS4zOTktOS4zOTl6bS0yLjgxIDguNjcxYTIuMzc0IDIuMzc0IDAgMSAxIDAtNC43NDggMi4zNzQgMi4zNzQgMCAwIDEgMCA0Ljc0OHoiIGZpbGw9IiNGRjdGMDAiLz48L3N2Zz4=" alt="PlatformIO" />
  </a>
  <a href="https://www.espressif.com/en/products/socs/esp32" target="_blank">
    <img src="https://img.shields.io/badge/ESP32-E7352C?logo=espressif&logoColor=white" alt="ESP32" />
  </a>
  <a href="https://git-scm.com/" target="_blank">
    <img src="https://img.shields.io/badge/Git-F05032?logo=git&logoColor=white" alt="Git" />
  </a>

This project utilizes a NodeMCU board (ESP32) to create a device that detects vibrations using a piezo element, triggers an LED light, and provides a web interface for monitoring and configuration. It also allows for control and configuration through serial commands.

This project is developed using PlatformIO within Visual Studio Code. PlatformIO provides a streamlined development environment for embedded systems, simplifying the build process and offering additional features.

### Hardware Requirements

* NodeMCU board (ESP32)
* Piezo element (disc)
* LED (any color)
* 220 ohm resistor
* Jumper wires
* Metal plate for mounting the piezo

### Software Requirements

* Visual Studio Code (https://code.visualstudio.com/)
* PlatformIO IDE extension for VS Code (https://marketplace.visualstudio.com/items?itemName=platformio.platformio-ide)
* Git version control system (https://git-scm.com/downloads)

### Assembly

1. **Connect the piezo element:**

    * Solder a jumper wire to each leg of the piezo element.
    * Connect one leg of the piezo to **D32 (GPIO0)** on the NodeMCU board.
    * Connect the other leg of the piezo through the ??? ohm resistor to **GND (ground)** on the NodeMCU board.
    * **Mounting:** Secure the piezo element to a clean, flat metal plate using electrical tape. Make sure the flat surface of the piezo is fully in contact with the metal plate.

2. **Connect the LED:**

    * Connect the positive leg (longer leg) of the LED to a 220 ohm resistor.
    * Connect the resistor to **D14 (GPIO2)** on the NodeMCU board.
    * Connect the negative leg (shorter leg) of the LED to **GND (ground)** on the NodeMCU board.

**Note:** Double-check your connections before uploading the code.

### Setting Up the Software

1. Install Visual Studio Code.
2. Install the PlatformIO IDE extension for VS Code.
3. Clone this repository using Git.
4. Open the project folder in VS Code.
5. PlatformIO will automatically handle dependencies and libraries. No additional library installations are required.
6. Update the WiFi network name (`ssid`) and password (`password`) in the code with your desired credentials.
7. Upload the code to your NodeMCU board using PlatformIO's built-in upload functionality.

**Web Interface:**

Once uploaded, the NodeMCU board will create a WiFi access point named "Hitmarker". Connect your computer or mobile device to this network. You can then access the web interface by opening the address http://hitmarker.local in your web browser.

**Serial Communication:**

The project can also be controlled and configured through serial communication. Open the serial monitor in VS Code at a baud rate of 115200. You can send the following commands:

* `restart`: Performs a full power cycle on the NodeMCU board.
* `ping`: Returns a "Pong!" response for testing.
* `threshold <value>`: Updates the vibration detection threshold (value is an integer).
* `trigger <value>`: Updates the LED trigger duration (value is an integer in milliseconds).
* `gun`: Prints ASCII art of a gun to the serial monitor.

**Configuration Files:**

The project utilizes a file named `main.vars` stored in the SPIFFS file system to store configuration settings like vibration threshold and trigger duration. This file is automatically updated when you change these values through the web interface or serial commands.

### TODO
* Find best resistor for the piezo element. (For the best reaction time and output)
* Fix bug on web interface that sometimes keeps flashing red background on hit.
* Better/cooler web interface.

### Additional Notes

* The `printAsciiArtToSerial` function is for fun and can be removed if desired.
* Most of the features of the webinterface and commands are purely for debugging and testing.

### License

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)

This project is licensed under the MIT License - see below for details:

```
MIT License

Copyright (c) 2025 Monstertov

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
```
