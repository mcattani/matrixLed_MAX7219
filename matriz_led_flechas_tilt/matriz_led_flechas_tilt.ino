/*
   Sketch de prueba para la Matriz de Led 8*8 con el chip MAX7219
   usando la librería LedControl.h
   Se utilizan dos sensores de inclinación de mercurio KY-017 conectados a los pines 6 y 7
   con sus respectivos LEDS (conectados a los pines 4 y 5).   
   La orientación de las flechas corresponden a la ubicación de la matriz led en la protoboard
   (por eso están invertidas respecto a la salida en el video de muestra)
   Toda la información y video demostrativo en: 
   https://thenerdyapprentice.blogspot.com/
*/

#include <LedControl.h>

LedControl lc = LedControl(11, 13, 10, 1); // Creamos objeto "lc" (DIN, CLS, CS, Nro. de dispositivos)

// Declaramos las constantes que vamos a utilizar para referirnos a los sensores y leds
const byte inc_izquierda = 7;
const byte inc_derecha = 6;
const byte ledIzquierda = 5;
const byte ledDerecha = 4;

/* Definimos los arrays (en formato binario) con las líneas correspondientes
 * a los puntos en la matriz para generar las imágenes
 */
 
byte flecha_izquierda[8] { 
  B00001000,
  B00011100,
  B00111110,
  B01111111,
  B00011100,
  B00011100,
  B00011100,
  B00011100
};

byte flecha_derecha[8] {
  B00011100,
  B00011100,
  B00011100,
  B00011100,
  B01111111,
  B00111110,
  B00011100,
  B00001000
};

// Creamos las funciones que llamaremos luego para mostrar la imagen en la matriz

void mostrar_flecha_izquierda() {
  for (int i = 0; i < 8; i++) // Itera 8 veces por el array
  {
    lc.setRow(0, i, flecha_izquierda[i]);
  }
}

void mostrar_flecha_derecha() {
  for (int i = 0; i < 8; i++) // Itera 8 veces por el array
  {
    lc.setRow(0, i, flecha_derecha[i]);
  }
}

void setup() {

  Serial.begin(9600); // Iniciamos el monitor serie (sirve para debug)
  
  // Seteamos los pines como entrada --> los sensores; y como salida --> los leds
  pinMode(inc_derecha, INPUT);
  pinMode(inc_izquierda, INPUT);
  pinMode(ledIzquierda, OUTPUT);
  pinMode(ledDerecha, OUTPUT);
  
  lc.shutdown(0, false);     // Enciende la matriz
  lc.setIntensity(0, 10);    // Establece brillo
  lc.clearDisplay(0);     // Apaga la matriz

  // Inizializamos los leds como apagados
  digitalWrite(ledIzquierda, LOW); 
  digitalWrite(ledDerecha, LOW);
}

void loop() {
// Leemos el input de los sensores y llamamos a la función que muestra la imagen correspondiente

  if (digitalRead(inc_derecha)) {
    mostrar_flecha_derecha();
    digitalWrite(ledDerecha, HIGH);
    delay(1200); // Delay alto para evitar rebotes, el sensor KY-017 produce muchos falsos contactos
  }
  else {
    lc.clearDisplay(0);
    digitalWrite(ledDerecha, LOW);
  }

  if (digitalRead(inc_izquierda) == 1) {
    mostrar_flecha_izquierda();
    digitalWrite(ledIzquierda, HIGH);
    delay(1200);
  }
  else {
    lc.clearDisplay(0);
    digitalWrite(ledIzquierda, LOW);
  }

}
