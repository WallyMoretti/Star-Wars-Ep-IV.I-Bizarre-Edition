#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <windows.h>
#include <pthread.h>
#include "gotoxy.h"
#include "StarWarsIntro.h"

// Hilo Musica Partida.
pthread_t hiloMusic;

/// Estructuras
typedef struct // Historia.
{
    int idActual; // ID del Nodo en el que se Encuentra.
    char historia[1200];
    char opcionA[700]; // Nodo Izquierda.
    char opcionB[700]; // Nodo Derecha.
    int idOpcionA; // Nodo Izquierda.
    int idOpcionB; // Nodo Derecha.
} stHistoria;

typedef struct nodoArbol
{
    stHistoria a; // Historia.
    struct nodoArbol * izq;
    struct nodoArbol * der;
} nodoArbol; // (Estructura Secundaria). Manejo de Historia.

typedef struct
{
    char nombreUsuario[30];
    char password[30];
    nodoArbol * arbolHistoria;
} celdaJugadores; // Arreglo (Estructura Primaria). Manejo de Usuarios.

typedef struct
{
    char nombreUsuario[30];
    char password[30];
    int IdActual;
} stPartidaGuardada; // Estructura que va a usarse para Guardar las Partidas en un Archivo.


// Funcion Musica Partida.
void reproducirMusica()
{
    while(TRUE)
    {
        PlaySound(TEXT("StarWarsTheme8bits.wav"),NULL,SND_FILENAME);
    }
}

/// Funciones

// OTRAS FUNCIONES //
void fullScreenAltEnter(); // FullScreen.
void consoleStopAndClean(); // Pausa y Limpia la Consola.
void printearTexto(int x, int y, char texto[]); // Printea un Texto en una Coordenada Especifica.

// MENU //
void menuPrincipal(); // Menu Principal del Juego.
void menuNuevaPartida(celdaJugadores array[], int validos); // Menu Opcion Nueva Partida.
void menuCargarPartida(celdaJugadores array[], int validos); // Menu Opcion Cargar Partida.

// INICIALIZAR //
void inicializarArrayArboles(celdaJugadores array[], int dimension); // Inicializa el Arreglo de Arboles.
nodoArbol * inicArbol(); // Inicializa los Arboles de cada Celda del Arreglo.
nodoArbol * crearNodoArbol(stHistoria a); // Crea un Nodo Arbol.

// AGREGAR //
nodoArbol * agregarAlArbol(nodoArbol * arbolito, nodoArbol * nuevoNodo); // Agrega un Nodo al Arbol.
int agregarUsuarioAndPasswordToArreglo_CrearPartidaArbol(celdaJugadores array[], int validos, char nameUser[], char passw[]); // Agrega un Usuario y Password al Arreglo. Crea y agrega los Nodos al Arbol.
int pasarArchivoPartidasGuardadasToArrayArboles(celdaJugadores array[], int validos); // Pasa del Archivo 'PartidasGuardadas' al Arreglo de Arboles.
int buscarUsuarioAndPasswordArrayArboles(celdaJugadores array[], int validos, char nameUser[], char passw[]); // Busca en el Arreglo de Arboles un Usuario con su correspondiente Password. Retorna la posicion si lo encuentra.

// COMPROBAR //
void mostrarUnNodoArbol(nodoArbol * arbolito); // Muestra UN solo Nodo del Arbol.
void mostrarArbolPreorder(nodoArbol * arbolito); // Muestra el Arbol de manera Preorder.
void mostrarArrayArbolesPreOrder(celdaJugadores array[], int validos); // Muestra un Arreglo de Arboles de manera PREORDER.

// PARTIDA //
void partida_funcionOne(nodoArbol * arbolito, int idDeter, char nameUser[], char passw[]); // Funcion Partida Parte 1.
int busquedaIdDeter_PrinteoHistoria_Decisiones(nodoArbol * arbolito, int idDeter, char nameUser[], char passw[]); // Funcion Partida Parte 2.
nodoArbol * buscarNodoEnElArbol(nodoArbol * arbolito, int idDeter); // Busca un Nodo en el Arbol Historia y lo retorna.
int tomaDeDecisiones(nodoArbol * nodoActual, char nameUser[], char passw[]); // Elige las Opciones disponibles para continuar la Historia.
void guardarPartidaArchivoPartidasGuardadas(char nameUser[], char passw[], int idDeter); // Copia en el Archivo 'PartidasGuardadas' el Usuario, Password y la ID Actual en la que se encuentra la Partida.
int cargarPartida_BuscarIdActual(char nameUser[], char passw[]); // Recibe el Usuario y Password y busca la ID Guardada.

// RECUADRO //
void recuadroJuego(); // Printea el Recuadro del Juego.
void recuadroSuperiorJuego(int x, int y); // Printea el Recuadro Superior del Juego.
void recuadroDerechoJuego(int x, int y); // Printea el Recuadro Derecho del Juego.
void recuadroInferiorJuego(int x, int y); // Printea el Recuadro Inferior del Juego.
void recuadroIzquierdoJuego(int x, int y); // Printea el Recuadro Izquierdo del Juego.
void gotoXY_printf218(int x, int y); // Printea ASCII 218.
void gotoXY_printf196(int x, int y); // Printea ASCII 196.
void gotoXY_printf191(int x, int y); // Printea ASCII 191.
void gotoXY_printf179(int x, int y); // Printea ASCII 179.
void gotoXY_printf217(int x, int y); // Printea ASCII 217.
void gotoXY_printf192(int x, int y); // Printea ASCII 192.


/// Main

int main()
{
    fullScreenAltEnter(); // Llamado a la Funcion FullScreen.
    menuPrincipal(); // Llamado a la Funcion Menu Principal.

    return 0;
}
void fullScreenAltEnter() // FullScreen.
{
    keybd_event(VK_MENU, 0x38, 0, 0); // Presiona ALT.
    keybd_event(VK_RETURN, 0x1c, 0, 0); // Presiona ENTER.
    keybd_event(VK_RETURN, 0x1c, KEYEVENTF_KEYUP, 0); // Libera ALT.
    keybd_event(VK_MENU, 0x38, KEYEVENTF_KEYUP, 0); // Libera ENTER.
}
void consoleStopAndClean() // Pausa y Limpia la Consola.
{
    system("pause");
    system("cls");
}
void printearTexto(int x, int y, char texto[]) // Printea un Texto en una Coordenada Especifica.
{
    gotoxy(x, y);
    printf("%s", texto);
}
void menuPrincipal() // Menu Principal del Juego.
{
    color(6);
    // VARIABLES //
    int z = 0, numeroMenu = 0; // Menu.

    int validosArregloUsuarios = 0; // Validos Arreglo.
    celdaJugadores arregloUsuarios[10]; // Arreglo.
    // VARIABLES //

    // Inicializo el Arreglo.
    inicializarArrayArboles(arregloUsuarios, 10); // Inicializacion de Arreglo.

    while(z == 0)
    {
        Sleep(2);
        printearTexto(60, 0, "WELCOME TO STAR WARS EPISODE IV.I - BIZARRE EDITION-");
        printearTexto(75, 15, "[1] - Nueva Partida");
        printearTexto(75, 16, "[2] - Cargar Partida");
        printearTexto(75, 18, "[0] - Salir");

        printearTexto(80, 21, "Opcion: ");
        fflush(stdin);
        scanf("%i", &numeroMenu);
        switch(numeroMenu)
        {
        case 1:
        {
            system("cls");
            menuNuevaPartida(arregloUsuarios, validosArregloUsuarios); // Llama a la Funcion 'menuNuevaPartida'.
            break;
        }
        case 2:
        {
            system("cls");
            menuCargarPartida(arregloUsuarios, validosArregloUsuarios); // Llama a la Funcion 'menuCargarPartida'.
            break;
        }
        case 0:
        {
            system("cls");
            printearTexto(60, 19, "Has dejado que el Imperio se salga con la suya :c");
            printearTexto(60, 21, "Press F to Pay Respect (Not for you)");
            printearTexto(0, 43, "");
            consoleStopAndClean();
            z++;
            break;
        }
        }
    }
}
void menuNuevaPartida(celdaJugadores array[], int validos) // Menu Opcion Nueva Partida.
{
    // VARIABLES //
    char nombreUsuario[30]; // Usuario.
    char password[30]; // Password del Usuario.
    int pos = -1; // Inicializada en -1. Cambia si encuentra la Posicion.
    // VARIABLES //

    printearTexto(65, 0, "---------------NUEVA PARTIDA---------------\n\n");

    // Funcion que pasa del Archivo 'PartidasGuardadas' al Arreglo de Arboles.
    validos = pasarArchivoPartidasGuardadasToArrayArboles(array, validos);

    // El Usuario Ingresa Contraseña y Password //
    printearTexto(73, 15, "Ingrese Usuario: ");
    fflush(stdin);
    gets(nombreUsuario);
    printearTexto(73, 16, "Ingrese Password: ");
    fflush(stdin);
    gets(password);

    // Comprueba si el Usuario y la Password estan en el Arreglo.
    pos = buscarUsuarioAndPasswordArrayArboles(array, validos, nombreUsuario, password);
    if(pos == -1)
    {
        // Si el Usuario y la Password no se encuentran en el Arreglo, lo agrega y confecciona el Arbol de la celda del Usuario.
        validos = agregarUsuarioAndPasswordToArreglo_CrearPartidaArbol(array, validos, nombreUsuario, password);
        pos = validos-1;

        // INTRO //

        // Hilo Musica.
        pthread_create(&hiloMusic, NULL, (void*) &reproducirMusica, NULL);
        system("cls");
        Sleep(1000);
        llamadoFinal();
        printearTexto(0, 43, "");
        Sleep(1000);
        system("cls");

        // Guardo la Partida por si el Usuario pierde.
        guardarPartidaArchivoPartidasGuardadas(nombreUsuario, password, 20);

        // Comienzo de la Partida.
        system("cls");
        partida_funcionOne(array[pos].arbolHistoria, 20, nombreUsuario, password);
    }
    else
    {
        system("cls");
        printearTexto(45, 16, "El Usuario y Password ya se encuentran registrados. Por favor, ingrese nuevos datos.\n\n");
        printearTexto(0, 43, "");
        consoleStopAndClean();
    }
}
void menuCargarPartida(celdaJugadores array[], int validos) // Menu Opcion Cargar Partida.
{
    // VARIABLES //
    char nombreUsuario[30]; // Usuario.
    char password[30]; // Password del Usuario.
    int pos = -1; // Inicializada en -1. Cambia si encuentra la Posicion.
    // VARIABLES //

    printearTexto(65, 0, "---------------CARGAR PARTIDA---------------\n\n");

    // Funcion que pasa del Archivo 'PartidasGuardadas' al Arreglo de Arboles.
    validos = pasarArchivoPartidasGuardadasToArrayArboles(array, validos);

    // El Usuario Ingresa Contraseña y Password //
    printearTexto(73, 15, "Ingrese Usuario: ");
    fflush(stdin);
    gets(nombreUsuario);
    printearTexto(73, 16, "Ingrese Password: ");
    fflush(stdin);
    gets(password);

    // Comprueba si el Usuario y la Password estan en el Arreglo.
    pos = buscarUsuarioAndPasswordArrayArboles(array, validos, nombreUsuario, password);
    if(pos == -1)
    {
        printearTexto(45, 16, "El Usuario y Password NO se encuentran cargados. Por favor, ingrese nuevos datos.\n\n");
        printearTexto(0, 43, "");
        consoleStopAndClean();
    }
    else
    {
        int idGuardada = cargarPartida_BuscarIdActual(nombreUsuario, password);
        system("cls");
        // Hilo Musica.
        pthread_create(&hiloMusic, NULL, (void*) &reproducirMusica, NULL);
        partida_funcionOne(array[pos].arbolHistoria, idGuardada, nombreUsuario, password);
    }
}
void inicializarArrayArboles(celdaJugadores array[], int dimension) // Inicializa el Arreglo de Arboles.
{
    // VARIABLES //
    int i = 0;
    // VARIABLES //

    for(i = 0; i<dimension; i++)
    {
        strcpy(array[i].nombreUsuario, "");
        strcpy(array[i].password, "");
        array[i].arbolHistoria = inicArbol();
    }
}
nodoArbol * crearNodoArbol(stHistoria a) // Crea un Nodo Arbol.
{
    nodoArbol * nuevoNodo = (nodoArbol *) malloc(sizeof(nodoArbol));
    nuevoNodo->a = a;
    nuevoNodo->izq = NULL;
    nuevoNodo->der = NULL;

    return nuevoNodo;
}
nodoArbol * inicArbol() // Inicializa los Arboles de cada Celda del Arreglo.
{
    return NULL;
}
nodoArbol * agregarAlArbol(nodoArbol * arbolito, nodoArbol * nuevoNodo) // Agrega un Nodo al Arbol.
{
    if(arbolito == NULL)
    {
        arbolito = nuevoNodo;
    }
    else
    {
        if(nuevoNodo->a.idActual < arbolito->a.idActual)
        {
            arbolito->izq = agregarAlArbol(arbolito->izq, nuevoNodo);
        }
        else
        {
            arbolito->der = agregarAlArbol(arbolito->der, nuevoNodo);
        }
    }

    return arbolito;
}
int agregarUsuarioAndPasswordToArreglo_CrearPartidaArbol(celdaJugadores array[], int validos, char nameUser[], char passw[]) // Agrega un Usuario y Password al Arreglo. Crea y agrega los Nodos al Arbol.
{
    // VARIABLES //
    stHistoria a;
    FILE * archiHistoria;
    // VARIABLES //

    strcpy(array[validos].nombreUsuario, nameUser);
    strcpy(array[validos].password, passw);

    archiHistoria = fopen("ArchivoHistoria", "rb"); // Abro el Archivo 'ArchivoHistoria' para copiar la Historia en el Arbol de la celda actual.
    if(archiHistoria != NULL)
    {
        while(fread(&a, sizeof(stHistoria), 1, archiHistoria) > 0)
        {
            nodoArbol * nuevoNodo = crearNodoArbol(a);
            array[validos].arbolHistoria = agregarAlArbol(array[validos].arbolHistoria, nuevoNodo); // Carga Nodo por Nodo al Arbol.
        }
        fclose(archiHistoria); // Cierro el Archivo 'ArchivoHistoria' una vez que copio toda la Historia en el Arbol.
    }
    validos++;

    return validos;
}
int pasarArchivoPartidasGuardadasToArrayArboles(celdaJugadores array[], int validos) // Pasa del Archivo 'PartidasGuardadas' al Arreglo de Arboles.
{
    // VARIABLES //
    stPartidaGuardada a;
    FILE * archiPartidasGuardadas;
    // VARIABLES //

    archiPartidasGuardadas = fopen("PartidasGuardadas", "rb");
    if(archiPartidasGuardadas != NULL)
    {
        while(fread(&a, sizeof(stPartidaGuardada), 1, archiPartidasGuardadas) > 0)
        {
            char nameUser[30];
            char passw[30];
            strcpy(nameUser, a.nombreUsuario);
            strcpy(passw, a.password);

            validos = agregarUsuarioAndPasswordToArreglo_CrearPartidaArbol(array, validos, nameUser, passw);
        }
    }

    return validos;
}
int buscarUsuarioAndPasswordArrayArboles(celdaJugadores array[], int validos, char nameUser[], char passw[]) // Busca en el Arreglo de Arboles un Usuario con su correspondiente Password. Retorna la posicion si lo encuentra.
{
    // VARIABLES //
    int i = 0, rta = -1;
    // VARIABLES //

    for(i = 0; i<validos; i++)
    {
        if(strcmp(array[i].nombreUsuario, nameUser) == 0)
        {
            if(strcmp(array[i].password, passw) == 0)
            {
                rta = i;
            }
        }
    }

    return rta;
}
void mostrarUnNodoArbol(nodoArbol * arbolito) // Muestra UN solo Nodo del Arbol.
{
    printf("------------------------------\n");
    printf("ID Actual: %i\n", arbolito->a.idActual);
    printf("Historia: %s\n", arbolito->a.historia);
    printf("Opcion A: %s\n", arbolito->a.opcionA);
    printf("Opcion B: %s\n", arbolito->a.opcionB);
    printf("ID Opcion A: %i\n", arbolito->a.idOpcionA);
    printf("ID Opcion B: %i\n", arbolito->a.idOpcionB);
    printf("------------------------------\n");
}
void mostrarArbolPreorder(nodoArbol * arbolito) // Muestra el Arbol de manera Preorder.
{
    if(arbolito != NULL)
    {
        mostrarUnNodoArbol(arbolito);
        mostrarArbolPreorder(arbolito->izq);
        mostrarArbolPreorder(arbolito->der);
    }
}
void mostrarArrayArbolesPreOrder(celdaJugadores array[], int validos) // Muestra un Arreglo de Arboles de manera PREORDER.
{
    // VARIABLES //
    int i = 0;
    // VARIABLES //

    for(i = 0; i<validos; i++)
    {
        printf("Usuario: %s\n", array[i].nombreUsuario);
        printf("Password: %s\n", array[i].password);
        printf("\n");
        mostrarArbolPreorder(array[i].arbolHistoria);
        printf("\n");
    }
}
void partida_funcionOne(nodoArbol * arbolito, int idDeter, char nameUser[], char passw[]) // Funcion Partida Parte 1.
{
    // VARIABLES //
    int idRetorno = idDeter;
    // VARIABLES //

    // Mientras la ID Retorno sea distinto de -1, sigue en el bucle del while. Realiza el llamado a 'busquedaIdDeter_PrinteoHistoria_Decisiones'.
    while(idRetorno != -1 && idRetorno != -2)
    {
        // Retorna la ID del siguiente Nodo. Si retorna -1, el juego termina. Si retorna -2, la partida se Guarda.
        idRetorno = busquedaIdDeter_PrinteoHistoria_Decisiones(arbolito, idRetorno, nameUser, passw);

        if(idRetorno == -1)
        {
            system("cls");
            printearTexto(60, 17,"La partida ha terminado. La fuerza no te ha ayudado. Khe sad\n\n");
            printearTexto(0, 43, "");
            consoleStopAndClean();
        }
        if(idRetorno == -2)
        {
            system("cls");
            printearTexto(65, 17, "La partida ha sido guardada con exito\n\n");
            printearTexto(0, 43, "");
            consoleStopAndClean();
        }
    }
}
int busquedaIdDeter_PrinteoHistoria_Decisiones(nodoArbol * arbolito, int idDeter, char nameUser[], char passw[]) // Funcion Partida Parte 2.
{
    // VARIABLES //
    int idRetorno = 0;
    nodoArbol * nodoActual = NULL;
    // VARIABLES //

    // Recibo el Nodo que necesito.
    nodoActual = buscarNodoEnElArbol(arbolito, idDeter);
    // Imprimo las Opciones y retorno la ID de la decision tomada.
    idRetorno = tomaDeDecisiones(nodoActual, nameUser, passw);


    return idRetorno;
}
nodoArbol * buscarNodoEnElArbol(nodoArbol * arbolito, int idDeter) // Busca un Nodo en el Arbol Historia y lo retorna.
{
    // VARIABLES //
    nodoArbol * retorno = NULL;

    if(arbolito != NULL)
    {
        if(idDeter == arbolito->a.idActual)
        {
            retorno = arbolito;
        }
        else
        {
            if(idDeter < arbolito->a.idActual)
            {
                retorno = buscarNodoEnElArbol(arbolito->izq, idDeter);
            }
            else
            {
                retorno = buscarNodoEnElArbol(arbolito->der, idDeter);
            }
        }
    }

    return retorno;
}
int tomaDeDecisiones(nodoArbol * nodoActual, char nameUser[], char passw[]) // Elige las Opciones disponibles para continuar la Historia.
{
    // VARIABLES //
    int idRetorno = 0;
    int x = 30, y = 11; // Ejes.
    int tamanioTexto = 0;
    char texto[1200];
    int contador = 0, altura = y;
    // VARIABLES //

    // Printea la Historia del Nodo actual.
    system("cls");
    tamanioTexto = strlen(nodoActual->a.historia); // Cantidad de Caracteres del Texto a Printear.
    strcpy(texto, nodoActual->a.historia);

    recuadroJuego();
    gotoxy(x, altura++);
    for(int i = 0; i<tamanioTexto; i++)
    {
        printf("%c", texto[i]); // Printea el Texto caracter por caracter.
        contador++;
        if(contador == 103) // Llegado el contador a el numero especificado, baja en Y y vuelve al Inicio de X para seguir printeando.
        {
            contador = 0;
            gotoxy(x, altura++);
        }
    }
    printearTexto(0, 43, "");
    system("pause>SystemPause");

    // Realiza las comprobaciones necesarias para retornar la ID adecuada para continuar con la Historia.
    if(nodoActual->a.idOpcionA == -1) // Opcion A = Lado Izquierdo.
    {
        // Si la Opcion A es igual a -1, toma el valor de la ID Opcion B y la retorna.
        idRetorno = nodoActual->a.idOpcionB;
    }
    if(nodoActual->a.idOpcionB == -1) // Opcion B = Lado Derecho.
    {
        // Si la Opcion B es igual a -1, toma el valor de la ID Opcion A y lo retorna.
        idRetorno = nodoActual->a.idOpcionA;
    }
    if(nodoActual->a.idOpcionA != -1 && nodoActual->a.idOpcionB != -1) // Si ambas Opciones son distintas de -1.
    {
        // VARIABLES //
        int opcion = 0;
        // VARIABLES //

        // Si ID Opcion A y B son distintas de -1, printea ambas Opciones y el Usuario elige cual.
        gotoxy(0, 32);
        printf("[1]. Opcion A: %s\n", nodoActual->a.opcionA); // Si elige Opcion A, continua con el Lado Izquierdo del Arbol.
        printf("---------------------------------------------------------------------------------------------------------\n");
        gotoxy(0, 34);
        printf("[2]. Opcion B: %s\n", nodoActual->a.opcionB); // Si elige Opcion B, continua con el Lado Derecho del Arbol.
        printf("---------------------------------------------------------------------------------------------------------\n");
        printearTexto(0, 37, "[3]. Guardar y Salir\n\n");
        printf("---------------------------------------------------------------------------------------------------------\n");
        printearTexto(0, 40, "Opcion: ");
        fflush(stdin);
        scanf("%i", &opcion);
        if(opcion == 1)
        {
            // Si elige la Opcion A, la funcion retorna la ID Opcion A.
            idRetorno = nodoActual->a.idOpcionA;
        }
        if(opcion == 2)
        {
            // Si elige la Opcion B, la funcion retorna la ID Opcion B.
            idRetorno = nodoActual->a.idOpcionB;
        }
        if(opcion == 3)
        {
            idRetorno = nodoActual->a.idActual;
            guardarPartidaArchivoPartidasGuardadas(nameUser, passw, idRetorno);
            idRetorno = -2;
            system("cls");
        }
    }

    return idRetorno;
}
void guardarPartidaArchivoPartidasGuardadas(char nameUser[], char passw[], int idDeter) // Copia en el Archivo 'PartidasGuardadas' el Usuario, Password y la ID Actual en la que se encuentra la Partida.
{
    // VARIABLES //
    stPartidaGuardada a;
    FILE * archiPartidasGuardadas;
    // VARIABLES //

    archiPartidasGuardadas = fopen("PartidasGuardadas", "ab");
    if(archiPartidasGuardadas != NULL)
    {
        strcpy(a.nombreUsuario, nameUser);
        strcpy(a.password, passw);
        a.IdActual = idDeter;

        fwrite(&a, sizeof(stPartidaGuardada), 1, archiPartidasGuardadas);

        fclose(archiPartidasGuardadas);
    }

}
int cargarPartida_BuscarIdActual(char nameUser[], char passw[]) // Recibe el Usuario y Password y busca la ID Guardada.
{
    // VARIABLES //
    int retorno = -1;
    stPartidaGuardada a;
    // VARIABLES //

    FILE * archiPartidasGuardadas;
    archiPartidasGuardadas = fopen("PartidasGuardadas", "rb");
    if(archiPartidasGuardadas != NULL)
    {
        while(fread(&a, sizeof(stPartidaGuardada), 1, archiPartidasGuardadas) > 0)
        {
            if(strcmp(a.nombreUsuario, nameUser) == 0)
            {
                if(strcmp(a.password, passw) == 0)
                {
                    retorno = a.IdActual;
                }
            }
        }
        fclose(archiPartidasGuardadas);
    }

    return retorno;
}
void recuadroJuego() // Printea el Recuadro del Juego.
{
    int x = 27, y = 8;
    recuadroSuperiorJuego(x, y);
    recuadroDerechoJuego(x+108, y+1);
    recuadroInferiorJuego(x+108, y+1);
    recuadroIzquierdoJuego(x, y+16);
}
void recuadroSuperiorJuego(int x, int y) // Printea el Recuadro Superior del Juego.
{
    gotoXY_printf218(x, y+1);
    gotoXY_printf196(x+1, y+1);
    gotoXY_printf196(x+2, y+1);
    gotoXY_printf196(x+3, y+1);
    gotoXY_printf196(x+4, y+1);
    gotoXY_printf196(x+5, y+1);
    gotoXY_printf196(x+6, y+1);
    gotoXY_printf196(x+7, y+1);
    gotoXY_printf196(x+8, y+1);
    gotoXY_printf196(x+9, y+1);
    gotoXY_printf196(x+10, y+1);
    gotoXY_printf196(x+11, y+1);
    gotoXY_printf196(x+12, y+1);
    gotoXY_printf196(x+13, y+1);
    gotoXY_printf196(x+14, y+1);
    gotoXY_printf196(x+15, y+1);
    gotoXY_printf196(x+16, y+1);
    gotoXY_printf196(x+17, y+1);
    gotoXY_printf196(x+18, y+1);
    gotoXY_printf196(x+19, y+1);
    gotoXY_printf196(x+20, y+1);
    gotoXY_printf196(x+21, y+1);
    gotoXY_printf196(x+22, y+1);
    gotoXY_printf196(x+23, y+1);
    gotoXY_printf196(x+24, y+1);
    gotoXY_printf196(x+25, y+1);
    gotoXY_printf196(x+26, y+1);
    gotoXY_printf196(x+27, y+1);
    gotoXY_printf196(x+28, y+1);
    gotoXY_printf196(x+29, y+1);
    gotoXY_printf196(x+30, y+1);
    gotoXY_printf196(x+31, y+1);
    gotoXY_printf196(x+32, y+1);
    gotoXY_printf196(x+33, y+1);
    gotoXY_printf196(x+34, y+1);
    gotoXY_printf196(x+35, y+1);
    gotoXY_printf196(x+36, y+1);
    gotoXY_printf196(x+37, y+1);
    gotoXY_printf196(x+38, y+1);
    gotoXY_printf196(x+39, y+1);
    gotoXY_printf196(x+40, y+1);
    gotoXY_printf196(x+41, y+1);
    gotoXY_printf196(x+42, y+1);
    gotoXY_printf196(x+43, y+1);
    gotoXY_printf196(x+44, y+1);
    gotoXY_printf196(x+45, y+1);
    gotoXY_printf196(x+46, y+1);
    gotoXY_printf196(x+47, y+1);
    gotoXY_printf196(x+48, y+1);
    gotoXY_printf196(x+49, y+1);
    gotoXY_printf196(x+50, y+1);
    gotoXY_printf196(x+51, y+1);
    gotoXY_printf196(x+52, y+1);
    gotoXY_printf196(x+53, y+1);
    gotoXY_printf196(x+54, y+1);
    gotoXY_printf196(x+55, y+1);
    gotoXY_printf196(x+56, y+1);
    gotoXY_printf196(x+57, y+1);
    gotoXY_printf196(x+58, y+1);
    gotoXY_printf196(x+59, y+1);
    gotoXY_printf196(x+60, y+1);
    gotoXY_printf196(x+61, y+1);
    gotoXY_printf196(x+62, y+1);
    gotoXY_printf196(x+63, y+1);
    gotoXY_printf196(x+64, y+1);
    gotoXY_printf196(x+65, y+1);
    gotoXY_printf196(x+66, y+1);
    gotoXY_printf196(x+67, y+1);
    gotoXY_printf196(x+68, y+1);
    gotoXY_printf196(x+69, y+1);
    gotoXY_printf196(x+70, y+1);
    gotoXY_printf196(x+71, y+1);
    gotoXY_printf196(x+72, y+1);
    gotoXY_printf196(x+73, y+1);
    gotoXY_printf196(x+74, y+1);
    gotoXY_printf196(x+75, y+1);
    gotoXY_printf196(x+76, y+1);
    gotoXY_printf196(x+77, y+1);
    gotoXY_printf196(x+78, y+1);
    gotoXY_printf196(x+79, y+1);
    gotoXY_printf196(x+80, y+1);
    gotoXY_printf196(x+81, y+1);
    gotoXY_printf196(x+82, y+1);
    gotoXY_printf196(x+83, y+1);
    gotoXY_printf196(x+84, y+1);
    gotoXY_printf196(x+85, y+1);
    gotoXY_printf196(x+86, y+1);
    gotoXY_printf196(x+87, y+1);
    gotoXY_printf196(x+88, y+1);
    gotoXY_printf196(x+89, y+1);
    gotoXY_printf196(x+90, y+1);
    gotoXY_printf196(x+91, y+1);
    gotoXY_printf196(x+92, y+1);
    gotoXY_printf196(x+93, y+1);
    gotoXY_printf196(x+94, y+1);
    gotoXY_printf196(x+95, y+1);
    gotoXY_printf196(x+96, y+1);
    gotoXY_printf196(x+97, y+1);
    gotoXY_printf196(x+98, y+1);
    gotoXY_printf196(x+99, y+1);
    gotoXY_printf196(x+100, y+1);
    gotoXY_printf196(x+101, y+1);
    gotoXY_printf196(x+102, y+1);
    gotoXY_printf196(x+103, y+1);
    gotoXY_printf196(x+104, y+1);
    gotoXY_printf196(x+105, y+1);
    gotoXY_printf196(x+106, y+1);
    gotoXY_printf196(x+107, y+1);
}
void recuadroDerechoJuego(int x, int y) // Printea el Recuadro Derecho del Juego.
{
    gotoXY_printf191(x, y);
    gotoXY_printf179(x, y+1);
    gotoXY_printf179(x, y+2);
    gotoXY_printf179(x, y+3);
    gotoXY_printf179(x, y+4);
    gotoXY_printf179(x, y+5);
    gotoXY_printf179(x, y+6);
    gotoXY_printf179(x, y+7);
    gotoXY_printf179(x, y+8);
    gotoXY_printf179(x, y+9);
    gotoXY_printf179(x, y+10);
    gotoXY_printf179(x, y+11);
    gotoXY_printf179(x, y+12);
    gotoXY_printf179(x, y+13);
    gotoXY_printf179(x, y+14);
    gotoXY_printf179(x, y+15);
    gotoXY_printf217(x, y+16);
}
void recuadroInferiorJuego(int x, int y) // Printea el Recuadro Inferior del Juego.
{
    gotoXY_printf217(x, y+16);
    gotoXY_printf196(x-1, y+16);
    gotoXY_printf196(x-2, y+16);
    gotoXY_printf196(x-3, y+16);
    gotoXY_printf196(x-4, y+16);
    gotoXY_printf196(x-5, y+16);
    gotoXY_printf196(x-6, y+16);
    gotoXY_printf196(x-7, y+16);
    gotoXY_printf196(x-8, y+16);
    gotoXY_printf196(x-9, y+16);
    gotoXY_printf196(x-10, y+16);
    gotoXY_printf196(x-11, y+16);
    gotoXY_printf196(x-12, y+16);
    gotoXY_printf196(x-13, y+16);
    gotoXY_printf196(x-14, y+16);
    gotoXY_printf196(x-15, y+16);
    gotoXY_printf196(x-16, y+16);
    gotoXY_printf196(x-17, y+16);
    gotoXY_printf196(x-18, y+16);
    gotoXY_printf196(x-19, y+16);
    gotoXY_printf196(x-20, y+16);
    gotoXY_printf196(x-21, y+16);
    gotoXY_printf196(x-22, y+16);
    gotoXY_printf196(x-23, y+16);
    gotoXY_printf196(x-24, y+16);
    gotoXY_printf196(x-25, y+16);
    gotoXY_printf196(x-26, y+16);
    gotoXY_printf196(x-27, y+16);
    gotoXY_printf196(x-28, y+16);
    gotoXY_printf196(x-29, y+16);
    gotoXY_printf196(x-30, y+16);
    gotoXY_printf196(x-31, y+16);
    gotoXY_printf196(x-32, y+16);
    gotoXY_printf196(x-33, y+16);
    gotoXY_printf196(x-34, y+16);
    gotoXY_printf196(x-35, y+16);
    gotoXY_printf196(x-36, y+16);
    gotoXY_printf196(x-37, y+16);
    gotoXY_printf196(x-38, y+16);
    gotoXY_printf196(x-39, y+16);
    gotoXY_printf196(x-40, y+16);
    gotoXY_printf196(x-41, y+16);
    gotoXY_printf196(x-42, y+16);
    gotoXY_printf196(x-43, y+16);
    gotoXY_printf196(x-44, y+16);
    gotoXY_printf196(x-45, y+16);
    gotoXY_printf196(x-46, y+16);
    gotoXY_printf196(x-47, y+16);
    gotoXY_printf196(x-48, y+16);
    gotoXY_printf196(x-49, y+16);
    gotoXY_printf196(x-50, y+16);
    gotoXY_printf196(x-51, y+16);
    gotoXY_printf196(x-52, y+16);
    gotoXY_printf196(x-53, y+16);
    gotoXY_printf196(x-54, y+16);
    gotoXY_printf196(x-55, y+16);
    gotoXY_printf196(x-56, y+16);
    gotoXY_printf196(x-57, y+16);
    gotoXY_printf196(x-58, y+16);
    gotoXY_printf196(x-59, y+16);
    gotoXY_printf196(x-60, y+16);
    gotoXY_printf196(x-61, y+16);
    gotoXY_printf196(x-62, y+16);
    gotoXY_printf196(x-63, y+16);
    gotoXY_printf196(x-64, y+16);
    gotoXY_printf196(x-65, y+16);
    gotoXY_printf196(x-66, y+16);
    gotoXY_printf196(x-67, y+16);
    gotoXY_printf196(x-68, y+16);
    gotoXY_printf196(x-69, y+16);
    gotoXY_printf196(x-70, y+16);
    gotoXY_printf196(x-71, y+16);
    gotoXY_printf196(x-72, y+16);
    gotoXY_printf196(x-73, y+16);
    gotoXY_printf196(x-74, y+16);
    gotoXY_printf196(x-75, y+16);
    gotoXY_printf196(x-76, y+16);
    gotoXY_printf196(x-77, y+16);
    gotoXY_printf196(x-78, y+16);
    gotoXY_printf196(x-79, y+16);
    gotoXY_printf196(x-80, y+16);
    gotoXY_printf196(x-81, y+16);
    gotoXY_printf196(x-82, y+16);
    gotoXY_printf196(x-83, y+16);
    gotoXY_printf196(x-84, y+16);
    gotoXY_printf196(x-85, y+16);
    gotoXY_printf196(x-86, y+16);
    gotoXY_printf196(x-87, y+16);
    gotoXY_printf196(x-88, y+16);
    gotoXY_printf196(x-89, y+16);
    gotoXY_printf196(x-90, y+16);
    gotoXY_printf196(x-91, y+16);
    gotoXY_printf196(x-92, y+16);
    gotoXY_printf196(x-93, y+16);
    gotoXY_printf196(x-94, y+16);
    gotoXY_printf196(x-95, y+16);
    gotoXY_printf196(x-96, y+16);
    gotoXY_printf196(x-97, y+16);
    gotoXY_printf196(x-98, y+16);
    gotoXY_printf196(x-99, y+16);
    gotoXY_printf196(x-100, y+16);
    gotoXY_printf196(x-101, y+16);
    gotoXY_printf196(x-102, y+16);
    gotoXY_printf196(x-103, y+16);
    gotoXY_printf196(x-104, y+16);
    gotoXY_printf196(x-105, y+16);
    gotoXY_printf196(x-106, y+16);
    gotoXY_printf196(x-107, y+16);
    gotoXY_printf192(x-108, y+16);
}
void recuadroIzquierdoJuego(int x, int y) // Printea el Recuadro Izquierdo del Juego.
{
    gotoXY_printf179(x, y);
    gotoXY_printf179(x, y-1);
    gotoXY_printf179(x, y-2);
    gotoXY_printf179(x, y-3);
    gotoXY_printf179(x, y-4);
    gotoXY_printf179(x, y-5);
    gotoXY_printf179(x, y-6);
    gotoXY_printf179(x, y-7);
    gotoXY_printf179(x, y-8);
    gotoXY_printf179(x, y-9);
    gotoXY_printf179(x, y-10);
    gotoXY_printf179(x, y-11);
    gotoXY_printf179(x, y-12);
    gotoXY_printf179(x, y-13);
    gotoXY_printf179(x, y-14);
}
void gotoXY_printf218(int x, int y) // Printea ASCII 218.
{
    gotoxy(x, y);
    printf("%c", 218);
}
void gotoXY_printf196(int x, int y) // Printea ASCII 196.
{
    gotoxy(x, y);
    printf("%c", 196);
}
void gotoXY_printf191(int x, int y) // Printea ASCII 191.
{
    gotoxy(x, y);
    printf("%c", 191);
}
void gotoXY_printf179(int x, int y) // Printea ASCII 179.
{
    gotoxy(x, y);
    printf("%c", 179);
}
void gotoXY_printf217(int x, int y) // Printea ASCII 217.
{
    gotoxy(x, y);
    printf("%c", 217);
}
void gotoXY_printf192(int x, int y) // Printea ASCII 192.
{
    gotoxy(x, y);
    printf("%c", 192);
}
