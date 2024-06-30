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
 // Enviar Mensagem quando: 0, 10, 30, 40, 
*/
////////////////////// Definições /////////////////////
//#define DEBUG false
#define NOME "RW"
#define R1_NOME "RW1"
#define R2_NOME "RW2"
#define DEBUG false    // Se tiver tudo OK, usa-me
//#define DEBUG true   // Se tiver bug, usa-me



#define LED_ON HIGH
#define LED_OFF LOW
#define ZERO "0%"
#define VAZIO "VAZIO"
#define STATUS_VAZIO "0"
#define TEMPO_ALARME 30000
///////////////////////////////////////////////////////

////////// Definição de Pinos e Objectos /////////////
#define LED 13

#define R1_SENSOR_NIVEL10 22
#define R1_SENSOR_NIVEL9 23
#define R1_SENSOR_NIVEL8 24
#define R1_SENSOR_NIVEL7 25
#define R1_SENSOR_NIVEL6 26
#define R1_SENSOR_NIVEL5 27
#define R1_SENSOR_NIVEL4 28
#define R1_SENSOR_NIVEL3 29
#define R1_SENSOR_NIVEL2 30
#define R1_SENSOR_NIVEL1 31


#define R1_BUZZER 52


#define R2_SENSOR_NIVEL10 32
#define R2_SENSOR_NIVEL9 33
#define R2_SENSOR_NIVEL8 34
#define R2_SENSOR_NIVEL7 35
#define R2_SENSOR_NIVEL6 36
#define R2_SENSOR_NIVEL5 37
#define R2_SENSOR_NIVEL4 38
#define R2_SENSOR_NIVEL3 39
#define R2_SENSOR_NIVEL2 40
#define R2_SENSOR_NIVEL1 41

#define R2_BUZZER 53

//////////////////////////////////////////////////

///////////// Inclusão de Bibliotecas /////////////
//#include <avr/wdt.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
//////////////////////////////////////////////////


//////////////// Declaração de Objectos ///////////
LiquidCrystal_I2C lcd(0x27, 20, 4);  // set the LCD address to 0x27 for a 16X02
///////////////////////////////////////////////////

byte cont = 0;
bool flag = false;
bool flagAlarme1 = false;
bool flagAlarme2 = false;
bool alarmeActive1 = false;
bool alarmeActive2 = false;

unsigned long int temporizador = 0;
unsigned long int timerAlarme1 = 0;
unsigned long int timerAlarme2 = 0;

String leituraReservatorio1 = ZERO;  /////
String nivelReservatorio1 = VAZIO;   /////
String status1 = STATUS_VAZIO;       /////

String leituraReservatorio2 = ZERO;  /////
String nivelReservatorio2 = VAZIO;   /////
String status2 = STATUS_VAZIO;       /////

void setup() 
{
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


  pinMode(R2_BUZZER, OUTPUT);
  digitalWrite(R2_BUZZER, LOW);

  pinMode(LED, OUTPUT);
  digitalWrite(LED, LOW);

  delay(100);

  lcd.init();       // inicializando o Dispaly
  lcd.backlight();  // mantem a luz do LCD acesso
  lcd.clear();
  delay(50);

  lcd.setCursor(0, 0);
  lcd.print("CONDOMINIO KIZOMBA");
  lcd.setCursor(0, 1);
  lcd.print("NIVEL DO TANQUE");
  lcd.setCursor(0, 2);
  lcd.print("RESERVATORIO "+ String(R1_NOME));
  lcd.setCursor(0, 3);
  lcd.print("RESERVATORIO "+ String(R2_NOME));

 
  Serial.begin(9600);
  delay(1000);
  Serial3.begin(9600); // SERIAL PARA O MASTER FW
  delay(1000);
  Serial.println("SISTEMA INICIADO COM SUCESSO!");

  //wdt_enable(WDTO_8S);
}


void loop() {
  //wdt_reset();
  receberDados();
  handleButton();
  
  if ((millis() - temporizador) > 1000) {
    temporizador = millis();
    lerSensores1();
    lerSensores2();
    enviarDados();
    if(++cont==2)
    {
      cont =0;
      flag = !flag;
      imprimirDadosLCD(lcd);
    }
    digitalWrite(LED, !digitalRead(LED));
  }

  delay(5);
}

void handleButton(){
  if(alarmeActive1 && !flagAlarme1)
    {
      flagAlarme1=true;
      timerAlarme1 = millis();
      ligarAlarme1();
    }
    else if(alarmeActive1 && flagAlarme1 && (millis()-timerAlarme1>TEMPO_ALARME)){
      desligarAlarme1();
    }

    if(alarmeActive2 && !flagAlarme2)
    {
      flagAlarme2=true;
      timerAlarme2 = millis();
      ligarAlarme2();
    }
    else if(alarmeActive2 && flagAlarme2 && (millis()-timerAlarme2>TEMPO_ALARME)){
      desligarAlarme2();
    }
}

//////////////////////////////////////////////////////////
void enviarDados() {
  String texto = String(NOME) + "*";
  texto += status1 + "*" + status2 + "*";
  Serial.println(texto);
  Serial3.println(texto);
}

///////////////////////////////////////////////////////////////////////////////////
void imprimirDadosLCD(LiquidCrystal_I2C lcd) {
  lcd.init();
  lcd.clear();
  lcd.setCursor(0, 0);
  if (flag) {
    lcd.print(("RESERVATORIO:" + String(R1_NOME)));
    lcd.setCursor(0, 1);
    lcd.print("NIVEL:");
    lcd.print(nivelReservatorio1);
    lcd.setCursor(0, 2);
    lcd.print("LEITURA:");
    lcd.print(leituraReservatorio1);
  } else {
    lcd.print(("RESERVATORIO:" + String(R2_NOME)));
    lcd.setCursor(0, 1);
    lcd.print("NIVEL:");
    lcd.print(nivelReservatorio2);
    lcd.setCursor(0, 2);
    lcd.print("LEITURA:");
    lcd.print(leituraReservatorio2);
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
    Serial.println(String(R1_NOME)+"_SENSOR10:"+String(sensor10));
    Serial.println(String(R1_NOME)+"_SENSOR9:"+String(sensor9));
    Serial.println(String(R1_NOME)+"_SENSOR8:"+String(sensor8));
    Serial.println(String(R1_NOME)+"_SENSOR7:"+String(sensor7));
    Serial.println(String(R1_NOME)+"_SENSOR6:"+String(sensor6));
    Serial.println(String(R1_NOME)+"_SENSOR5:"+String(sensor5));
    Serial.println(String(R1_NOME)+"_SENSOR4:"+String(sensor4));
    Serial.println(String(R1_NOME)+"_SENSOR3:"+String(sensor3));
    Serial.println(String(R1_NOME)+"_SENSOR2:"+String(sensor2));
    Serial.println(String(R1_NOME)+"_SENSOR1:"+String(sensor1));
    Serial.println("===========================================");
  }

  // Primeiro Nivel - 100% - 4,5 m^2 - todos os leds acesso
  if ((sensor10 == 1) && (sensor9 == 1) && (sensor8 == 1) && (sensor7 == 1) && (sensor6 == 1)
      && (sensor5 == 1) && (sensor4 == 1) && (sensor3 == 1) && (sensor2 == 1) && (sensor1 == 1)) {
    nivelReservatorio1 = "CHEIO";
    leituraReservatorio1 = "100%";
    status1="10";
    alarmeActive1=false;
    flagAlarme1=false;
  }

  // Segundo Nivel - 90% - 4,05 m^2 - um led apagado
  else if ((sensor10 == 0) && (sensor9 == 1) && (sensor8 == 1) && (sensor7 == 1) && (sensor6 == 1)
      && (sensor5 == 1) && (sensor4 == 1) && (sensor3 == 1) && (sensor2 == 1) && (sensor1 == 1)) {
    nivelReservatorio1 = "QUASE CHEIO";
    leituraReservatorio1 = "90%";
    status1="9";
    alarmeActive1=false;
    flagAlarme1=false;
  }

  // terceiro Nivel - 80% - 3,6 m^2 - dois leds apagados
  else if ((sensor10 == 0) && (sensor9 == 0) && (sensor8 == 1) && (sensor7 == 1) && (sensor6 == 1)
      && (sensor5 == 1) && (sensor4 == 1) && (sensor3 == 1) && (sensor2 == 1) && (sensor1 == 1)) {
    nivelReservatorio1 = "MUITO ALTO";
    leituraReservatorio1 = "80%";
    status1="8";
    alarmeActive1=false;
    flagAlarme1=false;
  }

  // Quarto Nivel - 70% - 3,15 m^2 - três leds apagados
  else if ((sensor10 == 0) && (sensor9 == 0) && (sensor8 == 0) && (sensor7 == 1) && (sensor6 == 1)
      && (sensor5 == 1) && (sensor4 == 1) && (sensor3 == 1) && (sensor2 == 1) && (sensor1 == 1)) {
    nivelReservatorio1 = "ALTO";
    leituraReservatorio1 = "70%";
    status1="7";
    alarmeActive1=false;
    flagAlarme1=false;
  }

  // Quinto Nivel - 60% - 2,7 m^2 - quatro leds apagados
  else if ((sensor10 ==0) && (sensor9 == 0) && (sensor8 == 0) && (sensor7 == 0) && (sensor6 == 1)
      && (sensor5 == 1) && (sensor4 == 1) && (sensor3 == 1) && (sensor2 == 1) && (sensor1 == 1)) {
    nivelReservatorio1 = "MEDIO ALTO";
    leituraReservatorio1 = "60%";
    status1="6";
    alarmeActive1=false;
    flagAlarme1=false;
  }

  // sexto Nivel - 50% - 2,25 m^2 - cinco leds apagados
  else if ((sensor10 == 0) && (sensor9 == 0) && (sensor8 == 0) && (sensor7 == 0) && (sensor6 == 0)
      && (sensor5 == 1) && (sensor4 == 1) && (sensor3 == 1) && (sensor2 == 1) && (sensor1 == 1)) {
    nivelReservatorio1 = "MEDIO";
    leituraReservatorio1 = "50%";
    status1="5";
    alarmeActive1=false;
    flagAlarme1=false;
  }

  // setimo Nivel - 40% - 1,8 m^2 - seis leds apagados
  else if ((sensor10 == 0) && (sensor9 == 0) && (sensor8 == 0) && (sensor7 == 0) && (sensor6 == 0)
      && (sensor5 == 0) && (sensor4 == 1) && (sensor3 == 1) && (sensor2 == 1) && (sensor1 == 1)) {
    nivelReservatorio1 = "MEDIO BAIXO";
    leituraReservatorio1 = "40%";
    status1="4";
    alarmeActive1=false;
    flagAlarme1=false;
  }

  // Oitavo Nivel - 30% - 1,35 m^2 - sete leds apagados
  else if ((sensor10 == 0) && (sensor9 == 0) && (sensor8 == 0) && (sensor7 == 0) && (sensor6 == 0)
      && (sensor5 == 0) && (sensor4 == 0) && (sensor3 == 1) && (sensor2 == 1) && (sensor1 == 1)) {
    nivelReservatorio1 = "BAIXO";
    leituraReservatorio1 = "30%";
    status1="3";
    alarmeActive1=true;
  }

  // Nono Nivel - 20% - 0,9 m^2 - oito leds apagados
  else if ((sensor10 == 0) && (sensor9 == 0) && (sensor8 == 0) && (sensor7 == 0) && (sensor6 == 0)
      && (sensor5 == 0) && (sensor4 == 0) && (sensor3 == 0) && (sensor2 == 1) && (sensor1 == 1)) {
    nivelReservatorio1 = "QUASE VAZIO";
    leituraReservatorio1 = "20%";
    status1="2";
    alarmeActive1=true;
  }
  // Decimo Nivel - 10% - 0,45 m^2 - nove leds apagados
  else if ((sensor10 == 0) && (sensor9 == 0) && (sensor8 == 0) && (sensor7 == 0) && (sensor6 == 0)
      && (sensor5 == 0) && (sensor4 == 0) && (sensor3 == 0) && (sensor2 == 0) && (sensor1 == 1)) {
    nivelReservatorio1 = "CRITICO";
    leituraReservatorio1 = "10%";
    status1="1";
    alarmeActive1=true;
  }

  // Decimo Nivel - 10% - 0,45 m^2 - nove leds apagados
  else if ((sensor10 == 0) && (sensor9 == 0) && (sensor8 == 0) && (sensor7 == 0) && (sensor6 == 0)
      && (sensor5 == 0) && (sensor4 == 1) && (sensor3 == 0) && (sensor2 == 0) && (sensor1 == 0)) {
    nivelReservatorio1 = "VAZIO";
    leituraReservatorio1 = "0%";
    status1="0";
    alarmeActive1=true;
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
    Serial.println(String(R2_NOME)+"_SENSOR10:"+String(sensor10));
    Serial.println(String(R2_NOME)+"_SENSOR9:"+String(sensor9));
    Serial.println(String(R2_NOME)+"_SENSOR8:"+String(sensor8));
    Serial.println(String(R2_NOME)+"_SENSOR7:"+String(sensor7));
    Serial.println(String(R2_NOME)+"_SENSOR6:"+String(sensor6));
    Serial.println(String(R2_NOME)+"_SENSOR5:"+String(sensor5));
    Serial.println(String(R2_NOME)+"_SENSOR4:"+String(sensor4));
    Serial.println(String(R2_NOME)+"_SENSOR3:"+String(sensor3));
    Serial.println(String(R2_NOME)+"_SENSOR2:"+String(sensor2));
    Serial.println(String(R2_NOME)+"_SENSOR1:"+String(sensor1));
    Serial.println("===========================================");
  }

  // Primeiro Nivel - 100% - 4,5 m^2 - todos os leds acesso
  if ((sensor10 == 1) && (sensor9 == 1) && (sensor8 == 1) && (sensor7 == 1) && (sensor6 == 1)
      && (sensor5 == 1) && (sensor4 == 1) && (sensor3 == 1) && (sensor2 == 1) && (sensor1 == 1)) {
    nivelReservatorio2 = "CHEIO";
    leituraReservatorio2 = "100%";
    status2 = "10";
    alarmeActive2=false;
    flagAlarme2=false;
  }

  // Segundo Nivel - 90% - 4,05 m^2 - um led apagado
  else if ((sensor10 == 0) && (sensor9 == 1) && (sensor8 == 1) && (sensor7 == 1) && (sensor6 == 1)
      && (sensor5 == 1) && (sensor4 == 1) && (sensor3 == 1) && (sensor2 == 1) && (sensor1 == 1)) {
    nivelReservatorio2 = "QUASE CHEIO";
    leituraReservatorio2 = "90%";
    status2 = "9";
    alarmeActive2=false;
    flagAlarme2=false;
  }

  // terceiro Nivel - 80% - 3,6 m^2 - dois leds apagados
  else if ((sensor10 == 0) && (sensor9 == 0) && (sensor8 == 1) && (sensor7 == 1) && (sensor6 == 1)
      && (sensor5 == 1) && (sensor4 == 1) && (sensor3 == 1) && (sensor2 == 1) && (sensor1 == 1)) {
    nivelReservatorio2 = "MUITO ALTO";
    leituraReservatorio2 = "80%";
    status2 = "8";
    alarmeActive2=false;
    flagAlarme2=false;
  }

  // Quarto Nivel - 70% - 3,15 m^2 - três leds apagados
  else if ((sensor10 == 0) && (sensor9 == 0) && (sensor8 == 0) && (sensor7 == 1) && (sensor6 == 1)
      && (sensor5 == 1) && (sensor4 == 1) && (sensor3 == 1) && (sensor2 == 1) && (sensor1 == 1)) {
    nivelReservatorio2 = "ALTO";
    leituraReservatorio2 = "70%";
    status2 = "7";
    alarmeActive2=false;
    flagAlarme2=false;
  }

  // Quinto Nivel - 60% - 2,7 m^2 - quatro leds apagados
  else if ((sensor10 == 0) && (sensor9 == 0) && (sensor8 == 0) && (sensor7 == 0) && (sensor6 == 1)
      && (sensor5 == 1) && (sensor4 == 1) && (sensor3 == 1) && (sensor2 == 1) && (sensor1 == 1)) {
    nivelReservatorio2 = "MEDIO ALTO";
    leituraReservatorio2 = "60%";
    status2 = "6";
    alarmeActive2=false;
    flagAlarme2=false;
  }

  // sexto Nivel - 50% - 2,25 m^2 - cinco leds apagados
  else if ((sensor10 == 0) && (sensor9 == 0) && (sensor8 == 0) && (sensor7 == 0) && (sensor6 == 0)
      && (sensor5 == 1) && (sensor4 == 1) && (sensor3 == 1) && (sensor2 == 1) && (sensor1 == 1)) {
    nivelReservatorio2 = "MEDIO";
    leituraReservatorio2 = "50%";
    status2 = "5";
    alarmeActive2=false;
    flagAlarme2=false;
  }

  // setimo Nivel - 40% - 1,8 m^2 - seis leds apagados
  else if ((sensor10 == 0) && (sensor9 == 0) && (sensor8 == 0) && (sensor7 == 0) && (sensor6 == 0)
      && (sensor5 == 0) && (sensor4 == 1) && (sensor3 == 1) && (sensor2 == 1) && (sensor1 == 1)) {
    nivelReservatorio2 = "MEDIO BAIXO";
    leituraReservatorio2 = "40%";
    status2 = "4";
    alarmeActive2=false;
    flagAlarme2=false;
  }

  // Oitavo Nivel - 30% - 1,35 m^2 - sete leds apagados
  else if ((sensor10 == 0) && (sensor9 == 0) && (sensor8 == 0) && (sensor7 == 0) && (sensor6 == 0)
      && (sensor5 == 0) && (sensor4 == 0) && (sensor3 == 1) && (sensor2 == 1) && (sensor1 == 1)) {
    nivelReservatorio2 = "BAIXO";
    leituraReservatorio2 = "30%";
    status2 = "3";
    alarmeActive2=true;
  }

  // Nono Nivel - 20% - 0,9 m^2 - oito leds apagados
  else if ((sensor10 == 0) && (sensor9 == 0) && (sensor8 == 0) && (sensor7 == 0) && (sensor6 == 0)
      && (sensor5 == 0) && (sensor4 == 0) && (sensor3 == 0) && (sensor2 == 1) && (sensor1 == 1)) {
    nivelReservatorio2 = "QUASE VAZIO";
    leituraReservatorio2 = "20%";
    status2 = "2";
    alarmeActive2=true;
  }

  // Decimo Nivel - 10% - 0,45 m^2 - nove leds apagados
  else if ((sensor10 == 0) && (sensor9 == 0) && (sensor8 == 0) && (sensor7 == 0) && (sensor6 == 0)
      && (sensor5 == 0) && (sensor4 == 0) && (sensor3 == 0) && (sensor2 == 0) && (sensor1 == 1)) {
    nivelReservatorio2 = "CRITICO";
    leituraReservatorio2 = "10%";
    status2 = "1";
    alarmeActive2=true;
  }

  // Decimo Nivel - 10% - 0,45 m^2 - nove leds apagados
  else if ((sensor10 == 0) && (sensor9 == 0) && (sensor8 == 0) && (sensor7 == 0) && (sensor6 == 0)
      && (sensor5 == 0) && (sensor4 == 0) && (sensor3 == 0) && (sensor2 == 0) && (sensor1 == 1)) {
    Serial.println("Nivel 0%");
    nivelReservatorio2 = "VAZIO";
    leituraReservatorio2 = "0%";
    status2 = "0";
    alarmeActive2=true;
  }
}

void receberDados() {
  //-------------------Serial do Controlador em Questão--------------------------
  if (Serial3.available()) {
    while (Serial3.available()) {
      String rx = Serial3.readString();
      Serial.print("CHEGOU:"+rx);
      if (rx.startsWith(R1_NOME) || rx.startsWith(R2_NOME)) {
        delay(4);
        if (rx.indexOf("RET") > 0) {
          Serial.println("### REENVIANDO p/:"+String(rx));
          enviarDados();
        }
      }
    }
  }
}
