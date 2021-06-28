#include <nRF24L01.h>
#include <RF24.h>
#include <RF24_config.h>
#include <SPI.h>

const int pinCE = 9;
const int pinCSN = 10;
RF24 radio(pinCE, pinCSN);

// Single radio pipe address for the 2 nodes to communicate.
const uint64_t pipe = 0xE8E8F0F0E1LL;

char data[16];

void setup(void)
{
   Serial.begin(9600);
   radio.begin();
   radio.openReadingPipe(1,pipe);
   pinMode(5, OUTPUT);
   pinMode(6, OUTPUT);
   pinMode(7, OUTPUT);
   radio.startListening();
}
 
void loop(void)
{
   if (radio.available())
   {
      radio.read(data, sizeof data);
      Serial.println("llega data");
      Serial.println(data);
      digitalWrite(5, HIGH);
      digitalWrite(6, HIGH);
      digitalWrite(7, HIGH);
      delay(1000);
      digitalWrite(5, LOW);
      digitalWrite(6, LOW);
      digitalWrite(7, LOW);
      delay(1000);
   }
}
