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

