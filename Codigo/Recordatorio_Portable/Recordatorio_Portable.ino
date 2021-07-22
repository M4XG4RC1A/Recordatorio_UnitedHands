#include <SoftwareSerial.h>
#include <DFPlayer_Mini_Mp3.h>
 
SoftwareSerial DFPlayerSerial(6, 7); // RX, TX //10,11

String Str[]={"Almorzar","Comer","Cenar","Ir al Baño","Salir","Entrar"};
float Strt[]={7,2,9,3,4,5};
int StrtM[] = {10,0,0,0,0,0};
int Hora,Minuto;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  DFPlayerSerial.begin(9600);
  mp3_set_serial(DFPlayerSerial);
  mp3_set_volume(20);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available()){
    Serial.println("Entro");
    float Cont = Serial.parseFloat();
    Serial.println(Cont);
    Hora = Cont;
    Minuto = (Cont-Hora)*100;
    char Seleccion = ' ';
    if (Hora==Strt[0] && Minuto == StrtM[0]){
      Seleccion = 'a';
      Serial.println(Str[0]);
      mp3_play(1);
    }else if (Hora==Strt[1] && Minuto == StrtM[1]){
      Seleccion = 'b';
      Serial.println(Str[1]);
      mp3_play(2);
    }else if (Hora==Strt[2] && Minuto == Strt[2]){
      Seleccion = 'c';
      Serial.println(Str[2]);
      mp3_play(3);
    }else if (Hora==Strt[3] && Minuto == StrtM[3]){
      Seleccion = 'd';
      Serial.println(Str[3]);
      mp3_play(4);
    }else if (Hora==Strt[4] && Minuto == StrtM[4]){
      Seleccion = 'e';
      Serial.println(Str[4]);
      mp3_play(5);
    }else if (Hora == Strt[5] && Minuto == StrtM[5]){
      Seleccion = 'f';
      Serial.println(Str[5]);
      mp3_play(6);
    }else{
      mp3_stop();
    }
    delay(3000);
    Serial.println("Salio");
    mp3_stop();
  }
}
