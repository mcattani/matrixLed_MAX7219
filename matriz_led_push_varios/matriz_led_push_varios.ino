/*
   Sketch de prueba para la Matriz de Led 8*8 con el MAX7219
   usando la librería LedControl.h
   Se utiliza un pulsador conectado al pin 8 (D8).
   La orientación de la barra corresponde a la ubicación de la matriz en la protoboard
   (por eso están invertidas).
   Toda la información y video demostrativo en:
   https://thenerdyapprentice.blogspot.com/
*/

#include <LedControl.h>

LedControl lc = LedControl(11, 13, 10, 1); // Creamos objeto (DIN, CLS, CS, Nro. de dispositivos)

const byte push = 8; // Definimos la constante por la que nos referiremos al pulsador
byte contador = 0; // Variable que usaremos para llevar la cuenta de las pulsaciones

/* Definimos el array (en formato binario) con las líneas correspondientes
   a los puntos en la matriz para generar la imágen
*/

byte uno[8] {
  B00000000,
  B00000100,
  B00000110,
  B10110010,
  B10110010,
  B00011110,
  B00001100,
  B00000000
};
byte dos[8] {
  B00000000,
  B00111100,
  B01000010,
  B01011010,
  B01011010,
  B01001100,
  B00100000,
  B00000000
};
byte tres[8] {
  B00000000,
  B01100100,
  B11111110,
  B10001010,
  B10011010,
  B11101110,
  B11000100,
  B10100000
};
byte cuatro[8] {
  B00000000,
  B00101000,
  B11111110,
  B11111110,
  B00101000,
  B11111110,
  B11111110,
  B00101000
};
byte cinco[8] {
  B00000000,
  B00011100,
  B00111110,
  B01111100,
  B11111000,
  B01111100,
  B00111110,
  B00011100
};
byte seis[8] {
  B00000000,
  B00010000,
  B00111000,
  B01111100,
  B11111110,
  B01111100,
  B00111000,
  B00010000
};
byte siete[8] {
  B00000000,
  B00010000,
  B00111000,
  B10010100,
  B11111110,
  B10010100,
  B00111000,
  B00010000
};
byte ocho[8] {
  B00000000,
  B00010000,
  B00111000,
  B10111100,
  B11111110,
  B10111100,
  B00111000,
  B00010000
};
byte nueve[8] {
  B00000000,
  B01100000,
  B10010000,
  B10010000,
  B01110010,
  B00001010,
  B00000110,
  B00011110
};
byte diez[8] {
  B00000000,
  B00000000,
  B01100100,
  B10010100,
  B10011110,
  B10010100,
  B01100100,
  B00000000
};
byte once[8] {
  B00000000,
  B11000000,
  B11100000,
  B01111110,
  B00000010,
  B00000100,
  B00000000,
  B00000000
};
byte doce[8] {
  B00010000,
  B01010100,
  B00111000,
  B11101110,
  B00111000,
  B01010100,
  B00010000,
  B00000000
};

// Creamos las funciones que llamaremos para mostrar las imágenes en la matriz

void mostrar_uno() {
  for (int i = 0; i < 8; i++) // Itera 8 veces por el array
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

void mostrar_diez() {
  for (int i = 0; i < 8; i++) 
  {
    lc.setRow(0, i, diez[i]);
  }
}

void mostrar_once() {
  for (int i = 0; i < 8; i++) 
  {
    lc.setRow(0, i, once[i]);
  }
}

void mostrar_doce() {
  for (int i = 0; i < 8; i++) 
  {
    lc.setRow(0, i, doce[i]);
  }
}

void setup() {

  Serial.begin(9600); // Iniciamos el puerto serie (para debug, no es necesario)
  pinMode(push, INPUT);  // Definimos al pulsador como entrada
  lc.shutdown(0, false); // Enciende la matriz
  lc.setIntensity(0, 6); // Establece brillo
  lc.clearDisplay(0);    // Apaga la matriz

}

void loop() {

  while (digitalRead(push) == LOW); // Detiene el loop hasta que realicemos una pulsación
  Serial.println(contador); // Mostramos el valor del contador por el monitor serie (no es necesaria esta línea)

// Según el valor que tome la variable "contador" llamamos a las funciones correspondientes

  switch (contador) {
    case 0:
      mostrar_uno();
      break;

    case 1:
      mostrar_dos();
      break;

    case 2:
      mostrar_tres();
      break;

    case 3:
      mostrar_cuatro();
      break;

    case 4:
      mostrar_cinco();
      break;

    case 5:
      mostrar_seis();
      break;

    case 6:
      mostrar_siete();
      break;

    case 7:
      mostrar_ocho();
      break;

    case 8:
      mostrar_nueve();
      break;

    case 9:
      mostrar_diez();
      break;

    case 10:
      mostrar_once();
      break;

    case 11:
      mostrar_doce();
      break;
  }

  contador++; // Aumentamos el valor de la variable tras cada pulsación

  if (contador > 11) contador = 0; // Reinicia el contador 

  delay(300);

}
