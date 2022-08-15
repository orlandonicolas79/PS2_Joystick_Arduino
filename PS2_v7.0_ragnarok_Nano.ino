#include <PS2X_lib.h>

//La programación está realizada en base a los pines de un Arduio NANO

//Motor B
int RPWM_A= 10;  //PIN PWM 
int LPWM_A= 9;  //PIN PWM
int LREN_A= 8;  //PIN DIGITAL

//Motor A
int RPWM_B= 6;  //PIN PWM 
int LPWM_B= 5; //PIN PWM
int LREN_B= 4; //PIN DIGITAL

          
PS2X ps2x;

int error = 0;
byte vibrate = 0;

void setup()
{
  //Motor A
  pinMode(RPWM_A, OUTPUT);
  pinMode(LPWM_A, OUTPUT);
  pinMode(LREN_A, OUTPUT);

  //Motor B
  pinMode(RPWM_B, OUTPUT);
  pinMode(LPWM_B, OUTPUT);
  pinMode(LREN_B, OUTPUT);


  Serial.begin(9600);
  error = ps2x.config_gamepad(13,12,A0,11,true,true);  //(clock, command, attention, data)

  if(error == 0)
  {
    Serial.println("Controlador encontrado y configurado");
  }
  else
  {
    Serial.println("Error, mando no encontrado");
  }
}

void Adelante(){
  Serial.println("ADELANTE");
  
  //Motor A
  digitalWrite(LREN_A, HIGH);
  analogWrite(RPWM_A, 140);
  analogWrite(LPWM_A, 0);

  //Motor B
  digitalWrite(LREN_B, HIGH);
  analogWrite(RPWM_B, 0);
  analogWrite(LPWM_B, 140);
}
void Atras(){
  Serial.println("ATRAS");
  
  //Motor A
  digitalWrite(LREN_A, HIGH);   
  analogWrite(RPWM_A, 0);
  analogWrite(LPWM_A, 140);

  //Motor B
  digitalWrite(LREN_B, HIGH);
  analogWrite(RPWM_B, 140);
  analogWrite(LPWM_B, 0);
}
void Izquierda(){
  Serial.println("IZQUIERDA");
  
  //Motor A
  digitalWrite(LREN_A, HIGH);
  analogWrite(RPWM_A, 140);
  analogWrite(LPWM_A, 0);

  //Motor B
  digitalWrite(LREN_B, HIGH);
  analogWrite(RPWM_B, 140);
  analogWrite(LPWM_B, 0);
}
void Derecha(){
  Serial.println("DERECHA");
  
  //Motor A
  digitalWrite(LREN_A, HIGH);
  analogWrite(RPWM_A, 0);
  analogWrite(LPWM_A, 140);

  //Motor B
  digitalWrite(LREN_B, HIGH);
  analogWrite(RPWM_B, 0);
  analogWrite(LPWM_B, 140);
}
void Stop(){
  Serial.println("STOP");
  
  //Motor A
  digitalWrite(LREN_A, LOW);
  analogWrite(RPWM_A, 0);
  analogWrite(LPWM_A, 0);

  //Motor B
  digitalWrite(LREN_B, LOW);
  analogWrite(RPWM_B, 0);
  analogWrite(LPWM_B, 0);
}

void loop() 
{
  
  int temp;
  ps2x.read_gamepad(false,vibrate);

  vibrate = ps2x.Analog(PSAB_BLUE);

  Stop();
  
  if(ps2x.Button(PSB_PAD_UP))
  {
    temp = ps2x.Analog(PSAB_PAD_UP);
    Adelante();
    Serial.print("Presionaste arriba: ");
    Serial.println(temp);
  }
  
  else if(ps2x.Button(PSB_PAD_DOWN))
  {
    temp = ps2x.Analog(PSAB_PAD_DOWN);
    Atras();
    Serial.print("Presionaste abajo: ");
    Serial.println(temp);
  }

  else if(ps2x.Button(PSB_PAD_LEFT))
  {
    temp = ps2x.Analog(PSAB_PAD_LEFT);
    Izquierda();
    Serial.println("Presionaste izquierda: ");
    Serial.print(temp);
  }

  else if(ps2x.Button(PSB_PAD_RIGHT))
  {
    temp = ps2x.Analog(PSAB_PAD_RIGHT);
    Derecha();
    Serial.println("Presionaste derecha: ");
    Serial.print(temp);
  }

  if(ps2x.Button(PSB_BLUE))
  {
    Atras();
    Serial.println("Presionaste X: ");
  }
  if(ps2x.Button(PSB_PINK))
  {
    Izquierda();
    Serial.println("Presionaste cuadrado: ");
  }
  if(ps2x.Button(PSB_RED))
  {
    Derecha();
    Serial.println("Presionaste redondo: ");
  }
  if(ps2x.Button(PSB_GREEN))
  {
    Adelante();
    Serial.println("Presionaste triangulo: ");
  }
  if(ps2x.Button(PSB_L1))
  {
    Atras();
    Serial.println("Presionaste L1: ");
  }
  if(ps2x.Button(PSB_L2))
  {
    Izquierda();
    Serial.println("Presionaste L2: ");
  }
  if(ps2x.Button(PSB_R1))
  {
    Adelante();
    Serial.println("Presionaste R1: ");
  }
  if(ps2x.Button(PSB_R2))
  {
    Derecha();
    Serial.println("Presionaste R2: ");
  }

  
  if(ps2x.Button(PSB_SELECT))
  {
    Serial.println("Presionaste seleccionar: ");
  }
  else if(ps2x.Button(PSB_START))
  {
    Serial.println("Presionaste entrar: ");
  }

  
  delay(50);
}
