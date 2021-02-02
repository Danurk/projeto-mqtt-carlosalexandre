# projeto-mqtt-carlosalexandre

# Repositório mqtt para porta da rack
---
# Objetivo
---
O objetivo do projéto é fazer o monitoramento do estado de uma rack mesmo estando à distância, podendo saber se ela está **ABERTO** ou **FECHADO**; utilizando um protocolo MQTT (*Message* *Queuing* *Telemetry* *Transport*), para enviar informação via internet a um servidor MQTT hospedado na AWS (*Amazon* *Web* *Service*) e exibi-lo em um client MQTT (MQTT Dash ou MQTT Tools) instalado em um Smartphone, como no exemplo abaixo:

![](https://camo.githubusercontent.com/7beef2d4780d87a603d7de49b2da0467c8537dff96575b628a04bd4010ebb1cc/68747470733a2f2f692e696d6775722e636f6d2f4d576870586b562e706e67)

As seguintes bibliotecas foram utilizadas nesse projeto:
* [UIPEtherne](https://github.com/UIPEthernet/UIPEthernet) - conexão do ENC28J60 com o Arduino.
* [PubSubClient](https://github.com/knolleary/pubsubclient) - cliente MQTT para o Arduino.
# Materias utilizados
```
Arduino UNO
Módulo Ethernet (ENC28J60)
Sensor Magnético (MC-38)
Jumpers
```
# Circuito Exemplo
---
![](https://camo.githubusercontent.com/ad1da211b35b60b23fb095a64e76dc6504d0c3229e853bd82a69a4d5d27bbb88/68747470733a2f2f692e696d6775722e636f6d2f594947477453472e706e67)

# Autor: Carlos Alexandre
