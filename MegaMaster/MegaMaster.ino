/*
   Autor:Erivelto Clénio da Costa e Silva
   Data última Atualização:18/05/2024
   Objectivo: Controle o nível de água em 2 reservatórios no Condominio Kizomba

  Principais Componentes usados:
 *** 1-ARDUINO MEGA 2560 (1)
 *** 2- RED LEDS (3)
 *** 3- ORANGE LEDS (2)
 *** 4- YELLOW LEDS (2)
 *** 5- GREEN LEDS (3)
 *** 6- RESISTOR 560 Ohm (10)
 *** 7- RESISTOR 10K Ohm (10)
 *** 9- WATER LEVEL SENSORS (10)
 *** 10-LCD WITH I2C (1)
 ***
*/
////////////////////// Definições /////////////////////
//#define DEBUG false
#define DEBUG true

#define LED_ON HIGH
#define LED_OFF LOW

#define ZERO "0%"
#define VAZIO "VAZIO"
///////////////////////////////////////////////////////

////////// Definição de Pinos e Objectos /////////////
#define LED 13

#define SENSOR1_NIVEL1 22
#define SENSOR1_NIVEL2 23
#define SENSOR1_NIVEL3 24
#define SENSOR1_NIVEL4 25
#define SENSOR1_NIVEL5 26
#define SENSOR1_NIVEL6 27
#define SENSOR1_NIVEL7 28
#define SENSOR1_NIVEL8 29
#define SENSOR1_NIVEL9 30
#define SENSOR1_NIVEL10 31

#define BUZZER 32

#define LED_VERDE1 2
#define LED_VERDE2 3

#define LED_AMARELO3 4
#define LED_AMARELO2 5
#define LED_AMARELO1 6

#define LED_LARANJA2 7
#define LED_LARANJA1 8

#define LED_VERMELHO3 9
#define LED_VERMELHO2 10
#define LED_VERMELHO1 11
//////////////////////////////////////////////////

///////////// Inclusão de Bibliotecas /////////////
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
//////////////////////////////////////////////////


//////////////// Declaração de Objectos ///////////
LiquidCrystal_I2C lcd1(0x23, 16, 2);  // set the LCD address to 0x26 for a 16X02
LiquidCrystal_I2C lcd2(0x27, 16, 2);  // set the LCD address to 0x27 for a 16X02
///////////////////////////////////////////////////

byte cont = 0;
bool flag = false;

bool flagEnvioMedio=false;
bool flagEnvioCritico=false;
bool flagEnvioSuperCritico=false;
bool flagEnvioVazio=false;


unsigned long int temporizador = 0;
String leituraReservatorio1 = ZERO;  /////
String nivelReservatorio1 = VAZIO;   /////

String leituraReservatorio2 = ZERO;  /////
String nivelReservatorio2 = VAZIO;   /////

const String PHONE_NUMBER1 = "+244940811141";
// const String PHONE_NUMBER2 = "+244940811141";

void setup() {
  pinMode(SENSOR1_NIVEL1, INPUT_PULLUP);
  pinMode(SENSOR1_NIVEL2, INPUT_PULLUP);
  pinMode(SENSOR1_NIVEL3, INPUT_PULLUP);
  pinMode(SENSOR1_NIVEL4, INPUT_PULLUP);
  pinMode(SENSOR1_NIVEL5, INPUT_PULLUP);
  pinMode(SENSOR1_NIVEL6, INPUT_PULLUP);
  pinMode(SENSOR1_NIVEL7, INPUT_PULLUP);
  pinMode(SENSOR1_NIVEL8, INPUT_PULLUP);
  pinMode(SENSOR1_NIVEL9, INPUT_PULLUP);
  pinMode(SENSOR1_NIVEL10, INPUT_PULLUP);

  pinMode(BUZZER, OUTPUT);

  pinMode(LED_VERDE1, OUTPUT);
  pinMode(LED_VERDE2, OUTPUT);
  digitalWrite(LED_VERDE1, LOW);
  digitalWrite(LED_VERDE2, LOW);

  pinMode(LED_AMARELO3, OUTPUT);
  pinMode(LED_AMARELO2, OUTPUT);
  pinMode(LED_AMARELO1, OUTPUT);
  digitalWrite(LED_AMARELO3, LOW);
  digitalWrite(LED_AMARELO2, LOW);
  digitalWrite(LED_AMARELO1, LOW);

  pinMode(LED_LARANJA2, OUTPUT);
  pinMode(LED_LARANJA1, OUTPUT);
  digitalWrite(LED_LARANJA2, LOW);
  digitalWrite(LED_LARANJA1, LOW);

  pinMode(LED_VERMELHO3, OUTPUT);
  pinMode(LED_VERMELHO2, OUTPUT);
  pinMode(LED_VERMELHO1, OUTPUT);
  digitalWrite(LED_VERMELHO3, LOW);
  digitalWrite(LED_VERMELHO2, LOW);
  digitalWrite(LED_VERMELHO1, LOW);

  pinMode(LED, OUTPUT);
  digitalWrite(LED, LOW);

  delay(100);

  lcd1.init();       // inicializando o Dispaly
  lcd1.backlight();  // mantem a luz do LCD acesso
  lcd1.clear();
  delay(50);

  lcd2.init();       // inicializando o Dispaly
  lcd2.backlight();  // mantem a luz do LCD acesso
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
  lcd1.print("RESERVATORIO RW1");

  lcd2.clear();
  lcd2.setCursor(0, 0);
  lcd2.print("CONDOM. KIZOMBA");
  lcd2.setCursor(0, 1);
  lcd2.print("RESERVATORIO RW2");


  Serial.begin(9600);
  delay(1000);
  Serial2.begin(9600);
  delay(1000);
  sendSMS(PHONE_NUMBER1, "## CONTROLE DE TANQUES FW1 & FW2 ON ##");
  Serial.println("SISTEMA INICIADO COM SUCESSO!");
}


void loop() {
  if ((millis() - temporizador) > 500) {
    temporizador = millis();
    lerSensores();
    enviarDados();
    if(++cont==2)
    {
      cont =0;
      flag = !flag;
      imprimirDadosLCD(lcd1, "RESERVATORIO RW1", nivelReservatorio1, leituraReservatorio1);
      imprimirDadosLCD(lcd2, "RESERVATORIO RW2", nivelReservatorio2, leituraReservatorio2);
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
void ligarlarme() {
  digitalWrite(BUZZER, HIGH);
}

///////////////////////////////////////////////////////////////////////////////////
void desligarAlarme() {
  digitalWrite(BUZZER, LOW);
}

///////////////////////////////////////////////////////////////////////////////////
void setNivel1(bool nivel1, bool nivel2, bool nivel3, bool nivel4, bool nivel5, bool nivel6, bool nivel7, bool nivel8, bool nivel9, bool nivel10) {
  digitalWrite(LED_VERDE1, nivel1);
  digitalWrite(LED_VERDE2, nivel2);
  digitalWrite(LED_AMARELO3, nivel3);
  digitalWrite(LED_AMARELO2, nivel4);
  digitalWrite(LED_AMARELO1, nivel5);
  digitalWrite(LED_LARANJA2, nivel6);
  digitalWrite(LED_LARANJA1, nivel7);
  digitalWrite(LED_VERMELHO3, nivel8);
  digitalWrite(LED_VERMELHO2, nivel9);
  digitalWrite(LED_VERMELHO1, nivel10);
}

/////////////////////////////////////////////////////////
void sendSMS(const String number, String sms)
{
  Serial.print("SMS: "); Serial.println(sms);
  Serial2.println("AT+CMGF=1");
  delay(1000);  comunication();
  Serial2.println("AT+CMGS=\"" + number + "\"\r");
  delay(1000);  comunication();
  Serial2.println(sms);
  delay(100);
  Serial2.println((char)26);
  delay(1000);  comunication();
  delay(4000);
  Serial.println("\n################ SMS SENT! #################");
}

/////////////////////////////////////////////////////////
void comunication()
{
  if (Serial.available())
    while (Serial.available())
      Serial2.write(Serial.read());

  if (Serial2.available())
    while (Serial2.available())
      Serial.write(Serial2.read());
}

///////////////////////////////////////////////////////////////////////////////////
// void MedioMessage() {
//   Serial2.println("AT+CMGF=1");
//   delay(1000);

//   Serial2.println("AT+CMGS=\"+244946128147\"\r");  //your number here
//   Serial2.println("AT+CMGS=\"+244928322931\"\r");  //your number here
//   delay(1000);

//   Serial2.println("Tanque FW1 a 50%, Nivel ao Meio");
//   delay(100);
//   Serial2.println((char)26);
//   delay(1000);
// }

///////////////////////////////////////////////////////////////////////////////////
// void CriticoMessage() {
//   Serial2.println("AT+CMGF=1");
//   delay(1000);

//   Serial2.println("AT+CMGS=\"+244946128147\"\r");  //your number here
//   Serial2.println("AT+CMGS=\"+244928322931\"\r");  //your number here
//   delay(1000);

//   Serial2.println("Tanque FW1 a 30%, Nivel Critico");
//   delay(100);
//   Serial2.println((char)26);
//   delay(1000);
// }

///////////////////////////////////////////////////////////////////////////////////
// void SuperCriticoMessage() {
//   Serial2.println("AT+CMGF=1");
//   delay(1000);

//   Serial2.println("AT+CMGS=\"+244946128147\"\r");  //your number here
//   Serial2.println("AT+CMGS=\"+244928322931\"\r");  //your number here
//   delay(1000);

//   Serial2.println("Tanque FW1 a 10%, Nivel Super Critico");
//   delay(100);
//   Serial2.println((char)26);
//   delay(1000);
// }

///////////////////////////////////////////////////////////////////////////////////
// void VazioMessage() {
//   Serial2.println("AT+CMGF=1");
//   delay(1000);

//   Serial2.println("AT+CMGS=\"+244946128147\"\r");  //your number here
//   Serial2.println("AT+CMGS=\"+244928322931\"\r");  //your number here
//   delay(1000);

//   Serial2.println("Tanque FW1 Vazio");
//   delay(100);
//   Serial2.println((char)26);
//   delay(1000);
// }

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void lerSensores() {
  int sensor1 = !digitalRead(SENSOR1_NIVEL1);
  int sensor2 = !digitalRead(SENSOR1_NIVEL2);
  int sensor3 = !digitalRead(SENSOR1_NIVEL3);
  int sensor4 = !digitalRead(SENSOR1_NIVEL4);
  int sensor5 = !digitalRead(SENSOR1_NIVEL5);
  int sensor6 = !digitalRead(SENSOR1_NIVEL6);
  int sensor7 = !digitalRead(SENSOR1_NIVEL7);
  int sensor8 = !digitalRead(SENSOR1_NIVEL8);
  int sensor9 = !digitalRead(SENSOR1_NIVEL9);
  int sensor10= !digitalRead(SENSOR1_NIVEL10);

  if(DEBUG)
  {
    Serial.println("===========================================");
    Serial.println("SENSOR10:"+String(sensor1));
    Serial.println("SENSOR9:"+String(sensor2));
    Serial.println("SENSOR8:"+String(sensor3));
    Serial.println("SENSOR7:"+String(sensor4));
    Serial.println("SENSOR6:"+String(sensor5));
    Serial.println("SENSOR5:"+String(sensor6));
    Serial.println("SENSOR4:"+String(sensor7));
    Serial.println("SENSOR3:"+String(sensor8));
    Serial.println("SENSOR2:"+String(sensor9));
    Serial.println("SENSOR1:"+String(sensor10));
    Serial.println("===========================================");
  }

  // Primeiro Nivel - 100% - 4,5 m^2 - todos os leds acesso
  if ((sensor1 == 1) && (sensor2 == 1) && (sensor3 == 1) && (sensor4 == 1) && (sensor5 == 1)
      && (sensor6 == 1) && (sensor7 == 1) && (sensor8 == 1) && (sensor9 == 1) && (sensor10 == 1)) {
    Serial.println("Reservatorio Cheio");
    nivelReservatorio1 = "CHEIO";
    leituraReservatorio1 = "100%";
    
    setNivel1(LED_ON, LED_ON, LED_ON, LED_ON, LED_ON, LED_ON, LED_ON, LED_ON, LED_ON, LED_ON);
    desligarAlarme();
  }

  // Segundo Nivel - 90% - 4,05 m^2 - um led apagado
  else if ((sensor1 == 0) && (sensor2 == 1) && (sensor3 == 1) && (sensor4 == 1) && (sensor5 == 1)
           && (sensor6 == 1) && (sensor7 == 1) && (sensor8 == 1) && (sensor9 == 1) && (sensor10 == 1)) {
    Serial.println("Nivel 100 a 90%");
    nivelReservatorio1 = "QUASE CHEIO";
    leituraReservatorio1 = "90%";
    desligarAlarme();
    setNivel1(LED_OFF, LED_ON, LED_ON, LED_ON, LED_ON, LED_ON, LED_ON, LED_ON, LED_ON, LED_ON);
  }

  // terceiro Nivel - 80% - 3,6 m^2 - dois leds apagados
  else if ((sensor1 == 0) && (sensor2 == 0) && (sensor3 == 1) && (sensor4 == 1) && (sensor5 == 1)
           && (sensor6 == 1) && (sensor7 == 1) && (sensor8 == 1) && (sensor9 == 1) && (sensor10 == 1)) {
    Serial.println("Nivel 90 a 80%");
    nivelReservatorio1 = "MUITO ALTO";
    leituraReservatorio1 = "80%";
    desligarAlarme();
    setNivel1(LED_OFF, LED_OFF, LED_ON, LED_ON, LED_ON, LED_ON, LED_ON, LED_ON, LED_ON, LED_ON);
  }

  // Quarto Nivel - 70% - 3,15 m^2 - três leds apagados
  else if ((sensor1 == 0) && (sensor2 == 0) && (sensor3 == 0) && (sensor4 == 1) && (sensor5 == 1)
           && (sensor6 == 1) && (sensor7 == 1) && (sensor8 == 1) && (sensor9 == 1) && (sensor10 == 1)) {
    Serial.println("Nivel 80 a 70%");
    nivelReservatorio1 = "ALTO";
    leituraReservatorio1 = "70%";
    desligarAlarme();
    setNivel1(LED_OFF, LED_OFF, LED_OFF, LED_ON, LED_ON, LED_ON, LED_ON, LED_ON, LED_ON, LED_ON);
    flagEnvioMedio=false;
    flagEnvioCritico=false;
    flagEnvioSuperCritico=false;
    flagEnvioVazio=false;
  }

  // Quinto Nivel - 60% - 2,7 m^2 - quatro leds apagados
  else if ((sensor1 == 0) && (sensor2 == 0) && (sensor3 == 0) && (sensor4 == 0) && (sensor5 == 1)
           && (sensor6 == 1) && (sensor7 == 1) && (sensor8 == 1) && (sensor9 == 1) && (sensor10 == 1)) {
    Serial.println("Nivel 70 a 60%");
    nivelReservatorio1 = "MEDIO ALTO";
    leituraReservatorio1 = "60%";
    desligarAlarme();
    setNivel1(LED_OFF, LED_OFF, LED_OFF, LED_OFF, LED_ON, LED_ON, LED_ON, LED_ON, LED_ON, LED_ON);
  }

  // sexto Nivel - 50% - 2,25 m^2 - cinco leds apagados
  else if ((sensor1 == 0) && (sensor2 == 0) && (sensor3 == 0) && (sensor4 == 0) && (sensor5 == 0)
           && (sensor6 == 1) && (sensor7 == 1) && (sensor8 == 1) && (sensor9 == 1) && (sensor10 == 1)) {
    Serial.println("Nivel 60 a 50%");
    nivelReservatorio1 = "MEDIO";
    leituraReservatorio1 = "50%";
    desligarAlarme();
    // MedioMessage();
    if(!flagEnvioMedio)
    {
      flagEnvioMedio=true;
      sendSMS(PHONE_NUMBER1, "TANQUE FW1 A 50%, NIVEL MEDIO");
    }
    setNivel1(LED_OFF, LED_OFF, LED_OFF, LED_OFF, LED_OFF, LED_ON, LED_ON, LED_ON, LED_ON, LED_ON);
  }

  // setimo Nivel - 40% - 1,8 m^2 - seis leds apagados
  else if ((sensor1 == 0) && (sensor2 == 0) && (sensor3 == 0) && (sensor4 == 0) && (sensor5 == 0)
           && (sensor6 == 0) && (sensor7 == 1) && (sensor8 == 1) && (sensor9 == 1) && (sensor10 == 1)) {
    Serial.println("Nivel 50 a 40%");
    nivelReservatorio1 = "MEDIO BAIXO";
    leituraReservatorio1 = "40%";
    desligarAlarme();
    setNivel1(LED_OFF, LED_OFF, LED_OFF, LED_OFF, LED_OFF, LED_OFF, LED_ON, LED_ON, LED_ON, LED_ON);
  }

  // Oitavo Nivel - 30% - 1,35 m^2 - sete leds apagados
  else if ((sensor1 == 0) && (sensor2 == 0) && (sensor3 == 0) && (sensor4 == 0) && (sensor5 == 0)
           && (sensor6 == 0) && (sensor7 == 0) && (sensor8 == 1) && (sensor9 == 1) && (sensor10 == 1)) {
    Serial.println("Nivel 40 a 30%");
    nivelReservatorio1 = "BAIXO";
    leituraReservatorio1 = "30%";
    // CriticoMessage();
    desligarAlarme();
    if(!flagEnvioCritico)
    {
      flagEnvioCritico=true;
      sendSMS(PHONE_NUMBER1, "TANQUE FW1 A 30%, NIVEL CRITICO");
    }
    setNivel1(LED_OFF, LED_OFF, LED_OFF, LED_OFF, LED_OFF, LED_OFF, LED_OFF, LED_ON, LED_ON, LED_ON);
  }

  // Nono Nivel - 20% - 0,9 m^2 - oito leds apagados
  else if ((sensor1 == 0) && (sensor2 == 0) && (sensor3 == 0) && (sensor4 == 0) && (sensor5 == 0)
           && (sensor6 == 0) && (sensor7 == 0) && (sensor8 == 0) && (sensor9 == 1) && (sensor10 == 1)) {
    Serial.println("Nivel 30 a 20%");
    nivelReservatorio1 = "QUASE VAZIO";
    leituraReservatorio1 = "20%";
    ligarlarme();
    setNivel1(LED_OFF, LED_OFF, LED_OFF, LED_OFF, LED_OFF, LED_OFF, LED_OFF, LED_OFF, LED_ON, LED_ON);
  }

  // Decimo Nivel - 10% - 0,45 m^2 - nove leds apagados
  else if ((sensor1 == 0) && (sensor2 == 0) && (sensor3 == 0) && (sensor4 == 0) && (sensor5 == 0)
           && (sensor6 == 0) && (sensor7 == 0) && (sensor8 == 0) && (sensor9 == 0) && (sensor10 == 1)) {
    Serial.println("Nivel 20 a 10%");
    nivelReservatorio1 = "CRITICO";
    leituraReservatorio1 = "10%";
    // SuperCriticoMessage();
    ligarlarme();
    if(!flagEnvioSuperCritico)
    {
      flagEnvioSuperCritico=true;
      sendSMS(PHONE_NUMBER1, "TANQUE FW1 A 10%, NIVEL SUPER CRITICO");
    }
    setNivel1(LED_OFF, LED_OFF, LED_OFF, LED_OFF, LED_OFF, LED_OFF, LED_OFF, LED_OFF, LED_OFF, LED_ON);
  }

  // Decimo Nivel - 10% - 0,45 m^2 - nove leds apagados
  else if ((sensor1 == 0) && (sensor2 == 0) && (sensor3 == 0) && (sensor4 == 0) && (sensor5 == 0)
           && (sensor6 == 0) && (sensor7 == 0) && (sensor8 == 0) && (sensor9 == 0) && (sensor10 == 0)) {
    Serial.println("Nivel 0%");
    nivelReservatorio1 = "VAZIO";
    leituraReservatorio1 = "0%";
    // VazioMessage();
    ligarlarme();
    if(!flagEnvioVazio)
    {
      flagEnvioVazio=true;
      sendSMS(PHONE_NUMBER1, "TANQUE FW1 A 0%, NIVEL VAZIO");
    }
    setNivel1(LED_OFF, LED_OFF, LED_OFF, LED_OFF, LED_OFF, LED_OFF, LED_OFF, LED_OFF, LED_OFF, LED_OFF);
  }
}
