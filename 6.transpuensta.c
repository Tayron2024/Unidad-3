/**
 * @file 6.transpuensta.c
 * @author Tayron Morales (mtyaronfernando@gmail.com)
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
    printf("Ingrese el tamanio de la matriz cuadrada: ");
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

    // Calcular e imprimir la matriz transpuesta
    printf("\nMatriz transpuesta:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matriz[j][i]);  // Intercambio de filas por columnas
        }
        printf("\n");
    }

    return 0;
}
