/* ESP8266+Arduino IDE Test code
Object :
- Serial Event output on RS232(b9600).

Requirement :
- ESP8266WiFi.h Library (https://github.com/esp8266/Arduino)
- DW.miniESP board  (https://github.com/deaware/dwminiesp_firmware_support)
- Arduino IDE 1.6.4

Write by : Myconfix (http://www.myconfix.com/)
Fanpage : https://www.facebook.com/myconfix
github : https://github.com/myconfix/ESP8266ArduinoExample
*/

#include "ESP8266WiFi.h"

String inputString = "";         // a string to hold incoming data
boolean stringComplete = false;  // whether the string is complete

void setup() {
	// initialize serial:
	Serial.begin(9600);
	// reserve 200 bytes for the inputString:
	WiFi.mode(WIFI_AP);
	WiFi.disconnect();
	inputString.reserve(200);
	
}

void loop() {

	if (Serial.isRxEnabled())
	{
		serialEvent();
	}// *** check RX is coming

	if (stringComplete) {
		Serial.println(inputString);
		// clear the string:
		inputString = "";
		stringComplete = false;
	}
	
}


void serialEvent() {
	while (Serial.available()) {
		// get the new byte:
		char inChar = (char)Serial.read();
		// add it to the inputString:
		inputString += inChar;
		// if the incoming character is a newline, set a flag
		// so the main loop can do something about it:
		if (inChar == '\n') {
			stringComplete = true;
		}
	}
}
