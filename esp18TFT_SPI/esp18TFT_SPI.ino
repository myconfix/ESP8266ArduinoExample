/* ESP8266+Arduino IDE Test code
Object :
- ESP8266 with 1.8 SPI 128x160 TFT MODULE
- Support Thai Langaues
Requirement :
- ST7735_TEE.h Library (http://)
- DW.miniESP board  (https://github.com/deaware/dwminiesp_firmware_support)
- Arduino IDE 1.6.4
- Wiring 
	ESP8266					1.8 TFT MODULE
		0						RST 
		12						DIN 
		13						D/C
		14						CLK
		15						CS
								BL		Vcc(+5v)

Write by : Myconfix (http://www.myconfix.com/)
Fanpage : https://www.facebook.com/myconfix
github : https://github.com/myconfix/ESP8266ArduinoExample
*/

#include "ST7735_TEE.h"

TEE_ST7735 lcd(14, 12, 13, 0, 15); //ESP8266 1.8 TFT module SPI 128x160  CLK,DIN,D/C,RST,CS

void setup()
{
	lcd.init(lcd.HORIZONTAL);
	lcd.fillScreen(BLACK);
	delay(500);
	lcd.Printstr(10, 20, (char*)"ทดสอบด้วย ESP8266", WHITE);
	delay(2000);
}

void loop()
{
	testlines(GREEN);
	delay(1000);
	lcd.fillScreen(BLUE);
	delay(500);
	lcd.Printstr(15, 20, (char*)"ทดสอบด้วย ESP8266", WHITE);
	delay(3000);
	lcd.fillScreen(BLUE);
	delay(500);
	lcd.Printstr(15, 55, (char*)"M Y C O N F I X", RED);
	delay(7000);
}

void testlines(uint16_t color) {
	lcd.fillScreen(BLACK);
	for (uint16_t x = 0; x < lcd.width; x += 6) {
		lcd.drawLine(0, 0, x, lcd.height - 1, color);
	}
	for (uint16_t y = 0; y < lcd.height; y += 6) {
		lcd.drawLine(0, 0, lcd.width - 1, y, color);
	}
}
