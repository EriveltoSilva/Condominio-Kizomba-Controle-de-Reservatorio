/*
   Autor:Erivelto Clénio da Costa e Silva
   Data última Atualização:02/03/2023
   Actuadore: Bomba
   Input:
   Objectivo:
  Principais Componentes usados:
 *** 1-ARDUINO MEGA 2560 (1)
 *** 2-BLUETOOTH (1) 
 *** 3-LCD COM I2C (1)
 *** 6-TRANSISTORES BC548 (6) COM RESISTORES (6)
 ***
*/

///////////// Inclusão de Bibliotecas /////////////
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
//////////////////////////////////////////////////

////////// Definição de Pinos e Objectos //////////
#define BOMBA2 2  /////
#define BOMBA1 3  /////
#define BOTAO1 4  /////
#define BOTAO2 5  /////

#define BUZZER2 7           /////
#define BUZZER1 8            /////
#define LED 13              /////
#define LED_VERDE1 45       /////
#define LED_AMARELO1 46     /////
#define LED_VERMELHO1 47    /////
#define LED_VERDE2 48       /////
#define LED_AMARELO2 49     /////
#define LED_VERMELHO2 50    /////
///////////////////////////////////////////////////
///////////////////////////////////////////////////
#define SENSOR_RESERVATORIO_CHEIO2 22  /////
#define SENSOR_RESERVATORIO_ALTO2 23   /////
#define SENSOR_RESERVATORIO_INTERMEDIO2 24  /////
/////
#define SENSOR_RESERVATORIO_MEDIO2 25    /////
#define SENSOR_RESERVATORIO_BAIXO2 26  /////
#define SENSOR_RESERVATORIO_CRITICO2 27    /////
///////////////////////////////////////////////////
///////////////////////////////////////////////////
#define SENSOR_RESERVATORIO_CHEIO1 28  /////
#define SENSOR_RESERVATORIO_ALTO1 29   /////
#define SENSOR_RESERVATORIO_INTERMEDIO1 30  /////
/////
#define SENSOR_RESERVATORIO_MEDIO1 31    /////
#define SENSOR_RESERVATORIO_BAIXO1 32  /////
#define SENSOR_RESERVATORIO_CRITICO1 33    /////
/////
#define VAZIO "VAZIO"  /////
///////////////////////////////////////////////////
LiquidCrystal_I2C lcd1(0x26, 16, 4);  // set the LCD address to 0x26 for a 16X04
LiquidCrystal_I2C lcd2(0x3F, 16, 4);  // set the LCD address to 0x27 for a 16x02
///////////////////////////////////////////////////

////////////////////////// Variaveis /////////////////////
byte flag1 = 0;              /////
byte flagAnterior1 = 0;      /////
boolean flagVazao1 = false;  /////
boolean modoAbastecimento1 = false, modoAbastecimento2 = false;
//////////////////////////////////////////////////////////
byte flag2 = 0;              /////
byte flagAnterior2 = 0;      /////
boolean flagVazao2 = false;  /////
//////////////////////////////////////////////////////////
char modo = 'A';                     /////
byte vez = 0;                        /////
unsigned long timer = 0;             /////
unsigned long tempoRecepcao = 0;     /////
String sensorReservatorio1 = VAZIO;  /////
String nivelReservatorio1 = VAZIO;   /////
String estadoBomba1 = "";            /////
String sensorReservatorio2 = VAZIO;  /////
String nivelReservatorio2 = VAZIO;   /////
String estadoBomba2 = "";            /////
//////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////
void receberDados();          /////
void enviarDados();           /////
void activarAlarme(byte);     /////
void desactivarAlarme(byte);  /////
void ligarBomba(byte);        /////
void desligarBomba(byte);     /////
void lerSensores();           /////
//////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////
void setup() {
  pinMode(LED, OUTPUT);
  digitalWrite(LED, LOW);

  pinMode(BOMBA1, OUTPUT);
  desligarBomba(1);

  pinMode(BOMBA2, OUTPUT);
  desligarBomba(2);

  pinMode(LED_VERDE1, OUTPUT);
  pinMode(LED_AMARELO1, OUTPUT);
  pinMode(LED_VERMELHO1, OUTPUT);
  setNivelVazio1();

  pinMode(LED_VERDE2, OUTPUT);
  pinMode(LED_AMARELO2, OUTPUT);
  pinMode(LED_VERMELHO2, OUTPUT);
  setNivelVazio2();

  pinMode(SENSOR_RESERVATORIO_CHEIO1, INPUT_PULLUP);
  pinMode(SENSOR_RESERVATORIO_ALTO1, INPUT_PULLUP);
  pinMode(SENSOR_RESERVATORIO_INTERMEDIO1, INPUT_PULLUP);

  pinMode(SENSOR_RESERVATORIO_MEDIO1, INPUT_PULLUP);
  pinMode(SENSOR_RESERVATORIO_BAIXO1, INPUT_PULLUP);
  pinMode(SENSOR_RESERVATORIO_CRITICO1, INPUT_PULLUP);

  pinMode(SENSOR_RESERVATORIO_CHEIO2, INPUT_PULLUP);
  pinMode(SENSOR_RESERVATORIO_ALTO2, INPUT_PULLUP);
  pinMode(SENSOR_RESERVATORIO_INTERMEDIO2, INPUT_PULLUP);

  pinMode(SENSOR_RESERVATORIO_MEDIO2, INPUT_PULLUP);
  pinMode(SENSOR_RESERVATORIO_BAIXO2, INPUT_PULLUP);
  pinMode(SENSOR_RESERVATORIO_CRITICO2, INPUT_PULLUP);

  pinMode(BOTAO1, INPUT_PULLUP);
  pinMode(BOTAO2, INPUT_PULLUP);

  pinMode(BUZZER1, OUTPUT);
  pinMode(BUZZER2, OUTPUT);
  desactivarAlarme(1);
  desactivarAlarme(2);
  delay(50);

  lcd1.init();  // initialize the lcd
  lcd1.backlight();
  delay(50);

  lcd2.init();  // initialize the lcd
  lcd2.backlight();
  delay(50);

  lcd1.setCursor(0, 0);
  lcd1.print(" UNIV.METODISTA");
  lcd1.setCursor(0, 1);
  lcd1.print(" PROJECTO FINAL");
  lcd1.setCursor(-4, 2);
  lcd1.print(" ## FÉLIX  ## ");

  lcd2.setCursor(0, 0);
  lcd2.print(" UNIV.METODISTA");
  lcd2.setCursor(0, 1);
  lcd2.print(" PROJECTO FINAL ");
  lcd2.setCursor(-4, 2);
  lcd2.print(" ## RICARDO ## ");

  Serial.begin(9600);
  delay(500);
  Serial2.begin(9600);
  delay(500);
  Serial.println("SISTEMA INICIADO COM SUCESSO!");
}

//////////////////////////////////////////////////////////
void loop() {
  receberDados();
  if (millis() - timer > 60 * 1000) modo = 'A';
  if ((millis() - tempoRecepcao) > 500) 
  {
    tempoRecepcao = millis();
    lerSensores();
    hasVazao();
    enviarDados();
    imprimirDadosLCD(1, lcd1);
    imprimirDadosLCD(2, lcd2);
    digitalWrite(LED, digitalRead(LED));
  }

  if (!digitalRead(BOTAO1)) ligarBomba(1);
  else desligarBomba(1);

  if (!digitalRead(BOTAO2)) ligarBomba(2);
  else desligarBomba(2);

  verificaDesliga();


 

  delay(10);
}

//////////////////////////////////////////////////////////
void lerSensores() {
  if (!digitalRead(SENSOR_RESERVATORIO_CHEIO1)) {
    nivelReservatorio1 = "CHEIO";
    sensorReservatorio1 = "100%";
    setNivelAlto1();
    flag1 = 6;
  } else if (!digitalRead(SENSOR_RESERVATORIO_ALTO1)) {
    nivelReservatorio1 = "ALTO";
    sensorReservatorio1 = "~80%";
    setNivelAlto1();
    flag1 = 5;
  } else if (!digitalRead(SENSOR_RESERVATORIO_INTERMEDIO1)) {
    nivelReservatorio1 = "INTERMEDIO";
    sensorReservatorio1 = "~60%";
    setNivelMedio1();
    flag1 = 4;
  } else if (!digitalRead(SENSOR_RESERVATORIO_MEDIO1)) {
    nivelReservatorio1 = "MEDIO";
    sensorReservatorio1 = "~40%";
    setNivelMedio1();
    flag1 = 3;
  } else if (!digitalRead(SENSOR_RESERVATORIO_BAIXO1)) {
    nivelReservatorio1 = "BAIXO";
    sensorReservatorio1 = "~20%";
    setNivelBaixo1();
    flag1 = 2;
  }
  else if (!digitalRead(SENSOR_RESERVATORIO_CRITICO1)) {
    nivelReservatorio1 = "CRITICO";
    sensorReservatorio1 = "~5%";
    setNivelBaixo1();
    flag1 = 1;
  }
  else {
    nivelReservatorio1 = "VAZIO";
    sensorReservatorio1 = "~0%";
    setNivelVazio1();
    flag1 = 0;
  }



  if (!digitalRead(SENSOR_RESERVATORIO_CHEIO2)) {
    nivelReservatorio2 = "CHEIO";
    sensorReservatorio2 = "100%";
    setNivelAlto2();
    flag2 = 6;
  } else if (!digitalRead(SENSOR_RESERVATORIO_ALTO2)) {
    nivelReservatorio2 = "ALTO";
    sensorReservatorio2 = "~80%";
    setNivelAlto2();
    flag2 = 5;
  } else if (!digitalRead(SENSOR_RESERVATORIO_INTERMEDIO2)) {
    nivelReservatorio2 = "INTERMEDIO";
    sensorReservatorio2 = "~60%";
    setNivelMedio2();
    flag2 = 4;
  } else if (!digitalRead(SENSOR_RESERVATORIO_MEDIO2)) {
    nivelReservatorio2 = "MEDIO";
    sensorReservatorio2 = "~40%";
    setNivelMedio2();
    flag2 = 3;
  } else if (!digitalRead(SENSOR_RESERVATORIO_BAIXO2)) {
    nivelReservatorio2 = "BAIXO";
    sensorReservatorio2 = "~20%";
    setNivelBaixo2();
    flag2 = 2;
  } 
  else if (!digitalRead(SENSOR_RESERVATORIO_CRITICO2)) {
    nivelReservatorio2 = "CRITICO";
    sensorReservatorio2 = "~5%";
    setNivelBaixo2();
    flag2 = 1;
  }
  else {
    nivelReservatorio2 = "VAZIO";
    sensorReservatorio2 = "~0%";
    setNivelVazio2();
    flag2 = 0;
  }


  estadoBomba1 = (digitalRead(BOMBA1)) ? "LIGADA" : "DESLIGADA";
  estadoBomba2 = (digitalRead(BOMBA2)) ? "LIGADA" : "DESLIGADA";
  // Serial.println("=============== DADOS ENVIADOS ==========================");
  // Serial.print("Modo Projecto:");
  // Serial.println((modo == 'A') ? "AUTOMATICO" : "MANUAL");
  // Serial.print("Niv.Reservatorio1:");
  // Serial.println(nivelReservatorio1);
  // Serial.print("Sen.Reservatorio1:");
  // Serial.println(sensorReservatorio1);
  // Serial.print("Flag1:");
  // Serial.println(flag1);
  // Serial.print("FlagAnterior1:");
  // Serial.println(flagAnterior1);
  // Serial.print("Estado Bomba1:");
  // Serial.println(estadoBomba1);
  // Serial.println();
  // Serial.print("Niv.Reservatorio2:");
  // Serial.println(nivelReservatorio2);
  // Serial.print("Sen.Reservatorio2:");
  // Serial.println(sensorReservatorio2);
  // Serial.print("Flag2:");
  // Serial.println(flag2);
  // Serial.print("FlagAnterior2:");
  // Serial.println(flagAnterior2);
  // Serial.print("Estado Bomba2:");
  // Serial.println(estadoBomba2);
  // Serial.println("=========================================================");
}

void verificaDesliga()
{
  if(nivelReservatorio1.equals("VAZIO"))
    desligarBomba(1);
  if(nivelReservatorio2.equals("VAZIO"))
    desligarBomba(2); 
}
//////////////////////////////////////////////////////////
boolean isBombaLigada(byte num) {
  if (num == 1)
    return (digitalRead(BOMBA1) == HIGH);
  return (digitalRead(BOMBA2) == HIGH);
}
//////////////////////////////////////////////////////////
void activarAlarme(byte num) {
  if (num == 1) {
    flagVazao1 = true;
    digitalWrite(BUZZER1, HIGH);
    desligarBomba(1);
  } else {
    flagVazao2 = true;
    digitalWrite(BUZZER2, HIGH);
    desligarBomba(2);
  }
}

//////////////////////////////////////////////////////////
void desactivarAlarme(byte num) {
  if (num == 1) {
    flagVazao1 = false;
    digitalWrite(BUZZER1, LOW);
  } else {
    flagVazao2 = false;
    digitalWrite(BUZZER2, LOW);
  }
}


//////////////////////////////////////////////////////////
void ligarBomba(byte num) {
  if (num == 1 && !(nivelReservatorio1.equalsIgnoreCase("VAZIO")) && !flagVazao1)
    digitalWrite(BOMBA1, HIGH);
  else if(num == 2 && !(nivelReservatorio2.equalsIgnoreCase("VAZIO")) && !flagVazao2)
    digitalWrite(BOMBA2, HIGH);
}

//////////////////////////////////////////////////////////
void desligarBomba(byte num) {
  if (num == 1)
    digitalWrite(BOMBA1, LOW);
  else
    digitalWrite(BOMBA2, LOW);
}


//////////////////////////////////////////////////////////
void imprimirDadosLCD(byte numLCD, LiquidCrystal_I2C lcd) {
  lcd.init();
  lcd.clear();
  lcd.setCursor(0, 0);
  if (numLCD == 1) 
  {
    if (!flagVazao1) {
      lcd.print("POSTO1");
      lcd.setCursor(0, 1);
      lcd.print("NIV.RES1:");
      lcd.print(nivelReservatorio1);
      lcd.setCursor(-4, 2);
      lcd.print("SEN.RES1:");
      lcd.print(sensorReservatorio1);
      lcd.setCursor(-4, 3);
      lcd.print("BOMBA1:");
      lcd.print(estadoBomba1);
    } else {
      lcd.print("POSTO1");
      lcd.setCursor(0, 1);
      lcd.print("#### ALERTA ####");
      lcd.setCursor(-4, 2);
      lcd.print("#POSSIVEL VAZAO#");
      lcd.setCursor(-4, 3);
      lcd.print("## DETECTADA  ##");
    }
  } 
  else 
  {
    if (!flagVazao2) {
      lcd.print("POSTO2");
      lcd.setCursor(0, 1);
      lcd.print("NIV.RES2:");
      lcd.print(nivelReservatorio2);
      lcd.setCursor(-4, 2);
      lcd.print("SEN.RES2:");
      lcd.print(sensorReservatorio2);
      lcd.setCursor(-4, 3);
      lcd.print("BOMBA2:");
      lcd.print(estadoBomba2);
    } else {
      lcd.print("POSTO2");
      lcd.setCursor(0, 1);
      lcd.print("#### ALERTA ####");
      lcd.setCursor(-4, 2);
      lcd.print("#POSSIVEL VAZAO#");
      lcd.setCursor(-4, 3);
      lcd.print("## DETECTADA  ##");
    }
  }
}


//////////////////////////////////////////////////////////
void enviarDados() {
  String texto ="B*";
  texto += nivelReservatorio1 + "*" + sensorReservatorio1 + "*" + estadoBomba1 + "*" + ((flagVazao1)?"1*":"0*");
  texto += nivelReservatorio2 + "*" + sensorReservatorio2 + "*" + estadoBomba2 + "*" + ((flagVazao2)?"1*":"0*")+((modoAbastecimento1)?"1*":"0*")+((modoAbastecimento2)?"1*":"0*");
  Serial.println(texto);
  Serial2.println(texto);
}



//////////////////////////////////////////////////////////
void receberDados() {
  if (Serial2.available()) {
    while (Serial2.available()) 
    {
      char rx = Serial2.read();
      Serial.print("### Recebido:");
      Serial.write(rx);
      switch (rx) 
      {
        case 'L':
          modo = 'M';
          timer = millis();
          ligarBomba(1);
          break;
        case 'l':
          modo = 'M';
          timer = millis();
          desligarBomba(1);
          break;
        case 'M':
          modo = 'M';
          timer = millis();
          ligarBomba(2);
          break;
        case 'm':
          modo = 'M';
          timer = millis();
          desligarBomba(2);
          break;
        case 'V':
          Serial.println("## Alarme1 Desactivado ##");
          desactivarAlarme(1);
          break;
        case 'v':
          Serial.println("## Alarme2 Desactivado ##");
          desactivarAlarme(2);
          break;
        case 'A':
          Serial.println("## Abastecendo Posto 1##");
          modoAbastecimento1 = true;
        break;
        case 'a':
          Serial.println("## Desligando modo abastecimento ##");
          modoAbastecimento1 = false;
          flagAnterior1= flag1;
        break;
        case 'B':
          Serial.println("## Abastecendo Posto 2##");
          modoAbastecimento2 = true;
          break;
        case 'b':
          Serial.println("## Desligando modo abastecimento ##");
          modoAbastecimento2 = false;
          flagAnterior2= flag2;
          break;
      }
    }
  }


  if (Serial.available()) {
    while (Serial.available()) {
      char rx = Serial.read();
      Serial.print("### Recebido:");
      Serial.write(rx);
      switch (rx) 
      {
        case 'L':
          modo = 'M';
          timer = millis();
          ligarBomba(1);
          break;
        case 'l':
          modo = 'M';
          timer = millis();
          desligarBomba(1);
          break;
        case 'M':
          modo = 'M';
          timer = millis();
          ligarBomba(2);
          break;
        case 'm':
          modo = 'M';
          timer = millis();
          desligarBomba(2);
          break;
        case 'V':
          Serial.println("## Alarme1 Desactivado ##");
          desactivarAlarme(1);
          break;
        case 'v':
          Serial.println("## Alarme2 Desactivado ##");
          desactivarAlarme(2);
          break;
        case 'A':
          Serial.println("## Abastecendo Posto 1##");
          modoAbastecimento1 = true;
        break;
        case 'a':
          Serial.println("## Desligando modo abastecimento ##");
          modoAbastecimento1 = false;
          flagAnterior1= flag1;
        break;
        case 'B':
          Serial.println("## Abastecendo Posto 2##");
          modoAbastecimento2 = true;
          break;
        case 'b':
          Serial.println("## Desligando modo abastecimento ##");
          modoAbastecimento2 = false;
          flagAnterior2= flag2;
          break;
      }
    }
  }
}


void setNivelAlto1() {
  digitalWrite(LED_VERDE1, HIGH);
  digitalWrite(LED_AMARELO1, HIGH);
  digitalWrite(LED_VERMELHO1, HIGH);
}

void setNivelMedio1() {
  digitalWrite(LED_VERDE1, LOW);
  digitalWrite(LED_AMARELO1, HIGH);
  digitalWrite(LED_VERMELHO1, HIGH);
}

void setNivelBaixo1() {
  digitalWrite(LED_VERDE1, LOW);
  digitalWrite(LED_AMARELO1, LOW);
  digitalWrite(LED_VERMELHO1, HIGH);
}

void setNivelVazio1() {
  digitalWrite(LED_VERDE1, LOW);
  digitalWrite(LED_AMARELO1, LOW);
  digitalWrite(LED_VERMELHO1, LOW);
}


void setNivelAlto2() {
  digitalWrite(LED_VERDE2, HIGH);
  digitalWrite(LED_AMARELO2, HIGH);
  digitalWrite(LED_VERMELHO2, HIGH);
}

void setNivelMedio2() {
  digitalWrite(LED_VERDE2, LOW);
  digitalWrite(LED_AMARELO2, HIGH);
  digitalWrite(LED_VERMELHO2, HIGH);
}

void setNivelBaixo2() {
  digitalWrite(LED_VERDE2, LOW);
  digitalWrite(LED_AMARELO2, LOW);
  digitalWrite(LED_VERMELHO2, HIGH);
}

void setNivelVazio2() {
  digitalWrite(LED_VERDE2, LOW);
  digitalWrite(LED_AMARELO2, LOW);
  digitalWrite(LED_VERMELHO2, LOW);
}

void hasVazao() {
  if (!isBombaLigada(1) && flag1 < flagAnterior1 && !modoAbastecimento1) {
    flagAnterior1 = flag1;
    activarAlarme(1);
  } else if (isBombaLigada(1)) {
    flagAnterior1 = flag1;
  } else if (flag1 > flagAnterior1) {
    flagAnterior1 = flag1;
  }


  if (!isBombaLigada(2) && flag2 < flagAnterior2 && !modoAbastecimento2) {
    flagAnterior2 = flag2;
    activarAlarme(2);
  } else if (isBombaLigada(2)) {
    flagAnterior2 = flag2;
  } else if (flag2 > flagAnterior2) {
    flagAnterior2 = flag2;
  }
}
