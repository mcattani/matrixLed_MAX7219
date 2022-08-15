/*
   Sketch de prueba para la Matriz de Led 8*8 con el chip MAX7219
   usando la librería LedControl.h
   Utilizaremos un pulsador conectado al pin 8 (D8).
   La orientación de la barra corresponde a la ubicación de la matriz en la protoboard
   (por eso está invertida).
   Toda la información y video demostrativo en:
   https://thenerdyapprentice.blogspot.com/
*/

#include <LedControl.h>

LedControl lc = LedControl(11, 13, 10, 1); // Creamos objeto (DIN, CLS, CS, Nro. de dispositivos)

const byte push = 8; // Constante para referirnos al pulsador
byte contador = 0; // Variable que usaremos para llevar la cuenta de las pulsaciones

/* Definimos los array (en formato binario) con las líneas correspondientes
   a los puntos en la matriz para generar la imágen
*/

byte cero[8] {
  B00111110,
  B01111111,
  B01110001,
  B01011001,
  B01001101,
  B01111111,
  B00111110,
  B00000000
};
byte uno[8] {
  B01000000,
  B01000010,
  B01111111,
  B01111111,
  B01000000,
  B01000000,
  B00000000,
  B00000000
};
byte dos[8] {
  B01100010,
  B01110011,
  B01011001,
  B01001001,
  B01101111,
  B01100110,
  B00000000,
  B00000000
};
byte tres[8] {
  B00100010,
  B01100011,
  B01001001,
  B01001001,
  B01111111,
  B00110110,
  B00000000,
  B00000000
};
byte cuatro[8] {
  B00011000,
  B00011100,
  B00010110,
  B01010011,
  B01111111,
  B01111111,
  B01010000,
  B00000000
};
byte cinco[8] {
  B00100111,
  B01100111,
  B01000101,
  B01000101,
  B01111101,
  B00111001,
  B00000000,
  B00000000
};
byte seis[8] {
  B00111100,
  B01111110,
  B01001011,
  B01001001,
  B01111001,
  B00110000,
  B00000000,
  B00000000
};
byte siete[8] {
  B00000011,
  B00000011,
  B01110001,
  B01111001,
  B00001111,
  B00000111,
  B00000000,
  B00000000
};
byte ocho[8] {
  B00110110,
  B01111111,
  B01001001,
  B01001001,
  B01111111,
  B00110110,
  B00000000,
  B00000000
};

byte nueve[8] {
  B00000110,
  B01001111,
  B01001001,
  B01101001,
  B00111111,
  B00011110,
  B00000000,
  B00000000
};

// Creamos las funciones que llamaremos para mostrar los números en la matriz

void mostrar_cero() {
  for (int i = 0; i < 8; i++) // Itera 8 veces por el array
  {
    lc.setRow(0, i, cero[i]);
  }
}

void mostrar_uno() {
  for (int i = 0; i < 8; i++)
  {
    lc.setRow(0, i, uno[i]);
  }
}

void mostrar_dos() {
  for (int i = 0; i < 8; i++) 
  {
    lc.setRow(0, i, dos[i]);
  }
}

void mostrar_tres() {
  for (int i = 0; i < 8; i++) 
  {
    lc.setRow(0, i, tres[i]);
  }
}

void mostrar_cuatro() {
  for (int i = 0; i < 8; i++) 
  {
    lc.setRow(0, i, cuatro[i]);
  }
}

void mostrar_cinco() {
  for (int i = 0; i < 8; i++) 
  {
    lc.setRow(0, i, cinco[i]);
  }
}

void mostrar_seis() {
  for (int i = 0; i < 8; i++) 
  {
    lc.setRow(0, i, seis[i]);
  }
}

void mostrar_siete() {
  for (int i = 0; i < 8; i++) 
  {
    lc.setRow(0, i, siete[i]);
  }
}

void mostrar_ocho() {
  for (int i = 0; i < 8; i++) 
  {
    lc.setRow(0, i, ocho[i]);
  }
}

void mostrar_nueve() {
  for (int i = 0; i < 8; i++) 
  {
    lc.setRow(0, i, nueve[i]);
  }
}

void setup() {

  Serial.begin(9600); // Iniciamos el puerto serie (para debug, no es necesario)
  pinMode(push, INPUT);  // Definimos al pulsador como entrada
  lc.shutdown(0, false); // Enciende la matriz
  lc.setIntensity(0, 6); // Establece el brillo
  lc.clearDisplay(0);    // Apaga matriz

}

void loop() {

  while (digitalRead(push) == LOW); // Detiene el loop hasta que realicemos una pulsación
  Serial.println(contador); // Mostramos el valor del contador por el monitor serie (no es necesaria esta línea)

// Según el valor que tome la variable "contador" llamamos a las funciones correspondientes

  switch (contador) {
    case 0:
      mostrar_cero();
      break;

    case 1:
      mostrar_uno();
      break;

    case 2:
      mostrar_dos();
      break;

    case 3:
      mostrar_tres();
      break;

    case 4:
      mostrar_cuatro();
      break;

    case 5:
      mostrar_cinco();
      break;

    case 6:
      mostrar_seis();
      break;

    case 7:
      mostrar_siete();
      break;

    case 8:
      mostrar_ocho();
      break;

    case 9:
      mostrar_nueve();
      break;

  }

  contador++; // Aumentamos el valor de la variable tras cada pulsación

  if (contador > 9) contador = 0; // Reinicia el contador 

  delay(300);

}
