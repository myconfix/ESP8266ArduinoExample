/* ESP8266+Arduino IDE Test code
Object :
- Deep Sleep mode test.
- Scan WiFi.
(code from https://github.com/sandeepmistry/esp8266-Arduino/blob/master/esp8266com/esp8266/libraries/ESP8266WiFi/examples/WiFiScan/WiFiScan.ino)
Requirement :
- ESP8266WiFi.h Library (https://github.com/esp8266/Arduino)
- DW.miniESP board  (https://github.com/deaware/dwminiesp_firmware_support)
	!!! Connect PIN 16 to RST (For running program) [!!!If program mode move out Pin 16]
- Arduino IDE 1.6.4


Write by : Myconfix (http://www.myconfix.com/)
Fanpage : https://www.facebook.com/myconfix
github : https://github.com/myconfix/ESP8266ArduinoExample
*/
#include "ESP8266WiFi.h"
#define DeepSleepTime 30  //second
void scanwifi(){
	Serial.println("scan start");

	// WiFi.scanNetworks will return the number of networks found
	int n = WiFi.scanNetworks();
	Serial.println("scan done");
	if (n == 0)
		Serial.println("no networks found");
	else
	{
		Serial.print(n);
		Serial.println(" networks found");
		for (int i = 0; i < n; ++i)
		{
			// Print SSID and RSSI for each network found
			Serial.print(i + 1);
			Serial.print(": ");
			Serial.print(WiFi.SSID(i));
			Serial.print(" (");
			Serial.print(WiFi.RSSI(i));
			Serial.print(")");
			Serial.println((WiFi.encryptionType(i) == ENC_TYPE_NONE) ? " " : "*");
			delay(10);
		}
	}
	Serial.println("");

	// Wait a bit before scanning again
	//delay(6000);
}
void setup() {
	Serial.begin(115200);
	Serial.println("ESP Wake UP");
	// Set WiFi to station mode and disconnect from an AP if it was previously connected
	WiFi.mode(WIFI_STA);
	WiFi.disconnect();
	delay(100);

	Serial.println("Setup done");
	scanwifi();

	ESP.deepSleep(DeepSleepTime*1000000, WAKE_RF_DEFAULT);
}

void loop() {
	
}
