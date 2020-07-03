#pragma once
#ifndef preguntas_h
#define preguntas_h

struct preguntas
{
	char pregunta[100]; 
	char respuesta[50]; 
	char respuestaIncorrecta[50];
}; 

void regisPreguntas();


#endif // !preguntas_h