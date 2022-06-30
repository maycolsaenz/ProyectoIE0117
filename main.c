#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//Funciones antes del main(){}
struct Nodo{
	int x;
	int y;
	struct Nodo *siguiente;
};

typedef struct Nodo node_t;


int cuenta_columnas(char *puntero){
    int n = 0;
    while(puntero[n] != '\n'){
    n++;
  }
  int columnas = (n + 1)/2;
  return columnas;
}


int cuenta_filas(char *puntero, int columnas){
  int len = strlen(puntero);
  int n = 0;
  for(int i = 0; i < len; i++){
    if(i%columnas == 0){
      n++;
    }
  }
  int filas = n/2; 

  return filas;
}


int Contruye_matrix(int filas, int columnas, char *puntero, int x, int y)
{
  int matrix[filas][columnas];
  int n = 0;
  for(int i = 0; i < filas; i++)
  {
    
    for(int j = 0; j < columnas; j++)
    {
     
     //cambio a integer
     if(puntero[n] == '1'){
        matrix[i][j] = 1; 
     } 
      else{
         if(puntero[n] == '2'){
          matrix[i][j] = 2; 
     } 
     else{matrix[i][j] = 0;}}
    n += 2; 
    }   
  }

  return matrix[x][y];
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



int main(){
  
  char *informacion = malloc(10000*sizeof(char));
  FILE *archivo = fopen("./laberinto.txt", "r");

  fread(informacion, 10000, sizeof informacion, archivo);
  
  int col_len = cuenta_columnas(informacion);
  int fil_len = cuenta_filas(informacion, col_len);
  node_t *HEAD = NULL;

  

  //construccion del laberinto para analizar
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
 int x;
 int y; 

 HEAD = par_ordenado(fil_len, col_len, laberinto);
//mostrar_pares(HEAD);
  
//Evaluacion de las entradas al laberinto
//******************************  
    while(HEAD != NULL){
        x = HEAD->x;
        y = HEAD->y;
        
        
    if(resuelve(x, y, fil_len, col_len, laberinto, solucion) == 1)
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
    
    
    
    
    
    
    /*
    
    printf("Filas: %d Columnas: %d. Posicion (%d, %d): %d \n", fil_len, col_len, x, y, (*laberinto)[x][y]);
        printf("Solucion encontrada!\n");
        imprimir_solucion(fil_len, col_len, solucion);
        printf("(%d, %d)\n", HEAD->x, HEAD->y);
        //break; //para no seguir evaluando los demas puntos de la lista.
    
    
    */
       



  fclose(archivo);
  free(solucion);
  free(laberinto);
  free(informacion);  
}
