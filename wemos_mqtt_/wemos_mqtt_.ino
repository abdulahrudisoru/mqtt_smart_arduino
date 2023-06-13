#include <ESP8266WiFi.h>
#include <PubSubClient.h>
#include <SoftwareSerial.h>
SoftwareSerial board_1(D1,D2); //rx,tx
SoftwareSerial board_2(D3,D4);
SoftwareSerial board_3(A0,D0);
SoftwareSerial board_4(D5,D6);
SoftwareSerial board_5(D7,D8);
SoftwareSerial board_6(RX,TX);

// Update these with values suitable for your network.
const char* ssid = "PTSN SR";
const char* password = "s@tnusa8989SR";
const char* mqtt_server = "192.168.88.60"; //host

// const char* ssid = "PTSN DOT UAT";
// const char* password = "DOTUAT8#PTSN";
// const char* mqtt_server = "192.168.88.60"; //host

WiFiClient espClient;
PubSubClient client(espClient);
unsigned long lastMsg = 0;
#define MSG_BUFFER_SIZE	(50)
char msg[MSG_BUFFER_SIZE];
int value = 0;
String tampungData = "";

void setup_wifi() {

  delay(10);
  // We start by connecting to a WiFi network
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  randomSeed(micros());

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

void callback(char* topic, byte* payload, unsigned int length) {
  Serial.print("Message arrived [");
  Serial.print(topic);
  Serial.print("] ");

  tampungData = "";
  
  for (int i = 0; i < length; i++) {
    tampungData += (char)payload[i];
  }

  Serial.println(tampungData);

  // Serial.println(payload[1]);


  //tinggal tambahkan if else untuk kirim serial ke board
  // Switch on the LED if an 1 was received as first character

  //****************************board_1
  if (tampungData == "010"||tampungData == "011"||tampungData == "020"||tampungData == "021"||tampungData == "030"||tampungData == "031"||tampungData == "040"||tampungData == "041"||tampungData == "050"||tampungData == "051"
  ||tampungData == "060"||tampungData == "061"||tampungData == "070"||tampungData == "071"||tampungData == "080"||tampungData == "081"||tampungData == "090"||tampungData == "091"||tampungData == "100"||tampungData == "101"
  ||tampungData == "110"||tampungData == "111"||tampungData == "120"||tampungData == "121"||tampungData == "130"||tampungData == "131"||tampungData == "140"||tampungData == "141"||tampungData == "150"||tampungData == "151"
  ||tampungData == "160"||tampungData == "161") { //Hidupkan LED
    Serial.println("**********BOARD 1**********");
    Serial.println("Input: " + tampungData );
    board_1.print(tampungData);  // Turn the LED on (Note that LOW is the voltage level
  }  // Turn the LED off by making the voltage HIGH

  //******************************board_2
  else if (tampungData == "170"||tampungData == "171"||tampungData == "180"||tampungData == "181"||tampungData == "190"||tampungData == "191"||tampungData == "200"||tampungData == "201"||tampungData == "210"||tampungData == "211"
  ||tampungData == "220"||tampungData == "221"||tampungData == "230"||tampungData == "231"||tampungData == "240"||tampungData == "241"||tampungData == "250"||tampungData == "251"||tampungData == "260"||tampungData == "261"
  ||tampungData == "270"||tampungData == "271"||tampungData == "280"||tampungData == "281"||tampungData == "290"||tampungData == "291"||tampungData == "300"||tampungData == "301"||tampungData == "310"||tampungData == "311"
  ||tampungData == "320"||tampungData == "321") { //matikan LED
    Serial.println("**********BOARD 2**********");
    Serial.println("Input: " + tampungData );
    board_2.print(tampungData);
  }

  //******************************board_3
  else if (tampungData == "330"||tampungData == "331"||tampungData == "340"||tampungData == "341"||tampungData == "350"||tampungData == "351"||tampungData == "360"||tampungData == "361"||tampungData == "370"||tampungData == "371"
  ||tampungData == "380"||tampungData == "381"||tampungData == "390"||tampungData == "391"||tampungData == "400"||tampungData == "401"||tampungData == "410"||tampungData == "411"||tampungData == "420"||tampungData == "421"
  ||tampungData == "430"||tampungData == "431"||tampungData == "440"||tampungData == "441"||tampungData == "450"||tampungData == "451"||tampungData == "460"||tampungData == "461"||tampungData == "470"||tampungData == "471"
  ||tampungData == "480"||tampungData == "481") { //matikan LED
    Serial.println("**********BOARD 3**********");
    Serial.println("Input: " + tampungData );
    board_3.print(tampungData);
  }

  //******************************board_4
  else if (tampungData == "490"||tampungData == "491"||tampungData == "500"||tampungData == "501"||tampungData == "510"||tampungData == "511"||tampungData == "520"||tampungData == "521"||tampungData == "530"||tampungData == "531"
  ||tampungData == "540"||tampungData == "541"||tampungData == "550"||tampungData == "551"||tampungData == "560"||tampungData == "561"||tampungData == "570"||tampungData == "571"||tampungData == "580"||tampungData == "581"
  ||tampungData == "590"||tampungData == "591"||tampungData == "600"||tampungData == "601"||tampungData == "610"||tampungData == "611"||tampungData == "620"||tampungData == "621"||tampungData == "630"||tampungData == "631"
  ||tampungData == "640"||tampungData == "641") { //matikan LED
    Serial.println("**********BOARD 4**********");
    Serial.println("Input: " + tampungData );
    board_4.print(tampungData);
  }

  //******************************board_5
  else if (tampungData == "650"||tampungData == "651"||tampungData == "660"||tampungData == "661"||tampungData == "670"||tampungData == "671"||tampungData == "680"||tampungData == "681"||tampungData == "690"||tampungData == "691"
  ||tampungData == "700"||tampungData == "701"||tampungData == "710"||tampungData == "711"||tampungData == "720"||tampungData == "721"||tampungData == "730"||tampungData == "731"||tampungData == "740"||tampungData == "741"
  ||tampungData == "750"||tampungData == "751"||tampungData == "760"||tampungData == "761"||tampungData == "770"||tampungData == "771"||tampungData == "780"||tampungData == "781"||tampungData == "790"||tampungData == "791"
  ||tampungData == "800"||tampungData == "801") { //matikan LED
    Serial.println("**********BOARD 5**********");
    Serial.println("Input: " + tampungData );
    board_5.print(tampungData);
  }

  //******************************board_6
  else if (tampungData == "810"||tampungData == "811"||tampungData == "820"||tampungData == "821"||tampungData == "830"||tampungData == "831"||tampungData == "840"||tampungData == "841"||tampungData == "850"||tampungData == "851") { //matikan LED
    Serial.println("**********BOARD 6**********");
    Serial.println("Input: " + tampungData );
    board_6.print(tampungData);
  }



}

void reconnect() {
  // Loop until we're reconnected
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    // Create a random client ID
    String clientId = "clientId-qqFVnGUkJv";//ClientID
    clientId += String(random(0xffff), HEX);
    // Attempt to connect
    if (client.connect(clientId.c_str())) {
      Serial.println("connected");
      digitalWrite(BUILTIN_LED, HIGH);
      // Once connected, publish an announcement...
      // client.publish("/device/moulding/out", "hello world");
      // ... and resubscribe
      client.subscribe("/device/moulding/in"); //topic
    } else {
      digitalWrite(BUILTIN_LED, LOW); 
      Serial.print("failed, rc="); 
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      // Wait 5 seconds before retrying
      delay(5000);
    }
  }
}

void setup() {
  pinMode(BUILTIN_LED, OUTPUT);     // Initialize the BUILTIN_LED pin as an output
  Serial.begin(115200);
  board_1.begin(9600);
  board_2.begin(9600);
  board_3.begin(9600);
  board_4.begin(9600);
  board_5.begin(9600);
  board_6.begin(9600);
  setup_wifi();
  client.setServer(mqtt_server, 1883);
  client.setCallback(callback);
}

void loop() {

  if (!client.connected()) {
    reconnect();
  }
  client.loop();

  // unsigned long now = millis();
  // if (now - lastMsg > 10000) {
  //   lastMsg = now;
  //   ++value;
  //   snprintf (msg, MSG_BUFFER_SIZE, "hello world #%ld", value);
  //   Serial.print("Publish message: ");
  //   Serial.println(msg);
  //   client.publish("/device/moulding/out", msg);
  // }
}