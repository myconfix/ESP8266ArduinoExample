/* ESP8266+Arduino IDE Test code
Object :
- Test Task Library.

Requirement :
- ESP8266WiFi.h Library (https://github.com/esp8266/Arduino)
- Task.h Library (https://github.com/Makuna/Task)
- DW.miniESP board  (https://github.com/deaware/dwminiesp_firmware_support)
- Arduino IDE 1.6.4

Write by : Myconfix (http://www.myconfix.com/)
Fanpage : https://www.facebook.com/myconfix
github : https://github.com/myconfix/ESP8266ArduinoExample
*/


#include "ESP8266WiFi.h"
#include "Task.h"
#include "taskBlinkLed.h"

#define LED	5  //port 5

TaskManager taskManager;
TaskBlinkLed taskblinkled(LED, MsToTaskTime(1000));

void setup(){

	pinMode(LED, OUTPUT);
	taskManager.StartTask(&taskblinkled);
}
void loop(){
	taskManager.Loop();
}