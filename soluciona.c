#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "struct.h"
#include "soluciona.h"

//Esta biblioteca contiene dos funciones
//    1.resuelve(): para encontrar el 2 en el laberinto
//    2.imprimir_solucion: para imprimir el laberinto con solo los numeros de la solucion


//Funcion para encontrar el valor '2'
int resuelve(int x, int y, int filas, int columnas, int (*laberinto)[filas][columnas],int (*solucion)[filas][columnas]){
  if((*laberinto)[x][y] == 2)
  {
    (*solucion)[x][y] = 2;
    return 1;
  }

  if(x>=0 && y>=0 && x<filas && y<columnas && (*solucion)[x][y] == 0 && (*laberinto)[x][y] == 1)
  {
    (*solucion)[x][y] = 1; //condiciones cumplidas -> se guarda la trayectoria
   
    //prueba si valor ABAJO es igual a 1;
    if(resuelve(x+1, y, filas, columnas, laberinto, solucion) == 1)
    {
      return 1;
    }
    //prueba si valor ARRIBA es igual a 1;
    if(resuelve(x-1, y, filas, columnas, laberinto, solucion) == 1)
    {
      return 1;
    }
            
    //prueba si valor IZQUIERDA es igual a 1;
    if(resuelve(x, y-1, filas, columnas, laberinto, solucion) == 1)
    {
      return 1;
    }
      
    //prueba si valor a la DERECHA es igual a 1;
    if(resuelve(x, y+1, filas, columnas, laberinto, solucion) == 1)
    {
      return 1;
    }

   //Si ninguna se cumple guardar cero e intentar de nuevo
   (*solucion)[x][y] = 0;
   return 0;    
  }
  return 0;
}

//genera par ordenado de entradas al laberinto
node_t *par_ordenado(int fil_len, int col_len, int (*laberinto)[fil_len][col_len])
{
  node_t *head, *temp, *pointer;
  head = NULL;
  temp = NULL;
  pointer = NULL;
	
	for(int i = 0; i < fil_len; i++){
		for(int j = 0 ; j < col_len; j++){
                            
			if(i == 0 || j == 0 || i == fil_len-1 || j == col_len-1){
                
                if((*laberinto)[i][j] == 2 || (*laberinto)[i][j] == 1){
            
                pointer = (node_t*)malloc(sizeof(node_t));
				pointer->x = i;
				pointer->y = j;
				pointer->siguiente = NULL;
                //fin del nodo aislado
                
				if(head == NULL){
					head = pointer;
                }
                else
                {
                   temp = head;
                    while(temp->siguiente != NULL){
                        temp = temp->siguiente;
                    }
                    temp->siguiente = pointer;
                }
					
					
              }
			}
		}
	}
    
    return head;
    free(pointer);
	}


//Funcion para imprimir la solucion
void imprimir_solucion(int filas, int columnas,int (*sol)[filas][columnas]){
  for(int i = 0; i < filas; i++){
    for(int j = 0; j < columnas; j++){
        
        printf("%d ", (*sol)[i][j]);
    }
    printf("\n");
  }

}