/**
 * @file 1.Matriz4Elementos.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2024-07-01
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    printf("Ingrese el tamaño de la matriz (Solo se permite ingresar matrices cuadradas) \n"); scanf("%d", &n);

    // Definir el tamaño de la matriz cuadratico ingresada por el usuario
    int matriz[n][n];

    // Pedir al usuario que ingrese los valores de la matriz
    printf("Ingrese los elementos de la matriz:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("Elemento (%d, %d): ", i + 1, j + 1); scanf("%d", &matriz[i][j]);
        }
    }

    // Imprimir los elementos de las esquinas
    int esquinaSuperiorIzquierda = matriz[0][0]; int esquinaSuperiorDerecha = matriz[0][n-1];
    int esquinaInferiorIzquierda = matriz[n-1][0]; int esquinaInferiorDerecha = matriz[n-1][n-1];

    printf("\nElemento esquina superior izquierda: %d\n", esquinaSuperiorIzquierda);
    printf("Elemento esquina superior derecha: %d\n", esquinaSuperiorDerecha);
    printf("Elemento esquina inferior izquierda: %d\n", esquinaInferiorIzquierda);
    printf("Elemento esquina inferior derecha: %d\n", esquinaInferiorDerecha);

    return 0;
}
