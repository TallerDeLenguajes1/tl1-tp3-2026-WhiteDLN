#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void MostrarPersonas(char *Vector[]) {
    printf("Nombres ingresados:\n");
    for (int i = 0; i < 5; i++) {
        printf("%s\n", Vector[i]);
    }
}

int main() {
    char *Vector[5]; 
    
    
    for (int i = 0; i < 5; i++) {
        Vector[i] = (char*)malloc(sizeof(char) * 20); // Asignar memoria para cada nombre, respetando el maximo de 20
        printf("Ingrese el nombre %d: ", i + 1);
        fgets(Vector[i], 20, stdin);

       
    }

    MostrarPersonas(Vector); // Mostrar los nombres ingresados

    for (int i = 0; i < 5; i++){
        free(Vector[i]);
        
    }
    
    MostrarPersonas(Vector); // Lo puse para probar si se libero la memoria aunque el resultado no fue el que esperaba
    return 0;
}