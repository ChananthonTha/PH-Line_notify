#include <ESP8266WiFi.h>
#include <TridentTD_LineNotify.h>

const char* ssid = "xxxxxxxx";       //ชื่อ WiFi **2.4Ghz**
const char* password = "xxxxxxxxx";  // รหัส WiFi
const char* LINE_TOKEN = "xxxxxxx"   // Token Line Notify
  //Line notify url:https://notify-bot.line.me/my/

  void
  setup() {
  Serial.begin(115200);
  Serial.println("Connecting...");

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(250);
    Serial.print(".");
  }

  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

  //Line Token
  LINE.setToken(LINE_TOKEN);
}

void loop() {
  sensor(); //Call sensor Function

  // ตัวอย่างส่งข้อความ
  LINE.notify("ค่า PH เกินกำหนด");
  LINE.notify("PH:8.17");
  delay(10000); // 1 Second = 1000
}

void sensor(){
  //PH sensor
}
