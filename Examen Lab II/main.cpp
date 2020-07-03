#include "ListaEmpleados.h"
#include <conio.h>

int main()
{
	ListaEmpleados alo;

	
	alo.agregarElemento(4, "fer", 1000);
	alo.agregarElemento(2, "carlos", 2000);
	alo.agregarElemento(3, "juan", 3000);
	alo.agregarElemento(1, "jose", 5000);
	alo.imprimirLista();

	alo.desactivarEmpleado(4);
	alo.obtenerCantidadEmpleados();
	alo.imprimirLista();
	
	alo.eliminarEmpleado(1);
	alo.imprimirLista();
	alo.obtenerCantidadEmpleados();

	alo.actualizarSalarios(0.7);
	alo.imprimirLista();

	alo.guardarEmpleados();

	_getch();
}