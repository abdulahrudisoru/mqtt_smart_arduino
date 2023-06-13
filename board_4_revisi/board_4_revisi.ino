//Program Atmega untuk board_1
#include <SoftwareSerial.h>  //untuk komunikasi serial
#define RX 0                 //pin RX
#define TX 1                 //pin TX

int LED[100];

//deklarasi variable untuk read data
char c;
String data;
String codeString;
int code;
int intState;
bool state;

//define RX & TX pada board 1
SoftwareSerial wemos(RX, TX);


void setup() {
  LED[49] = A3;
  LED[50] = A4;
  LED[51] = A5;
  LED[52] = PD4;
  LED[53] = PD5;
  LED[54] = PD6;
  LED[55] = PD7;
  LED[56] = 8;
  LED[57] = 9;
  LED[58] = 10;
  LED[59] = 11;
  LED[60] = 12;
  LED[61] = 13;
  LED[62] = A0;
  LED[63] = A1;
  LED[64] = A2;

  // setup serial
  Serial.begin(115200);
  wemos.begin(9600);

  //setup pin LED
  for (int i = 49; i <= 64; i++) {
    pinMode(LED[i], OUTPUT);
    delay(100);
    digitalWrite(LED[i], HIGH);
    delay(100);
  }
}

void loop() {
  if (wemos.available()) {
    // while (wemos.available()) {
    //   data = wemos.readString();

    //   Serial.println("init str: " + data);
    // }

    while(wemos.available()>0){
      delay(10);
      c = wemos.read();
      data+=c;
    }
    if (data.length() > 2) {
      codeString = data.substring(0, 2);
      Serial.println("codeString: " + codeString);

      intState = data.substring(2).toInt();

      if (intState == 0) {
        state = 1;
        Serial.println("intState Mati");
      } else {
        state = 0;
        Serial.println("intState Hidup");
      }

      code = codeString.toInt();

      //logika LED hidup/mati
      digitalWrite(LED[code], state);

      //mengembalikan data menjadi ""
      data = "";
    }
  }
}
