//Program Atmega untuk board_1
#include <SoftwareSerial.h>  //untuk komunikasi serial
#define RX 0                 //pin RX
#define TX 1                 //pin TX

int LED[82];
//deklarasi pin LED
// #define LED_1 A3
// #define LED_2 A4
// #define LED_3 A5
// #define LED_4 PD4
// #define LED_5 PD5
// #define LED_6 PD6
// #define LED_7 PD7
// #define LED_8 8
// #define LED_9 9
// #define LED_10 10
// #define LED_11 11
// #define LED_12 12
// #define LED_13 13
// #define LED_14 A0
// #define LED_15 A1
// #define LED_16 A2

//deklarasi variable untuk read data
String data;
String codeString;
int code;
int intState;
bool state;

//define RX & TX pada board 1
SoftwareSerial wemos(RX, TX);


void setup() {
  LED[65] = A3;
  LED[66] = A4;
  LED[67] = A5;
  LED[68] = PD4;
  LED[69] = PD5;
  LED[70] = PD6;
  LED[71] = PD7;
  LED[72] = 8;
  LED[73] = 9;
  LED[74] = 10;
  LED[75] = 11;
  LED[76] = 12;
  LED[77] = 13;
  LED[78] = A0;
  LED[79] = A1;
  LED[80] = A2;

  // setup serial
  Serial.begin(115200);
  wemos.begin(9600);

  //setup pin LED
  for (int i = 65; i <= 81; i++) {
    pinMode(LED[i], OUTPUT);
    delay(100);
    digitalWrite(LED[i], HIGH);
    delay(100);
  }


  // //Matikan semua lampu
  // for(int i = 65; i<=81;i++){
  //   digitalWrite(LED[i], HIGH);
  //   delay(100);
  // }
}

void loop() {
  if (wemos.available()) {
    while (wemos.available()) {
      data = wemos.readString();

      Serial.println("init str: " + data);
    }

    if (data.length() > 2) {
      codeString = data.substring(0, 2);
      Serial.println("codeString: " + codeString);

      intState = data.substring(2).toInt();

      if (intState == 0) {
        state = 0;
        Serial.println("intState 0");
      } else {
        state = 1;
        Serial.println("intState 1");
      }

      code = codeString.toInt();

      //logika LED hidup/mati
      digitalWrite(LED[code], state);

      //mengembalikan data menjadi ""
      data = "";
    }
  }
}
