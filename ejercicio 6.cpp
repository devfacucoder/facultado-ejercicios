#include <stdio.h>
#include <string.h>
typedef struct {
    int codigo;
    int stock;
    float precio;
    float acInvertido;
} Producto;

typedef struct {
    char nombre[100];
    int numProvedor;
    int cantCompras;
} Provedor;

void cargarProductos(Producto p[], int numProductos) {
    for (int i = 0; i < numProductos; i++) {
    	p[i].acInvertido = 0.0;
        int codigoPro = 0;
        printf("\n----------------------------");
        while (codigoPro < 1 || codigoPro > 50) {
            printf("\nIngrese el codigo del producto (1 a 50): ");
            scanf("%d", &codigoPro);
        }
        p[i].codigo = codigoPro;

        printf("\nIngrese el precio del producto: ");
        scanf("%f", &p[i].precio);

        printf("\nIngrese el stock del producto: ");
        scanf("%d", &p[i].stock);
    }
    //TODO hago un ordenamiento????
    
    
}

void verProductos(Producto p[], int numProductos) {
    for (int i = 0; i < numProductos; i++) {
    	printf("\n----------------------------");
        printf("\nProducto con el código %d, precio %f, stock %d el total de ventas es de: %.2f\n", 
               p[i].codigo, p[i].precio, p[i].stock,p[i].acInvertido);
    }
}

void cargarProvedores(Provedor p[], int numProvedores) {
    for (int i = 0; i < numProvedores; i++) {
        int numPro = 0;
        printf("\n----------------------------");
        while (numPro < 1000 || numPro > 1022) {
            printf("\nIngrese el número del proveedor (1000 a 1022): ");
            scanf("%d", &numPro);
        }
        p[i].numProvedor = numPro;

        printf("\nIngrese el nombre del proveedor: ");
        scanf("%s", p[i].nombre);  // Usar %s para cadenas cortas, no recomendado para nombres largos
    	 p[i].cantCompras = 0;  // Inicializar cantCompras 
	}
}

void verProvedores(Provedor p[], int numProvedores) {
    for (int i = 0; i < numProvedores; i++) {
    	printf("\n----------------------------");
        printf("\nProveedor número: %d, nombre: %s, la Cantidad de compras que hizo es de %i", p[i].numProvedor, p[i].nombre,p[i].cantCompras);
    }
}


void comprar(Provedor pv[], Producto pd[], int numProveedores, int numProductos, int numProvedor) {
    int productoAComprar = 0;
    int cantDeCompra = 0;
    float totalDeLaCompra = 0.0;
    printf("\n----------------------------");
    printf("\nIngrese el número del producto a comprar:");
    scanf("%d", &productoAComprar);
    
    printf("\n¿Cuántos productos va a comprar?:");
    scanf("%d", &cantDeCompra);
    
    // Buscar el producto por código
    for (int i = 0; i < numProductos; i++) {
        if (pd[i].codigo == productoAComprar) {
            if (pd[i].stock >= cantDeCompra) {
                totalDeLaCompra = pd[i].precio * cantDeCompra;
                pd[i].stock -= cantDeCompra;  // Restar stock
                pd[i].acInvertido += totalDeLaCompra;  // Sumar al acumulador
                
                // Buscar el proveedor por número y actualizar cantCompras
                for (int j = 0; j < numProveedores; j++) {
                    if (pv[j].numProvedor == numProvedor) {
                        pv[j].cantCompras++;  // Incrementar la cantidad de compras
                        printf("\nCompra realizada por el proveedor %s. Total gastado: %.2f\n", pv[j].nombre, totalDeLaCompra);
                        return;
                    }
                }

                printf("\nProveedor no encontrado.\n");
            } else {
                printf("\nStock insuficiente.\n");
            }
            return;
        }
    }
    
    printf("\nProducto no encontrado.\n");
}
void cargarProvedoresMasventas(Provedor pr[],Provedor prcopy[],int numPro){
	int ct = 0;
	for(int i = 0;i<numPro;i++){
		if(pr[i].cantCompras >=3){
			prcopy[ct].numProvedor = pr[i].numProvedor;
			strcpy(prcopy[ct].nombre, pr[i].nombre);
			prcopy[ct].cantCompras = pr[i].cantCompras;
			ct++;
	
		}
		
	}
	
	
}

void buscarProvedorPorNombre(Provedor pr[], int numProvedores) {
    char nombreBuscado[100];
    int encontrado = 0;
    
    printf("Ingrese el nombre del proveedor a buscar: ");
    scanf("%99s", nombreBuscado); // Usar %99s para evitar desbordamiento de buffer
    
    for (int i = 0; i < numProvedores; i++) {
        if (strcmp(pr[i].nombre, nombreBuscado) == 0) { // esto compara cadenas
            printf("\nProveedor encontrado:\n");
            printf("Número del proveedor: %d\n", pr[i].numProvedor);
            printf("Cantidad de compras: %d\n", pr[i].cantCompras);
            encontrado = 1;
            break;
        }
    }
    
    if (!encontrado) {
        printf("Proveedor no encontrado.\n");
    }
}
void ordenarProvedoresPorNombre(Provedor p[], int numProvedores) {
    Provedor temp;
    for (int i = 0; i < numProvedores - 1; i++) {
        for (int j = 0; j < numProvedores - i - 1; j++) {
            if (strcmp(p[j].nombre, p[j + 1].nombre) > 0) {
                // Intercambiar p[j] y p[j + 1]
                temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }
}
int main() {
    // Definir el número de productos y proveedores
    const int numProductos = 2;
    const int numProvedores = 2;
    int interacciones = 0;
    // Crear arreglos para productos y proveedores
    
	Producto productos[numProductos];
    Provedor provedores[numProvedores];
    Provedor provedoresMas10ventas[numProvedores];
    //Cargar y mostrar los productos
    cargarProductos(productos, numProductos);
    
    
    // Cargar y mostrar los proveedores
    cargarProvedores(provedores, numProvedores);
    
	while(interacciones != 1){
    	printf("\n----------------------------");
    	int prove;
		printf("\n\n Ingrese su Numero de Provedor");
    	scanf("%i",&prove);
    	comprar(provedores,productos,numProvedores,numProductos,prove);
    	printf("\n quiere seguir Comprando? ingrese 0 para si y 1 para no");
    	scanf("%i",&interacciones);
	}
    verProductos(productos, numProductos);
    verProvedores(provedores, numProvedores);
    cargarProvedoresMasventas(provedores,provedoresMas10ventas,numProvedores);    
    printf("\n Provedores con mas de 10 ventas");
    ordenarProvedoresPorNombre(provedoresMas10ventas,numProvedores);
	verProvedores(provedoresMas10ventas, numProvedores);
    
    buscarProvedorPorNombre(provedores,numProvedores);
	return 0;
}
