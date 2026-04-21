#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void MostrarPersonas(char *Vector[]) {
    printf("Nombres ingresados:\n");
    for (int i = 0; i < 5; i++) {
        printf("%s\n", Vector[i]);
    }
}

void BuscarNombre(char Frase[], char *Vector[]){
    
    for (int i = 0; i < 5; i++){

        if (strstr(Vector[i], Frase) != NULL){
            printf("Se ha encontrado: %s\n", Vector[i]);
        }
    }
    
}

int main() {
    char *Vector[5]; 
    int Seleccion = 0;
    char Frase[20];
    
    for (int i = 0; i < 5; i++) {
        Vector[i] = (char*)malloc(sizeof(char) * 20); // Asignar memoria para cada nombre, respetando el maximo de 20
        printf("Ingrese el nombre %d: ", i + 1);
        fgets(Vector[i], 20, stdin);

       
    }

    printf("Ingrese una frase para ver coincidencias.\n");
    fgets(Frase, 20, stdin);

    Frase[strcspn(Frase, "\n")] = '\0'; //Para que elimine el salto de linea dentro del fgets porque sino no hayara coincidencias

    BuscarNombre(Frase, Vector);

    MostrarPersonas(Vector);

    for (int i = 0; i < 5; i++){
        free(Vector[i]);
        
    }
    
    MostrarPersonas(Vector); // Lo puse para probar si se libero la memoria aunque el resultado no fue el que esperaba
    return 0;
}