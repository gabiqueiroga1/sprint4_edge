#include <WiFi.h>
#include <PubSubClient.h>
#include <ArduinoJson.h>

#define poten_pin 34

WiFiClient wifiClient;
PubSubClient mqttClient(wifiClient);

void setup() {
  pinMode(poten_pin, INPUT);
  Serial.begin(115200);
  
  WiFi.begin("Wokwi-GUEST", "");
  while (WiFi.status() != WL_CONNECTED) delay(100);

  mqttClient.setServer("test.mosquitto.org", 1883);

  mqttClient.connect("esp32-cliente");
}

void loop() {
  mqttClient.loop();
  
  int potValue = analogRead(poten_pin);
  float peso = map(potValue, 0, 4095, 2000, 10000) / 1000.0; // 2.0 a 10.0 kg (divide por 1000 transforma gramas em kg)
  float volume = peso * 150; // fórmula: peso × 150 ml

  Serial.println("Peso: " + String(peso));
  Serial.println("Volume: " + String(volume));


  StaticJsonDocument<100> json;
  json["Peso"] = peso;
  json["Volume"] = volume;

  char jsonBuffer[200];
  serializeJson(json, jsonBuffer);

  mqttClient.publish("nutrikids/gabi", jsonBuffer);

  delay(2000);

}
