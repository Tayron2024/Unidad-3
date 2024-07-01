/**
 * @file 10.restaMarices.c
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

#define MAX_SIZE 100

int main() {
    int filas, columnas;

    // Pedir al usuario que ingrese el número de filas y columnas de las matrices
    printf("Ingrese el número de filas de las matrices: ");
    scanf("%d", &filas);
    printf("Ingrese el número de columnas de las matrices: ");
    scanf("%d", &columnas);

    // Verificar que el tamaño de las matrices sea válido
    if (filas <= 0 || filas > MAX_SIZE || columnas <= 0 || columnas > MAX_SIZE) {
        printf("Tamanio de matriz no válido. Debe ser un entero positivo y menor o igual a %d.\n", MAX_SIZE);
        return 1; // Terminar el programa con código de error
    }

    // Definir las matrices con el tamaño ingresado por el usuario
    int matriz1[filas][columnas], matriz2[filas][columnas], resta[filas][columnas];

    // Pedir al usuario que ingrese los elementos de la primera matriz
    printf("\nIngrese los elementos de la primera matriz (%d x %d):\n", filas, columnas);
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            printf("Elemento (%d, %d): ", i + 1, j + 1);
            scanf("%d", &matriz1[i][j]);
        }
    }

    // Pedir al usuario que ingrese los elementos de la segunda matriz
    printf("\nIngrese los elementos de la segunda matriz (%d x %d):\n", filas, columnas);
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            printf("Elemento (%d, %d): ", i + 1, j + 1);
            scanf("%d", &matriz2[i][j]);
        }
    }

    // Calcular la resta de las matrices
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            resta[i][j] = matriz1[i][j] - matriz2[i][j];
        }
    }

    // Imprimir la matriz resultante (resta de matrices)
    printf("\nLa resta de las matrices es:\n");
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            printf("%d ", resta[i][j]);
        }
        printf("\n");
    }

    return 0;
}
