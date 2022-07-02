#Este es un makefile
all:
	gcc obtieneMatriz.c soluciona.c main.c -o execute
exec:
	./execute
clean:
	rm -rf execute
	rm -rf *.out