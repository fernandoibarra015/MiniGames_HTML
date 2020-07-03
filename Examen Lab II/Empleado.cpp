#include "Empleado.h"
#include <iostream>

using namespace std;

Empleado::Empleado() :codigoEmpleado(-1), nombreEmpleado(nullptr), salario(0), activo(true), 
                      siguiente(nullptr), anterior(nullptr)
{}


Empleado::Empleado(int _codigo, string _nombre, float _salario, bool _activo, Empleado* _siguiente, Empleado* _anterior) {
	setCodigo(_codigo);
	setNombre(_nombre);
	setSalario(_salario);
	setActivo(_activo);
	setSiguiente(_siguiente);
	setAnterior(_anterior);
}

void Empleado::imprimirEmpleado() {

	Empleado empleado;
	cout << "Empleado { codigo: " << empleado.getCodigo() << ", nombre: " << empleado.getNombre() << 
		", salario: " << empleado.getSalario() << "\n";
}


void Empleado::setCodigo(int _codigo) {
	this->codigoEmpleado = _codigo;
}

int Empleado::getCodigo() {
	return codigoEmpleado;
}

void Empleado::setNombre(string _nombre) {
	this->nombreEmpleado = _nombre;
}

string Empleado::getNombre() {
	return nombreEmpleado;
}

void Empleado::setSalario(float _salario) {
	this->salario = _salario;
}

float Empleado::getSalario() {
	return salario;
}

void Empleado::setActivo(bool _activo) {
	this->activo = _activo;
}

bool Empleado::getActivo() {
	return activo;
}

void Empleado::setSiguiente(Empleado* _siguiente) {
	this->siguiente = _siguiente;
}

Empleado* Empleado::getSiguiente() {
	return siguiente;
}

void Empleado::setAnterior(Empleado* _anterior) {
	this->anterior = _anterior;
}

Empleado* Empleado::getAnterior() {
	return anterior;
}