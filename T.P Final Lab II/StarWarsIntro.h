#ifndef STARWARSINTRO_H_INCLUDED
#define STARWARSINTRO_H_INCLUDED

////////////////////////////////////////////////// Star Wars Logo.

/// Funciones
void llamadoFinal(); // Llama a todas las Letras y las Printea.
void letra_S_T(int, int); // Printea las Letras ST.
void letra_A(int, int); // Printea la Letra A.
void letra_R(int, int); // Printea la Letra R.
void letra_W(int, int); // Printea la Letra W.
void letra_R_S(int, int); // Printea las Letras RS.

void gotoXY_printf218_sleep(int, int); // Printea ASCII 218.
void gotoXY_printf196_sleep(int, int); // Printea ASCII 196.
void gotoXY_printf191_sleep(int, int); // Printea ASCII 191.
void gotoXY_printf179_sleep(int, int); // Printea ASCII 179.
void gotoXY_printf217_sleep(int, int); // Printea ASCII 217.
void gotoXY_printf192_sleep(int, int); // Printea ASCII 192.
void gotoXY_printf47_sleep(int, int); // Printea ASCII 47.
void gotoXY_printf92_sleep(int, int); // Printea ASCII 92.

////////////////////////////////////////////////// Star Wars Logo.


////////////////////////////////////////////////// Star Wars Texto Intro.

/// Estructuras
typedef struct
{
    char texto[150];
}textoIntro;

/// Funciones
void consoleStopAndClean(); // Pausa y Limpia la Consola.
void cargarArchivoTextoIntro(); // Carga el Archivo 'textoIntro'.
void mostrarArchivoTextoIntro(); // Muestra Archivo 'textoIntro'.
void abrirArchivoTextoIntro(); // Abre Archivo 'textoIntro'. Se llama a la funcion mostrarArchivoRecursivo.
void mostrarArchivoTextoIntroAutomatico(FILE * archivo, int contador); // Muestra Archivo 'textoIntro' Recursivo Automatico(Star Wars Text).
void muestraUnCaseArchivoTextoIntro(FILE * archivo, int contador); // Muestra un Case Archivo 'textoIntro'.

////////////////////////////////////////////////// Star Wars Texto Intro.

#endif // STARWARSINTRO_H_INCLUDED











