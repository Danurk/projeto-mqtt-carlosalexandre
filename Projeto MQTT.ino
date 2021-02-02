#include <PubSubClient.h>
#include <UIPEthernet.h>
#include <utility/logging.h>
#include <SPI.h>


//Define o endereço MAC que será utilizado
byte mac[] = {0x8C, 0xA9, 0x92, 0x95, 0xBE, 0xEA};

bool mensagem;
int pino2 = 2;
bool estado_sensor;

//Inicia o cliente Ethernet
EthernetClient client;

PubSubClient mqttClient(client);

void setup() {
    //Inicia o controlador Ethernet e solicita um IP para o servidor de DHCP
    Ethernet.begin(mac);

    //Inicia o monitor Serial
    Serial.begin(9600);

    mqttClient.setServer("54.174.235.157",1883);
    
    //Exibe no Monitor Serial as informações sobre o IP do Arduino
    Serial.print("O IP do Arduino e: ");
    Serial.println(Ethernet.localIP());

    //Exibe no Monitor Serial as informações sobre a Máscara de Rede do Arduino
    Serial.print("A Mascara de Rede do Arduino e: ");
    Serial.println(Ethernet.subnetMask());

    //Exibe no Monitor Serial as informações sobre o Gateway do Arduino
    Serial.print("O Gateway do Arduino e: ");
    Serial.println(Ethernet.gatewayIP());

    //Exibe uma linha em branco
    Serial.println("");

    pinMode(pino2,INPUT_PULLUP);
}

void loop() {

    estado_sensor = digitalRead(pino2);

    mqttClient.connect("carlosalexandre");

    mensagem = mqttClient.publish("carlosalexandre-t","FUNCIONOU!");

    Serial.println(mensagem);

    if(estado_sensor == 1){

      Serial.println("ABERTO");
      mensagem = mqttClient.publish("carlosalexandre-t1","ABERTO");
      delay(500);
    }else{
      Serial.println("FECHADO");
      mensagem = mqttClient.publish("carlosalexandre-t1","FECHADO");
      delay(500);
    }
     
    mqttClient.loop();
    
}
