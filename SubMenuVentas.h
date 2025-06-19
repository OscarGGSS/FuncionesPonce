//Bibliotecas
#include <stdio.h>
#include <stdlib.h> 
#include <string.h> 
#include "Tipos.h"
#include "ZInterfaz.h"
#include "ZFunciones.h"
#include <conio.h>
#include "SubMenuClientes.h"

//Prototipos

void SubMenuVentas(TaVentas *, int *, TaClientes, int);
void GuardarVentasEnArchivo(TaVentas *, int);
int BuscarVenta(TaVentas, int, int, int);
void MostrarResumenVenta(TrVenta);
void ValidarIdArchivo(int *, float *, char *, char *, int);
void CargarVentas(TaVentas, int *);

//Funciones RegistrarVenta:
void RegistrarVenta(TaVentas *, int *, TaClientes, int);
float CalcularPrecio(float, float);
float CalcularImporte(float, int);
void CapturarProducto(TrProducto *, float *, float *);
void CapturarDatosVenta(TrVenta *);
void CapturarProductosVenta(TrVenta *, float *);
void FinalizarVenta(TrVenta *, int, float);
void GenerarIdVenta(TaVentas *, int, int *);
void GuardarNuevaVenta(TaVentas *, int *, TrVenta *);
void MostrarPreciosProducto(TrProducto, int);
void MostrarTotalesVenta(TrVenta);
TrProducto ProcesarProducto(TrProducto, TrVenta *, int, float, float, float *);

//Funciones CancelarVenta:
void CancelarVenta(TaVentas *, int *);
void CapturarDatosCancelacion(TrVenta *);
int ValidarIdVentaCancelacion(TaVentas, int, int *);

//Funciones ConsultarVentasPorFechas:
void ConsultarVentasPorFechas(TaVentas *, int);
void PantallaConsultaFechas();
int ValidarFechaMenorOIgual(TrFecha, TrFecha);
void MostrarDatosVenta(TaVentas *, int, int);
int FiltrarMostrarVentasPorFecha(TaVentas *, int, TrFecha, TrFecha);

//Funciones ConsultarVentaPorId:
void ConsultarVentaPorId(TaVentas *, int);
int ValidarIdVentaConsulta(TaVentas, int);
void MostrarDatosCancelacion(TrVenta);

//Funciones ReporteMensualVentas:
void ReporteMensualVentas(TaVentas *, int);
void ImprimirVentasPorPlataforma(TaVentas *, int, TePlataformas, int, int, int *, float *, int);
void MostrarFilaVentaPlataforma(TrVenta rVenta, int eRenglon, char *sCancelada);


void SubMenuVentas(TaVentas *aVentas, int *eTotalVentas, TaClientes aClientes, int eTotalClientes) {
    
	int eOpcion;
   
    do {
    	
        Pantalla4();
        
        Centrar("VENTAS", 2);
        
        Mensaje(9, 49, "1. Registrar venta");
        Mensaje(10, 49, "2. Cancelar venta");
        Mensaje(11, 49, "3. Consultar venta (fechas)");
        Mensaje(12, 49, "4. Consultar venta (ID)");
        Mensaje(13, 49, "5. Reporte mensual");
        Mensaje(14, 49, "0. Regresar");

        Mensaje(16, 50, "Seleccione una opci%cn: ", 162);
        eOpcion = LeerEntero(16, 73, 1); //Valida entero
	
		switch (eOpcion) {
           
		    case 1: RegistrarVenta(aVentas, eTotalVentas, aClientes, eTotalClientes);
                	getch();
                	break;
            
			case 2: CancelarVenta(aVentas, eTotalVentas);
    				break;
                
            case 3: ConsultarVentasPorFechas(aVentas, *eTotalVentas);
    				break;
                
            case 4: ConsultarVentaPorId(aVentas, *eTotalVentas);
              	  	break;
                
            case 5: ReporteMensualVentas(aVentas, *eTotalVentas);
    				break;
                   
			case 0: break;
			
            default: Error(1); //Error (opción no válida)
                	 getch();
    
        }
        
    } while(eOpcion != 0);
    
} //SubMenuVentas

void CargarVentas(TaVentas aVentas, int *eTotalVentas) {
	
	FILE *pArchivoVentas;
	
    pArchivoVentas = fopen("ventas.dat", "rb");
    
    if (pArchivoVentas != NULL) {
    	
        fread(eTotalVentas, sizeof(int), 1, pArchivoVentas);
        
        fread(aVentas, sizeof(TrVenta), *eTotalVentas, pArchivoVentas);
        
        fclose(pArchivoVentas);
        
    } else {
    	
        *eTotalVentas = 0; // archivo no existe, arreglo vacío
        
    }
    
} //CargarVentas

void GuardarVentasEnArchivo(TaVentas *aVentas, int eTotalVentas) {
    
	FILE *pArchivo = fopen("ventas.dat", "wb");
    
    if (pArchivo != NULL) {
    	
        fwrite(&eTotalVentas, sizeof(int), 1, pArchivo);
        fwrite(aVentas, sizeof(TrVenta), eTotalVentas, pArchivo);
        fclose(pArchivo);
        
    } else {
    	
        Error(2); //Error (al guardar ventas en archivo)
        getch();
        
    }

} //GuardarVentasEnArchivo

void RegistrarVenta(TaVentas *aVentas, int *eTotalVentas, TaClientes aClientes, int eTotalClientes){
	
	TrVenta rVenta;
    int eSeguirVenta;
    float fSubtotal;
    char sMensaje[50];
	
    do {
    	
    	Pantalla4();	
    	Centrar("Registrar Venta", 2);

        if (*eTotalVentas == MAX_VENTAS - 1) {
            
			Error(3); //Error (No hay espacio)
            getch();
        	return;
        	
    	} else {

			fSubtotal = 0;
	
			rVenta.eIdCliente = ValidarIdCliente(aClientes, eTotalClientes, 1);
	
			if (rVenta.eIdCliente == -1) {
				
				return;
		
			} else {
		            	
			    CapturarDatosVenta(&rVenta);
		
				CapturarProductosVenta(&rVenta, &fSubtotal);
			
				FinalizarVenta(&rVenta, rVenta.eTotalProductos, fSubtotal);
				MostrarTotalesVenta(rVenta);
						
				GuardarNuevaVenta(aVentas, eTotalVentas, &rVenta);
				
				Pantalla3();
		    	
				sprintf(sMensaje, "%cRegistrar otra venta? (s/n):", 168);	
				eSeguirVenta = LeerSN(14, 44, sMensaje);
				
			}
			
		}
    
	} while (eSeguirVenta);
    
    Centrar("Presione cualquier tecla para regresar...", 26);

}//RegistrarVenta

float CalcularPrecio(float fPrecioInsumo, float fPrecioDisenio) {
    
	return fPrecioInsumo + fPrecioDisenio;
	
} //CalcularPrecio

float CalcularImporte(float fPrecio, int eCantidad) {
	
    return fPrecio * eCantidad;
    
} //CalcularImporte

TrProducto ProcesarProducto(TrProducto rProducto, TrVenta *pVenta, int eContador, float fPrecioInsumo, float fPrecioDisenio, float *pSubtotal) {
    
    float fPrecioFinal, fImporte;
	
	rProducto.fPrecioInsumo = fPrecioInsumo;
    rProducto.fPrecioDisenio = fPrecioDisenio;

    fPrecioFinal = CalcularPrecio(fPrecioInsumo, fPrecioDisenio);
    rProducto.fPrecio = fPrecioFinal;

    fImporte = CalcularImporte(fPrecioFinal, rProducto.eCantidad);
    *pSubtotal += fImporte;

    rProducto.eIdProducto = eContador + 1;

    (*pVenta).aProductos[eContador] = rProducto;

    return rProducto;
    
} //ProcesarProducto

void CapturarProductosVenta(TrVenta *pVenta, float *pSubtotal) {
	
    TrProducto rProducto;
    int eContador = 0;
    int eRenglon = 11;
    float fPrecioInsumo, fPrecioDisenio;
    int eSeguirProducto = 1;
    char sMensaje[60];

    PantallaProductos();

    while (eSeguirProducto && eContador < MAX_PRODUCTOS) {
        
		CapturarProducto(&rProducto, &fPrecioInsumo, &fPrecioDisenio);

        if (eRenglon > 20) {
            
			eRenglon = 12;
            
			BorrarZona(11, 3, 10, 114);
        }

        Mensaje(eRenglon, 12, "%d", eContador + 1);
        
        rProducto.eCantidad = LeerEnteroEnRango(eRenglon, 31, 1, 100);

        rProducto = ProcesarProducto(rProducto, pVenta, eContador, fPrecioInsumo, fPrecioDisenio, pSubtotal);
        eContador++;

        MostrarPreciosProducto(rProducto, eRenglon);

        eRenglon += 2;

        if (eContador < MAX_PRODUCTOS) {
            
			sprintf(sMensaje, "%cAgregar otro producto? (s/n):", 168);
            eSeguirProducto = LeerSN(26, 2, sMensaje);
            
        } else {
        	
            sprintf(sMensaje, "Se alcanz%c el m%cximo de productos por venta.", 162, 160);
    		Centrar(sMensaje, 26);
    		getch();
            eSeguirProducto = 0;
            
        }
    }

    (*pVenta).eTotalProductos = eContador;
    
} //CapturarProductosVenta

void GuardarNuevaVenta(TaVentas *aVentas, int *eTotalVentas, TrVenta *pVenta) {
	
    int eIdActual;
    char sMensaje[50];
    
    GenerarIdVenta(aVentas, *eTotalVentas, &eIdActual);
    
    (*pVenta).eIdVenta = eIdActual;    
    
    (*aVentas)[*eTotalVentas] = *pVenta;
    
	(*eTotalVentas)++;
    
    GuardarVentasEnArchivo(aVentas, *eTotalVentas);
    
    BorrarZona(26, 1, 2, 45);
    
    Mensaje(26, 2, "La venta se registr%c correctamente.", 162);
    sprintf(sMensaje, "ID de la venta: %d", eIdActual);
    Centrar(sMensaje, 26);
    
	getch(); 
    
}//GuardarNuevaVenta

void FinalizarVenta(TrVenta *pVenta, int eContador, float fSubtotal) {
	
    TrVenta rCopia = *pVenta;

    rCopia.eTotalProductos = eContador;
    rCopia.fSubtotal = fSubtotal;
    rCopia.fIva = fSubtotal * 0.16f;
    rCopia.fTotal = rCopia.fSubtotal + rCopia.fIva;
    rCopia.eCancelada = 0;
    rCopia.rFechaCancelacion.eDia = 0;
    rCopia.rFechaCancelacion.eMes = 0;
    rCopia.rFechaCancelacion.eAnio = 0;
    rCopia.sMotivoCancelacion[0] = '\0';

    *pVenta = rCopia;

} //FinalizarVenta

void MostrarTotalesVenta(TrVenta rVenta) {
	
    Mensaje(22, 95, "Subtotal: $%.2f", rVenta.fSubtotal);
    Mensaje(23, 100, "IVA: $%.2f", rVenta.fIva);
    Mensaje(26, 98, "Total: $%.2f", rVenta.fTotal);
    
} //MostrarTotalesVenta

void MostrarPreciosProducto(TrProducto rProducto, int eRenglon) {

    float fImporte;

    fImporte = CalcularImporte(rProducto.fPrecio, rProducto.eCantidad);

    Mensaje(eRenglon, 47, "$%.2f", rProducto.fPrecioDisenio);
    Mensaje(eRenglon, 68, "$%.2f", rProducto.fPrecioInsumo);
    Mensaje(eRenglon, 87, "$%.2f", rProducto.fPrecio);
    Mensaje(eRenglon, 105, "$%.2f", fImporte);
    
} //MostrarPreciosProducto

void CapturarProducto(TrProducto *pProducto, float *pPrecioInsumo, float *pPrecioDisenio) {

    TrProducto rCopia;
    float fInsumo, fDisenio;

    BorrarZona(5, 20, 3, 3);  // Borra campos de ID
    BorrarZona(26, 1, 2, 70); // Borra posibles errores previos

    ValidarIdArchivo(&rCopia.eIdInsumo, &fInsumo, "Insumos.txt", "insumo", 5);
    ValidarIdArchivo(&rCopia.eIdDisenio, &fDisenio, "Disenos.txt", "diseno", 6);

    *pPrecioInsumo = fInsumo;
    *pPrecioDisenio = fDisenio;
    *pProducto = rCopia;

} //CapturarProducto

void CapturarDatosVenta(TrVenta *pVenta) {

    int eOpcion;
    TrVenta rCopia = *pVenta;

    Mensaje(10, 10, "Fecha de la venta:");
    rCopia.rFechaVenta = LeerFecha(11, 10);

    Mensaje(16, 10, "[1- MERCADO LIBRE     2-SHOPIFY     3-INSTAGRAM]");
    Mensaje(17, 10, "Plataforma:");
    
    eOpcion = LeerEnteroEnRango(17, 22, 1, 3);
    
    rCopia.ePlataforma = (TePlataformas)(eOpcion - 1);

    *pVenta = rCopia;

} //CapturarDatosVenta

void ValidarIdArchivo(int *pId, float *pPrecio, char *sArchivo, char *sTipo, int eFila) {

    int eValido, eIdLeido;
    char sNombre[50];
    float fPrecioLeido;
    FILE *archivo;
    char sEtiqueta[30];
    
    eValido = 0;
    
    sprintf(sEtiqueta, "ID del %s:", sTipo);
    Mensaje(eFila, 5, sEtiqueta);

    do {
    	
        BorrarZona(eFila, 20, 1, 10);
        BorrarZona(26, 20, 2, 80);

        GoToXY(eFila, 20);
        *pId = LeerEntero(eFila, 20, 6);

        archivo = fopen(sArchivo, "r");

        if (archivo == NULL) {
        	
            Mensaje(26, 2, "No se pudo abrir el archivo.");
            getch();
            return;
            
        }

        eValido = 0;

        while (fscanf(archivo, "%d|%[^|]|%f\n", &eIdLeido, sNombre, &fPrecioLeido) == 3) {  //entero | texto hasta ‘|’ | flotante + salto de línea.
            
			if (eIdLeido == *pId) {
                *pPrecio = fPrecioLeido;
                eValido = 1;
                break;
                
            }
        }

        fclose(archivo);

        if (!eValido) {
            Error(12);  // Muestra "ID no válido"
            getch();
        }

    } while (!eValido);
}

void GenerarIdVenta(TaVentas *aVentas, int eTotalVentas, int *pIdVentaNuevo) {
	
    int eMaxId, eContador;
    
    eMaxId = 0;
    
    for (eContador = 0; eContador < eTotalVentas; eContador++) {
    	
        if ((*aVentas)[eContador].eIdVenta > eMaxId) {
        	
            eMaxId = (*aVentas)[eContador].eIdVenta;
            
        }
    }
    
    *pIdVentaNuevo = eMaxId + 1;
    
} //GenerarIdVenta

int BuscarVenta(TaVentas aVentas, int eTotalVentas, int eIdBusqueda, int eCancelar) {
    
    int eMenor, eMayor, eMedio;
    
    if (eTotalVentas <= 0) {
    	
        return -1;
        
    }
    
    eMenor = 0;
    eMayor = eTotalVentas - 1;
    eMedio = (eMenor + eMayor) / 2;
    
    while (eMayor >= eMenor && eIdBusqueda != aVentas[eMedio].eIdVenta) {
        
        if (eIdBusqueda < aVentas[eMedio].eIdVenta) {
        	
            eMayor = eMedio - 1;
            
        } else {
        	
            eMenor = eMedio + 1;
            
        }
        
        eMedio = (eMenor + eMayor) / 2;
    }
    
    if (eMayor < eMenor) {
    	
        return -1;
        
    } else if (eCancelar == 1){
        
        if (aVentas[eMedio].eCancelada == 0) {
        	
            return eMedio;
            
        } else {
        	
            return -1;
            
        }
    }
    
} //BuscarVenta

void CancelarVenta(TaVentas *aVentas, int *eTotalVentas) {
	
    int eIdBusqueda, eContador, ePos, eConfirmacion;
	TrVenta rVenta;
	char sMensaje[50];
	
    Pantalla4();
    Centrar("CANCELAR VENTA", 2);
	
	if(*eTotalVentas == 0){
		
		Centrar("No hay ventas", 26);
		getch();
	
	} else{
		
	    ePos = ValidarIdVentaCancelacion(*aVentas, *eTotalVentas, &eIdBusqueda);

		if (ePos == -1) {
		
			Mensaje(26, 40, "No se encontr%c una venta [activa] con ID %d.", 162, eIdBusqueda);
	    	getch();
		
		} else {
	
    			rVenta = (*aVentas)[ePos];
				MostrarResumenVenta(rVenta);
				
				sprintf(sMensaje, " %cCancelar esta venta? (s/n)?:", 168);
				eConfirmacion = LeerSN(22, 38, sMensaje);
				
				if (eConfirmacion) {
				    BorrarZona(5, 2, 19, 117);
				
				    CapturarDatosCancelacion(&rVenta);
				    rVenta.eCancelada = 1;
				
				    (*aVentas)[ePos] = rVenta;
				    GuardarVentasEnArchivo(aVentas, *eTotalVentas);
				
				    Mensaje(26, 45, "Venta cancelada correctamente.");
	                
	            } else {
	            	
	                Mensaje(26, 45, "Cancelaci%cn anulada por el usuario.", 162);
	                
	            }

            getch();
        }
    }

} //CancelarVenta
	        
int ValidarIdVentaCancelacion(TaVentas aVentas, int eTotalVentas, int *pIdVenta) {
	
    int eId, ePos;
    
    while (1) {
    	
        Mensaje(6, 37, "Ingrese el ID de la venta que desea cancelar:");
        GoToXY(6, 83);
        eId = LeerEntero(6, 83, 6);

        ePos = BuscarVenta(aVentas, eTotalVentas, eId, 1);

        if (ePos == -1) {
        	
            Mensaje(26, 40, "No se encontr%c una venta [activa] con ID %d.", 162, eId);
            getch();
            
            BorrarZona(6, 83, 1, 6);
            BorrarZona(26, 40, 1, 45);
            
        } else {
        	
            *pIdVenta = eId;
            return ePos;
            
        }
    }
    
} //ValidarIdVentaCancelacion

void CapturarDatosCancelacion(TrVenta *pVenta) {
    
	int eContador;

	BorrarZona(26, 40, 1, 45);
    Mensaje(6, 5, "Motivo de cancelaci%cn: ", 162);

    for (eContador = 0; eContador < 130; eContador++) {
        (*pVenta).sMotivoCancelacion[eContador] = '\0';
    }

    fflush(stdin);
    gets((*pVenta).sMotivoCancelacion);

    Mensaje(9, 5, "Fecha de cancelaci%cn", 162);
    (*pVenta).rFechaCancelacion = LeerFecha(10, 5);

} //CapturarDatosCancelacion

int ValidarFechaMenorOIgual(TrFecha rFecha1, TrFecha rFecha2) {
    
	if (rFecha1.eAnio < rFecha2.eAnio){
	
		return 1;
		
	} else if (rFecha1.eAnio > rFecha2.eAnio){
	
		return 0;
		
	} else if (rFecha1.eMes < rFecha2.eMes){
		
		return 1;
	
	} else if (rFecha1.eMes > rFecha2.eMes){
	
		return 0;
		
	} else if (rFecha1.eDia <= rFecha2.eDia){
		
		return 1;
	
	} else {
		
    	return 0;
    	
	}
	
} //ValidarFechaMenorOIgual

void PantallaConsultaFechas(){
	    
		DibujarTabla(9, 3, 1, 6, 18);
		    
		Mensaje(10, 10, "Fecha ");
		Mensaje(10, 46, "ID Cliente", 164);
		Mensaje(10, 64, "Plataforma");
		Mensaje(10, 84, "Cancelada");
		Mensaje(10, 105, "Total");
		Mensaje(10, 28, "ID Venta");
		
} //PantallaConsultaFechas

void MostrarDatosVenta(TaVentas *aVentas, int eIndice, int eRenglon) {
	
    char sPlataforma[20];
    char sCancelada[5];
    TrVenta rVenta = (*aVentas)[eIndice];

    if (rVenta.ePlataforma == MERCADOLIBRE) {
    	
        strcpy(sPlataforma, "MercadoLibre");
        
    } else if (rVenta.ePlataforma == SHOPIFY) {
    	
        strcpy(sPlataforma, "Shopify");
        
    } else if (rVenta.ePlataforma == INSTAGRAM) {
    	
        strcpy(sPlataforma, "Instagram");
        
    } else {
    	
        strcpy(sPlataforma, "Desconocido");
        
    }

    if (rVenta.eCancelada == 1) {
    	
        strcpy(sCancelada, "SI");
        
    } else {
    	
        strcpy(sCancelada, "NO");
        
    }

    Mensaje(eRenglon + 1, 8, "%02d/%02d/%04d", rVenta.rFechaVenta.eDia, rVenta.rFechaVenta.eMes, rVenta.rFechaVenta.eAnio);
    Mensaje(eRenglon + 1, 32, "%d", rVenta.eIdVenta);
    Mensaje(eRenglon + 1, 51, "%d", rVenta.eIdCliente);
    Mensaje(eRenglon + 1, 64, "%s", sPlataforma);
    Mensaje(eRenglon + 1, 88, "%s", sCancelada);
    Mensaje(eRenglon + 1, 104, "$%.2f", rVenta.fTotal);
    
} //MostrarDatosVenta

int FiltrarMostrarVentasPorFecha(TaVentas *aVentas, int eTotalVentas, TrFecha rFechaInicio, TrFecha rFechaFin) {
    
	int eContador, eFechaMaOIInicio, eFechaMeOIFin, eEncontrado, eRenglon;
	TrFecha rFechaVenta;
	
	eEncontrado = 0;
	eRenglon = 11;
	
    for (eContador = 0; eContador < eTotalVentas; eContador++) {
    	
        rFechaVenta = (*aVentas)[eContador].rFechaVenta;

        eFechaMaOIInicio = 0;
        
        if (rFechaVenta.eAnio > rFechaInicio.eAnio) {
            eFechaMaOIInicio = 1;
        } else if (rFechaVenta.eAnio == rFechaInicio.eAnio) {
            if (rFechaVenta.eMes > rFechaInicio.eMes) {
                eFechaMaOIInicio = 1;
            } else if (rFechaVenta.eMes == rFechaInicio.eMes) {
                if (rFechaVenta.eDia >= rFechaInicio.eDia) {
                    eFechaMaOIInicio = 1;
                }
            }
        }

        eFechaMeOIFin = 0;
        if (rFechaVenta.eAnio < rFechaFin.eAnio) {
            eFechaMeOIFin = 1;
        } else if (rFechaVenta.eAnio == rFechaFin.eAnio) {
            if (rFechaVenta.eMes < rFechaFin.eMes) {
                eFechaMeOIFin = 1;
            } else if (rFechaVenta.eMes == rFechaFin.eMes) {
                if (rFechaVenta.eDia <= rFechaFin.eDia) {
                    eFechaMeOIFin = 1;
                }
            }
        }

        if (eFechaMaOIInicio && eFechaMeOIFin) {
            MostrarDatosVenta(aVentas, eContador, eRenglon);
            eEncontrado = 1;
            eRenglon++;

            if (eRenglon >= 23) {
                Centrar("Presiona una tecla para continuar...", 26);
                getch();
                BorrarZona(12, 3, 12, 112);
                eRenglon = 11;
            }
        }
    }

    return eEncontrado;
    
} //FiltrarMostrarVentasPorFecha

void ConsultarVentasPorFechas(TaVentas *aVentas, int eTotalVentas) {
	
	TrFecha rFechaInicio, rFechaFin;
    int eEncontrado, eRenglon;
	
    Pantalla2();
    Centrar("CONSULTA DE VENTAS POR RANGO DE FECHAS", 1);
	
    if (eTotalVentas == 0) {
        
		Centrar("No hay ventas", 26);
		getch();
    
	} else {
		
		do {
            
            BorrarZona(5, 10, 3, 6);
            BorrarZona(5, 32, 3, 6);
            
			Mensaje(4, 5, "Fecha Inicial");
            rFechaInicio = LeerFecha(5, 5);

            Mensaje(4, 28, "Fecha Final");
            rFechaFin = LeerFecha(5, 28);

            if (!ValidarFechaMenorOIgual(rFechaInicio, rFechaFin)) {
                
				Error(15);
				getch();
				
			}

		} while (!ValidarFechaMenorOIgual(rFechaInicio, rFechaFin));

        PantallaConsultaFechas();

        eEncontrado = FiltrarMostrarVentasPorFecha(aVentas, eTotalVentas, rFechaInicio, rFechaFin);

        if (eEncontrado == 0) {
        	
            Centrar("No se encontraron ventas en el rango especificado.", 26);
            getch();
            
        } else {
        	
            Centrar("Consulta finalizada. Presiona una tecla para continuar...", 26);
            getch();
            
        }
    }

} //ConsultarVentasPorFechas

int ValidarIdVentaConsulta(TaVentas aVentas, int eTotalVentas) {
    
	int eId, ePos;

    while (1) {
    	
        Mensaje(4, 44, "Ingrese el ID de la venta:");
        GoToXY(4, 71);
        eId = LeerEntero(4, 71, 6);

        ePos = BuscarVenta(aVentas, eTotalVentas, eId, 0);

        if (ePos == -1) {
        	
            Centrar("ID no encontrado. Intenta de nuevo.", 8);
            getch();
            BorrarZona(6, 37, 2, 50);
            
        } else {
        	
            return ePos;
            
        }
    }
    
} //ValidarIdVentaConsulta

void MostrarResumenVenta(TrVenta rVenta) {
    
	char sPlataforma[20];
    char sCancelada[3];

    if (rVenta.ePlataforma == MERCADOLIBRE) {
    	
        strcpy(sPlataforma, "MercadoLibre");
        
    } else if (rVenta.ePlataforma == SHOPIFY) {
    	
        strcpy(sPlataforma, "Shopify");
        
    } else if (rVenta.ePlataforma == INSTAGRAM) {
    	
        strcpy(sPlataforma, "Instagram");
        
    } else {
    	
        strcpy(sPlataforma, "Desconocido");
        
    }

    if (rVenta.eCancelada == 1) {
    	
        strcpy(sCancelada, "SI");
        
    } else {
    	
        strcpy(sCancelada, "NO");
        
    }

    Mensaje(10, 19, "ID Cliente:");
    Mensaje(10, 34, "%d", rVenta.eIdCliente);

    Mensaje(12, 15, "Fecha de venta:");
    Mensaje(12, 34, "%02d/%02d/%04d", rVenta.rFechaVenta.eDia, rVenta.rFechaVenta.eMes, rVenta.rFechaVenta.eAnio);

    Mensaje(14, 19, "Plataforma:");
    Mensaje(14, 34, "%s", sPlataforma);

    Mensaje(16, 21, "Subtotal:");
    Mensaje(16, 34, "$%.2f", rVenta.fSubtotal);

    Mensaje(18, 26, "IVA:");
    Mensaje(18, 34, "$%.2f", rVenta.fIva);

    Mensaje(20, 24, "Total:");
    Mensaje(20, 34, "$%.2f", rVenta.fTotal);
    
} //MostrarResumenVenta

void MostrarDatosCancelacion(TrVenta rVenta) {

    int eContador;
    char sTemp[33]; // 32 caracteres + '\0'

    Mensaje(8, 23, " VENTA:    CANCELADA");
    Mensaje(8, 60, "Motivo de cancelacion:");

    for (eContador = 0; eContador < 4; eContador++) {
        
		strncpy(sTemp, rVenta.sMotivoCancelacion + (eContador * 32), 32);
        sTemp[32] = '\0';

        if (strlen(sTemp) > 0) {
            
			Mensaje(10 + eContador, 60, "%s", sTemp);
        
		}
    }

    Mensaje(16, 60, "Fecha de cancelacion:");
    Mensaje(16, 82, "%02d/%02d/%04d", rVenta.rFechaCancelacion.eDia, rVenta.rFechaCancelacion.eMes, rVenta.rFechaCancelacion.eAnio);
        
} //MostrarDatosCancelacion

void ConsultarVentaPorId(TaVentas *aVentas, int eTotalVentas) {
	
    int eContador2, ePos;
    char sPlataforma[5];
    char sCancelada[5];
    char sTemp[32];
    TrVenta rVenta;

    Pantalla2();
    Centrar("CONSULTA DE VENTA POR ID", 1);

    if (eTotalVentas == 0) {
    	
        Centrar("No hay ventas", 26);
        
    } else {
    	
        ePos = ValidarIdVentaConsulta(*aVentas, eTotalVentas);
        rVenta = (*aVentas)[ePos];

		MostrarResumenVenta(rVenta);

        if (rVenta.eCancelada == 1) {
    		
			MostrarDatosCancelacion(rVenta);
			
		}

        Centrar("Consulta finalizada. Presiona una tecla para continuar...", 26);
    }

    getch();
    
} //ConsultarVentaPorId

void MostrarFilaVentaPlataforma(TrVenta rVenta, int eRenglon, char *sCancelada) {
	
    TrFecha rFechaVenta = rVenta.rFechaVenta;

    Mensaje(eRenglon, 21, "%d", rVenta.eIdVenta);
    Mensaje(eRenglon, 37, "%02d/%02d/%04d", rFechaVenta.eDia, rFechaVenta.eMes, rFechaVenta.eAnio);
    Mensaje(eRenglon, 59, "%d", rVenta.eIdCliente);
    Mensaje(eRenglon, 78, "%s", sCancelada);
    Mensaje(eRenglon, 96, "$%.2f", rVenta.fTotal);
    
} //MostrarFilaVentaPlataforma

void ImprimirVentasPorPlataforma(TaVentas *aVentas, int eTotalVentas, TePlataformas ePlataforma, int eMes, int eAnio, int *eVentas, 
								  float *fTotal, int eUltimaPlataforma){
    
    int eContador, eRenglon;
    char sCancelada[3];
    TrFecha rFechaVenta;
    TrVenta rVenta;

    *eVentas = 0;
    *fTotal = 0;
	eRenglon = 11;

	BorrarZona(11, 12, 12, 100);
	BorrarZona(6, 45, 2, 30);
	
    if (ePlataforma == MERCADOLIBRE){
    	
        Centrar("MERCADOLIBRE", 7);
        
    } else if (ePlataforma == SHOPIFY) {
    	
        Centrar("SHOPIFY", 7);
        
    } else if (ePlataforma == INSTAGRAM) {
    	
        Centrar("INSTAGRAM", 7);
    }

    TablaPlataforma();

    for (eContador = 0; eContador < eTotalVentas; eContador++) { //recorre las ventas

        rVenta = (*aVentas)[eContador]; //toma la venta donde esta el contador
        rFechaVenta = rVenta.rFechaVenta; //toma su fecha

        if (rVenta.ePlataforma == ePlataforma && rFechaVenta.eMes == eMes && rFechaVenta.eAnio == eAnio) { //mostrar si coincide plataforma,mes y año

            if (eRenglon > 19) { //imprime hasta la linea 19
            	
                Centrar("Presione una tecla para continuar...", 26);
                getch();
                BorrarZona(11, 12, 11, 90);
                eRenglon = 11;
            }
			
			if (rVenta.eCancelada == 1) {
            	
                strcpy(sCancelada, "SI");
                
            } else {
            	
                strcpy(sCancelada, "NO");
                
            }

            MostrarFilaVentaPlataforma(rVenta, eRenglon, sCancelada);
			
            *fTotal += rVenta.fTotal;
            *eVentas += 1;
            eRenglon++;
        }
    }

    Mensaje(21, 75, "# Ventas: %d", *eVentas);
    Mensaje(21, 92, "Total: $%.2f", *fTotal);

    if (!eUltimaPlataforma) { //si no es la última plataforma...
    	
        Centrar("Presione una tecla para continuar...", 26);
        getch();
        
    }
    
} //ImprimirVentasPorPlataforma

void ReporteMensualVentas(TaVentas *aVentas, int eTotalVentas) {

	char sPeriodo[15];
	int eVentasTotales, eVentasML, eVentasShopify, eVentasInstagram, eMes, eAnio;
	float fTotalVentas, fTotalML, fTotalShopify, fTotalInstagram;

	eVentasML = 0;
	eVentasShopify = 0;
	eVentasInstagram = 0;
	fTotalML = 0;
	fTotalShopify = 0;
	fTotalInstagram = 0;
	
    Pantalla5();
    Centrar("No vacancy", 1);
    Centrar("Subsistema de Ventas", 2);
    Centrar("REPORTE MENSUAL DE VENTAS", 3);

	if(eTotalVentas == 0){
		
		Centrar("No hay ventas", 26);

	} else {
		
	    Centrar("Ingrese el mes: ", 13);
	    eMes = LeerEnteroEnRango(13, 68, 1, 31);
	
	    Mensaje(15, 52, "Ingrese el a%co: ", 164);
	    eAnio = LeerEnteroEnRango(15, 68, 2020, 2100);
	
	    BorrarZona(13, 48, 4, 25);
	
	    sprintf(sPeriodo, "Periodo: %02d/%04d", eMes, eAnio);
	    Centrar(sPeriodo, 4);
	
	    ImprimirVentasPorPlataforma(aVentas, eTotalVentas, MERCADOLIBRE, eMes, eAnio, &eVentasML, &fTotalML, 0);
	    ImprimirVentasPorPlataforma(aVentas, eTotalVentas, SHOPIFY, eMes, eAnio, &eVentasShopify, &fTotalShopify, 0);
	    ImprimirVentasPorPlataforma(aVentas, eTotalVentas, INSTAGRAM, eMes, eAnio, &eVentasInstagram, &fTotalInstagram, 1);
	
	    eVentasTotales = eVentasML + eVentasShopify + eVentasInstagram;
	    fTotalVentas = fTotalML + fTotalShopify + fTotalInstagram;
	
	    Mensaje(23, 27, "# VENTAS TOTALES: %d", eVentasTotales);
	    Mensaje(23, 58, "TOTAL VENTAS DEL PERIODO: $%.2f", fTotalVentas);
	
	    Centrar("Se ha completado el reporte. Presione una tecla para continuar...", 26);
	}
	
    getch();
    
} //ReporteMensualVentas
