#include "ListaEmpleados.h"
#include <iostream>

using namespace std;

ListaEmpleados::ListaEmpleados():primero(nullptr), ultimo(nullptr)
{}

bool ListaEmpleados::estaVacia()
{
	return primero == nullptr;
}

void ListaEmpleados::agregarEmpleado(int _codigo, string _nombre, float _salario, bool _activo, Empleado* _siguiente, Empleado* _anterior) {
	Empleado* nuevo = new Empleado(_codigo, _nombre, _salario, true, nullptr, nullptr);

	Empleado* actual = primero;

	if(estaVacia()){
		primero = nuevo;
		ultimo = nuevo;

		ultimo->setSiguiente(primero);
		primero->setAnterior(ultimo);
	}
	else {
		do {
			if (actual->getCodigo == _codigo)
			{
				cout << "Codigo de empleado a existe";
				return;
			}
			actual = actual->getSiguiente();

		} while (actual != primero);

		ultimo->setSiguiente(nuevo);
		nuevo->setAnterior(ultimo);

		ultimo = nuevo;

		ultimo->setSiguiente(primero);
		primero->setAnterior(ultimo);
	}
	cout << "Se ingreso empleado!!";
}

void ListaEmpleados::obtenerCantidadEmpleados() {
	if (estaVacia())
		return;

	Empleado* actual = primero;

	int cantidad = 0;

	do
	{
		cantidad++;
		actual = actual->getSiguiente();

	} while (actual != primero);

	cout<< cantidad;
}

void ListaEmpleados::actualizarSalario(float aumento) {
	if (estaVacia()) {

		return;
	}
	else {

		Empleado* actual = primero;

		while (actual != nullptr) {
			if (aumento > 0 && aumento < 1) {

				actual->setSalario(actual->getSalario() + (actual->getSalario() * aumento));
			}
			else {

				cout << "Salario no valido";
			}
			actual = actual->getSiguiente();
		}
	}

}

void ListaEmpleados::imprimirLista()
{

	if (estaVacia()) {

		return;
	}

	Empleado* actual = primero;
	Empleado emp;

	do {

		if (emp.getActivo() == true) {

			emp.imprimirEmpleado();
			actual = actual->getSiguiente();
		}
		cout << "\n";
	} while (actual != primero);
}

void ListaEmpleados::eliminarEmpleado(int _codigo) {
	if (estaVacia())
		return;

	Empleado* actual = primero;

	do
	{

		if (actual->getCodigo() == _codigo)
		{

			if (actual == primero)
			{
				primero = actual->getSiguiente();
				primero->setAnterior(ultimo);
				ultimo->setSiguiente(primero);

				delete actual;
			}
			else if (actual == ultimo)
			{
				ultimo = actual->getAnterior();
				ultimo->setSiguiente(primero);
				primero->setAnterior(ultimo);

				delete actual;

			}
			else
			{
				actual->getAnterior()->setSiguiente(actual->getSiguiente());
				actual->getSiguiente()->setAnterior(actual->getAnterior());

				delete actual;
			}

			cout << "Nodo Eliminado!\n";
			return;

		}
		else
			actual = actual->getSiguiente();

	} while (actual != primero);
}

void ListaEmpleados::desactivarEmpleado(int _codigo) {
	if (estaVacia()) {

		return;
	}

	Empleado* actual = primero;

	do {

		if (actual->getCodigo() == _codigo) {

			actual->setActivo(false);
		}
		else {
			actual = actual->getSiguiente();
		}

	} while (actual != primero);
}

void ListaEmpleados::guardarEmpleados(){
	Empleado* actual = primero;

	do {
		if (actual->getActivo() == true) {

			ofstream fer("ListaEmpleados.bin", ios::out | ios::binary);

			if (!fer) {

				cout << "Error al intentar abrir archivo\n";
				return;
			}

			actual->getCodigo();
			actual->getNombre();
			actual->getSalario();

			fer.write(reinterpret_cast<const char*>(&actual), sizeof(ListaEmpleados));
			actual = actual->getSiguiente();
		}
		else {
			actual = actual->getSiguiente();
		}
	} while (actual != primero);
}