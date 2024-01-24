#include <stdio.h>
#include <string.h>
// Definiendo las variables al empezar el codigo
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
// Pidiendo al usuario que cantidad de productos se van a comprar
int main(int argc, char const *argv[])
{
    int n;
    printf("Ingrese la cantidad de productos: ");
    fflush(stdout);
    scanf("%d", &n);

    struct producto compra[n];
    //Pidiendo al usuario que opciones tiene para ingresr los productos o si ya desea verlos, para eso vamos a utilizr un switch case
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
        //Hemos definido como queremos que el usuario elija las opciones correctas, sino elije una de las tres opciones, tendra que intentarlo de nuevo
    } while (opcion != 3);
}
int ingresarDatos(struct producto *compra)
{
    //Vamos a configurar el ingreso de datos, los datos que vamos a pedir son el codigo, nombre, descripcion, precio
    char buffer[100];

    printf("Codigo del producto: ");
    fflush(stdout);
    getchar();
    fgets(buffer, sizeof(buffer), stdin);
    buffer[strcspn(buffer, "\n")] = '\0';
    strncpy(compra->codigo, buffer, sizeof(compra->codigo));

    printf("Nombre del producto: ");
    fflush(stdout);
    fgets(buffer, sizeof(buffer), stdin);
    buffer[strcspn(buffer, "\n")] = '\0';
    strncpy(compra->nombreProductoProducto, buffer, sizeof(compra->nombreProductoProducto));
    
    printf("Descripcion del producto: ");
    fflush(stdout);
    fgets(buffer, sizeof(buffer), stdin);
    buffer[strcspn(buffer, "\n")] = '\0';
    strncpy(compra->descriProducto, buffer, sizeof(compra->descriProducto));

    printf("Precio del Producto: ");
    fflush(stdout);
    scanf("%f", &(compra->precioCompra));
    return 0;
}
//En este int vamos a mostrar los datos, uno seguido del otro, y si son mas productos, uno abajo del otro
int mostrarDatos(struct producto *compra)
{
    printf("    %s", compra->codigo);
    printf("    %s", compra->nombreProductoProducto);
    printf("    %s", compra->descriProducto);
    printf("    %.2f", compra->precioCompra);
    printf("\n");

    return 0;
}   