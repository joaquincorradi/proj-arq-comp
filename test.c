#include "EasyPIO.h"
#include <stdio.h>

void choquef(void);
void disp_binary(int);
void leds(int num);
void no_yet(void);
int menu(void);
void autof(void); // Asumiendo que esta función existe

void main() {
  const char led[] = {14, 15, 10, 23, 24, 25, 8, 7};
  pioInit();
  int i;
  for (i = 0; i < 8; i++) {
    pinMode(led[i], OUTPUT);
  }
  leds(0xFF);

  int choice;
  for (;;) {
    choice = menu();
    switch (choice) {
    case 1:
      autof();
      break;

    case 2:
      choquef();
      break;

    case 3:
      no_yet();
      break;

    case 4:
      no_yet();
      break;

    case 5:

    default:
      printf("Opción no válida.\n");
    }
  }
}

void no_yet(void) { printf("Función no implementada\n"); }

int menu(void) {
  int s;
  do {
    printf("MENU\n");
    printf("1) autof\n");
    printf("2) choquef\n");
    printf("3) opción 3\n");
    printf("4) opción 4\n");
    printf("5) Salir\n");
    printf("Elija una opción: ");
    scanf("%d", &s);
  } while (s < 1 || s > 5);

  return s;
}

void choquef(void) {
  printf("Mostrando choque:\n");
  unsigned char tabla[8] = {0x81, 0x42, 0x24, 0x10, 0x10, 0x24, 0x42, 0x81};
  for (int i = 0; i < 8; i++) {
    disp_binary(tabla[i]);
    leds(~tabla[i]);
    delayMillis(300);
  }
}

void disp_binary(int i) {
  for (int t = 128; t > 0; t = t / 2) {
    if (i & t) {
      printf("*");
    } else {
      printf("_");
    }
  }
  printf("\n");
}

void leds(int num) {
  const char led[] = {14, 15, 10, 23,
                      24, 25, 8,  7}; // Debe declararse nuevamente aquí
  for (int i = 0; i < 8; i++) {
    int numval = (num >> i) & 0x01;
    digitalWrite(led[i], numval);
  }
}