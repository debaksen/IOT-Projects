#include <ESP8266WiFi.h>
#include<WiFiUdp.h>

const char* ssid ="tiuiotlab";
const char* password="eng@tiu11";

unsigned int localport = 49999;
WiFiUDP Udp;
char Message[50];

void setup() {
  pinMode(D0 ,OUTPUT); 
  // put your setup code here, to run once:
  Serial.begin(9600);
  delay(100);


  
  WiFi.begin(ssid,password);
  Serial.print("Connecting to ---->");
  Serial.println(ssid);

  
  while(WiFi.status() !=WL_CONNECTED) 
  {
    delay(1200);
    Serial.print("*");
    }
    
    Serial.println("");
    Serial.println("WiFi connected");
  


 Serial.println("WiFi Connected and your device details are:");
      Serial.println("````````````````````````````````````````````````````````````````````````");
      Serial.print("Your Device is online and the Ip is: ");
      Serial.println(WiFi.localIP());
      Serial.print("And the port is: ");
      Serial.println(localport);
      Serial.println("````````````````````````````````````````````````````````````````````````");

  Udp.begin(localport);


//end 

}



void loop() {
  // put your main code here, to run repeatedly:
  
  int packetSize =Udp.parsePacket();
  if(packetSize > 0) {
      Serial.println("Got a packet");
      IPAddress remote= Udp.remoteIP();
      unsigned int port =Udp.remotePort();
      //Serial.println("remote");
     
      //Serial.println("Payload length");
      //Serial.print(packetSize);
      //Serial.println("Bytes");
      Udp.read(Message,30);
      //Serial.println("Content: ");
      //Serial.println(ReceivingBuffer);
      String logic=String(Message);
     // Serial.print("---");
      //Serial.print(logic);
      //Serial.print("---");


// Now adding just a command based secure layer so that it will get into action only when a specified command is called for 
//For example if I want the led to get switched ON wonly when "ON" is send as a packet from the packet sender , fien below the cdes for that 

      
      if(logic.equals("ON")){
        Serial.println("Access Granted");
        Serial.println("Welcome Home - Lights are on");
        digitalWrite(D0, HIGH); 
        delay(2000);    
           // turn the LED off by making the voltage LOW
      }
      else if(logic.equals("OFF")){
        Serial.println("Access Granted");
        Serial.println("Welcome  Home - Lights are off now");
        digitalWrite(D0, LOW); 
        }
      else{
      Serial.println("Access Denied");
      Serial.print("unauthorized Access from: ---------> ");
      Serial.println(remote);
      Serial.print("Port: ---------> ");
      Serial.println(port);
      Serial.println("Port ");
      Serial.print("Used command is: ---------->  ");
      Serial.println(logic);
      }

// very important part of the program 
// in order to flush the previous content from the ReceivingBuffer array everytime after the execeution of the command ...we are setting the array to null
      
      for(int i=0;i<50;i++)
      Message [i] = 0;
       Serial.println("");
       Serial.println("");

       
       
      Serial.println("````````````");
      Serial.println("````````````");
      Serial.print(" Your Device is online and the Ip is: ");
      Serial.println(WiFi.localIP());
      Serial.print("And the port is: ");
      Serial.println(localport);
      Serial.println("````````````");
      Serial.println("````````````");
    }
}
