#ifndef OBTIENEMATRIZ_H
#define OBTIENEMATRIZ_H   

int cuenta_columnas(char *puntero);
int cuenta_filas(char *puntero, int columnas);
void Construye_matriz(int filas, int columnas, char *puntero, int (*laberinto)[filas][columnas]);

#endif