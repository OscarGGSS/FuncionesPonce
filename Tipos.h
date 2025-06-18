#ifndef TIPOS_H
#define TIPOS_H

//Constantes
#define MAX_PRODUCTOS 100
#define MAX_CLIENTES 100
#define MAX_VENTAS 100
#define IVA 0.16f
#define MAX_CADENA 50

//Tipos
typedef struct rFecha {
	
    int eDia;
    int eMes;
    int eAnio;
    
} TrFecha; //TrFecha

typedef enum ePlataformas {
	
    MERCADOLIBRE,
    SHOPIFY,
    INSTAGRAM
    
} TePlataformas; //TePlataformas

typedef struct rProducto {
	
	int eIdProducto;
    int eIdInsumo;
    int eIdDisenio;
    int eCantidad;
    float fPrecioDisenio;
    float fPrecioInsumo;
    float fPrecio;
    
} TrProducto; //TrProducto

typedef TrProducto TaProductos[MAX_PRODUCTOS];

typedef struct rVenta {
	
    int eIdVenta;
    int eIdCliente;
    TePlataformas ePlataforma;
    TrFecha rFechaVenta;
    int eTotalProductos;
    TaProductos aProductos;
    float fSubtotal;
    float fIva;
    float fTotal;
    int eCancelada;
    TrFecha rFechaCancelacion;
    char sMotivoCancelacion[130];
    
} TrVenta; //TrVenta

typedef TrVenta TaVentas[MAX_VENTAS];

typedef struct rCliente {
	
	int eIdCliente;
	char sNombre [40];
	char sTelefono[20];
	char sDireccion[50];
	char sCorreo[30];
	int eActivo;
	
} TrCliente;

typedef TrCliente TaClientes[MAX_CLIENTES];


#endif
