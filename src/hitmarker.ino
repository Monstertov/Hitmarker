#include <WiFi.h>
#include <WebServer.h>
#include <ESPmDNS.h>
#include <SPIFFS.h>
#include <ArduinoJson.h>

const char *ssid = "Hitmarker";       // WiFi network name
const char *password = "hitmarker";   // WiFi network password
const char *hostname = "hitmarker";   // Hostname for mDNS
WebServer server(80);                 // Create a web server on port 80

const int piezoPin = 32;              // Use GPIO pin 32 for the piezo element
const int ledPin = 14;                // Use GPIO pin 14 for the LED
int vibrationThreshold = 150;         // Adjust the threshold as needed with default value
unsigned long triggerDuration = 500;  // Duration for LED to stay on and trigger high in milliseconds
unsigned long previousMillis = 0;     // Variable to store the previous time when LED was turned on
bool ledState = false;                // Variable to track the state of the LED
int PDV = 0;                          // Piezo Detection Value for web
int triggerState = 0;                 // Variable to store trigger state

void setup() {
  Serial.begin(115200); // Start serial communication
  delay(1000); // Allow some time for the Serial monitor to initialize

  Serial.println("Booting...");

  // Initialize SPIFFS
  if (!SPIFFS.begin(true)) {
    Serial.println("An error occurred while mounting SPIFFS");
    while (true); // Loop indefinitely if SPIFFS initialization fails
  }

  // Read the main.vars file
  File configFile = SPIFFS.open("/main.vars", "r");
  if (!configFile) {
    Serial.println("Failed to open main.vars file");
  } else {
    // Parse the JSON file
    DynamicJsonDocument doc(1024);
    DeserializationError error = deserializeJson(doc, configFile);
    if (error) {
      Serial.println("Failed to parse main.vars file");
    } else {
      // Read the vibrationThreshold value
      vibrationThreshold = doc["vibrationThreshold"];
      Serial.print("Loaded vibrationThreshold from main.vars: ");
      Serial.println(vibrationThreshold);
      triggerDuration = doc["triggerDuration"];
      Serial.print("Loaded triggerDuration from main.vars: ");
      Serial.println(triggerDuration);
    }
    configFile.close();
  }

  pinMode(piezoPin, INPUT);  // Set the piezo pin as input
  pinMode(ledPin, OUTPUT);   // Set the LED pin as output

  // Connect to WiFi network
  WiFi.softAP(ssid, password);

  // Configure DHCP server
  IPAddress local_IP(192, 168, 1, 1);
  IPAddress gateway(192, 168, 1, 254);
  IPAddress subnet(255, 255, 255, 0);
  WiFi.config(local_IP, gateway, subnet);

  // Start DHCP server
  if (!WiFi.softAP(ssid, password)) {
    Serial.println("Failed to start DHCP server");
    return;
  }

  Serial.println("WiFi AP Started");

  // Initialize mDNS
  if (!MDNS.begin(hostname)) {
    Serial.println("Error setting up mDNS responder!");
  } else {
    Serial.println("mDNS responder started");
  }

  // Route for root / web page
  server.on("/", HTTP_GET, []() {
    Serial.print("HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n");
    Serial.print("Client IP: ");
    Serial.println(server.client().remoteIP());
    server.send(200, "text/html", readFile("/index.html"));
  });

  // Route for data endpoint
  server.on("/data", HTTP_GET, []() {
    // Create a JSON object with live data
    StaticJsonDocument<256> jsonData;
    jsonData["piezoValue"] = PDV;
    jsonData["triggerState"] = triggerState;
    jsonData["vibrationThreshold"] = vibrationThreshold;
    jsonData["triggerDuration"] = triggerDuration;

    // Serialize JSON to string
    String jsonString;
    serializeJson(jsonData, jsonString);

    // Send JSON response
    server.send(200, "application/json", jsonString);
  });

  // Route for sending command to serial
    server.on("/send-command", HTTP_POST, []() {
        String command = server.arg("plain");
        Serial.println("Sending command " + command + " to serial port...");
        DynamicJsonDocument jsonDocument(256);
        jsonDocument["command"].as<String>();
        DeserializationError error = deserializeJson(jsonDocument, command);
        commander(jsonDocument["command"].as<String>());
        server.send(200, "application/json", "{\"success\": true, \"response\": \"Command sent to serial\"}");
    });

  // Start server
  server.begin();
  Serial.println("HTTP server started");
  printAsciiArtToSerial();
  Serial.println("Ready!");
}

void loop() {
  server.handleClient();

  int piezoValue = analogRead(piezoPin);

  // Log all analog readings above 0
  if (piezoValue > 0) {
    Serial.print("Vibration detected with signal value at: ");
    PDV = piezoValue; // Update Piezo Detection Value buffer to last known vibration
    Serial.println(piezoValue);
  }

  // Add a threshold to detect vibrations
  if (piezoValue > vibrationThreshold) {
    // Perform an action when a vibration is detected and print the detected analog signal
    Serial.print("Trigger detected with signal value at: ");
    Serial.println(piezoValue);

    // Turn on the LED to indicate detection
    digitalWrite(ledPin, HIGH);
    previousMillis = millis(); // Record the time when LED is turned on
    ledState = true; // Set the LED state to on
    triggerState = 1; // Set trigger state high
  }

  // Check if it's time to turn off the LED
  if (ledState && millis() - previousMillis >= triggerDuration) {
    digitalWrite(ledPin, LOW); // Turn off the LED
    ledState = false; // Set the LED state to off
    triggerState = 0; // Set trigger state low
  }

  // Handle Serial commands
  handleSerialCommands();
}

void powerCycle() {
  ESP.restart();
}

String readFile(const char *filename) {
  File file = SPIFFS.open(filename);
  if (!file) {
    Serial.println("Failed to open file for reading");
    return "";
  }

  String fileContent = "";
  while (file.available()) {
    fileContent += (char)file.read();
  }
  file.close();
  return fileContent;
}

void handleSerialCommands() {
  if (Serial.available() > 0) {
    String command = Serial.readStringUntil('\n'); // Read the command until newline character
    commander(command);
  }
}

void commander(String command){
  if (command.startsWith("restart")) {
      Serial.println("Performing full power cycle...");
      powerCycle();
    } else if (command.startsWith("ping")) {
      Serial.println("Pong!");
    } else if (command.startsWith("threshold")) {
      // Extract the new threshold value from the command    
      // Update the vibrationThreshold variable
      vibrationThreshold = command.substring(10).toInt(); // Assuming the command format is "threshold <value>"
      
      // Update the main.vars file
      updateConfig("vibrationThreshold", String(vibrationThreshold));
      
      Serial.print("Updated vibrationThreshold to ");
      Serial.println(vibrationThreshold);
      } else if (command.startsWith("trigger")) {
      // Extract the new triggerDuration value from the command
      // Update the vibrationThreshold variable
      triggerDuration = command.substring(8).toInt(); // Assuming the command format is "trigger <value>";
      
      // Update the main.vars file
      updateConfig("triggerDuration", String(triggerDuration));
      
      Serial.print("Updated triggerDuration to ");
      Serial.println(triggerDuration);
    } else if (command.startsWith("gun")) {
      printAsciiArtToSerial();
    } else {
      Serial.print("Unknown command: ");
      Serial.println(command);
    }
}

void updateConfig(String key, String value) {
  // Create or open the main.vars file in write mode
  File configFile = SPIFFS.open("/main.vars", "w");
  if (!configFile) {
    Serial.println("Failed to open main.vars file for writing");
    return;
  }
  
  // Create a JSON object with the new threshold value
  StaticJsonDocument<64> doc;
  doc[key] = value;
  
  // Serialize JSON to string
  String jsonString;
  serializeJson(doc, jsonString);
  
  // Write the JSON string to the file
  configFile.println(jsonString);
  
  // Close the file
  configFile.close();
}

void printAsciiArtToSerial() {
  Serial.println("  _  ____________.---------.");
  Serial.println("  \\`'  __________|_________|");
  Serial.println(" /   (_)__]");
  Serial.println("|    |");
  Serial.println(".'   .'");
  Serial.println("|____]");
}