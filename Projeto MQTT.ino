//Bibliotecas utilizadas
#include <PubSubClient.h>
#include <UIPEthernet.h>
#include <utility/logging.h>
#include <SPI.h>


//Define o endereço MAC que será utilizado
byte mac[] = {0x8C, 0xA9, 0x92, 0x95, 0xBE, 0xEA};

//Variaveis utilizadas
bool mensagem;
bool estado_sensor;
int pino2 = 2;

//Inicia o cliente Ethernet
EthernetClient client;

PubSubClient mqttClient(client);

void setup() {
    //Inicia o controlador Ethernet e solicita um IP para o servidor de DHCP
    Ethernet.begin(mac);

    //Inicia o monitor Serial
    Serial.begin(9600);

    //Define o servidor para qual as informações serão enviadas
    mqttClient.setServer("54.161.191.80",1883);
    
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

    //Define o estado do pino 2 para enviar informações
    pinMode(pino2,INPUT_PULLUP);
}

void loop() {
    
    //Variavel utilizada para leitura do pino 2
    estado_sensor = digitalRead(pino2);

    //Abre uma nova conexão com o MQTT Broker
    mqttClient.connect("carlosalexandre");

    //Publica uma mensagem no servidor MQTT
    mensagem = mqttClient.publish("carlosalexandre-t","FUNCIONOU!");
    
    //Exibe no Monitor Serial o conteudo da variavel "mensagem"
    Serial.println(mensagem);
    
    //Se a rack estiver aberta esse script será utilizado
    if(estado_sensor == 1){

      //Exibe uma Mensagem no Monitor Serial
      Serial.println("ABERTO");

      //Publlica uma Mensagem no Servidor MQTT
      mensagem = mqttClient.publish("carlosalexandre-t1","ABERTO");
   
      //Se a rack estiver fechada esse script será utilizado
     } else{

      //Exibe uma Mensagem no Monitor Serial
      Serial.println("FECHADO");

      //Publica uma Mensagem no Servidor MQTT
      mensagem = mqttClient.publish("carlosalexandre-t1","FECHADO");
  
    mqttClient.loop();
    
}
