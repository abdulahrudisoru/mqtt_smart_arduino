//Program Atmega untuk board_5
#include <SoftwareSerial.h> //untuk komunikasi serial
#define RX 0 //pin RX
#define TX 1 //pin TX

//deklarasi pin LED
#define LED_01 A3
#define LED_02 A4
#define LED_03 A5
#define LED_04 PD4
#define LED_05 PD5
#define LED_06 PD6
#define LED_07 PD7
#define LED_08 8
#define LED_09 9
#define LED_10 10
#define LED_11 11
#define LED_12 12
#define LED_13 13
#define LED_14 A0
#define LED_15 A1
#define LED_16 A2

//deklarasi variable untuk read data
String data;
char c;


//define RX & TX pada board 1
SoftwareSerial wemos (RX, TX);


void setup() {
  // setup serial
  Serial.begin(9600);
  wemos.begin(9600);

  //setup pin LED
  pinMode(LED_01, OUTPUT);
  pinMode(LED_02, OUTPUT);
  pinMode(LED_03, OUTPUT);
  pinMode(LED_04, OUTPUT);
  pinMode(LED_05, OUTPUT);
  pinMode(LED_06, OUTPUT);
  pinMode(LED_07, OUTPUT);
  pinMode(LED_08, OUTPUT);
  pinMode(LED_09, OUTPUT);
  pinMode(LED_10, OUTPUT);
  pinMode(LED_11, OUTPUT);
  pinMode(LED_12, OUTPUT);
  pinMode(LED_13, OUTPUT);
  pinMode(LED_14, OUTPUT);
  pinMode(LED_15, OUTPUT);
  pinMode(LED_16, OUTPUT);

  //Matikan semua lampu
  digitalWrite(LED_01, LOW);
  digitalWrite(LED_02, LOW);
  digitalWrite(LED_03, LOW);
  digitalWrite(LED_04, LOW);
  digitalWrite(LED_05, LOW);
  digitalWrite(LED_06, LOW);
  digitalWrite(LED_07, LOW);
  digitalWrite(LED_08, LOW);
  digitalWrite(LED_09, LOW);
  digitalWrite(LED_10, LOW);
  digitalWrite(LED_11, LOW);
  digitalWrite(LED_12, LOW);
  digitalWrite(LED_13, LOW);
  digitalWrite(LED_14, LOW);
  digitalWrite(LED_15, LOW);
  digitalWrite(LED_16, LOW);
}

void loop() {
  //Membaca data yang dikirim oleh WEMOS
  // while(wemos.available()>0){
  //   delay(10);
  //   c = wemos.read();
  //   data+=c;
  // }
  if (wemos.available()) {
    data = wemos.readString(); 
  }


  //logika LED hidup/mati
  if(data == "650"){
    digitalWrite(LED_01, HIGH);
  } 
  else if(data == "651"){
    digitalWrite(LED_01, LOW);
  } 
  else if(data == "660"){
    digitalWrite(LED_02, HIGH);
  } 
  else if(data == "661"){
    digitalWrite(LED_02, LOW);
  } 
  else if(data == "670"){
    digitalWrite(LED_03, HIGH);
  } 
  else if(data == "671"){
    digitalWrite(LED_03, LOW);
  }
  else if(data == "680"){
    digitalWrite(LED_04, HIGH);
  }
  else if(data == "681"){
    digitalWrite(LED_04, LOW);
  }
  else if(data == "690"){
    digitalWrite(LED_05, HIGH);
  }
  else if(data == "691"){
    digitalWrite(LED_05, LOW);
  }
  else if(data == "700"){
    digitalWrite(LED_06, HIGH);
  }
  else if(data == "701"){
    digitalWrite(LED_06, LOW);
  }
  else if(data == "710"){
    digitalWrite(LED_07, HIGH);
  }
  else if(data == "711"){
    digitalWrite(LED_07, LOW);
  }
  else if(data == "720"){
    digitalWrite(LED_08, HIGH);
  }
  else if(data == "721"){
    digitalWrite(LED_08, LOW);
  }
  else if(data == "730"){
    digitalWrite(LED_09, HIGH);
  }
  else if(data == "731"){
    digitalWrite(LED_09, LOW);
  }
  else if(data == "740"){
    digitalWrite(LED_10, HIGH);
  }
  else if(data == "741"){
    digitalWrite(LED_10, LOW);
  }
  else if(data == "750"){
    digitalWrite(LED_11, HIGH);
  }
  else if(data == "751"){
    digitalWrite(LED_11, LOW);
  }
  else if(data == "760"){
    digitalWrite(LED_12, HIGH);
  }
  else if(data == "761"){
    digitalWrite(LED_12, LOW);
  }
  else if(data == "770"){
    digitalWrite(LED_13, HIGH);
  }
  else if(data == "771"){
    digitalWrite(LED_13, LOW);
  }
  else if(data == "780"){
    digitalWrite(LED_14, HIGH);
  }
  else if(data == "781"){
    digitalWrite(LED_14, LOW);
  }
  else if(data == "790"){
    digitalWrite(LED_15, HIGH);
  }
  else if(data == "791"){
    digitalWrite(LED_15, LOW);
  }
  else if(data == "800"){
    digitalWrite(LED_16, HIGH);
  }
  else if(data == "801"){
    digitalWrite(LED_16, LOW);
  }
  
  //mengembalikan data menjadi ""
  data="";

}
