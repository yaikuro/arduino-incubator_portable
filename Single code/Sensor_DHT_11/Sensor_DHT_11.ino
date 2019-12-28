#include <DHT.h>
#define DHTPIN A0
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);


int LED1 = 3; //LED kuning
int LED2 = 4; //LED Hijau
int LED3 = 5; //LED Merah
int LED4 = 9; 
int LED5 = 10;
int LED6 = 11;

void setup() {
  Serial.begin(9600);
  dht.begin();
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  pinMode(LED5, OUTPUT);
  pinMode(LED6, OUTPUT);
  


}

void loop() {
  float kelembaban = dht.readHumidity();
  float suhu = dht.readTemperature();
  
  Serial.println("");
  Serial.print("Kelembaban : ");
  Serial.print(kelembaban);
  Serial.println("%");
  Serial.print("Suhu : ");
  Serial.print(suhu);
  Serial.println("*C");
  
  delay(500);
  
  if ( suhu > 24.00){
        digitalWrite(LED1, LOW);
        digitalWrite(LED2, LOW);
        digitalWrite(LED3, HIGH);
     }
  else if ( suhu < 22.00){
        digitalWrite(LED1, HIGH);
        digitalWrite(LED2, LOW);
        digitalWrite(LED3, LOW);
     }
  else {
        digitalWrite(LED1, LOW);
        digitalWrite(LED2, HIGH);
        digitalWrite(LED3, LOW);   
  }// put your main code here, to run repeatedly:
}
