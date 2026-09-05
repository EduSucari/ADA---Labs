#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generar_array(int* array, int n) {
    for (int i = 0; i < n; i++) {
        array[i] = (rand() % 101) - 50;
    }
}

int suma_max_cubic(int* array, int size) {
    int max = array[0];
    for (int i = 0; i < size; i++) {
        for (int j = i; j < size; j++) {
            int suma = 0;
            for (int k = i; k <= j; k++) {
                suma += array[k];
            }
            if (suma > max) {
                max = suma;
            }
        }
    }
    return max;
}

int suma_max_quadratic(int* array, int size) {
    int max = array[0];
    for (int i = 0; i < size; i++) {
        int suma = 0;
        for (int j = i; j < size; j++) {
            suma += array[j];
            if (suma > max) {
                max = suma;
            }
        }
    }
    return max;
}

int suma_max_linear(int* array, int size) {
    int current = array[0];
    int global = array[0];

    for (int i = 1; i < size; i++) {
        current = (array[i] > (array[i] + current))
                    ? array[i]
                    : array[i] + current;
        global = (current > global)
                    ? current
                    : global;
    }
    return global;
}

double medir_tiempo(int (*funcion)(int*, int), int* array, int n) {
    clock_t inicio, fin;
    inicio = clock();
    funcion(array, n);
    fin = clock();
    return (double)(fin - inicio) / CLOCKS_PER_SEC;
}

int main() {
    return 0;
}