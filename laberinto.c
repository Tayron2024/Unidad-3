/**
 * @file laberinto.c
 * @author Tayron Morales
 * @brief 
 * @version 0.1
 * @date 2024-07-16
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 13
#define WALL '#'
#define PATH ' '
#define VISITED '.'

// Estructura para representar una posición en el laberinto
typedef struct {
    int x, y;
} Position;

// Estructura para el laberinto
typedef struct {
    char grid[SIZE][SIZE];
} Maze;

// Funciones
void initializeMaze(Maze *maze);
void generateMaze(Maze *maze);
void printMaze(Maze *maze);
int solveMaze(Maze *maze, Position start, Position end);
int isSafe(Maze *maze, int x, int y);
void markSolution(Maze *maze, Position *path, int stepCount);

int main() {
    srand(time(NULL)); // Inicializar el generador de números aleatorios

    Maze maze;
    initializeMaze(&maze);
    generateMaze(&maze);
    
    printf("Laberinto generado:\n");
    printMaze(&maze);
    
    Position start = {1, 1}; // Posición inicial
    Position end = {SIZE - 2, SIZE - 2}; // Posición final

    if (solveMaze(&maze, start, end)) {
        printf("\nSolución encontrada:\n");
        printMaze(&maze);
    } else {
        printf("\nNo se encontró solución.\n");
    }

    return 0;
}

// Inicializa el laberinto con muros
void initializeMaze(Maze *maze) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (i % 2 == 0 && j % 2 == 0) {
                maze->grid[i][j] = WALL; // Muros
            } else {
                maze->grid[i][j] = PATH; // Espacio vacío
            }
        }
    }
    // Entradas y salidas
    maze->grid[1][1] = PATH;
    maze->grid[SIZE - 2][SIZE - 2] = PATH;
}

// Genera el laberinto usando un algoritmo aleatorio
void generateMaze(Maze *maze) {
    for (int i = 1; i < SIZE - 1; i += 2) {
        for (int j = 1; j < SIZE - 1; j += 2) {
            if (i < SIZE - 2) {
                int dir = rand() % 4; // Direcciones aleatorias
                if (dir == 0 && j < SIZE - 2) {
                    maze->grid[i][j + 1] = PATH;
                } else if (dir == 1 && i < SIZE - 2) {
                    maze->grid[i + 1][j] = PATH;
                } else if (dir == 2 && j > 1) {
                    maze->grid[i][j - 1] = PATH;
                } else if (dir == 3 && i > 1) {
                    maze->grid[i - 1][j] = PATH;
                }
            }
        }
    }
}

// Imprime el laberinto
void printMaze(Maze *maze) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%c", maze->grid[i][j]);
        }
        printf("\n");
    }
}

// Resuelve el laberinto usando búsqueda en profundidad
int solveMaze(Maze *maze, Position start, Position end) {
    Position stack[SIZE * SIZE];
    int top = -1;
    stack[++top] = start;
    int stepCount = 0;

    while (top >= 0) {
        Position current = stack[top--];

        if (current.x == end.x && current.y == end.y) {
            return 1; // Solución encontrada
        }

        if (isSafe(maze, current.x, current.y)) {
            maze->grid[current.x][current.y] = VISITED;
            stepCount++;
            // Agregar posiciones adyacentes
            stack[++top] = (Position){current.x + 1, current.y}; // Abajo
            stack[++top] = (Position){current.x - 1, current.y}; // Arriba
            stack[++top] = (Position){current.x, current.y + 1}; // Derecha
            stack[++top] = (Position){current.x, current.y - 1}; // Izquierda
        }
    }

    return 0; // No se encontró solución
}

// Verifica si una posición es segura para moverse
int isSafe(Maze *maze, int x, int y) {
    return (x >= 0 && x < SIZE && y >= 0 && y < SIZE && maze->grid[x][y] == PATH);
}