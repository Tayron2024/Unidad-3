/**
 * @file 7.Simetrica.c
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
#include <stdbool.h> 
// Incluir biblioteca para usar booleanos

#define MAX_SIZE 100

int main() {
    int n;
    printf("Ingrese el tamanio de la matriz cuadrada (máx. %d): ", MAX_SIZE);
    scanf("%d", &n);

    // Verificar que el tamaño de la matriz sea válido
    if (n <= 0 || n > MAX_SIZE) {
        printf("Tamanio de matriz no válido. Debe ser un entero positivo y menor o igual a %d.\n", MAX_SIZE);
        return 1; // Terminar el programa con código de error
    }

    // Definir la matriz con el tamaño ingresado por el usuario
    int matriz[MAX_SIZE][MAX_SIZE];

    // Pedir al usuario que ingrese los valores de la matriz
    printf("Ingrese los elementos de la matriz:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("Elemento (%d, %d): ", i + 1, j + 1);
            scanf("%d", &matriz[i][j]);
        }
    }

    // Verificar si la matriz es simétrica
    bool es_simetrica = true;
    for (int i = 0; i < n && es_simetrica; i++) {
        for (int j = 0; j < n; j++) {
            if (matriz[i][j] != matriz[j][i]) {
                es_simetrica = false;
                break; // Salir del bucle interior
            }
        }
    }

    // Imprimir el resultado
    if (es_simetrica) {
        printf("\nLa matriz ingresada es simétrica.\n");
    } else {
        printf("\nLa matriz ingresada NO es simétrica.\n");
    }

    return 0;
}
