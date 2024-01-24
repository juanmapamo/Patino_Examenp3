#include <stdio.h>
#include <string.h>

struct producto
{
    int cantidad;
    char nombreProductoProducto[50];
    char descriProducto[50];
    char codigo[25];
    float precioCompra;
};
int ingresarDatos(struct producto *compra);
int mostrarDatos(struct producto *compra);

int main(int argc, char const *argv[])
{
    int n;
    printf("Ingrese la cantidad de productos: ");
    fflush(stdout);
    scanf("%d", &n);

    struct producto compra[n];
 int opcion;
    do
    {
        printf("\n1. Ingresar datos de los productos \n");
        printf("2. Mostrar datos de los productos\n");
        printf("3. Salir\n");
        printf("Seleccione una opcion: ");
        fflush(stdout);
        scanf("%d", &opcion);
        
        switch (opcion)
        {
        case 1:
            for (int i = 0; i < n; i++)
            {
                printf("\nIngrese los datos del producto %d:\n", i + 1);
                ingresarDatos(&compra[i]);
            }
            break;
        case 2:
            printf("\nDatos de los productos:\n");
            for (int i = 0; i < n; i++)
            {
                mostrarDatos(&compra[i]);
            }
            break;
        case 3:
            printf("Saliendo del programa.\n");
            break;
        default:
            printf("Opción no válida. Inténtelo de nuevo.\n");
            break;
        }
    } while (opcion != 3);
}
