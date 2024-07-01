/**
 * @file 8.FilasColumnas.c
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

    // Pedir al usuario que ingrese el número de filas y columnas de la matriz
    printf("Ingrese el número de filas de la matriz: ");
    scanf("%d", &filas);
    printf("Ingrese el número de columnas de la matriz: ");
    scanf("%d", &columnas);

    // Verificar que el tamaño de la matriz sea válido
    if (filas <= 0 || filas > MAX_SIZE || columnas <= 0 || columnas > MAX_SIZE) {
        printf("Tamanio de matriz no válido. Debe ser un entero positivo y menor o igual a %d.\n", MAX_SIZE);
        return 1; // Terminar el programa con código de error
    }

    // Definir la matriz con el tamaño ingresado por el usuario
    int matriz[filas][columnas];

    // Pedir al usuario que ingrese los valores de la matriz
    printf("Ingrese los elementos de la matriz (%d x %d):\n", filas, columnas);
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            printf("Elemento (%d, %d): ", i + 1, j + 1);
            scanf("%d", &matriz[i][j]);
        }
    }

    // Presentar el número de filas y columnas de la matriz
    printf("\nLa matriz ingresada tiene %d filas y %d columnas.\n", filas, columnas);

    return 0;
}
