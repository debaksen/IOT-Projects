# Switching LED ON/OFF using User Datagram Protocol

### Introduction : 

UDP is an alternative communications protocol to TCP used primarily fir establishing low latency & loss-tolerating connections.
UDP does not use acknowledgments at all i.e does't need handshaking at every moment unlike TCP. Here in this mini project,
we will implement UDP trasmission as a part of switching ON/OFF

### Hardware Used :

1.Node MCU
2.LED
3.BreadBoard
4.Jumper Wires

### Library Used :

Here we used two library first <ESP8266WiFi.h> for fetching the raw data of NodeMCU & WiFiUdp for the UDP connection part.
The code is attached and commented lines are made for understanding purpouse. 

