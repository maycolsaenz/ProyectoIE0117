#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "struct.h"
#include "obtieneMatriz.h"
#include "soluciona.h"

int main(){
  
  char *informacion = malloc(10000*sizeof(char));
  FILE *archivo = fopen("./laberinto.txt", "r");

  fread(informacion, 10000, sizeof informacion, archivo);
  
  int col_len = cuenta_columnas(informacion);
  int fil_len = cuenta_filas(informacion, col_len);
  node_t *HEAD = NULL;

  
//construccion del laberinto para analizar. Se guardara en el heap.
	int (*laberinto)[fil_len][col_len] = malloc(sizeof*laberinto); 

    for(int m = 0; m < fil_len; m++){
     for(int n = 0; n < col_len; n++){
      (*laberinto)[m][n] = Contruye_matrix(fil_len, col_len, informacion, m, n);
    }
  }

//se rellena la matrix solucion con ceros
  int (*solucion)[fil_len][col_len] = malloc(sizeof*solucion);
  for(int i = 0; i < fil_len; i++){
    for(int j = 0; j < col_len; j++){
      (*solucion)[i][j] = 0;
    }
  }

//Asignacion de coordenadas de entrada al laberinto por los lados
 int a;
 int b;


// HEAD devuelve las coordenadas (x,y) de los unos en los bordes del laberinto como puntos de entrada. 
 HEAD = par_ordenado(fil_len, col_len, laberinto);

  
//Evaluacion de las entradas al laberinto
//******************************  
    while(HEAD != NULL){
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



  fclose(archivo);
  free(solucion);
  free(laberinto);
  free(informacion);  
}
