/*
   Autor:Erivelto Clénio da Costa e Silva
   Data última Atualização:18/05/2024
   Objectivo: Controle o nível de água em 2 reservatórios no Condominio Kizomba

  Principais Componentes usados:
 *** 1-ARDUINO MEGA 2560 (1)
 *** 2- 
 *** 3-LCD COM I2C (1)
 *** 6-TRANSISTORES BC548 (6) COM RESISTORES (6)
 ***
*/


#include<LiquidCrystal.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <SoftwareSerial.h>

LiquidCrystal_I2C lcd(0x27,20,4);
SoftwareSerial mySerial(34, 35); // RX, TX

char msg;

#define Sensor1 22
#define Sensor2 23
#define Sensor3 24
#define Sensor4 25
#define Sensor5 26
#define Sensor6 27
#define Sensor7 28
#define Sensor8 29
#define Sensor9 30
#define Sensor10 31

#define buzzer  13

#define Ledverde1 2
#define Ledverde2 3
#define Ledamarelo3 4
#define Ledamarelo2 5
#define Ledamarelo1 6
#define Ledlaranja2 7
#define Ledlaranja1 8
#define Ledvermelho3 9
#define Ledvermelho2 10
#define Ledvermelho1 11

 
int sensor1 = 1, sensor2 = 1, sensor3 = 1, sensor4 = 1, sensor5 = 1;
int sensor6 = 1, sensor7 = 1, sensor8 = 1, sensor9 = 1, sensor10 = 1;
 
int nivelinicial = 0;
 
void setup() {

  mySerial.begin(9600); 
  Serial.begin(9600);
 
  pinMode(Sensor1, INPUT);
  pinMode(Sensor2, INPUT);
  pinMode(Sensor3, INPUT);
  pinMode(Sensor4, INPUT);
  pinMode(Sensor5, INPUT);
  pinMode(Sensor6, INPUT);
  pinMode(Sensor7, INPUT);
  pinMode(Sensor8, INPUT);
  pinMode(Sensor9, INPUT);
  pinMode(Sensor10, INPUT);

  pinMode(buzzer, OUTPUT);

  pinMode(Ledverde1, OUTPUT);
  pinMode(Ledverde2, OUTPUT);
  pinMode(Ledamarelo3, OUTPUT);
  pinMode(Ledamarelo2, OUTPUT);
  pinMode(Ledamarelo1, OUTPUT);
  pinMode(Ledlaranja2, OUTPUT);
  pinMode(Ledlaranja1, OUTPUT);
  pinMode(Ledvermelho3, OUTPUT);
  pinMode(Ledvermelho2, OUTPUT);
  pinMode(Ledvermelho1, OUTPUT);

 
  lcd.init();        // inicializando o Dispaly
  lcd.backlight();  // mantem a luz do LCD acesso
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("NIVEL DO TANQUE");
  lcd.setCursor(0,1);
  lcd.print("      FW1   ");
  delay(300);
  
}
 
void loop() {
  int sensor1 = digitalRead(Sensor1);
  int sensor2 = digitalRead(Sensor2);
  int sensor3 = digitalRead(Sensor3);
  int sensor4 = digitalRead(Sensor4);
  int sensor5 = digitalRead(Sensor5);
  int sensor6 = digitalRead(Sensor6);
  int sensor7 = digitalRead(Sensor7);
  int sensor8 = digitalRead(Sensor8);
  int sensor9 = digitalRead(Sensor9);
  int sensor10 = digitalRead(Sensor10);

  // Primeiro Nivel - 100% - 4,5 m^2 - todos os leds acesso
 
  if ((sensor1 == 1) && (sensor2 == 1) && (sensor3 == 1) && (sensor4 == 1) && (sensor5 == 1) 
   && (sensor6 == 1) && (sensor7 == 1) && (sensor8 == 1) && (sensor9 == 1) && (sensor10 == 1)) {
    lcd.clear();
    Serial.println("Reservatorio Cheio");
    lcd.setCursor(0,0);
    lcd.print("RESERVATORIO FW1");
    lcd.setCursor(0,1);
    lcd.print("     Cheio     ");

    digitalWrite(buzzer, LOW);

    digitalWrite(Ledverde1, HIGH);
    digitalWrite(Ledverde2, HIGH);
    digitalWrite(Ledamarelo3, HIGH);
    digitalWrite(Ledamarelo2, HIGH);
    digitalWrite(Ledamarelo1, HIGH);
    digitalWrite(Ledlaranja2, HIGH);
    digitalWrite(Ledlaranja1, HIGH);
    digitalWrite(Ledvermelho3, HIGH);
    digitalWrite(Ledvermelho2, HIGH);
    digitalWrite(Ledvermelho1, HIGH);
    delay(200);
  }

    // Segundo Nivel - 90% - 4,05 m^2 - um led apagado
 
  else if ((sensor1 == 0) && (sensor2 == 1) && (sensor3 == 1) && (sensor4 == 1) && (sensor5 == 1) 
   && (sensor6 == 1) && (sensor7 == 1) && (sensor8 == 1) && (sensor9 == 1) && (sensor10 == 1)) {
     lcd.clear();
    Serial.println("Nivel 100 a 90%");
    lcd.setCursor(0,0);
    lcd.print("RESERVATORIO FW1");
    lcd.setCursor(0,1);
    lcd.print("   NIVEL a 90%");

    digitalWrite(buzzer, LOW);

    digitalWrite(Ledverde1, LOW);
    digitalWrite(Ledverde2, HIGH);
    digitalWrite(Ledamarelo3, HIGH);
    digitalWrite(Ledamarelo2, HIGH);
    digitalWrite(Ledamarelo1, HIGH);
    digitalWrite(Ledlaranja2, HIGH);
    digitalWrite(Ledlaranja1, HIGH);
    digitalWrite(Ledvermelho3, HIGH);
    digitalWrite(Ledvermelho2, HIGH);
    digitalWrite(Ledvermelho1, HIGH);
    delay(200);

  }

    // terceiro Nivel - 80% - 3,6 m^2 - dois leds apagados
 
  else if ((sensor1 == 0) && (sensor2 == 0) && (sensor3 == 1) && (sensor4 == 1) && (sensor5 == 1) 
        && (sensor6 == 1) && (sensor7 == 1) && (sensor8 == 1) && (sensor9 == 1) && (sensor10 == 1)) {
    lcd.clear();
    Serial.println("Nivel de 90 a 80%");
    lcd.setCursor(0,0);
    lcd.print("RESERVATORIO FW1");
    lcd.setCursor(0,1);
    lcd.print("   Nivel a 80%");
 
    digitalWrite(buzzer, LOW);

    digitalWrite(Ledverde1, LOW);
    digitalWrite(Ledverde2, LOW);
    digitalWrite(Ledamarelo3, HIGH);
    digitalWrite(Ledamarelo2, HIGH);
    digitalWrite(Ledamarelo1, HIGH);
    digitalWrite(Ledlaranja2, HIGH);
    digitalWrite(Ledlaranja1, HIGH);
    digitalWrite(Ledvermelho3, HIGH);
    digitalWrite(Ledvermelho2, HIGH);
    digitalWrite(Ledvermelho1, HIGH);
    delay(200);
  }

  // Quarto Nivel - 70% - 3,15 m^2 - três leds apagados
 
  else if ((sensor1 == 0) && (sensor2 == 0) && (sensor3 == 0) && (sensor4 == 1) && (sensor5 == 1)
        && (sensor6 == 1) && (sensor7 == 1) && (sensor8 == 1) && (sensor9 == 1) && (sensor10 == 1)) {
    lcd.clear();
    Serial.println("Nivel de 80 a 70%");
    lcd.setCursor(0,0);
    lcd.print("RESERVATORIO FW1");
    lcd.setCursor(0,1);
    lcd.print("  Nivel a 70%");
    
    digitalWrite(buzzer, LOW);

    digitalWrite(Ledverde1, LOW);
    digitalWrite(Ledverde2, LOW);
    digitalWrite(Ledamarelo3, LOW);
    digitalWrite(Ledamarelo2, HIGH);
    digitalWrite(Ledamarelo1, HIGH);
    digitalWrite(Ledlaranja2, HIGH);
    digitalWrite(Ledlaranja1, HIGH);
    digitalWrite(Ledvermelho3, HIGH);
    digitalWrite(Ledvermelho2, HIGH);
    digitalWrite(Ledvermelho1, HIGH);
    delay(200);
  }

  
  // Quinto Nivel - 60% - 2,7 m^2 - quatro leds apagados
 
  else if ((sensor1 == 0) && (sensor2 == 0) && (sensor3 == 0) && (sensor4 == 0) && (sensor5 == 1)
        && (sensor6 == 1) && (sensor7 == 1) && (sensor8 == 1) && (sensor9 == 1) && (sensor10 == 1)) {
    lcd.clear();
    Serial.println("Nivel de 70 a 60%");
    lcd.setCursor(0,0);
    lcd.print("RESERVATORIO FW1");
    lcd.setCursor(0,1);
    lcd.print("  Nivel a 60%");
    
    digitalWrite(buzzer, LOW);

    digitalWrite(Ledverde1, LOW);
    digitalWrite(Ledverde2, LOW);
    digitalWrite(Ledamarelo3, LOW);
    digitalWrite(Ledamarelo2, LOW);
    digitalWrite(Ledamarelo1, HIGH);
    digitalWrite(Ledlaranja2, HIGH);
    digitalWrite(Ledlaranja1, HIGH);
    digitalWrite(Ledvermelho3, HIGH);
    digitalWrite(Ledvermelho2, HIGH);
    digitalWrite(Ledvermelho1, HIGH);
    delay(200);
      
  }
 
 
  // sexto Nivel - 50% - 2,25 m^2 - cinco leds apagados

  else if ((sensor1 == 0) && (sensor2 == 0) && (sensor3 == 0) && (sensor4 == 0) && (sensor5 == 0)
        && (sensor6 == 1) && (sensor7 == 1) && (sensor8 == 1) && (sensor9 == 1) && (sensor10 == 1)) {
    lcd.clear();
    Serial.println("Nivel de 60 a 50%");
    lcd.setCursor(0,0);
    lcd.print("RESERVATORIO FW1");
    lcd.setCursor(0,1);
    lcd.print("  NIVEL a 50%   ");
    
    MedioMessage();
    
    digitalWrite(buzzer, LOW);
    
    digitalWrite(Ledverde1, LOW);
    digitalWrite(Ledverde2, LOW);
    digitalWrite(Ledamarelo3, LOW);
    digitalWrite(Ledamarelo2, LOW);
    digitalWrite(Ledamarelo1, LOW);
    digitalWrite(Ledlaranja2, HIGH);
    digitalWrite(Ledlaranja1, HIGH);
    digitalWrite(Ledvermelho3, HIGH);
    digitalWrite(Ledvermelho2, HIGH);
    digitalWrite(Ledvermelho1, HIGH);
    delay(200);
  }

  // setimo Nivel - 40% - 1,8 m^2 - seis leds apagados

  else if ((sensor1 == 0) && (sensor2 == 0) && (sensor3 == 0) && (sensor4 == 0) && (sensor5 == 0)
        && (sensor6 == 0) && (sensor7 == 1) && (sensor8 == 1) && (sensor9 == 1) && (sensor10 == 1)) {
    lcd.clear();
    Serial.println("Nivel de 50 a 40%");
    lcd.setCursor(0,0);
    lcd.print("RESERVATORIO FW1");
    lcd.setCursor(0,1);
    lcd.print("  NIVEL a 40%   ");

    digitalWrite(buzzer, LOW);
    
    digitalWrite(Ledverde1, LOW);
    digitalWrite(Ledverde2, LOW);
    digitalWrite(Ledamarelo3, LOW);
    digitalWrite(Ledamarelo2, LOW);
    digitalWrite(Ledamarelo1, LOW);
    digitalWrite(Ledlaranja2, LOW);
    digitalWrite(Ledlaranja1, HIGH);
    digitalWrite(Ledvermelho3, HIGH);
    digitalWrite(Ledvermelho2, HIGH);
    digitalWrite(Ledvermelho1, HIGH);
    delay(200);
  }
  
  // Oitavo Nivel - 30% - 1,35 m^2 - sete leds apagados

  else if ((sensor1 == 0) && (sensor2 == 0) && (sensor3 == 0) && (sensor4 == 0) && (sensor5 == 0)
        && (sensor6 == 0) && (sensor7 == 0) && (sensor8 == 1) && (sensor9 == 1) && (sensor10 == 1)) {
    lcd.clear();
    Serial.println("Nivel de 40 a 30%");
    lcd.setCursor(0,0);
    lcd.print("RESERVATORIO FW1");
    lcd.setCursor(0,1);
    lcd.print("   NIVEL a 30%   ");
    CriticoMessage();

    digitalWrite(buzzer,LOW);
    
    digitalWrite(Ledverde1, LOW);
    digitalWrite(Ledverde2, LOW);
    digitalWrite(Ledamarelo3, LOW);
    digitalWrite(Ledamarelo2, LOW);
    digitalWrite(Ledamarelo1, LOW);
    digitalWrite(Ledlaranja2, LOW);
    digitalWrite(Ledlaranja1, LOW);
    digitalWrite(Ledvermelho3, HIGH);
    digitalWrite(Ledvermelho2, HIGH);
    digitalWrite(Ledvermelho1, HIGH);
    delay(200);
  }

  // Nono Nivel - 20% - 0,9 m^2 - oito leds apagados

  else if ((sensor1 == 0) && (sensor2 == 0) && (sensor3 == 0) && (sensor4 == 0) && (sensor5 == 0)
        && (sensor6 == 0) && (sensor7 == 0) && (sensor8 == 0) && (sensor9 == 1) && (sensor10 == 1)) {
    lcd.clear();
    Serial.println("Nivel de 30 a 20%");
   
    lcd.setCursor(0,0);
    lcd.print("RESERVATORIO FW1");
    lcd.setCursor(0,1);
    lcd.print("   NIVEL a 20%   ");
    
    digitalWrite(buzzer,HIGH);

    digitalWrite(Ledverde1, LOW);
    digitalWrite(Ledverde2, LOW);
    digitalWrite(Ledamarelo3, LOW);
    digitalWrite(Ledamarelo2, LOW);
    digitalWrite(Ledamarelo1, LOW);
    digitalWrite(Ledlaranja2, LOW);
    digitalWrite(Ledlaranja1, LOW);
    digitalWrite(Ledvermelho3, LOW);
    digitalWrite(Ledvermelho2, HIGH);
    digitalWrite(Ledvermelho1, HIGH);
    delay(200);
  }

  // Decimo Nivel - 10% - 0,45 m^2 - nove leds apagados

  else if ((sensor1 == 0) && (sensor2 == 0) && (sensor3 == 0) && (sensor4 == 0) && (sensor5 == 0)
        && (sensor6 == 0) && (sensor7 == 0) && (sensor8 == 0) && (sensor9 == 0) && (sensor10 == 1)) {
    lcd.clear();
    Serial.println("Nivel de 20 a 10%");
    lcd.setCursor(0,0);
    lcd.print("RESERVATORIO FW1");
    lcd.setCursor(0,1);
    lcd.print("   Nivel a 10%   ");
    SuperCriticoMessage();

    digitalWrite(buzzer, HIGH);
  
    digitalWrite(Ledverde1, LOW);
    digitalWrite(Ledverde2, LOW);
    digitalWrite(Ledamarelo3, LOW);
    digitalWrite(Ledamarelo2, LOW);
    digitalWrite(Ledamarelo1, LOW);
    digitalWrite(Ledlaranja2, LOW);
    digitalWrite(Ledlaranja1, LOW);
    digitalWrite(Ledvermelho3, LOW);
    digitalWrite(Ledvermelho2, LOW);
    digitalWrite(Ledvermelho1, HIGH);
    delay(200);
  }

// ultimo Nivel - 0% - 0,45 m^2 - nove leds apagados  

  else if ((sensor1 == 0) && (sensor2 == 0) && (sensor3 == 0) && (sensor4 == 0) && (sensor5 == 0)
        && (sensor6 == 0) && (sensor7 == 0) && (sensor8 == 0) && (sensor9 == 0) && (sensor10 == 0)) {
    lcd.clear(); 
    Serial.println("Reservatorio Vazio");
    lcd.setCursor(0,0);
    lcd.print("RESERVATORIO FW1");
    lcd.setCursor(0,1);
    lcd.print("     Vazio   ");
    VazioMessage();

    digitalWrite(buzzer, HIGH);
    
    digitalWrite(Ledverde1, LOW);
    digitalWrite(Ledverde2, LOW);
    digitalWrite(Ledamarelo3, LOW);
    digitalWrite(Ledamarelo2, LOW);
    digitalWrite(Ledamarelo1, LOW);
    digitalWrite(Ledlaranja2, LOW);
    digitalWrite(Ledlaranja1, LOW);
    digitalWrite(Ledvermelho3, LOW);
    digitalWrite(Ledvermelho2, LOW);
    digitalWrite(Ledvermelho1, HIGH);
    delay(200);
  }
 
  else {
    //Serial.println("ALERTA - ERRO");
  }
 
  delay(200);
}

void MedioMessage()
{
mySerial.println("AT+CMGF=1"); 
delay(1000); 

mySerial.println("AT+CMGS=\"+244946128147\"\r");//your number here 
mySerial.println("AT+CMGS=\"+244928322931\"\r");//your number here 
delay(1000);

mySerial.println("Tanque FW1 a 50%, Nivel ao Meio");
delay(100);
mySerial.println((char)26);
delay(1000);
}

void CriticoMessage()
{
mySerial.println("AT+CMGF=1"); 
delay(1000); 

mySerial.println("AT+CMGS=\"+244946128147\"\r");//your number here 
mySerial.println("AT+CMGS=\"+244928322931\"\r");//your number here 
delay(1000);

mySerial.println("Tanque FW1 a 30%, Nivel Critico");
delay(100);
mySerial.println((char)26);
delay(1000);
}

void SuperCriticoMessage()
{
mySerial.println("AT+CMGF=1"); 
delay(1000); 

mySerial.println("AT+CMGS=\"+244946128147\"\r");//your number here 
mySerial.println("AT+CMGS=\"+244928322931\"\r");//your number here 
delay(1000);

mySerial.println("Tanque FW1 a 10%, Nivel Super Critico");
delay(100);
mySerial.println((char)26);
delay(1000);
}

void VazioMessage()
{
mySerial.println("AT+CMGF=1"); 
delay(1000); 

mySerial.println("AT+CMGS=\"+244946128147\"\r");//your number here 
mySerial.println("AT+CMGS=\"+244928322931\"\r");//your number here 
delay(1000);

mySerial.println("Tanque FW1 Vazio");
delay(100);
mySerial.println((char)26);
delay(1000);
}
