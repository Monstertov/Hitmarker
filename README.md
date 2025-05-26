<p align="center">
  <img src="gfx/hitmarker.gif" alt="Hitmarker" style="width:400px;" />
</p>

## Hitmarker NodeMCU Project

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
* Fix bug on webinterface that sometimes keep flashing red background on hit.
* Better/cooler webinterface.

### Additional Notes

* The `printAsciiArtToSerial` function is for fun and can be removed if desired.
* Most of the features of the webinterface and commands are purely for debugging and testing.