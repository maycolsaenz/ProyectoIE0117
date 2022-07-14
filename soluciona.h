#ifndef SOLUCIONA_H
#define SOLUCIONA_H    

node_t *par_ordenado(int fil_len, int col_len, int short(*laberinto)[fil_len][col_len]);
int resuelve(int x, int y, int filas, int columnas, int short(*laberinto)[filas][columnas],int short (*solucion)[filas][columnas]);
void imprimir_solucion(int filas, int columnas,int short (*sol)[filas][columnas]);

#endif