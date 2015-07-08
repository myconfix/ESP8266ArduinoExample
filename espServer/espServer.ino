/* ESP8266+Arduino IDE Test code
Object :
- TCP Socket(port 4444) Server.
- ESP8266 AP mode test.
Requirement :
- ESP8266WiFi.h Library (https://github.com/esp8266/Arduino)
- DW.miniESP board  (https://github.com/deaware/dwminiesp_firmware_support)
- Arduino IDE 1.6.4

Write by : Myconfix (http://www.myconfix.com/)
Fanpage : https://www.facebook.com/myconfix
github : https://github.com/myconfix/ESP8266ArduinoExample
*/


#include "ESP8266WiFi.h"


//Prepare AP mode parameter
const char *APssid = "SSID";
const char *APpassword = "password";

//Listen port
uint16_t port = 4444;


WiFiServer LocalServer(port);

void connect2AP()
{

	WiFi.mode(WIFI_AP);
	WiFi.softAP(APssid, APpassword, 3);  //softAP (SSID,Password,Channel)
	WiFi.disconnect();

	WiFi.printDiag(Serial);
}
void setup()
{
	Serial.begin(115200);

	connect2AP();

	LocalServer.begin();
	Serial.println("Server started.");

}

WiFiClient client;

void loop()
{

	if (client.connected())
	{
		String line = client.readStringUntil('\r');
		Serial.println(line);
		delay(500);
	}
	else {
		client = LocalServer.available();
		if (client.connected())	{
			Serial.println("New Connection");
			client.println("hello client\r");
			delay(100);
		}
	}

}
