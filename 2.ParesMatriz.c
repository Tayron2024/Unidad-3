/**
 * @file 2.ParesMatriz.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2024-07-01
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <stdio.h>
#include <stdio.h>

int main() {
    int n;
    printf("Ingrese el tamaño de la matriz cuadrada: ");
    scanf("%d", &n);

    // Definir la matriz con el tamaño ingresado por el usuario
    int matriz[n][n];

    // Pedir al usuario que ingrese los valores de la matriz
    printf("Ingrese los elementos de la matriz:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("Elemento (%d, %d): ", i + 1, j + 1);
            scanf("%d", &matriz[i][j]);
        }
    }

    // Imprimir los elementos pares de la matriz
    printf("\nElementos pares de la matriz:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (matriz[i][j] % 2 == 0) {
                printf("%d ", matriz[i][j]);
            }
        }
    }
    printf("\n");

    return 0;
}
