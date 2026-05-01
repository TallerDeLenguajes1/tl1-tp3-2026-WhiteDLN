#include <stdio.h>
#include <string.h>
#include <stdlib.h> //NO OLVIDES PARA EL MALLOC
#include <ctype.h>
#include <time.h>

char *TiposProductos[20]={"Galletas","Snack","Cigarrillos","Caramelos","Bebidas"};


typedef struct Producto {
 int ProductoID; //Numerado en ciclo iterativo
 int Cantidad; // entre 1 y 10
 char *TipoProducto; // Algún valor del arreglo TiposProductos
 float PrecioUnitario; // entre 10 - 100
}Producto;

typedef struct Cliente {
int ClienteID; // Numerado en el ciclo iterativo
char *NombreCliente; // Ingresado por usuario
int CantidadProductosAPedir; // (aleatorio entre 1 y 5)
Producto *Productos; //El tamaño de este arreglo depende de la variable
 // “CantidadProductosAPedir”
}Cliente;

void LimpiarBuffer(){
    int c;
    while ((c = getchar()) != '\n' && c != EOF){}
}

float CalcularPrecio(Producto *productos);
void CargarProductos(Producto *productos, int CantidadProductoCopia);
void CargarClientes();

int main(){
    srand(time(NULL));
    CargarClientes();
    

    return 0;
}

float CalcularPrecio(Producto *productos){
    
    return productos->Cantidad * productos->PrecioUnitario;
}

void CargarProductos(Producto *productos, int CantidadProductoCopia){ //el segundo se puede llamar como sea porque el valor se dara dentro de la otra funcion.

    for (int j = 0; j < CantidadProductoCopia; j++){
        productos[j].ProductoID = j + 1;
        productos[j].Cantidad = 1 + rand()%10;

        int IndexRandom = rand()%5;
        productos[j].TipoProducto = TiposProductos[IndexRandom];

        productos[j].PrecioUnitario = 10 + rand()%91;
    }
}

void CargarClientes(){
    
    int CantidadElegida = 0;
    int continuar = 1;
    Cliente *clientes = NULL; // para que clientes no quede invalido en clientes

    while (continuar == 1){
        CantidadElegida++;
        clientes = (Cliente*) realloc(clientes, sizeof(Cliente) * CantidadElegida); //USAR REALLOC EN VEZ DE MALLOC EN ESTE CASO
    

    
        
            // Asignar ID.
            clientes[CantidadElegida - 1].ClienteID = CantidadElegida; 
        
            //Asignar nombre.
            clientes[CantidadElegida - 1].NombreCliente = (char *)malloc(sizeof(char) * 50); //asignar memoria al arreglo char del nombre obtenido por fgets, siempre hacerlo antes.
            printf("Ingrese el nombre del cliente[%d].\n", CantidadElegida);
            fgets(clientes[CantidadElegida - 1].NombreCliente, 50, stdin); //Recuerda esto para cuando es un puntero en estructura.

            // Asignacion de una cantidad random entre el 1-10
            clientes[CantidadElegida - 1].CantidadProductosAPedir = 1 + rand()%10;

            //Asignar memoria para el arreglo de los productos.
            clientes[CantidadElegida - 1].Productos = (Producto*) malloc (sizeof(Producto) * clientes[CantidadElegida - 1].CantidadProductosAPedir);
        
            CargarProductos(clientes[CantidadElegida - 1].Productos, clientes[CantidadElegida - 1].CantidadProductosAPedir); //AQUI SI ES IMPORTANTE QUE SE LLAME IGUAL LA SEGUNDA VARIABLE

        printf("\n¿Desea cargar otro cliente? (1 = Sí / 0 = No): ");
        scanf("%d", &continuar);
        LimpiarBuffer();

    }
        float TotalGeneral = 0;

         for (int i = 0; i < CantidadElegida; i++) {
            float TotalCliente = 0;
            printf("\nCliente: %s (ID: %d)\n", clientes[i].NombreCliente, clientes[i].ClienteID);
            for (int j = 0; j < clientes[i].CantidadProductosAPedir; j++) {
                float Subtotal = CalcularPrecio(&clientes[i].Productos[j]);
                TotalCliente += Subtotal;
                printf("  Producto %d: %s x%d = $%.2f | Subtotal: $%.2f\n",
                       clientes[i].Productos[j].ProductoID,
                       clientes[i].Productos[j].TipoProducto,
                       clientes[i].Productos[j].Cantidad,
                       clientes[i].Productos[j].PrecioUnitario,
                       Subtotal
                    );
                       
            }

            printf("  ▶ TOTAL CLIENTE: $%.2f\n", TotalCliente);
            TotalGeneral += TotalCliente;
        }

        for (int i = 0; i < CantidadElegida; i++) {
        free(clientes[i].NombreCliente);
        free(clientes[i].Productos);  // NOTA: No liberar TiposProductos porque apunta al array global
        }
        free(clientes);
    

    
}