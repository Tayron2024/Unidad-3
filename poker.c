/**
 * @file 14.cartas.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2024-07-03
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_CARTAS 52
#define NUM_PALOS 4
#define NUM_VALORES 13
#define NUM_JUGADORES 4
#define CARTAS_POR_JUGADOR 5

typedef struct {
    int valor;
    int palo;
} Carta;

// Nombres de los palos
const char *nombres_palos[NUM_PALOS] = {"Corazones", "Diamantes", "Picas", "Tréboles"};

void inicializarBaraja(Carta baraja[]);
void barajar(Carta baraja[]);
void repartir(Carta baraja[], Carta manos[][CARTAS_POR_JUGADOR]);
void imprimirManos(Carta manos[][CARTAS_POR_JUGADOR]);

int main() {
    Carta baraja[NUM_CARTAS];
    Carta manos[NUM_JUGADORES][CARTAS_POR_JUGADOR];

    srand(time(NULL));

    inicializarBaraja(baraja);
    barajar(baraja);
    repartir(baraja, manos);
    imprimirManos(manos);

    return 0;
}

void inicializarBaraja(Carta baraja[]) {
    for (int i = 0; i < NUM_PALOS; i++) {
        for (int j = 0; j < NUM_VALORES; j++) {
            baraja[i * NUM_VALORES + j].valor = j + 1;
            baraja[i * NUM_VALORES + j].palo = i;
        }
    }
}

void barajar(Carta baraja[]) {
    for (int i = 0; i < NUM_CARTAS; i++) {
        int j = rand() % NUM_CARTAS;
        Carta temp = baraja[i];
        baraja[i] = baraja[j];
        baraja[j] = temp;
    }
}

void repartir(Carta baraja[], Carta manos[][CARTAS_POR_JUGADOR]) {
    int cartaActual = 0;
    for (int i = 0; i < NUM_JUGADORES; i++) {
        for (int j = 0; j < CARTAS_POR_JUGADOR; j++) {
            manos[i][j] = baraja[cartaActual++];
        }
    }
}

void imprimirManos(Carta manos[][CARTAS_POR_JUGADOR]) {
    for (int i = 0; i < NUM_JUGADORES; i++) {
        printf("Jugador %d:\n", i + 1);
        printf("-----------------\n");
        for (int j = 0; j < CARTAS_POR_JUGADOR; j++) {
            printf("Carta %d: Valor %d, %s\n", j + 1, manos[i][j].valor, nombres_palos[manos[i][j].palo]);
        }
        printf("\n");
    }
}
