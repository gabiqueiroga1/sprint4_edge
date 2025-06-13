# 🍼 Simulação de Cálculo para Lactário

Este projeto tem como objetivo calcular automaticamente o volume de fórmula (em ml) que uma criança deve consumir, com base no seu peso, e enviar os dados para uma interface gráfica.

---

# 📈 Diagrama

![Diagrama drawio](https://github.com/user-attachments/assets/7282e698-23e7-44bd-bb89-181766b35116)

# Descrição do Diagrama

Este projeto apresenta a arquitetura de um sistema IoT utilizando **ESP32**, comunicação via Wi-Fi, protocolo MQTT e uma aplicação web para visualização dos dados.

## 🛠️ Componentes

- **Potenciômetro**: Sensor simulado de peso

Todos os dispositivos estão conectados ao **ESP32**, que coleta os dados e os envia através da conexão Wi-Fi.

## 🔗 Comunicação

- O **ESP32** envia os dados capturados para a internet utilizando Wi-Fi  
- As informações são publicadas em um **Broker MQTT** (ex: **HiveMQ**)  
- O Broker organiza a comunicação entre o ESP32 e o **Back-end**

## 🖥️ Back-end

- O Back-end se conecta ao Broker MQTT  
- Recebe os dados publicados e converte as mensagens no formato **JSON**, facilitando a manipulação e integração com a aplicação web

## 📊 Aplicação Web

- A aplicação web (Dashboard) consome os dados em formato **JSON** e exibe informações em tempo real para o usuário  
- A Dashboard permite visualizar a temperatura, umidade e status dos atuadores  

## 🔁 Fluxo Resumido

1. Sensores enviam dados para o ESP32  
2. ESP32 publica as informações no Broker MQTT através do Wi-Fi  
3. Back-end consome as mensagens MQTT e gera dados em JSON  
4. A aplicação Web consome o JSON e exibe no Dashboard

---

# 🍼 Sobre o simulador para Cálculo de Lactário

## Print do projeto no Wokwi

![wokwi](https://github.com/user-attachments/assets/5ebebccd-003c-4c41-9282-eb148505749a)


### Link do Wokwi

- https://wokwi.com/projects/433591284210525185


## Link do vídeo no Youtube explicando sobre o projeto:

- https://www.youtube.com/watch?v=nJhkSou_CQc&t=1s

---

## 🧰 Componentes Utilizados

- **ESP32**  
- Potenciômetro  
- Jumpers  
- Broker MQTT (local ou em nuvem)

---

## ⚙️ Funcionalidades

- Cálculo da fórmula
- Comunicação com MQTT
- Monitoramento no NODE-RED(dashboard)

---

## 🔌 Esquema de Conexão

### Potenciômetro:
- Pino de dados →  GPIO 34 do ESP32
---

## 📚 Bibliotecas Necessárias

- `ArduinoJson`   
- `PubSubClient` *(para MQTT)*  
- `WiFi.h` *(biblioteca nativa do ESP32)*

---

## 📡 Saída Serial (exemplo)

```json
{"Peso":8.67}
{"Volume":1365.0}
```

---

# Integrantes do Grupo

- Gabriela Queiroga - RM 560035  
- Maria Eduarda Ferrés - RM 560418
