#include "ArchivoPreguntas.h"
#include <fstream>
#include <iostream>

using namespace std;

void regisPreguntas() {

	preguntas preg;
	ofstream preguntasOut("preguntas.bin", ios::binary);
	strcpy(preg.pregunta, "Cual es el acronimo para Hypertext Markup Language?");
	strcpy(preg.respuesta, "HTML");
	strcpy(preg.respuestaIncorrecta, "HYMP");
	strcpy(preg.respuestaIncorrecta, "HYMALA");
	strcpy(preg.respuestaIncorrecta, "HMAL");

	strcpy(preg.pregunta, "Con que se comienza y cierra un documento de HTML?");
	strcpy(preg.respuesta, "<html> </html>");
	strcpy(preg.respuestaIncorrecta, "class html{}");
	strcpy(preg.respuestaIncorrecta, "(html) (/html)");
	strcpy(preg.respuestaIncorrecta, "<class> <endOfClass>");

	strcpy(preg.pregunta, "Cual ha sido el uso mas frecuente de HTML?");
	strcpy(preg.respuesta, "Desarrollo Web");
	strcpy(preg.respuestaIncorrecta, "Desarrollo de juegos");
	strcpy(preg.respuestaIncorrecta, "Bases de datos");
	strcpy(preg.respuestaIncorrecta, "Estilizar elementos");

	strcpy(preg.pregunta, "Cual de estas tecnologias no asiste a HTML?");
	strcpy(preg.respuesta, "NFC");
	strcpy(preg.respuestaIncorrecta, "Javascript");
	strcpy(preg.respuestaIncorrecta, "CSS");
	strcpy(preg.respuestaIncorrecta, "VBScript");

	preguntasOut.write((char*)&preg, sizeof(preguntas));
	preguntasOut.close();
}