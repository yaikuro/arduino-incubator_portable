#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DHT.h>
#define DHTPIN A0
#define DHTTYPE DHT22

LiquidCrystal_I2C lcd(0x3F, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);
DHT dht(DHTPIN, DHTTYPE);


int LED1 = 3; //LED kuning suhu
int LED2 = 4; //LED hijau
int LED3 = 5; //LED merah
int LED4 = 9; //LED kuning2 kelembaban
int LED5 = 10;//LED hijau2
int LED6 = 11; //LED merah2

int RELAY1= A1;
int RELAY2= A2;

void setup() {
  
  dht.begin();
  lcd.begin(16,2);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  pinMode(LED5, OUTPUT);
  pinMode(LED6, OUTPUT);
  pinMode(RELAY1, OUTPUT);
  pinMode(RELAY2, OUTPUT);

  lcd.setCursor(4,1);
  lcd.print("Starting up");
  delay(2000);
  lcd.clear();
  lcd.setCursor(5,0);
  lcd.print("Incubator            Portable");
  delay(2000);
  Serial.begin(9600);

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
  
  if ( suhu >= 37){                 // SUHU
        digitalWrite(LED1, LOW);
        digitalWrite(LED2, HIGH);
        digitalWrite(LED3, LOW);
        digitalWrite(RELAY1, HIGH); //high = arus mati (relay)
     }
  else if ( suhu > 37){
        digitalWrite(LED1, LOW);
        digitalWrite(LED2, LOW);
        digitalWrite(LED3, HIGH);
        digitalWrite(RELAY1, HIGH);
  }
  else if ( suhu < 33){
        digitalWrite(LED1, HIGH);
        digitalWrite(LED2, LOW);
        digitalWrite(LED3, LOW);
        digitalWrite(RELAY1, LOW ); //Jika 'LOW' = aki tidak menyala
     }
  else {
        digitalWrite(LED1, LOW);
        digitalWrite(LED2, HIGH);
        digitalWrite(LED3, LOW);   
        digitalWrite(RELAY1, LOW);
     }
     
  if ( kelembaban > 60) {          //KELEMBABAN
        digitalWrite(LED4, LOW);
        digitalWrite(LED5, LOW);
        digitalWrite(LED6, HIGH);
   }
  else if ( kelembaban < 40){
        digitalWrite(LED4, HIGH);
        digitalWrite(LED5, LOW);
        digitalWrite(LED6, LOW);
     }
  else {
        digitalWrite(LED4, LOW);
        digitalWrite(LED5, HIGH);
        digitalWrite(LED6, LOW);
  }


  lcd.clear();
  
  lcd.setCursor(0,0);
  lcd.print  (" Incubator Portable Suhu       : ");
  lcd.print  (suhu);
  lcd.print("'C");
  
  lcd.setCursor(0,1);
  lcd.print("                    Kelembaban : ");
  lcd.print(kelembaban);
  lcd.print(" %");
  
}
