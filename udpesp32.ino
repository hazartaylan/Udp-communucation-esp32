#include <WiFi.h>
#include <WiFiUdp.h>
int read_command;
const char * udpAddress = "10.30.0.191"; // your pc ip
const int udpPort = 8080; //port server
WiFiUDP udp;
void setup() {
Serial.begin(115200); // to monitor activity
  
  //Connect to the WiFi network
   WiFi.begin(ssid, pwd);
   Serial.println("");

  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
  //This initializes udp and transfer buffer
  udp.begin(udpPort);
}

void loop() {
  uint8_t buffer[50];
  udp.beginPacket(udpAddress, udpPort);
  udp.print(veri.dataMessage);
  udp.write(buffer, 11);
  udp.endPacket();
  memset(buffer, 0, 50);
    udp.parsePacket();
   if(udp.read(buffer, 50) > 0){
    Serial.print("Server to client: ");
    Serial.println((char *)buffer);
    buffer[50];
  read_command=atoi((char *)buffer);// read command and put your code
  if(read_command==0){
      // put your code for receive command
  }

}
