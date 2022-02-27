#include <LiquidCrystal.h>
LiquidCrystal lcd(5,6,8,9,10,11); //pines para la pantalla LCD
  
int rojo = 2;
int verde = 3;
int buzzer = 4;
int sensor = A0; //Entrada de señal del sensor
int sensorUmbral = 400; //minimo para que se active el sensor

void setup()
{
pinMode(rojo, OUTPUT); //pin de salida para Led's y zumbador
pinMode(verde,OUTPUT);
pinMode(buzzer,OUTPUT);
pinMode(sensor,INPUT); //pin de entrada para sensor
Serial.begin(9600);
lcd.begin(16,2);
}

void loop()
{
  int Valor = analogRead(sensor);//valor leido por el sensor de gas
  Serial.println(Valor);
  if(Valor>sensorUmbral)//condicion si detecta alcohol
  {
    digitalWrite(rojo,HIGH);
    digitalWrite(verde,LOW);
    //suena el buzzer con una frquencia de 4000Hz por 10 segundos.
    tone(buzzer,4000,10000);
    lcd.clear();
    //Envia los mensjaes
    lcd.setCursor(0,0);
    lcd.print("ALCOHOL DETECTETADO.");
    delay(5000);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("ENVIANDO ALERTA");
    delay(5000);
    lcd.setCursor(0,1);
    lcd.print("DETENGA EL VEHICULO");
    delay(5000);
    lcd.clear();
  }
  else//Si no detecta alcohol
  {
    digitalWrite(verde,HIGH); //Prende led verde y apaga rojo
    digitalWrite(rojo,LOW);
    noTone(buzzer); //Apaga el zumbador
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("SEGURO");
    delay(1000);
    lcd.clear();
    delay(1000);
  }  
     
}
