/*
   Sketch de pruebas para la Matriz de Led 8*8 con el chip MAX7219
   usando la librería LedControl.h
   Se utiliza un potenciómetro conectado al pin analógico 2 (A2).
   El valor del potenciómetro se muestra como una barra en la matriz de led.
   La orientación de la barra corresponde a la ubicación de la matriz en la protoboard
   (por eso está invertida).
   Toda la información y video de demostración en:
   https://thenerdyapprentice.blogspot.com/
*/

#include <LedControl.h>

LedControl lc = LedControl(11, 13, 10, 1); // Creamos objeto (DIN, CLS, CS, Nro. de dispositivos)

const int pot = A2; // Nuestro potenciómetro
int valor = 0; // Variable que usaremos luego junto a la función map()

/* Definimos el array (en formato binario) con las líneas correspondientes
   a los puntos en la matriz para generar la imágen
*/

byte cero[8] {
  B11111111,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B11111111
};

byte uno[8] {
  B11111111,
  B00000000,
  B10000000,
  B10000000,
  B10000000,
  B10000000,
  B00000000,
  B11111111
};

byte dos[8] {
  B11111111,
  B00000000,
  B11000000,
  B11000000,
  B11000000,
  B11000000,
  B00000000,
  B11111111
};

byte tres[8] {
  B11111111,
  B00000000,
  B11100000,
  B11100000,
  B11100000,
  B11100000,
  B00000000,
  B11111111
};

byte cuatro[8] {
  B11111111,
  B00000000,
  B11110000,
  B11110000,
  B11110000,
  B11110000,
  B00000000,
  B11111111
};

byte cinco[8] {
  B11111111,
  B00000000,
  B11111000,
  B11111000,
  B11111000,
  B11111000,
  B00000000,
  B11111111
};

byte seis[8] {
  B11111111,
  B00000000,
  B11111100,
  B11111100,
  B11111100,
  B11111100,
  B00000000,
  B11111111
};

byte siete[8] {
  B11111111,
  B00000000,
  B11111110,
  B11111110,
  B11111110,
  B11111110,
  B00000000,
  B11111111
};

byte ocho[8] {
  B11111111,
  B00000000,
  B11111111,
  B11111111,
  B11111111,
  B11111111,
  B00000000,
  B11111111
};

// Creamos las funciones que llamaremos luego para mostrar la barra de progreso en la matriz

void mostrar_cero() {
  for (int i = 0; i < 8; i++) // Itera 8 veces por el array
  {
    lc.setRow(0, i, cero[i]);
  }
}

void mostrar_uno() {
  for (int i = 0; i < 8; i++) // Itera 8 veces por el array
  {
    lc.setRow(0, i, uno[i]);
  }
}

void mostrar_dos() {
  for (int i = 0; i < 8; i++) // Itera 8 veces por el array
  {
    lc.setRow(0, i, dos[i]);
  }
}

void mostrar_tres() {
  for (int i = 0; i < 8; i++) // Itera 8 veces por el array
  {
    lc.setRow(0, i, tres[i]);
  }
}

void mostrar_cuatro() {
  for (int i = 0; i < 8; i++) // Itera 8 veces por el array
  {
    lc.setRow(0, i, cuatro[i]);
  }
}

void mostrar_cinco() {
  for (int i = 0; i < 8; i++) // Itera 8 veces por el array
  {
    lc.setRow(0, i, cinco[i]);
  }
}

void mostrar_seis() {
  for (int i = 0; i < 8; i++) // Itera 8 veces por el array
  {
    lc.setRow(0, i, seis[i]);
  }
}

void mostrar_siete() {
  for (int i = 0; i < 8; i++) // Itera 8 veces por el array
  {
    lc.setRow(0, i, siete[i]);
  }
}

void mostrar_ocho() {
  for (int i = 0; i < 8; i++) // Itera 8 veces por el array
  {
    lc.setRow(0, i, ocho[i]);
  }
}


void setup() {

  Serial.begin(9600);   // Iniciamos el puerto serie (sirve para debug)
  lc.shutdown(0, false);    // Enciende la matriz
  lc.setIntensity(0, 6);   // Establece brillo
  lc.clearDisplay(0);     // Apaga matriz

}

void loop() {
/* Mapeamos la entrada del potenciómetro para adaptarlo al rango de barras que muestra la matriz;
   utilizamos el valor de 9 en vez de 8 (cantidad de barras) para evitar las fluctuaciones de la lectura del
   potenciómetro. Quizás mi potenciómetro es de mala calidad :)
*/
  valor = map(analogRead(pot), 0, 1023, 0, 9); // Mapeamos los valores de potenciómetro y guardamos el resultado en la variable 
  Serial.println(analogRead(pot)); // Esta línea no es necesaria (sirve para debug)

// Según el valor que obtenemos de mapear el input del potenciómetro llamaremos a la función correspondiente

  switch (valor) {
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
  }

  delay(200);

}
