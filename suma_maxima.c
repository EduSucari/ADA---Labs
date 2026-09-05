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
    srand(time(NULL));

    // Tamaños de prueba
    int tamanos[] = {1000, 2000, 4000, 8000};
    int cantidad_tamanos = 4;

    printf("%-10s %-20s %-20s %-20s\n",
           "N",
           "CUBIC O(n^3)",
           "CUADRATIC O(n^2)",
           "LINEAL O(n)");

    printf("---------------------------------------------------------------------\n");

    for (int i = 0; i < cantidad_tamanos; i++) {
        int n = tamanos[i];
        int* arr = (int*)malloc(n * sizeof(int));

        if (arr == NULL) {
            printf("Error al reservar memoria.\n");
            return 1;
        }

        // Array aleatorio
        generar_array(arr, n);

        // Mediciones
        double tiempo_cubic =
            medir_tiempo(suma_max_cubic, arr, n);

        double tiempo_quadratic =
            medir_tiempo(suma_max_quadratic, arr, n);

        double tiempo_linear =
            medir_tiempo(suma_max_linear, arr, n);

        printf("%-10d %-20.6f %-20.6f %-20.6f\n",
               n,
               tiempo_cubic,
               tiempo_quadratic,
               tiempo_linear);

        free(arr);
    }

    return 0;
}