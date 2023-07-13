/*
  Fundacion Kinal
  Centro Educativo Tecnico Kinal
  Electronica
  Grado: Quinto
  Curso: Taller de Electronica Digital
  Alumno: Roberto Antonio Monterroso Aguilar
  Seccion: A
  Carne: 2019507
  Proyecto: MAPA
*/
#include <Wire.h>
#include <PCF8574.h>
#include <SoftwareSerial.h>

const int TotalNames = 22; // Numero maximo de nombres a guardar
String names[TotalNames]; // Arreglo para almacenar los nombres
int Indice = 0; // Indice actual en el arreglo de nombres

#define BUZZER 3 
#define LED_Peten          5 
#define LED_Huehuetenango  6 
#define LED_Quiche         7 
#define LED_AltaVera       8 
#define LED_Izabal         9 
#define LED_SanMarcos      10
#define LED_Totonicapan    11
#define LED_BajaVera       12
#define LED_ElProgreso     13
#define LED_Zacapa         14 //A0
#define LED_Chimaltenango  15 //A1
#define LED_Quetzaltenango 16 //A2
#define LED_Solola         17 //A3


#define PCF8574_HIGH LOW
#define PCF8574_LOW HIGH

SoftwareSerial bluetooth(2, 4);

PCF8574 expansor_PCF1(0x27);
PCF8574 expansor_PCF2(0x26);

void Random_Name(void);
void melodia_buzzer(void); 

void setup() {
  // Nombres de departamento
  names[0] = "Peten";
  names[1] = "Huehuetenango";
  names[2] = "Quiche";
  names[3] = "Alta Verapaz";
  names[4] = "Izabal";
  names[5] = "San Marcos";
  names[6] = "Totonicapan";
  names[7] = "Baja Verapaz";
  names[8] = "El Progreso";
  names[9] = "Zacapa";
  names[10] = "Quetzaltenango";
  names[11] = "Solola";
  names[12] = "Chimaltenango";
  names[13] = "Sacatepequez";
  names[14] = "Guatemala";
  names[15] = "Jalapa";
  names[16] = "Chiquimula";
  names[17] = "Retalhuleu";
  names[18] = "Suchitepequez";
  names[19] = "Escuintla";
  names[20] = "Santa Rosa";
  names[21] = "Jutiapa";

  // Inicio la comunicación serial
  bluetooth.begin(9600);
  bluetooth.println("Inicio de Programa");
  Wire.begin();//Inicio la comunicacion i2c.
  expansor_PCF1.begin();
  expansor_PCF2.begin();
  
  // Inicializar el generador de números aleatorios
  randomSeed(analogRead(A0));

  // Configurar los pines del LED como salida
  for(int i = 5; i <=20; i++){   
  pinMode(i,OUTPUT);             
  }

  pinMode(BUZZER,OUTPUT);
}

void loop() {
 Random_Name();
}

void Random_Name() {
 int indice_aleatorio;
  do {
    indice_aleatorio = random(TotalNames); // Obtener un índice aleatorio
  } while (indice_aleatorio == Indice); // Evitar la repetición del mismo índice

  Indice = indice_aleatorio; // Actualizar el índice actual

  String Random_Name = names[Indice]; // Obtener el nombre correspondiente al índice

delay(1000);
  bluetooth.print("Departamento: ");
  bluetooth.println(Random_Name);

  bluetooth.println("Ingresa la capital:");

  while (!bluetooth.available()) {
    // Esperar hasta que se ingrese una respuesta
  }

  String respuesta = bluetooth.readStringUntil('\n');
  respuesta.trim(); // Eliminar espacios en blanco al inicio y final

  if (Random_Name == "Peten" && respuesta == "Flores") {
    digitalWrite(LED_Peten, HIGH);
    noTone(BUZZER);
  } else if(Random_Name == "Peten" && respuesta != "Flores"){
    melodia_buzzer();
  }
  if (Random_Name == "Huehuetenango" && respuesta == "Huehuetenango") {
    digitalWrite(LED_Huehuetenango, HIGH);
    noTone(BUZZER);
  } else if(Random_Name == "Huehuetenango" && respuesta != "Huehuetenango"){
    melodia_buzzer();
  }
  if (Random_Name == "Quiche" && respuesta == "Santa Cruz del Quiche") {
    digitalWrite(LED_Quiche, HIGH);
    noTone(BUZZER);
  } else if(Random_Name == "Quiche" && respuesta != "Santa Cruz del Quiche"){
    melodia_buzzer();
  }
  if (Random_Name == "Alta Verapaz" && respuesta == "Coban") {
    digitalWrite(LED_AltaVera, HIGH);
    noTone(BUZZER);
  } else if(Random_Name == "Alta Verapaz" && respuesta != "Coban"){
    melodia_buzzer();
  }
  if (Random_Name == "Izabal" && respuesta == "Puerto Barrios") {
    digitalWrite(LED_Izabal, HIGH);
    noTone(BUZZER);
  } else if(Random_Name == "Izabal" && respuesta != "Puerto Barrios"){
    melodia_buzzer();
  }
  if (Random_Name == "San Marcos" && respuesta == "San Marcos") {
    digitalWrite(LED_SanMarcos, HIGH);
    noTone(BUZZER);
  } else if(Random_Name == "San Marcos" && respuesta != "San Marcos"){
    melodia_buzzer();
  }
  if (Random_Name == "Totonicapan" && respuesta == "Totonicapan") {
    digitalWrite(LED_Totonicapan, HIGH);
    noTone(BUZZER);
  } else if(Random_Name == "Totonicapan" && respuesta != "Totonicapan"){
    melodia_buzzer();
  }
  if (Random_Name == "Baja Verapaz" && respuesta == "Salama") {
    digitalWrite(LED_BajaVera, HIGH);
    noTone(BUZZER);
  } else if(Random_Name == "Baja Verapaz" && respuesta != "Salama"){
    melodia_buzzer();
  }
  if (Random_Name == "El Progreso" && respuesta == "Guatatoya") {
    digitalWrite(LED_ElProgreso, HIGH);
    noTone(BUZZER);
  } else if(Random_Name == "El Progreso" && respuesta != "Guatatoya"){
    melodia_buzzer();
  }
  if (Random_Name == "Zacapa" && respuesta == "Zacapa") {
    digitalWrite(LED_Zacapa, HIGH);
    noTone(BUZZER);
  } else if(Random_Name == "Zacapa" && respuesta != "Zacapa"){
    melodia_buzzer();
  }
  if (Random_Name == "Quetzaltenango" && respuesta == "Quetzaltenango") {
    digitalWrite(LED_Quetzaltenango, HIGH);
    noTone(BUZZER);
  } else if(Random_Name == "Quetzaltenango" && respuesta != "Quetzaltenango"){
    melodia_buzzer();
  }
  if (Random_Name == "Solola" && respuesta == "Solola") {
    digitalWrite(LED_Solola, HIGH);
    noTone(BUZZER);
  } else if(Random_Name == "Solola" && respuesta != "Solola"){
    melodia_buzzer();
  }
  if (Random_Name == "Chimaltenango" && respuesta == "Chimaltenango") {
    digitalWrite(LED_Chimaltenango, HIGH);
    noTone(BUZZER);
  } else if(Random_Name == "Chimaltenango" && respuesta != "Chimaltenango"){
    melodia_buzzer();
  }
  if (Random_Name == "Sacatepequez" && respuesta == "Antigua Guatemala") {
    expansor_PCF1.write(0,PCF8574_HIGH);
    noTone(BUZZER);
  } else if(Random_Name == "Sacatepequez" && respuesta != "Antigua Guatemala"){
    melodia_buzzer();
  }
  if (Random_Name == "Guatemala" && respuesta == "Ciudad de Guatemala") {
    expansor_PCF1.write(1,PCF8574_HIGH);
    noTone(BUZZER);
  } else if(Random_Name == "Guatemala" && respuesta != "Ciudad de Guatemala"){
    melodia_buzzer();
  }
  if (Random_Name == "Jalapa" && respuesta == "Jalapa") {
    expansor_PCF1.write(2,PCF8574_HIGH);
    noTone(BUZZER);
  } else if(Random_Name == "Jalapa" && respuesta != "Jalapa"){
    melodia_buzzer();
  }
  if (Random_Name == "Chiquimula" && respuesta == "chiquimula") {
    expansor_PCF1.write(4,PCF8574_HIGH);
    noTone(BUZZER);
  } else if(Random_Name == "Chiquimula" && respuesta != "Flores"){
    melodia_buzzer();
  }
  if (Random_Name == "Retalhuleu" && respuesta == "Retalhuleu ") {
    expansor_PCF1.write(5,PCF8574_HIGH);
    noTone(BUZZER);
  } else if(Random_Name == "Retalhuleu" && respuesta != "Flores"){
    melodia_buzzer();
  }
  if (Random_Name == "Suchitepequez" && respuesta == "Mazatenango") {
    expansor_PCF1.write(6,PCF8574_HIGH);
    noTone(BUZZER);
  } else if(Random_Name == "Suchitepequez" && respuesta != "Flores"){
    melodia_buzzer();
  }
  if (Random_Name == "Escuintla" && respuesta == "Escuintla ") {
    expansor_PCF1.write(7,PCF8574_HIGH);
    noTone(BUZZER);
  } else if(Random_Name == "Escuintla" && respuesta != "Flores"){
    melodia_buzzer();
  }
  if (Random_Name == "Santa Rosa" && respuesta == "Cuilapa") {
    expansor_PCF2.write(0,PCF8574_HIGH);
    noTone(BUZZER);
  } else if(Random_Name == "Santa Rosa" && respuesta != "Flores"){
    melodia_buzzer();
  }
  if (Random_Name == "Jutiapa" && respuesta == "Jalapa") {
    expansor_PCF2.write(1,PCF8574_HIGH);
    noTone(BUZZER);
  } else if(Random_Name == "Jutiapa" && respuesta != "Flores"){
    melodia_buzzer();
  }
}

void melodia_buzzer(){
  tone(BUZZER, 196, 250); // Frecuencia: G3, Duración: 250ms
  delay(250);
  tone(BUZZER, 147, 250); // Frecuencia: D3, Duración: 250ms
  delay(250);
  tone(BUZZER, 131, 500); // Frecuencia: C3, Duración: 500ms
  delay(500);
  tone(BUZZER, 98, 1000); // Frecuencia: G2, Duración: 1000ms
}
