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
  LED[1] = A3;
  LED[2] = A4;
  LED[3] = A5;
  LED[4] = PD4;
  LED[5] = PD5;
  LED[6] = PD6;
  LED[7] = PD7;
  LED[8] = 8;
  LED[9] = 9;
  LED[10] = 10;
  LED[11] = 11;
  LED[12] = 12;
  LED[13] = 13;
  LED[14] = A0;
  LED[15] = A1;
  LED[16] = A2;

  // setup serial
  Serial.begin(115200);
  wemos.begin(9600);

  //setup pin LED
  for (int i = 1; i <= 16; i++) {
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
