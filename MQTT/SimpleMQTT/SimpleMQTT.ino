/**
   A simple Azure IoT example for sending telemetry.
*/

//#include <WiFi.h>
//#include "Esp32MQTTClient.h"

#include "EspMQTTClient.h"

EspMQTTClient client(
  "LAB_IoT",
  "1234567890",
  "10.5.5.1",  // MQTT Broker server ip
  "",   // MQTT User - Can be omitted if not needed
  "",   // MQTT Pass - Can be omitted if not needed
  "TestClient"      // Client name that uniquely identify your device
);
int i=0;
void onConnectionEstablished() {

  //simple Receiver
  client.subscribe("mytopic/test", [] (const String & payload)  {
    Serial.println(payload);
  });

  client.publish("mytopic/test", "This is a message");
  i++;
  char buffer[10];
  sprintf(buffer, "%li", i);
  client.publish("mytopic/number", buffer,0);
}

void setup() {
  Serial.begin(115200);
  Serial.println("Starting connecting WiFi.");
}

void loop() {
  client.loop();
}

//
//// Please input the SSID and password of WiFi
//const char* ssid     = "LAB_IoT";
//const char* password = "1234567890";
//
///*String containing Hostname, Device Id & Device Key in the format:                         */
///*  "HostName=<host_name>;DeviceId=<device_id>;SharedAccessKey=<device_key>"                */
///*  "HostName=<host_name>;DeviceId=<device_id>;SharedAccessSignature=<device_sas_token>"    */
//static const char* connectionString = "HostName=10.5.5.1;DeviceId=esp32-t1;";
//
//static bool hasIoTHub = false;
//
//void setup() {
//  Serial.begin(115200);
//  Serial.println("Starting connecting WiFi.");
//  delay(10);
//  WiFi.begin(ssid, password);
//  while (WiFi.status() != WL_CONNECTED) {
//    delay(500);
//    Serial.print(".");
//  }
//  Serial.println("WiFi connected");
//  Serial.println("IP address: ");
//  Serial.println(WiFi.localIP());
//
//  if (!Esp32MQTTClient_Init((const uint8_t*)connectionString))
//  {
//    hasIoTHub = false;
//    Serial.println("Initializing IoT hub failed.");
//    return;
//  }
//  hasIoTHub = true;
//}
//
//void loop() {
//  Serial.println("start sending events.");
//  if (hasIoTHub)
//  {
//    char buff[128];
//
//    // replace the following line with your data sent to Azure IoTHub
//    snprintf(buff, 128, "{\"topic\":\"iot\"}");
//
//    if (Esp32MQTTClient_SendEvent(buff))
//    {
//      Serial.println("Sending data succeed");
//    }
//    else
//    {
//      Serial.println("Failure...");
//    }
//    delay(5000);
//  }
//}
