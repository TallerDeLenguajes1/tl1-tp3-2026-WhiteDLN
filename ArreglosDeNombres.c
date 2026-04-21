#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void MostrarPersonas(char *Vector[]) {
    printf("Nombres ingresados:\n");
    for (int i = 0; i < 5; i++) {
        printf("%s\n", Vector[i]);
    }
}

void BuscarNombrePalabra(char Frase[], char *Vector[]){
    
    for (int i = 0; i < 5; i++){

        if (strstr(Vector[i], Frase) != NULL){
            printf("Se ha encontrado: %s\n", Vector[i]);
        }
    }
    
}

void BuscarNombreID(int Seleccion, char *Vector[]){
    Seleccion = Seleccion - 1;
    printf("\nEl nombre seleccionado es:\n");
    printf("%s\n", Vector[Seleccion]);
}

int main() {
    char *Vector[5];
    int Eleccion;
    int Seleccion = 0;
    char Frase[20];
    
    for (int i = 0; i < 5; i++) {
        Vector[i] = (char*)malloc(sizeof(char) * 20); // Asignar memoria para cada nombre, respetando el maximo de 20
        printf("Ingrese el nombre %d: ", i + 1);
        fgets(Vector[i], 20, stdin);

       
    }

    printf("Seleccione que desea hacer.\n");
    printf("[1] Buscar nombre por id.\n");
    printf("[2] Seleccionar por coincidencia.\n");
    scanf("%d", &Eleccion);
    fflush(stdin);


    if(Eleccion == 1) {
        printf("Seleccione un número <= 5.\n");
        scanf("%d", &Seleccion);
        fflush(stdin);
        if (Seleccion <= 5 && Seleccion >= 1) {
        BuscarNombreID(Seleccion, Vector);
        }

        else{
        printf ("No se ha encontrado el valor buscado.\n");
        }
    }

    else if(Eleccion == 2){
        printf("Ingrese una frase para ver coincidencias.\n");
        fgets(Frase, 20, stdin);

        Frase[strcspn(Frase, "\n")] = '\0'; //Para que elimine el salto de linea dentro del fgets porque sino no hayara coincidencias

        BuscarNombrePalabra(Frase, Vector);
    }
    
    else {
        printf("La opcion seleccionada no es valida.");
    }
    

    MostrarPersonas(Vector);

    for (int i = 0; i < 5; i++){
        free(Vector[i]);
        
    }
    
    MostrarPersonas(Vector); // Lo puse para probar si se libero la memoria aunque el resultado no fue el que esperaba
    return 0;
}