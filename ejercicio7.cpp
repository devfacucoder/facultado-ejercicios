#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define FILAS 5
#define COLUMNAS 4

void cargarTablaAleatoria(int tabla[FILAS][COLUMNAS]) {
    // Inicializar la semilla para n�meros aleatorios
    srand(time(NULL));
    
    // Llenar la tabla con n�meros aleatorios entre 1 y 200
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            tabla[i][j] = rand() % 200 + 1;  // N�meros aleatorios entre 1 y 200
        }
    }
}

void mostrarSumaFilas(int tabla[FILAS][COLUMNAS]) {
    for (int i = 0; i < FILAS; i++) {
        int suma = 0;
        for (int j = 0; j < COLUMNAS; j++) {
            suma += tabla[i][j];
        }
        printf("Suma de la fila %d: %d\n", i, suma);
    }
}

void calcularPromedioTerceraColumna(int tabla[FILAS][COLUMNAS]) {
    int suma = 0;
    for (int i = 0; i < FILAS; i++) {
        suma += tabla[i][2];  // La tercera columna tiene �ndice 2
    }
    float promedio = (float)suma / FILAS;
    printf("Promedio de la tercera columna: %.2f\n", promedio);
}

void contarNumerosMayores100(int tabla[FILAS][COLUMNAS]) {
    int contador = 0;
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            if (tabla[i][j] > 100) {
                contador++;
            }
        }
    }
    printf("Cantidad de n�meros mayores a 100: %d\n", contador);
}

int main() {
    int tabla[FILAS][COLUMNAS];

    // Cargar la tabla con n�meros aleatorios
    cargarTablaAleatoria(tabla);

    // Mostrar la suma de cada fila
    mostrarSumaFilas(tabla);

    // Calcular el promedio de la tercera columna
    calcularPromedioTerceraColumna(tabla);

    // Contar cu�ntos n�meros son mayores a 100
    contarNumerosMayores100(tabla);

    return 0;
}
