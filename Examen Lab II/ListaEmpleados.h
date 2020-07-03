#pragma once
#include "Empleado.h"
class ListaEmpleados {



	Empleado* primero;
	Empleado* ultimo;

	ListaEmpleados(void);

	bool estaVacia();
	void agregarEmpleado(int _codigo, string _nombre, float _salario,bool _activo, Empleado* _siguiente, Empleado* _anterior);
	void obtenerCantidadEmpleados();
	void actualizarSalario(float);
	void imprimirLista();
	void eliminarEmpleado(int);
	void desactivarEmpleado(int);
	void guardarEmpleados();


};
