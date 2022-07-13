#include <stdio.h>
#include <stdlib.h>
#include "struct.h"
#include "obtieneMatriz.h"
#include "soluciona.h"

int main(){
  //Seccion 1: lectura del archivo laberinto.txt
	
  //Determina el tamano total del archivo.
  FILE *archivo_aux = fopen("./laberinto.txt", "r");
  int contador = 0;
  while(fscanf(archivo_aux, "%*c") != EOF){
    contador++;
  }
  printf("n = %d\n", contador);
  

  FILE *archivo = fopen("./laberinto.txt", "r");
  char *informacion = malloc(contador*sizeof(char));
  fread(informacion, sizeof(char), contador, archivo);
  //fread(memoria, tamano de cada elemento a ser leido, cantidad de elementos, puntero al archivo)
  //Una mejora es poder modificar el espacio de memoria segun el tamano de la matriz. 
  //Investigar uso de calloc.
  int col_len = cuenta_columnas(informacion);
  int fil_len = cuenta_filas(informacion, col_len); 
	
//Seccion 2: construccion del laberinto para analizar. Se guardara en el heap.
	int (*laberinto)[fil_len][col_len] = malloc(sizeof*laberinto); 
	for(int m = 0; m < fil_len; m++){
     for(int n = 0; n < col_len; n++){
      (*laberinto)[m][n] = Contruye_matrix(fil_len, col_len, informacion, m, n);
    }
  }
//Seccion 3: se rellena la matrix solucion con ceros
  int (*solucion)[fil_len][col_len] = malloc(sizeof*solucion);
  for(int i = 0; i < fil_len; i++){
    for(int j = 0; j < col_len; j++){
      (*solucion)[i][j] = 0;
    }
  }

//seccion 4: HEAD devuelve las coordenadas (x,y) de los unos en los bordes del laberinto como puntos de entrada.
 node_t *HEAD = NULL;
 HEAD = par_ordenado(fil_len, col_len, laberinto);

//Seccion 5: Evaluacion de las entradas al laberinto
//Asignacion de coordenadas de entrada al laberinto por los lados
 int a;
 int b;
	
    while(HEAD != NULL){ //llamada a los pares ordenados de entrada al laberinto
        a = HEAD->x;
        b = HEAD->y;
    if(resuelve(a, b, fil_len, col_len, laberinto, solucion) == 1)
    {
        printf("Solucion encontrada!\n");
        printf("Punto de entrada: (%d, %d)\n", HEAD->x, HEAD->y);
        imprimir_solucion(fil_len, col_len, solucion);
        break;
    }
		
    HEAD = HEAD->siguiente;
}
    
    if(HEAD == NULL)
    {
     printf("No hay solucion\n"); 
    }     
//seccion 6: liberacion de memoria
  fclose(archivo_aux);
  fclose(archivo);
  free(solucion);
  free(laberinto);
  free(informacion);  

return 0;
}