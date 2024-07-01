/**
 * @file 13.potencia.c
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

// Función para multiplicar dos matrices
void multiplicarMatrices(int filasA, int columnasA, int filasB, int columnasB, int matrizA[filasA][columnasA], int matrizB[filasB][columnasB], int resultado[filasA][columnasB]) {
    // Verificar que las dimensiones permitan la multiplicación de matrices
    if (columnasA != filasB) {
        printf("No se pueden multiplicar las matrices. El número de columnas de la primera matriz debe ser igual al número de filas de la segunda matriz.\n");
        return;
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
}

// Función para elevar una matriz a una potencia entera positiva
void potenciarMatriz(int filas, int columnas, int matriz[filas][columnas], int exponente, int resultado[filas][columnas]) {
    // Caso base: si el exponente es 0, la matriz resultante es la matriz identidad
    if (exponente == 0) {
        for (int i = 0; i < filas; i++) {
            for (int j = 0; j < columnas; j++) {
                resultado[i][j] = (i == j) ? 1 : 0; // Matriz identidad
            }
        }
        return;
    }

    // Caso base: si el exponente es 1, la matriz resultante es la matriz original
    if (exponente == 1) {
        for (int i = 0; i < filas; i++) {
            for (int j = 0; j < columnas; j++) {
                resultado[i][j] = matriz[i][j];
            }
        }
        return;
    }

    // Algoritmo para potenciación de matrices
    int matrizTemporal[filas][columnas];
    potenciarMatriz(filas, columnas, matriz, exponente / 2, matrizTemporal);
    multiplicarMatrices(filas, columnas, filas, columnas, matrizTemporal, matrizTemporal, resultado);

    if (exponente % 2 != 0) {
        int resultadoTemporal[filas][columnas];
        multiplicarMatrices(filas, columnas, filas, columnas, resultado, matriz, resultadoTemporal);
        for (int i = 0; i < filas; i++) {
            for (int j = 0; j < columnas; j++) {
                resultado[i][j] = resultadoTemporal[i][j];
            }
        }
    }
}

// Función para imprimir una matriz
void imprimirMatriz(int filas, int columnas, int matriz[filas][columnas]) {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int filas, columnas, exponente;

    // Pedir al usuario que ingrese las dimensiones de la matriz
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
    int matriz[filas][columnas], resultado[filas][columnas];

    // Pedir al usuario que ingrese los elementos de la matriz
    printf("\nIngrese los elementos de la matriz (%d x %d):\n", filas, columnas);
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            printf("Elemento (%d, %d): ", i + 1, j + 1);
            scanf("%d", &matriz[i][j]);
        }
    }

    // Pedir al usuario que ingrese el exponente al que se quiere elevar la matriz
    printf("\nIngrese el exponente al que desea elevar la matriz: ");
    scanf("%d", &exponente);

    // Calcular la potencia de la matriz
    potenciarMatriz(filas, columnas, matriz, exponente, resultado);

    // Imprimir la matriz resultante (resultado de la potenciación de la matriz)
    printf("\nEl resultado de elevar la matriz a la potencia %d es:\n", exponente);
    imprimirMatriz(filas, columnas, resultado);

    return 0;
}
