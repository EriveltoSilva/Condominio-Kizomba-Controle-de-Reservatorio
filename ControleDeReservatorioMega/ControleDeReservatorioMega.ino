/*
   Autor:ETO(By: Alfredo Muongo & Erivelto Silva)
   Data última Atualização:18/05/2024
   Objectivo: Controle o nível de água em 2 reservatórios no Condominio Kizomba

  Principais Componentes usados: 
 *** 1-ARDUINO MEGA 2560 (1)
 *** 2- RED LEDS (6)
 *** 3- ORANGE LEDS (4)
 *** 4- YELLOW LEDS (4)
 *** 5- GREEN LEDS (6)
 *** 6- RESISTOR 560 Ohm (20)
 *** 7- RESISTOR 10K Ohm (20)
 *** 9- WATER LEVEL SENSORS (20)
 *** 10-LCD WITH I2C (2)
 ***
*/
////////////////////// Definições /////////////////////
//#define DEBUG false
#define R1_NOME "RW1"
#define R2_NOME "RW2"
#define DEBUG false    // Se tiver tudo OK, usa-me
//#define DEBUG true   // Se tiver bug, usa-me



#define LED_ON HIGH
#define LED_OFF LOW
#define ZERO "0%"
#define VAZIO "VAZIO"
///////////////////////////////////////////////////////

////////// Definição de Pinos e Objectos /////////////
#define LED 13

#define R1_SENSOR_NIVEL1 22
#define R1_SENSOR_NIVEL2 23
#define R1_SENSOR_NIVEL3 24
#define R1_SENSOR_NIVEL4 25
#define R1_SENSOR_NIVEL5 26
#define R1_SENSOR_NIVEL6 27
#define R1_SENSOR_NIVEL7 28
#define R1_SENSOR_NIVEL8 29
#define R1_SENSOR_NIVEL9 30
#define R1_SENSOR_NIVEL10 31

#define R1_LED_VERDE1 2
#define R1_LED_VERDE2 3
#define R1_LED_AMARELO3 4
#define R1_LED_AMARELO2 5
#define R1_LED_AMARELO1 6
#define R1_LED_LARANJA2 7
#define R1_LED_LARANJA1 8
#define R1_LED_VERMELHO3 9
#define R1_LED_VERMELHO2 10
#define R1_LED_VERMELHO1 11

#define R1_BUZZER 52


#define R2_SENSOR_NIVEL1 32
#define R2_SENSOR_NIVEL2 33
#define R2_SENSOR_NIVEL3 34
#define R2_SENSOR_NIVEL4 35
#define R2_SENSOR_NIVEL5 36
#define R2_SENSOR_NIVEL6 37
#define R2_SENSOR_NIVEL7 38
#define R2_SENSOR_NIVEL8 39
#define R2_SENSOR_NIVEL9 40
#define R2_SENSOR_NIVEL10 41

#define R2_LED_VERDE1 42
#define R2_LED_VERDE2 43
#define R2_LED_AMARELO3 44
#define R2_LED_AMARELO2 45
#define R2_LED_AMARELO1 46
#define R2_LED_LARANJA2 47
#define R2_LED_LARANJA1 48
#define R2_LED_VERMELHO3 49
#define R2_LED_VERMELHO2 50
#define R2_LED_VERMELHO1 51

#define R2_BUZZER 53

//////////////////////////////////////////////////

///////////// Inclusão de Bibliotecas /////////////
#include <avr/wdt.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
//////////////////////////////////////////////////


//////////////// Declaração de Objectos ///////////
LiquidCrystal_I2C lcd1(0x27, 16, 2);  // set the LCD address to 0x27 for a 16X02
LiquidCrystal_I2C lcd2(0x23, 16, 2);  // set the LCD address to 0x26 for a 16X02
///////////////////////////////////////////////////

byte cont = 0;
bool flag = false;

unsigned long int temporizador = 0;
String leituraReservatorio1 = ZERO;  /////
String nivelReservatorio1 = VAZIO;   /////

String leituraReservatorio2 = ZERO;  /////
String nivelReservatorio2 = VAZIO;   /////

void setup() {

  // --------- DEFINIÇÃO DOS PINOS DOS SENSORES DO  RESERVATORIO 1 ---------------------
  pinMode(R1_SENSOR_NIVEL1, INPUT_PULLUP);
  pinMode(R1_SENSOR_NIVEL2, INPUT_PULLUP);
  pinMode(R1_SENSOR_NIVEL3, INPUT_PULLUP);
  pinMode(R1_SENSOR_NIVEL4, INPUT_PULLUP);
  pinMode(R1_SENSOR_NIVEL5, INPUT_PULLUP);
  pinMode(R1_SENSOR_NIVEL6, INPUT_PULLUP);
  pinMode(R1_SENSOR_NIVEL7, INPUT_PULLUP);
  pinMode(R1_SENSOR_NIVEL8, INPUT_PULLUP);
  pinMode(R1_SENSOR_NIVEL9, INPUT_PULLUP);
  pinMode(R1_SENSOR_NIVEL10, INPUT_PULLUP);

  pinMode(R1_LED_VERDE1, OUTPUT);
  pinMode(R1_LED_VERDE2, OUTPUT);
  pinMode(R1_LED_AMARELO3, OUTPUT);
  pinMode(R1_LED_AMARELO2, OUTPUT);
  pinMode(R1_LED_AMARELO1, OUTPUT);
  pinMode(R1_LED_LARANJA2, OUTPUT);
  pinMode(R1_LED_LARANJA1, OUTPUT);
  pinMode(R1_LED_VERMELHO3, OUTPUT);
  pinMode(R1_LED_VERMELHO2, OUTPUT);
  pinMode(R1_LED_VERMELHO1, OUTPUT);

  digitalWrite(R1_LED_VERDE1, LOW);
  digitalWrite(R1_LED_VERDE2, LOW);
  digitalWrite(R1_LED_AMARELO3, LOW);
  digitalWrite(R1_LED_AMARELO2, LOW);
  digitalWrite(R1_LED_AMARELO1, LOW);
  digitalWrite(R1_LED_LARANJA2, LOW);
  digitalWrite(R1_LED_LARANJA1, LOW);
  digitalWrite(R1_LED_VERMELHO3, LOW);
  digitalWrite(R1_LED_VERMELHO2, LOW);
  digitalWrite(R1_LED_VERMELHO1, LOW);

  pinMode(R1_BUZZER, OUTPUT);
  digitalWrite(R1_BUZZER, LOW);

  delay(100);

  // --------- DEFINIÇÃO DOS PINOS DOS SENSORES DO  RESERVATORIO 2 ---------------------
  pinMode(R2_SENSOR_NIVEL1, INPUT_PULLUP);
  pinMode(R2_SENSOR_NIVEL2, INPUT_PULLUP);
  pinMode(R2_SENSOR_NIVEL3, INPUT_PULLUP);
  pinMode(R2_SENSOR_NIVEL4, INPUT_PULLUP);
  pinMode(R2_SENSOR_NIVEL5, INPUT_PULLUP);
  pinMode(R2_SENSOR_NIVEL6, INPUT_PULLUP);
  pinMode(R2_SENSOR_NIVEL7, INPUT_PULLUP);
  pinMode(R2_SENSOR_NIVEL8, INPUT_PULLUP);
  pinMode(R2_SENSOR_NIVEL9, INPUT_PULLUP);
  pinMode(R2_SENSOR_NIVEL10, INPUT_PULLUP);

  pinMode(R2_LED_VERDE1, OUTPUT);
  pinMode(R2_LED_VERDE2, OUTPUT);
  pinMode(R2_LED_AMARELO3, OUTPUT);
  pinMode(R2_LED_AMARELO2, OUTPUT);
  pinMode(R2_LED_AMARELO1, OUTPUT);
  pinMode(R2_LED_LARANJA2, OUTPUT);
  pinMode(R2_LED_LARANJA1, OUTPUT);
  pinMode(R2_LED_VERMELHO3, OUTPUT);
  pinMode(R2_LED_VERMELHO2, OUTPUT);
  pinMode(R2_LED_VERMELHO1, OUTPUT);

  digitalWrite(R2_LED_VERDE1, LOW);
  digitalWrite(R2_LED_VERDE2, LOW);
  digitalWrite(R2_LED_AMARELO3, LOW);
  digitalWrite(R2_LED_AMARELO2, LOW);
  digitalWrite(R2_LED_AMARELO1, LOW);
  digitalWrite(R2_LED_LARANJA2, LOW);
  digitalWrite(R2_LED_LARANJA1, LOW);
  digitalWrite(R2_LED_VERMELHO3, LOW);
  digitalWrite(R2_LED_VERMELHO2, LOW);
  digitalWrite(R2_LED_VERMELHO1, LOW);

  pinMode(R2_BUZZER, OUTPUT);
  digitalWrite(R2_BUZZER, LOW);

  pinMode(LED, OUTPUT);
  digitalWrite(LED, LOW);

  delay(100);

  lcd1.init();       // inicializando o Dispaly
  lcd1.backlight();  // mantem a luz do LCD acesso
  lcd1.clear();
  delay(50);

  lcd2.init();       // inicializando o Dispaly
  lcd1.backlight();  // mantem a luz do LCD acesso
  delay(50);

  lcd1.clear();
  lcd1.setCursor(0, 0);
  lcd1.print("CONDOM. KIZOMBA");
  lcd1.setCursor(0, 1);
  lcd1.print("NIVEL DO TANQUE");

  lcd2.clear();
  lcd2.setCursor(0, 0);
  lcd2.print("CONDOM. KIZOMBA");
  lcd2.setCursor(0, 1);
  lcd2.print("NIVEL DO TANQUE");

  delay(1000);
  lcd1.clear();
  lcd1.setCursor(0, 0);
  lcd1.print("CONDOM. KIZOMBA");
  lcd1.setCursor(0, 1);
  lcd1.print("RESERVATORIO "+ String(R1_NOME));

  lcd2.clear();
  lcd2.setCursor(0, 0);
  lcd2.print("CONDOM. KIZOMBA");
  lcd2.setCursor(0, 1);
  lcd2.print("RESERVATORIO "+ String(R2_NOME));


  Serial.begin(9600);
  delay(1000);
  Serial2.begin(9600); // SERIAL PARA O GSM
  delay(1000);
  Serial.println("SISTEMA INICIADO COM SUCESSO!");

  wdt_enable(WDTO_8S);
}


void loop() {
  wdt_reset();
  
  if ((millis() - temporizador) > 500) {
    temporizador = millis();
    lerSensores1();
    lerSensores2();
    enviarDados();
    if(++cont==2)
    {
      cont =0;
      flag = !flag;
      imprimirDadosLCD(lcd1, ("RESERVATORIO " + String(R1_NOME)), nivelReservatorio1, leituraReservatorio1);
      imprimirDadosLCD(lcd2, ("RESERVATORIO " + String(R2_NOME)), nivelReservatorio2, leituraReservatorio2);
    }
    digitalWrite(LED, !digitalRead(LED));
  }

  delay(50);
}


//////////////////////////////////////////////////////////
void enviarDados() {
  String texto = "R*";
  texto += nivelReservatorio1 + "*" + leituraReservatorio1 + "*";
  texto += nivelReservatorio2 + "*" + leituraReservatorio2 + "*";
  Serial.println(texto);
  Serial2.println(texto);
}

///////////////////////////////////////////////////////////////////////////////////
void imprimirDadosLCD(LiquidCrystal_I2C lcd, String reservatorio, String nivel, String leitura) {

  lcd.init();
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(reservatorio);
  lcd.setCursor(0, 1);
  if (flag) {
    lcd.print("NIVEL:");
    lcd.print(nivel);
  } else {
    lcd.print("LEITURA:");
    lcd.print(leitura);
  }

}

///////////////////////////////////////////////////////////////////////////////////
void ligarAlarme1() {
  digitalWrite(R1_BUZZER, HIGH);
}

///////////////////////////////////////////////////////////////////////////////////
void desligarAlarme1() {
  digitalWrite(R1_BUZZER, LOW);
}

///////////////////////////////////////////////////////////////////////////////////
void ligarAlarme2() {
  digitalWrite(R2_BUZZER, HIGH);
}

///////////////////////////////////////////////////////////////////////////////////
void desligarAlarme2() {
  digitalWrite(R2_BUZZER, LOW);
}

///////////////////////////////////////////////////////////////////////////////////
void setNivelReservatorio1(bool nivel1, bool nivel2, bool nivel3, bool nivel4, bool nivel5, bool nivel6, bool nivel7, bool nivel8, bool nivel9, bool nivel10) {
  digitalWrite(R1_LED_VERDE1, nivel1);
  digitalWrite(R1_LED_VERDE2, nivel2);
  digitalWrite(R1_LED_AMARELO3, nivel3);
  digitalWrite(R1_LED_AMARELO2, nivel4);
  digitalWrite(R1_LED_AMARELO1, nivel5);
  digitalWrite(R1_LED_LARANJA2, nivel6);
  digitalWrite(R1_LED_LARANJA1, nivel7);
  digitalWrite(R1_LED_VERMELHO3, nivel8);
  digitalWrite(R1_LED_VERMELHO2, nivel9);
  digitalWrite(R1_LED_VERMELHO1, nivel10);
}

void setNivelReservatorio2(bool nivel1, bool nivel2, bool nivel3, bool nivel4, bool nivel5, bool nivel6, bool nivel7, bool nivel8, bool nivel9, bool nivel10) {
  digitalWrite(R2_LED_VERDE1, nivel1);
  digitalWrite(R2_LED_VERDE2, nivel2);
  digitalWrite(R2_LED_AMARELO3, nivel3);
  digitalWrite(R2_LED_AMARELO2, nivel4);
  digitalWrite(R2_LED_AMARELO1, nivel5);
  digitalWrite(R2_LED_LARANJA2, nivel6);
  digitalWrite(R2_LED_LARANJA1, nivel7);
  digitalWrite(R2_LED_VERMELHO3, nivel8);
  digitalWrite(R2_LED_VERMELHO2, nivel9);
  digitalWrite(R2_LED_VERMELHO1, nivel10);
}

///////////////////////////////////////////////////////////////////////////////////
void MedioMessage() {
  Serial2.println("AT+CMGF=1");
  delay(1000);

  Serial2.println("AT+CMGS=\"+244946128147\"\r");  //your number here
  Serial2.println("AT+CMGS=\"+244928322931\"\r");  //your number here
  delay(1000);

  Serial2.println("Tanque FW1 a 50%, Nivel ao Meio");
  delay(100);
  Serial2.println((char)26);
  delay(1000);
}

///////////////////////////////////////////////////////////////////////////////////
void CriticoMessage() {
  Serial2.println("AT+CMGF=1");
  delay(1000);

  Serial2.println("AT+CMGS=\"+244946128147\"\r");  //your number here
  Serial2.println("AT+CMGS=\"+244928322931\"\r");  //your number here
  delay(1000);

  Serial2.println("Tanque FW1 a 30%, Nivel Critico");
  delay(100);
  Serial2.println((char)26);
  delay(1000);
}

///////////////////////////////////////////////////////////////////////////////////
void SuperCriticoMessage() {
  Serial2.println("AT+CMGF=1");
  delay(1000);

  Serial2.println("AT+CMGS=\"+244946128147\"\r");  //your number here
  Serial2.println("AT+CMGS=\"+244928322931\"\r");  //your number here
  delay(1000);

  Serial2.println("Tanque FW1 a 10%, Nivel Super Critico");
  delay(100);
  Serial2.println((char)26);
  delay(1000);
}

///////////////////////////////////////////////////////////////////////////////////
void VazioMessage() {
  Serial2.println("AT+CMGF=1");
  delay(1000);

  Serial2.println("AT+CMGS=\"+244946128147\"\r");  //your number here
  Serial2.println("AT+CMGS=\"+244928322931\"\r");  //your number here
  delay(1000);

  Serial2.println("Tanque FW1 Vazio");
  delay(100);
  Serial2.println((char)26);
  delay(1000);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void lerSensores1() {
  int sensor1 = !digitalRead(R1_SENSOR_NIVEL1);
  int sensor2 = !digitalRead(R1_SENSOR_NIVEL2);
  int sensor3 = !digitalRead(R1_SENSOR_NIVEL3);
  int sensor4 = !digitalRead(R1_SENSOR_NIVEL4);
  int sensor5 = !digitalRead(R1_SENSOR_NIVEL5);
  int sensor6 = !digitalRead(R1_SENSOR_NIVEL6);
  int sensor7 = !digitalRead(R1_SENSOR_NIVEL7);
  int sensor8 = !digitalRead(R1_SENSOR_NIVEL8);
  int sensor9 = !digitalRead(R1_SENSOR_NIVEL9);
  int sensor10= !digitalRead(R1_SENSOR_NIVEL10);

  if(DEBUG)
  {
    Serial.println("===========================================");
    Serial.println(String(R1_NOME)+"_SENSOR1:"+String(sensor1));
    Serial.println(String(R1_NOME)+"_SENSOR2:"+String(sensor2));
    Serial.println(String(R1_NOME)+"_SENSOR3:"+String(sensor3));
    Serial.println(String(R1_NOME)+"_SENSOR4:"+String(sensor4));
    Serial.println(String(R1_NOME)+"_SENSOR5:"+String(sensor5));
    Serial.println(String(R1_NOME)+"_SENSOR6:"+String(sensor6));
    Serial.println(String(R1_NOME)+"_SENSOR7:"+String(sensor7));
    Serial.println(String(R1_NOME)+"_SENSOR8:"+String(sensor8));
    Serial.println(String(R1_NOME)+"_SENSOR9:"+String(sensor9));
    Serial.println(String(R1_NOME)+"_SENSOR10:"+String(sensor10));
    Serial.println("===========================================");
  }

  // Primeiro Nivel - 100% - 4,5 m^2 - todos os leds acesso
  if ((sensor1 == 1) && (sensor2 == 1) && (sensor3 == 1) && (sensor4 == 1) && (sensor5 == 1)
      && (sensor6 == 1) && (sensor7 == 1) && (sensor8 == 1) && (sensor9 == 1) && (sensor10 == 1)) {
    nivelReservatorio1 = "CHEIO";
    leituraReservatorio1 = "100%";
    setNivelReservatorio1(LED_ON, LED_ON, LED_ON, LED_ON, LED_ON, LED_ON, LED_ON, LED_ON, LED_ON, LED_ON);
    desligarAlarme1();
  }

  // Segundo Nivel - 90% - 4,05 m^2 - um led apagado
  else if ((sensor1 == 0) && (sensor2 == 1) && (sensor3 == 1) && (sensor4 == 1) && (sensor5 == 1)
           && (sensor6 == 1) && (sensor7 == 1) && (sensor8 == 1) && (sensor9 == 1) && (sensor10 == 1)) {
    nivelReservatorio1 = "QUASE CHEIO";
    leituraReservatorio1 = "90%";
    desligarAlarme1();
    setNivelReservatorio1(LED_OFF, LED_ON, LED_ON, LED_ON, LED_ON, LED_ON, LED_ON, LED_ON, LED_ON, LED_ON);
  }

  // terceiro Nivel - 80% - 3,6 m^2 - dois leds apagados
  else if ((sensor1 == 0) && (sensor2 == 0) && (sensor3 == 1) && (sensor4 == 1) && (sensor5 == 1)
           && (sensor6 == 1) && (sensor7 == 1) && (sensor8 == 1) && (sensor9 == 1) && (sensor10 == 1)) {
    nivelReservatorio1 = "MUITO ALTO";
    leituraReservatorio1 = "80%";
    desligarAlarme1();
    setNivelReservatorio1(LED_OFF, LED_OFF, LED_ON, LED_ON, LED_ON, LED_ON, LED_ON, LED_ON, LED_ON, LED_ON);
  }

  // Quarto Nivel - 70% - 3,15 m^2 - três leds apagados
  else if ((sensor1 == 0) && (sensor2 == 0) && (sensor3 == 0) && (sensor4 == 1) && (sensor5 == 1)
           && (sensor6 == 1) && (sensor7 == 1) && (sensor8 == 1) && (sensor9 == 1) && (sensor10 == 1)) {
    nivelReservatorio1 = "ALTO";
    leituraReservatorio1 = "70%";
    desligarAlarme1();
    setNivelReservatorio1(LED_OFF, LED_OFF, LED_OFF, LED_ON, LED_ON, LED_ON, LED_ON, LED_ON, LED_ON, LED_ON);
  }

  // Quinto Nivel - 60% - 2,7 m^2 - quatro leds apagados
  else if ((sensor1 == 0) && (sensor2 == 0) && (sensor3 == 0) && (sensor4 == 0) && (sensor5 == 1)
           && (sensor6 == 1) && (sensor7 == 1) && (sensor8 == 1) && (sensor9 == 1) && (sensor10 == 1)) {
    nivelReservatorio1 = "MEDIO ALTO";
    leituraReservatorio1 = "60%";
    desligarAlarme1();
    setNivelReservatorio1(LED_OFF, LED_OFF, LED_OFF, LED_OFF, LED_ON, LED_ON, LED_ON, LED_ON, LED_ON, LED_ON);
  }

  // sexto Nivel - 50% - 2,25 m^2 - cinco leds apagados
  else if ((sensor1 == 0) && (sensor2 == 0) && (sensor3 == 0) && (sensor4 == 0) && (sensor5 == 0)
           && (sensor6 == 1) && (sensor7 == 1) && (sensor8 == 1) && (sensor9 == 1) && (sensor10 == 1)) {
    nivelReservatorio1 = "MEDIO";
    leituraReservatorio1 = "50%";
    desligarAlarme1();
    setNivelReservatorio1(LED_OFF, LED_OFF, LED_OFF, LED_OFF, LED_OFF, LED_ON, LED_ON, LED_ON, LED_ON, LED_ON);
  }

  // setimo Nivel - 40% - 1,8 m^2 - seis leds apagados
  else if ((sensor1 == 0) && (sensor2 == 0) && (sensor3 == 0) && (sensor4 == 0) && (sensor5 == 0)
           && (sensor6 == 0) && (sensor7 == 1) && (sensor8 == 1) && (sensor9 == 1) && (sensor10 == 1)) {
    nivelReservatorio1 = "MEDIO BAIXO";
    leituraReservatorio1 = "40%";
    MedioMessage();
    desligarAlarme1();
    setNivelReservatorio1(LED_OFF, LED_OFF, LED_OFF, LED_OFF, LED_OFF, LED_OFF, LED_ON, LED_ON, LED_ON, LED_ON);
  }

  // Oitavo Nivel - 30% - 1,35 m^2 - sete leds apagados
  else if ((sensor1 == 0) && (sensor2 == 0) && (sensor3 == 0) && (sensor4 == 0) && (sensor5 == 0)
           && (sensor6 == 0) && (sensor7 == 0) && (sensor8 == 1) && (sensor9 == 1) && (sensor10 == 1)) {
    nivelReservatorio1 = "BAIXO";
    leituraReservatorio1 = "30%";
    CriticoMessage();
    desligarAlarme1();
    setNivelReservatorio1(LED_OFF, LED_OFF, LED_OFF, LED_OFF, LED_OFF, LED_OFF, LED_OFF, LED_ON, LED_ON, LED_ON);
  }

  // Nono Nivel - 20% - 0,9 m^2 - oito leds apagados
  else if ((sensor1 == 0) && (sensor2 == 0) && (sensor3 == 0) && (sensor4 == 0) && (sensor5 == 0)
           && (sensor6 == 0) && (sensor7 == 0) && (sensor8 == 0) && (sensor9 == 1) && (sensor10 == 1)) {
    nivelReservatorio1 = "QUASE VAZIO";
    leituraReservatorio1 = "20%";
    ligarAlarme1();
    setNivelReservatorio1(LED_OFF, LED_OFF, LED_OFF, LED_OFF, LED_OFF, LED_OFF, LED_OFF, LED_OFF, LED_ON, LED_ON);
  }

  // Decimo Nivel - 10% - 0,45 m^2 - nove leds apagados
  else if ((sensor1 == 0) && (sensor2 == 0) && (sensor3 == 0) && (sensor4 == 0) && (sensor5 == 0)
           && (sensor6 == 0) && (sensor7 == 0) && (sensor8 == 0) && (sensor9 == 0) && (sensor10 == 1)) {
    nivelReservatorio1 = "CRITICO";
    leituraReservatorio1 = "10%";
    SuperCriticoMessage();
    ligarAlarme1();
    setNivelReservatorio1(LED_OFF, LED_OFF, LED_OFF, LED_OFF, LED_OFF, LED_OFF, LED_OFF, LED_OFF, LED_OFF, LED_ON);
  }

  // Decimo Nivel - 10% - 0,45 m^2 - nove leds apagados
  else if ((sensor1 == 0) && (sensor2 == 0) && (sensor3 == 0) && (sensor4 == 0) && (sensor5 == 0)
           && (sensor6 == 0) && (sensor7 == 0) && (sensor8 == 0) && (sensor9 == 0) && (sensor10 == 0)) {
    nivelReservatorio1 = "VAZIO";
    leituraReservatorio1 = "0%";
    VazioMessage();
    ligarAlarme1();
    setNivelReservatorio1(LED_OFF, LED_OFF, LED_OFF, LED_OFF, LED_OFF, LED_OFF, LED_OFF, LED_OFF, LED_OFF, LED_OFF);
  }
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void lerSensores2() {
  int sensor1 = !digitalRead(R2_SENSOR_NIVEL1);
  int sensor2 = !digitalRead(R2_SENSOR_NIVEL2);
  int sensor3 = !digitalRead(R2_SENSOR_NIVEL3);
  int sensor4 = !digitalRead(R2_SENSOR_NIVEL4);
  int sensor5 = !digitalRead(R2_SENSOR_NIVEL5);
  int sensor6 = !digitalRead(R2_SENSOR_NIVEL6);
  int sensor7 = !digitalRead(R2_SENSOR_NIVEL7);
  int sensor8 = !digitalRead(R2_SENSOR_NIVEL8);
  int sensor9 = !digitalRead(R2_SENSOR_NIVEL9);
  int sensor10= !digitalRead(R2_SENSOR_NIVEL10);

  if(DEBUG)
  {
    Serial.println("===========================================");
    Serial.println(String(R2_NOME)+"_SENSOR1:"+String(sensor1));
    Serial.println(String(R2_NOME)+"_SENSOR2:"+String(sensor2));
    Serial.println(String(R2_NOME)+"_SENSOR3:"+String(sensor3));
    Serial.println(String(R2_NOME)+"_SENSOR4:"+String(sensor4));
    Serial.println(String(R2_NOME)+"_SENSOR5:"+String(sensor5));
    Serial.println(String(R2_NOME)+"_SENSOR6:"+String(sensor6));
    Serial.println(String(R2_NOME)+"_SENSOR7:"+String(sensor7));
    Serial.println(String(R2_NOME)+"_SENSOR8:"+String(sensor8));
    Serial.println(String(R2_NOME)+"_SENSOR9:"+String(sensor9));
    Serial.println(String(R2_NOME)+"_SENSOR10:"+String(sensor10));
    Serial.println("===========================================");
  }

  // Primeiro Nivel - 100% - 4,5 m^2 - todos os leds acesso
  if ((sensor1 == 1) && (sensor2 == 1) && (sensor3 == 1) && (sensor4 == 1) && (sensor5 == 1)
      && (sensor6 == 1) && (sensor7 == 1) && (sensor8 == 1) && (sensor9 == 1) && (sensor10 == 1)) {
    nivelReservatorio2 = "CHEIO";
    leituraReservatorio2 = "100%";
    setNivelReservatorio2(LED_ON, LED_ON, LED_ON, LED_ON, LED_ON, LED_ON, LED_ON, LED_ON, LED_ON, LED_ON);
    desligarAlarme2();
  }

  // Segundo Nivel - 90% - 4,05 m^2 - um led apagado
  else if ((sensor1 == 0) && (sensor2 == 1) && (sensor3 == 1) && (sensor4 == 1) && (sensor5 == 1)
           && (sensor6 == 1) && (sensor7 == 1) && (sensor8 == 1) && (sensor9 == 1) && (sensor10 == 1)) {
    nivelReservatorio2 = "QUASE CHEIO";
    leituraReservatorio2 = "90%";
    desligarAlarme2();
    setNivelReservatorio2(LED_OFF, LED_ON, LED_ON, LED_ON, LED_ON, LED_ON, LED_ON, LED_ON, LED_ON, LED_ON);
  }

  // terceiro Nivel - 80% - 3,6 m^2 - dois leds apagados
  else if ((sensor1 == 0) && (sensor2 == 0) && (sensor3 == 1) && (sensor4 == 1) && (sensor5 == 1)
           && (sensor6 == 1) && (sensor7 == 1) && (sensor8 == 1) && (sensor9 == 1) && (sensor10 == 1)) {
    nivelReservatorio2 = "MUITO ALTO";
    leituraReservatorio2 = "80%";
    desligarAlarme2();
    setNivelReservatorio2(LED_OFF, LED_OFF, LED_ON, LED_ON, LED_ON, LED_ON, LED_ON, LED_ON, LED_ON, LED_ON);
  }

  // Quarto Nivel - 70% - 3,15 m^2 - três leds apagados
  else if ((sensor1 == 0) && (sensor2 == 0) && (sensor3 == 0) && (sensor4 == 1) && (sensor5 == 1)
           && (sensor6 == 1) && (sensor7 == 1) && (sensor8 == 1) && (sensor9 == 1) && (sensor10 == 1)) {
    nivelReservatorio2 = "ALTO";
    leituraReservatorio2 = "70%";
    desligarAlarme2();
    setNivelReservatorio2(LED_OFF, LED_OFF, LED_OFF, LED_ON, LED_ON, LED_ON, LED_ON, LED_ON, LED_ON, LED_ON);
  }

  // Quinto Nivel - 60% - 2,7 m^2 - quatro leds apagados
  else if ((sensor1 == 0) && (sensor2 == 0) && (sensor3 == 0) && (sensor4 == 0) && (sensor5 == 1)
           && (sensor6 == 1) && (sensor7 == 1) && (sensor8 == 1) && (sensor9 == 1) && (sensor10 == 1)) {
    nivelReservatorio2 = "MEDIO ALTO";
    leituraReservatorio2 = "60%";
    desligarAlarme2();
    setNivelReservatorio2(LED_OFF, LED_OFF, LED_OFF, LED_OFF, LED_ON, LED_ON, LED_ON, LED_ON, LED_ON, LED_ON);
  }

  // sexto Nivel - 50% - 2,25 m^2 - cinco leds apagados
  else if ((sensor1 == 0) && (sensor2 == 0) && (sensor3 == 0) && (sensor4 == 0) && (sensor5 == 0)
           && (sensor6 == 1) && (sensor7 == 1) && (sensor8 == 1) && (sensor9 == 1) && (sensor10 == 1)) {
    nivelReservatorio2 = "MEDIO";
    leituraReservatorio2 = "50%";
    desligarAlarme2();
    setNivelReservatorio2(LED_OFF, LED_OFF, LED_OFF, LED_OFF, LED_OFF, LED_ON, LED_ON, LED_ON, LED_ON, LED_ON);
  }

  // setimo Nivel - 40% - 1,8 m^2 - seis leds apagados
  else if ((sensor1 == 0) && (sensor2 == 0) && (sensor3 == 0) && (sensor4 == 0) && (sensor5 == 0)
           && (sensor6 == 0) && (sensor7 == 1) && (sensor8 == 1) && (sensor9 == 1) && (sensor10 == 1)) {
    nivelReservatorio2 = "MEDIO BAIXO";
    leituraReservatorio2 = "40%";
    // MedioMessage();
    desligarAlarme2();
    setNivelReservatorio2(LED_OFF, LED_OFF, LED_OFF, LED_OFF, LED_OFF, LED_OFF, LED_ON, LED_ON, LED_ON, LED_ON);
  }

  // Oitavo Nivel - 30% - 1,35 m^2 - sete leds apagados
  else if ((sensor1 == 0) && (sensor2 == 0) && (sensor3 == 0) && (sensor4 == 0) && (sensor5 == 0)
           && (sensor6 == 0) && (sensor7 == 0) && (sensor8 == 1) && (sensor9 == 1) && (sensor10 == 1)) {
    nivelReservatorio2 = "BAIXO";
    leituraReservatorio2 = "30%";
    // CriticoMessage();
    desligarAlarme2();
    setNivelReservatorio2(LED_OFF, LED_OFF, LED_OFF, LED_OFF, LED_OFF, LED_OFF, LED_OFF, LED_ON, LED_ON, LED_ON);
  }

  // Nono Nivel - 20% - 0,9 m^2 - oito leds apagados
  else if ((sensor1 == 0) && (sensor2 == 0) && (sensor3 == 0) && (sensor4 == 0) && (sensor5 == 0)
           && (sensor6 == 0) && (sensor7 == 0) && (sensor8 == 0) && (sensor9 == 1) && (sensor10 == 1)) {
    nivelReservatorio2 = "QUASE VAZIO";
    leituraReservatorio2 = "20%";
    ligarAlarme2();
    setNivelReservatorio2(LED_OFF, LED_OFF, LED_OFF, LED_OFF, LED_OFF, LED_OFF, LED_OFF, LED_OFF, LED_ON, LED_ON);
  }

  // Decimo Nivel - 10% - 0,45 m^2 - nove leds apagados
  else if ((sensor1 == 0) && (sensor2 == 0) && (sensor3 == 0) && (sensor4 == 0) && (sensor5 == 0)
           && (sensor6 == 0) && (sensor7 == 0) && (sensor8 == 0) && (sensor9 == 0) && (sensor10 == 1)) {
    nivelReservatorio2 = "CRITICO";
    leituraReservatorio2 = "10%";
    // SuperCriticoMessage();
    ligarAlarme2();
    setNivelReservatorio2(LED_OFF, LED_OFF, LED_OFF, LED_OFF, LED_OFF, LED_OFF, LED_OFF, LED_OFF, LED_OFF, LED_ON);
  }

  // Decimo Nivel - 10% - 0,45 m^2 - nove leds apagados
  else if ((sensor1 == 0) && (sensor2 == 0) && (sensor3 == 0) && (sensor4 == 0) && (sensor5 == 0)
           && (sensor6 == 0) && (sensor7 == 0) && (sensor8 == 0) && (sensor9 == 0) && (sensor10 == 0)) {
    Serial.println("Nivel 0%");
    nivelReservatorio2 = "VAZIO";
    leituraReservatorio2 = "0%";
    // VazioMessage();
    ligarAlarme2();
    setNivelReservatorio2(LED_OFF, LED_OFF, LED_OFF, LED_OFF, LED_OFF, LED_OFF, LED_OFF, LED_OFF, LED_OFF, LED_OFF);
  }
}