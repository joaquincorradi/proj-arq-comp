#include "EasyPIO.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void delay(int);
void displayBinary(int);
void leds(int);
void passwordValidation();
void menu();
void autoFantastico();
void choque();

int main() { pioInit(); }

/*
 * Funcion que genera un retardo en el programa
 * @param time: tiempo en milisegundos
 */
void delay(int time) {
  int i;
  unsigned int j;
  for (i = time; i > 0; --i)
    for (j = 0; j < 65535; ++j)
      ;
}

/*
 * Muestra la representacion binaria de un numero en pantalla
 * @param i: numero a mostrar en binario
 */
void displayBinary(int i) {
  int t;
  for (t = 128; t > 0; t = t / 2)
    if (i & t)      // Si el bit en t esta encendido
      printf("1 "); // Muestra 1
    else            // Si el bit en t esta apagado
      printf("0 "); // Muestra 0
  printf("\n");
}

/*
 * Muestra la representacion binaria de un numero en los leds
 * @param num: numero a mostrar en binario
 */
void leds(int num) {
  const char led[] = {14, 15, 10, 23, 24, 25, 8, 7};
  for (int i = 0; i < 8; i++) { // Recorre los 8 bits del numero
    int numval = (num >> i) & 0x01;
    digitalWrite(led[i], numval); // Enciende o apaga el led
  }
}

/*
 * Muestra un efecto de auto fantastico en los leds
 */
void autoFantastico() {
  printf("Mostrando auto fantastico:\n");
  unsigned char tabla[8] = {0x81, 0x42, 0x24, 0x18, 0x18, 0x24, 0x42, 0x81};
  for (int i = 0; i < 8; i++) { // Muestra el efecto de izquierda a derecha
    disp_binary(tabla[i]);
    leds(tabla[i]);
    delayMillis(300);
  }
  for (int i = 6; i > 0; i--) { // Muestra el efecto de derecha a izquierda
    disp_binary(tabla[i]);
    leds(tabla[i]);
    delayMillis(300);
  }
}

/*
 * Muestra un efecto de choque en los leds
 */
void choque() {
  printf("Mostrando choque:\n");
  unsigned char tabla[8] = {0x81, 0x42, 0x24, 0x10, 0x10, 0x24, 0x42, 0x81};
  for (int i = 0; i < 8; i++) {
    disp_binary(tabla[i]);
    leds(~tabla[i]);
    delayMillis(300);
  }
}

/*
 * Muestra un menu con las opciones disponibles
 */
void menu() {
  int opcion;
  do {
    printf("Menu:\n");
    printf("1. Mostrar auto fantastico\n");
    printf("2. Mostrar choque\n");
    printf("3. Tercera secuencia de luces (falta crear)\n");
    printf("4. Cuarta secuencia de luces (falta crear)\n");
    printf("5. Salir\n");
    printf("Opcion: ");
    scanf("%d", &opcion);
    switch (opcion) {
    case 1:
      autoFantastico();
      break;
    case 2:
      choque();
      break;
    case 3:
      printf("Falta implementar\n");
      break;
    case 4:
      printf("Falta implementar\n");
      break;
    case 5:
      printf("Saliendo...\n");
      delay(1000);
      break;
    default:
      printf("Opcion no valida\n");
      break;
    }
  } while (opcion != 5);
}