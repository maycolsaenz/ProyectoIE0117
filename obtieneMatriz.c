#include <stdio.h>
#include <string.h>
#include "struct.h"
#include "obtieneMatriz.h"

//Esta biblioteca contiene 3 funciones
//    1.cuenta_columnas(): con base en la entrada tipo string desde el laberinto.txt
//    2.cuenta_filas(): con base en la entrada tipo string desde el laberinto.txt
//    3. Construye_matrix(): genera una matriz de integers con base en el laberinto.txt y las filas y columnas contadas.

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
