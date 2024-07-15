#include <stdio.h>

#define SIZE 3

typedef struct {
    char tablero[SIZE][SIZE];
    char jugadorActual;
    int movimientos;
} Juego;

void inicializarJuego(Juego *juego) {
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            juego->tablero[i][j] = ' ';
    juego->jugadorActual = 'X';
    juego->movimientos = 0;
}

void imprimirTablero(Juego *juego) {
    printf("\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf(" %c ", juego->tablero[i][j]);
            if (j < SIZE - 1) printf("|");
        }
        printf("\n");
        if (i < SIZE - 1) {
            printf("---|---|---\n");
        }
    }
    printf("\n");
}

int verificarGanador(Juego *juego) {
    char jugador = juego->jugadorActual;

    // Verificar filas
    for (int i = 0; i < SIZE; i++)
        if (juego->tablero[i][0] == jugador && juego->tablero[i][1] == jugador && juego->tablero[i][2] == jugador)
            return 1;

    // Verificar columnas
    for (int j = 0; j < SIZE; j++)
        if (juego->tablero[0][j] == jugador && juego->tablero[1][j] == jugador && juego->tablero[2][j] == jugador)
            return 1;

    // Verificar diagonales
    if (juego->tablero[0][0] == jugador && juego->tablero[1][1] == jugador && juego->tablero[2][2] == jugador)
        return 1;
    if (juego->tablero[0][2] == jugador && juego->tablero[1][1] == jugador && juego->tablero[2][0] == jugador)
        return 1;

    return 0;
}

void cambiarJugador(Juego *juego) {
    juego->jugadorActual = (juego->jugadorActual == 'X') ? 'O' : 'X';
}

int main() {
    Juego juego;
    inicializarJuego(&juego);
    
    int fila, col;
    int juegoActivo = 1;

    while (juegoActivo && juego.movimientos < SIZE * SIZE) {
        imprimirTablero(&juego);
        printf("Jugador %c, ingrese fila y columna (0-2): ", juego.jugadorActual);
        scanf("%d %d", &fila, &col);

        // Verificar si la posición es válida
        if (fila >= 0 && fila < SIZE && col >= 0 && col < SIZE && juego.tablero[fila][col] == ' ') {
            juego.tablero[fila][col] = juego.jugadorActual;
            juego.movimientos++;

            if (verificarGanador(&juego)) {
                imprimirTablero(&juego);
                printf("¡Jugador %c gana!\n", juego.jugadorActual);
                juegoActivo = 0;
            } else {
                cambiarJugador(&juego);
            }
        } else {
            printf("Movimiento inválido, intente de nuevo.\n");
        }
    }

    if (juego.movimientos == SIZE * SIZE) {
        imprimirTablero(&juego);
        printf("¡Es un empate!\n");
    }

    return 0;
}
