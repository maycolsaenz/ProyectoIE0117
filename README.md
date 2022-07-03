# 🧩Corredor del laberinto

Introduce tu propio laberinto en el archivo de texto y obtén la solución. Código fuente en C.

## Pasos previos
```
1. Clona el proyecto a un directorio local.

2. Ubícate en el directorio del proyecto usando la consola de Linux.
```
## Ejecutando el programa 
  
1. Abre el archivo `laberinto.txt` para modificarlo o agregar tu propia version del laberinto que quieres resolver.
    
2. Recuerda que el número `2` marca el lugar que se quiere encontrar dentro del laberinto.
    
3. Digita `make` para compilar y `make exec` para ejecutar podrás ver la ruta solución.   

## Estructura del programa

| Código fuente | Librerías |
| :------|:------------|
| main.c | struct.h |
| obtieneMatriz.c | obtieneMatriz.h |
| Soluciona.c | Soluciona.h|

### Descripcion de archivos
<details>
    <summary>main.c (iniciador)</summary>
    <ol>
        <li>Lee laberinto.txt</li>
        <li>Aloja espacio en el heap para el laberinto.</li>
        <li>Genera matriz de ceros del mismo tamaño.</li>
        <li>Llama a las funciones de las bibliotecas.</li>
    </ol>
</details>


<details>
    <summary>obtieneMatriz.c (biblioteca)</summary>
    <ol>
        <li>cuenta_columnas(): cuenta las columnas buscando \n.</li>
        <li>cuenta_filas(): cuenta filas con base en la longitud total y cantidad de columnas.</li>
        <li>Contruye_matrix(): devuelve matriz laberinto de integers.</li>
    </ol>
</details>
<details>
    <summary>soluciona.c (biblioteca)</summary>
    <ol>
        <li>resuelve(): evalúa cada posible entrada al laberinto, devuelve el camino hacia el 2.</li>
        <li>par_ordenado(): devuelve todos los puntos de ingreso en los bordes del laberinto.</li>
        <li>imprimir_solucion(): imprime un camino hacia el 2, reemplaza el resto con ceros.</li>
    </ol>    
</details>


