#include <stdio.h>
#include <stdlib.h>
#include "struct.h"
#include "soluciona.h"

//Esta biblioteca contiene tres funciones
//    1.resuelve(): para encontrar el 2 en el laberinto
//    2.par_ordenado(): guarda en un struct la posicion(x,y) de los nuemeros iguales a 1 en los bordes de la matriz
//    3.imprimir_solucion(): para imprimir el laberinto con solo los numeros de la solucion


//Funcion para encontrar el valor '2'
int resuelve(int x, int y, int filas, int columnas, int short(*laberinto)[filas][columnas],int short (*solucion)[filas][columnas]){
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

//Genera par ordenado de entradas al laberinto y los guarda en un struct
node_t *par_ordenado(int fil_len, int col_len, int short (*laberinto)[fil_len][col_len])
{
  node_t *head, *temp, *pointer;
  head = NULL;
  temp = NULL;
  pointer = NULL;
	
	for(int i = 0; i < fil_len; i++){
		for(int j = 0 ; j < col_len; j++){
                            
			if(i == 0 || j == 0 || i == fil_len-1 || j == col_len-1){ //recorre solo los bordes de la matriz
                
                if((*laberinto)[i][j] == 2 || (*laberinto)[i][j] == 1){
            
                pointer = (node_t*)malloc(sizeof(node_t));
				pointer->x = i;
				pointer->y = j;
				pointer->siguiente = NULL;
                //fin del nuevo nodo
                
				if(head == NULL){		//Asignamos el primero valor al primer nodo
					head = pointer;
                }
                else
                {
                   temp = head;						//Recorremos los nodos existentes
                    while(temp->siguiente != NULL){ //hasta el final
                        temp = temp->siguiente;
                    }
                    temp->siguiente = pointer;		//ahora le agregamos el nuevo nodo creado arriba
                }
					
					
              }
			}
		}
	}
    
    return head;
    free(pointer);
	}



void imprimir_solucion(int filas, int columnas,int short (*sol)[filas][columnas]){
  int posicion[2];
  for(int i = 0; i < filas; i++){
    for(int j = 0; j < columnas; j++){
        
        printf("%d ", (*sol)[i][j]);
        if((*sol)[i][j] == 2){
          posicion[0] = i;
          posicion[1] = j;
        }
    }
    printf("\n");
  }
  printf("La posicion del numero 2 es (%d, %d)\n", posicion[0], posicion[1]);
}