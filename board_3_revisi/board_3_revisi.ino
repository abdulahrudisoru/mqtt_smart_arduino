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
  LED[33] = A3;
  LED[34] = A4;
  LED[35] = A5;
  LED[36] = PD4;
  LED[37] = PD5;
  LED[38] = PD6;
  LED[39] = PD7;
  LED[40] = 8;
  LED[41] = 9;
  LED[42] = 10;
  LED[43] = 11;
  LED[44] = 12;
  LED[45] = 13;
  LED[46] = A0;
  LED[47] = A1;
  LED[48] = A2;

  // setup serial
  Serial.begin(115200);
  wemos.begin(9600);

  //setup pin LED
  for (int i = 33; i <= 48; i++) {
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
