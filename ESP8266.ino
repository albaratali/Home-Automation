// Fill-in information from your Blynk Template here
#define BLYNK_TEMPLATE_ID "TMPL6rqvtmVha"
#define BLYNK_TEMPLATE_NAME "Home Automation"

#define BLYNK_FIRMWARE_VERSION        "0.1.0"

#define BLYNK_PRINT Serial
//#define BLYNK_DEBUG

#define APP_DEBUG

// Uncomment your board, or configure a custom board in Settings.h
//#define USE_SPARKFUN_BLYNK_BOARD
#define USE_NODE_MCU_BOARD
//#define USE_WITTY_CLOUD_BOARD
//#define USE_WEMOS_D1_MINI

#include "BlynkEdgent.h"

int RelayPin1 = 5;
int RelayPin2 = 4;
int RelayPin3 = 14;
int RelayPin4 = 12;

BLYNK_WRITE(V0) { //Button Widget is writing to pin V0
  int pinValue = param.asInt();
  digitalWrite(RelayPin1, pinValue);
}

BLYNK_WRITE(V1) { //Button Widget is writing to pin V1
  int pinValue = param.asInt();
  digitalWrite(RelayPin2, pinValue);
}
BLYNK_WRITE(V2) { //Button Widget is writing to pin V2
  int pinValue = param.asInt();
  digitalWrite(RelayPin3, pinValue);
}
BLYNK_WRITE(V3) { //Button Widget is writing to pin V3
  int pinValue = param.asInt();
  digitalWrite(RelayPin4, pinValue);
}

void setup()
{
  Serial.begin(115200);
  pinMode(RelayPin1, OUTPUT);
  pinMode(RelayPin2, OUTPUT);
  pinMode(RelayPin3, OUTPUT);
  pinMode(RelayPin4, OUTPUT);

  //TURN OFF all Relays on Start 
  digitalWrite(RelayPin1, HIGH);
  digitalWrite(RelayPin2, HIGH);
  digitalWrite(RelayPin3, HIGH);
  digitalWrite(RelayPin4, HIGH);
  
  delay(100);
  BlynkEdgent.begin();
}

void loop() {
  BlynkEdgent.run();
}
