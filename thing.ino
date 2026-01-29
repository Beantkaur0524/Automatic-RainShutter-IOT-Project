#include <WiFi.h>
#include<PubSubClient.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>

// Define the BME sensor object
Adafruit_BME280 bme;
const int rainPin = 35;

const char* ssid ="realme 5i";
const char* passwd = "sranshaab";

long channelId = 2188840; // channel id

//experimenatl
char userName[] = "Kw8uKgsnAx8RGhY8KTIVMCs"; // added device userId
char passKey[] = "BtLzAZy+yP+SvT+7kaer/NP+"; // added device pasword
char clientId[] = "BnXCfd7EVVtPEGukMRHNSmeF"; // added device clientId

WiFiClient client;

const char* server = "mqtt3.thingspeak.com";

PubSubClient mqttClient(client); // init PubSub

unsigned long lastConnectionTime = 0;
const unsigned long postingInterval = 20 * 1000; // post data every 20 sec (1000ms = 1 sec)


void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  int status = WL_IDLE_STATUS;
  
  Serial.println("Esp32 started..!");
  
  while(status != WL_CONNECTED){
    status = WiFi.begin(ssid, passwd);
    status = WL_CONNECTED;
    delay(5000);
    }

//  pinMode(solar, INPUT);
//  pinMode(elec, INPUT);
//  pinMode(bat,INPUT);

    Serial.println("Connected to Wifi...");
    mqttClient.setServer(server, 1883);
    
    mqttClient.setCallback(subCallback);
    mqttClient.setBufferSize( 2048 ); // imp step for getting data from thingspeak
//    Serial.print("mqttClient State: "); Serial.println(mqttClient.state());

}

void loop() {
  // put your main code here, to run repeatedly:
  if(!mqttClient.connected()){
    
    reconnect();
    
    }

    mqttClient.loop();

    if(millis() - lastConnectionTime > postingInterval){
  
      mqttPublishFeed();
      Serial.print("mqttClient State: "); 
      Serial.println(mqttClient.state());
    }
    
}

// reconnect function
void reconnect(){
  
//  char clientId[9];

  while(!mqttClient.connected()){
    Serial.println("Trying to get connection...");
      delay(2000);
      
  if(mqttClient.connect(clientId,userName,passKey)){
      Serial.println("Connected..!");
      bool PubSub_Status = mqttClient.connected();
      mqttSubscribe();
      Serial.print("mqttClient.connected after mqttClient.connect: "); 
      Serial.println(PubSub_Status);
      Serial.print("mqttClient State: "); 
      Serial.println(mqttClient.state());
      }
  else{
      Serial.print("failed, rc=");
      Serial.print(mqttClient.state());
      Serial.println("try again in 5 sec");
      delay(5000);
      }
    }
  }

  void mqttPublishFeed(){
    // provide data generation mechanism below
  float temperature = bme.readTemperature();
  float humidity = bme.readHumidity();
  float pressure = bme.readPressure() / 100.0; // Convert from Pa to hPa
  int rainfall = analogRead(rainPin);
  
  String data = String("field1=") + String(temperature) + String("&field2=") + String(humidity))+ String("&field3=") + String(pressure)+ String("&field4=") + String(rainfall)+String("&status=MQTTPUBLISH");
    int length = data.length();
    const char *msgBuffer;
    msgBuffer = data.c_str();
    Serial.println(msgBuffer);

//    String topicString = "channels/" + String(channelId) + "/publish/" + String(writeApiKey);
    String topicString = "channels/" + String(channelId) + "/publish";
    length = topicString.length();
    const char *topicBuffer;
    topicBuffer = topicString.c_str();
    Serial.println(topicBuffer);
    bool mqttpublish = mqttClient.publish(topicBuffer, msgBuffer);
    Serial.print("mqttClient.publish status: "); 
    Serial.println(mqttpublish);
    bool PubSub_Status = mqttClient.connected();
    Serial.print("mqttClient.connected after publish: "); 
    Serial.println(PubSub_Status);

    lastConnectionTime = millis();
    
    }

// Logic for subscribe

    void mqttSubscribe(){
      String myTopic = "channels/"+String( channelId )+"/subscribe";
      bool substatus = mqttClient.subscribe(myTopic.c_str());
      Serial.println(substatus);
      Serial.print("Subcribed to experimenatal channel: ");
      Serial.println(channelId);
    }

    void subCallback(char* topic, byte* message, unsigned int length) {
      Serial.print("Message arrived on topic: ");
      Serial.print(topic);
      Serial.print(". Message: ");
      String messageTemp;
      
      for (int i = 0; i < length; i++) {
        Serial.print((char)message[i]);
        messageTemp += (char)message[i];
      }
      
      Serial.println();
}
