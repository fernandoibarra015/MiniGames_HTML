#include "ListaEmpleados.h"
#include <conio.h>
#include <iostream>
int main()
{
	ListaEmpleados le;

	le.agregarEmpleado(1, "David", 6000);
	le.agregarEmpleado(2, "Raul", 5000);
	le.agregarEmpleado(3, "Jose", 7000);
	le.agregarEmpleado(4, "Manuel", 3000);

	cout << "Cantidad de empleados: " << le.obtenerCantidadEmpleados();

	le.imprimirLista();

	le.desactivarEmpleado(3);

	le.imprimirLista();

	le.desactivarEmpleado(3);

	le.imprimirLista();

	le.actualizarSalarios(0.50);

	le.imprimirLista();

	le.eliminarEmpleado(2);

	le.imprimirLista();

	le.obtenerCantidadEmpleados();

	le.guardarEmpleados();


}