/* ESP8266+Arduino IDE Test code
Object : 
	- TCP Socket(port 4444) client, connection to Server.
	- ESP8266 Station mode test.
Requirement : 
 - ESP8266WiFi.h Library (https://github.com/esp8266/Arduino)
 - DW.miniESP board  (https://github.com/deaware/dwminiesp_firmware_support)
 - Arduino IDE 1.6.4

Write by : Myconfix (http://www.myconfix.com/)
Fanpage : https://www.facebook.com/myconfix
github : https://github.com/myconfix/ESP8266ArduinoExample
*/

#include "ESP8266WiFi.h"

// Prepare AP id&password.
const char *ssid = "Access Point SSID";  //your access point ssid // cannot be longer than 32 characters!
const char *password = "Access Point Password"; //your access point password

// Prepare Server IP and Port.
uint16_t port = 4444;
char *server = "192.168.4.1";

WiFiClient client;

// Connect to WiFi
void connectwifi()
{
	WiFi.mode(WIFI_STA);
	WiFi.disconnect();
	Serial.print("Connecting to ");
	Serial.println(ssid);
	WiFi.begin(ssid, password);

	while (WiFi.status() != WL_CONNECTED) {
		delay(500);
		Serial.print(".");
	}

	Serial.println("");
	Serial.println("WiFi connected");
	Serial.println("IP address: ");
	Serial.println(WiFi.localIP());
	WiFi.printDiag(Serial);

}

void setup()
{

	Serial.begin(115200);

	connectwifi();

}



void loop()
{

	if (!client.connected()) //check if not connect to server then connect..
	{
		if (client.connect(server, port)){
			String line = client.readStringUntil('\r');
			Serial.println(line);
			Serial.println("reconnect..Ok.");
		}
	}else {		
		Serial.println("hello server");
			client.println("hello server\r");
			delay(1000);
		}
	
	// Check Wifi 
	if (WiFi.status() != WL_CONNECTED){
		WiFi.disconnect();
		connectwifi();
	}

}
