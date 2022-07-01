#ifndef STRUCT_H
#define STRUCT_H    


struct Nodo{
	int x;
	int y;
	struct Nodo *siguiente;
};
typedef struct Nodo node_t;

#endif