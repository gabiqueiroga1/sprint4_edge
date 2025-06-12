#include <WiFi.h>
#include <PubSubClient.h>
#include <ArduinoJson.h>

#define poten_pin 34  // Pino do potenciômetro

WiFiClient wifiClient;
PubSubClient mqttClient(wifiClient);

void setup() {
  pinMode(poten_pin, INPUT);
  Serial.begin(115200);

  // Conexão Wi-Fi
  WiFi.begin("Wokwi-GUEST", "");
  while (WiFi.status() != WL_CONNECTED) delay(100);

  // Configuração do servidor MQTT
  mqttClient.setServer("test.mosquitto.org", 1883);

  // Conexão com o broker MQTT
  mqttClient.connect("esp32-cliente");
}

void loop() {
  mqttClient.loop();  // Mantém a conexão MQTT

  // Leitura do valor do potenciômetro
  int potValue = analogRead(poten_pin);

  // Conversão do valor para peso (em kg)
  float peso = map(potValue, 0, 4095, 2000, 10000) / 1000.0;

  // Cálculo do volume com base no peso
  float volume = peso * 150;

  // Exibe os valores no monitor serial
  Serial.println("Peso: " + String(peso));
  Serial.println("Volume: " + String(volume));

  // Criação do JSON com os dados
  StaticJsonDocument<100> json;
  json["Peso"] = peso;
  json["Volume"] = volume;

  // Serializa e envia os dados via MQTT
  char jsonBuffer[200];
  serializeJson(json, jsonBuffer);
  mqttClient.publish("nutrikids/gabi", jsonBuffer);

  delay(2000);  // Aguarda 2 segundos antes da próxima leitura
}
