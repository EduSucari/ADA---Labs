# Máximo Subarreglo

Implementación en C del problema del máximo subarreglo utilizando tres enfoques diferentes:

- **Algoritmo cúbico**: `O(n³)`
- **Algoritmo cuadrático**: `O(n²)`
- **Algoritmo de Kadane**: `O(n)`

Los arreglos utilizados en las pruebas se generan aleatoriamente con valores enteros en el rango de `-50` a `50`.

## Características

- Generación automática de arreglos de diferentes tamaños.
- Medición del tiempo de ejecución utilizando `time.h` y `clock()`.
- Pruebas con tamaños `n = 1000, 2000, 4000 y 8000`.
- El experimento fue elaborado con los equipos de la escuela de Computer Science de la UNSA, por lo que no es posible acceder a las especificaciones del sistema por el momento.

## Resultados

Los resultados de las mediciones y el análisis experimental se encuentran en la carpeta:
    
    /resultados

Dentro de esta carpeta se incluye un archivo Excel con los tiempos obtenidos, las razones de crecimiento y las predicciones correspondientes.

## Compilación

Para compilar el programa utilizando GCC:

```bash
gcc main.c -o max_subarray
```
Una vez compilado solo queda ejecutar con:

```bash
./max_subarray
```

## Conclusión

El trabajo permite comparar experimentalmente cómo influye la complejidad algorítmica en el rendimiento. En los resultados se puede observar que Kadane (O(n)) es la solución más eficiente para arreglos grandes, mientras que los algoritmos cuadrático y cúbico presentan un crecimiento mucho mayor en su tiempo de ejecución.