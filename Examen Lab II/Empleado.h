#pragma once
#include <string>
#include <fstream>
using namespace std;

class Empleado {


private:
	int codigoEmpleado;
	string nombreEmpleado;
	float salario;
	bool activo;
	Empleado* siguiente;
	Empleado* anterior;
	fstream fer;

public:
	Empleado(void);
	Empleado(int, string, float, bool, Empleado*, Empleado*);

	void setCodigo(int);
	int getCodigo();
	void setNombre(string);
	string getNombre();
	void setSalario(float);
	float getSalario();
	void setActivo(bool);
	bool getActivo();
	void setSiguiente(Empleado*);
	Empleado* getSiguiente();
	void setAnterior(Empleado*);
	Empleado* getAnterior();

	void imprimirEmpleado();
	
};
