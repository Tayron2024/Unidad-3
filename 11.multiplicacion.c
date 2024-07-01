/**
 * @file 11.multiplicacion.c
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
    int filasA, columnasA, filasB, columnasB;

    // Pedir al usuario que ingrese las dimensiones de la primera matriz
    printf("Ingrese el número de filas de la primera matriz: ");
    scanf("%d", &filasA);
    printf("Ingrese el número de columnas de la primera matriz: ");
    scanf("%d", &columnasA);

    // Pedir al usuario que ingrese las dimensiones de la segunda matriz
    printf("Ingrese el número de filas de la segunda matriz: ");
    scanf("%d", &filasB);
    printf("Ingrese el número de columnas de la segunda matriz: ");
    scanf("%d", &columnasB);

    // Verificar que las dimensiones de las matrices permitan la multiplicación
    if (columnasA != filasB) {
        printf("No se pueden multiplicar las matrices. El número de columnas de la primera matriz debe ser igual al número de filas de la segunda matriz.\n");
        return 1; // Terminar el programa con código de error
    }

    // Verificar que el tamaño de las matrices sea válido
    if (filasA <= 0 || filasA > MAX_SIZE || columnasA <= 0 || columnasA > MAX_SIZE ||
        filasB <= 0 || filasB > MAX_SIZE || columnasB <= 0 || columnasB > MAX_SIZE) {
        printf("Tamanio de matriz no válido. Debe ser un entero positivo y menor o igual a %d.\n", MAX_SIZE);
        return 1; // Terminar el programa con código de error
    }

    // Definir las matrices con el tamaño ingresado por el usuario
    int matrizA[filasA][columnasA], matrizB[filasB][columnasB], resultado[filasA][columnasB];

    // Pedir al usuario que ingrese los elementos de la primera matriz
    printf("\nIngrese los elementos de la primera matriz (%d x %d):\n", filasA, columnasA);
    for (int i = 0; i < filasA; i++) {
        for (int j = 0; j < columnasA; j++) {
            printf("Elemento (%d, %d): ", i + 1, j + 1);
            scanf("%d", &matrizA[i][j]);
        }
    }

    // Pedir al usuario que ingrese los elementos de la segunda matriz
    printf("\nIngrese los elementos de la segunda matriz (%d x %d):\n", filasB, columnasB);
    for (int i = 0; i < filasB; i++) {
        for (int j = 0; j < columnasB; j++) {
            printf("Elemento (%d, %d): ", i + 1, j + 1);
            scanf("%d", &matrizB[i][j]);
        }
    }

    // Calcular la multiplicación de las matrices
    for (int i = 0; i < filasA; i++) {
        for (int j = 0; j < columnasB; j++) {
            resultado[i][j] = 0; // Inicializar el elemento de resultado en (i, j) a 0
            for (int k = 0; k < columnasA; k++) {
                resultado[i][j] += matrizA[i][k] * matrizB[k][j];
            }
        }
    }

    // Imprimir la matriz resultante (resultado de la multiplicación de matrices)
    printf("\nEl resultado de la multiplicación de las matrices es:\n");
    for (int i = 0; i < filasA; i++) {
        for (int j = 0; j < columnasB; j++) {
            printf("%d ", resultado[i][j]);
        }
        printf("\n");
    }

    return 0;
}
