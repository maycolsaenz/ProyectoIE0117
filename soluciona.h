#ifndef SOLUCIONA_H
#define SOLUCIONA_H    

node_t *par_ordenado(int fil_len, int col_len, int (*laberinto)[fil_len][col_len]);
int resuelve(int x, int y, int filas, int columnas, int (*laberinto)[filas][columnas],int (*solucion)[filas][columnas]);
void imprimir_solucion(int filas, int columnas,int (*sol)[filas][columnas]);

#endif