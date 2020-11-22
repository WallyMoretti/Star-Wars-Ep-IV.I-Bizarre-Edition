#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <windows.h>
#include "gotoxy.h"
#include "StarWarsIntro.h"

/// Constantes Star Wars Logo.
const int velocidadCreacionTexto = 10;

/// Constantes Star Wars Texto Intro.
const int tiempoEsperaTextIntro = 800;


////////////////////////////////////////////////// Star Wars Logo.

void llamadoFinal() // Llama a todas las Letras y las Printea.
{
    int x=30;
    int y=10;
    color(6);
    letra_S_T(x+20, y);
    letra_A(x+20, y);
    letra_R(x+20, y);
    letra_W(x+20, y);
    letra_A(x+9, y+12);
    letra_R_S(x+7, y+12);
    gotoxy(x+94, y+22);
    color(0);
    Sleep(1500);
    letra_S_T(x+20, y);
    letra_A(x+20, y);
    letra_R(x+20, y);
    letra_W(x+20, y);
    letra_A(x+9, y+12);
    letra_R_S(x+7, y+12);
    abrirArchivoTextoIntro();
}
void letra_S_T(int x, int y) // Printea las Letras ST.
{
    /// Techo Letras ST
    gotoXY_printf196_sleep(x, y);
    gotoXY_printf196_sleep(x+1, y);
    gotoXY_printf196_sleep(x+2, y);
    gotoXY_printf196_sleep(x+3, y);
    gotoXY_printf196_sleep(x+4, y);
    gotoXY_printf196_sleep(x+5, y);
    gotoXY_printf196_sleep(x+6, y);
    gotoXY_printf196_sleep(x+7, y);
    gotoXY_printf196_sleep(x+8, y);
    gotoXY_printf196_sleep(x+9, y);
    gotoXY_printf196_sleep(x+10, y);
    gotoXY_printf196_sleep(x+11, y);
    gotoXY_printf196_sleep(x+12, y);
    gotoXY_printf196_sleep(x+13, y);
    gotoXY_printf196_sleep(x+14, y);
    gotoXY_printf196_sleep(x+15, y);
    gotoXY_printf196_sleep(x+16, y);
    gotoXY_printf196_sleep(x+17, y);
    gotoXY_printf196_sleep(x+18, y);
    gotoXY_printf196_sleep(x+19, y);
    gotoXY_printf196_sleep(x+20, y);
    gotoXY_printf196_sleep(x+21, y);
    gotoXY_printf196_sleep(x+22, y);
    gotoXY_printf196_sleep(x+23, y);
    gotoXY_printf196_sleep(x+24, y);
    gotoXY_printf191_sleep(x+25, y);

    /// Costado Derecho Letra T
    gotoXY_printf179_sleep(x+25, y+1);
    gotoXY_printf179_sleep(x+25, y+2);
    gotoXY_printf217_sleep(x+25, y+3);
    gotoXY_printf196_sleep(x+24, y+3);
    gotoXY_printf196_sleep(x+23, y+3);
    gotoXY_printf196_sleep(x+22, y+3);
    gotoXY_printf196_sleep(x+21, y+3);
    gotoXY_printf196_sleep(x+20, y+3);
    gotoXY_printf196_sleep(x+19, y+3);
    gotoXY_printf196_sleep(x+18, y+3);
    gotoXY_printf218_sleep(x+17, y+3);
    gotoXY_printf179_sleep(x+17, y+4);
    gotoXY_printf179_sleep(x+17, y+5);
    gotoXY_printf179_sleep(x+17, y+6);
    gotoXY_printf179_sleep(x+17, y+7);
    gotoXY_printf179_sleep(x+17, y+8);
    gotoXY_printf179_sleep(x+17, y+9);
    gotoXY_printf217_sleep(x+17, y+10);

    /// Piso Letra T
    gotoXY_printf196_sleep(x+16, y+10);
    gotoXY_printf196_sleep(x+15, y+10);
    gotoXY_printf196_sleep(x+14, y+10);
    gotoXY_printf196_sleep(x+13, y+10);
    gotoXY_printf196_sleep(x+12, y+10);
    gotoXY_printf192_sleep(x+12, y+10);

    /// Costado Izquierdo Letra T
    gotoXY_printf179_sleep(x+12, y+9);
    gotoXY_printf179_sleep(x+12, y+8);
    gotoXY_printf179_sleep(x+12, y+7);
    gotoXY_printf179_sleep(x+12, y+6);
    gotoXY_printf179_sleep(x+12, y+5);
    gotoXY_printf179_sleep(x+12, y+4);
    gotoXY_printf191_sleep(x+12, y+3);

    /// Costado Derecho Letra S
    gotoXY_printf196_sleep(x+11, y+3);
    gotoXY_printf196_sleep(x+10, y+3);
    gotoXY_printf196_sleep(x+9, y+3);
    gotoXY_printf196_sleep(x+8, y+3);
    gotoXY_printf196_sleep(x+7, y+3);
    gotoXY_printf196_sleep(x+6, y+3);
    gotoXY_printf196_sleep(x+5, y+3);
    gotoXY_printf92_sleep(x+5, y+4);
    gotoXY_printf92_sleep(x+6, y+5);
    gotoXY_printf92_sleep(x+7, y+6);
    gotoXY_printf47_sleep(x+8, y+7);
    gotoXY_printf47_sleep(x+7, y+8);
    gotoXY_printf47_sleep(x+6, y+9);

    /// Piso Letra S
    gotoXY_printf196_sleep(x+5, y+10);
    gotoXY_printf196_sleep(x+4, y+10);
    gotoXY_printf196_sleep(x+3, y+10);
    gotoXY_printf196_sleep(x+2, y+10);
    gotoXY_printf196_sleep(x+1, y+10);
    gotoXY_printf196_sleep(x, y+10);
    gotoXY_printf196_sleep(x-1, y+10);
    gotoXY_printf196_sleep(x-2, y+10);
    gotoXY_printf196_sleep(x-3, y+10);
    gotoXY_printf196_sleep(x-4, y+10);
    gotoXY_printf196_sleep(x-5, y+10);
    gotoXY_printf196_sleep(x-6, y+10);
    gotoXY_printf196_sleep(x-7, y+10);
    gotoXY_printf196_sleep(x-8, y+10);
    gotoXY_printf196_sleep(x-9, y+10);
    gotoXY_printf196_sleep(x-10, y+10);
    gotoXY_printf196_sleep(x-11, y+10);
    gotoXY_printf196_sleep(x-12, y+10);
    gotoXY_printf196_sleep(x-13, y+10);
    gotoXY_printf196_sleep(x-14, y+10);
    gotoXY_printf196_sleep(x-15, y+10);
    gotoXY_printf196_sleep(x-16, y+10);
    gotoXY_printf192_sleep(x-16, y+10);

    /// Costado Izquierdo Letra S
    gotoXY_printf179_sleep(x-16, y+9);
    gotoXY_printf179_sleep(x-16, y+8);
    gotoXY_printf218_sleep(x-16, y+7);
    gotoXY_printf196_sleep(x-15, y+7);
    gotoXY_printf196_sleep(x-14, y+7);
    gotoXY_printf196_sleep(x-13, y+7);
    gotoXY_printf196_sleep(x-12, y+7);
    gotoXY_printf196_sleep(x-11, y+7);
    gotoXY_printf196_sleep(x-10, y+7);
    gotoXY_printf196_sleep(x-9, y+7);
    gotoXY_printf196_sleep(x-8, y+7);
    gotoXY_printf196_sleep(x-7, y+7);
    gotoXY_printf196_sleep(x-6, y+7);
    gotoXY_printf196_sleep(x-5, y+7);
    gotoXY_printf196_sleep(x-4, y+7);
    gotoXY_printf196_sleep(x-3, y+7);
    gotoXY_printf92_sleep(x-3, y+6);
    gotoXY_printf92_sleep(x-4, y+5);
    gotoXY_printf92_sleep(x-5, y+4);
    gotoXY_printf47_sleep(x-6, y+3);
    gotoXY_printf47_sleep(x-5, y+2);
    gotoXY_printf47_sleep(x-4, y+1);
    gotoXY_printf196_sleep(x-3, y);
    gotoXY_printf196_sleep(x-2, y);
    gotoXY_printf196_sleep(x-1, y);
}
void letra_A(int x, int y) // Printea la Letra A.
{
    /// Techo Letra A
    gotoXY_printf196_sleep(x+29, y);
    gotoXY_printf196_sleep(x+30, y);
    gotoXY_printf196_sleep(x+31, y);
    gotoXY_printf196_sleep(x+32, y);
    gotoXY_printf196_sleep(x+33, y);
    gotoXY_printf196_sleep(x+34, y);
    gotoXY_printf196_sleep(x+35, y);
    gotoXY_printf196_sleep(x+36, y);
    gotoXY_printf196_sleep(x+37, y);
    gotoXY_printf196_sleep(x+38, y);
    gotoXY_printf196_sleep(x+39, y);
    gotoXY_printf196_sleep(x+40, y);

    /// Costado Derecho Letra A
    gotoXY_printf92_sleep(x+41, y+1);
    gotoXY_printf92_sleep(x+42, y+2);
    gotoXY_printf92_sleep(x+43, y+3);
    gotoXY_printf92_sleep(x+44, y+4);
    gotoXY_printf92_sleep(x+45, y+5);
    gotoXY_printf92_sleep(x+46, y+6);
    gotoXY_printf92_sleep(x+47, y+7);
    gotoXY_printf92_sleep(x+48, y+8);
    gotoXY_printf92_sleep(x+49, y+9);

    /// Piso Letra A
    gotoXY_printf196_sleep(x+49, y+10);
    gotoXY_printf196_sleep(x+48, y+10);
    gotoXY_printf196_sleep(x+47, y+10);
    gotoXY_printf196_sleep(x+46, y+10);
    gotoXY_printf196_sleep(x+45, y+10);
    gotoXY_printf196_sleep(x+44, y+10);
    gotoXY_printf196_sleep(x+43, y+10);
    gotoXY_printf196_sleep(x+42, y+10);
    gotoXY_printf196_sleep(x+41, y+10);
    gotoXY_printf196_sleep(x+40, y+10);
    gotoXY_printf196_sleep(x+39, y+10);
    gotoXY_printf92_sleep(x+38, y+9);
    gotoXY_printf92_sleep(x+37, y+8);
    gotoXY_printf196_sleep(x+36, y+7);
    gotoXY_printf196_sleep(x+35, y+7);
    gotoXY_printf196_sleep(x+34, y+7);
    gotoXY_printf196_sleep(x+33, y+7);
    gotoXY_printf47_sleep(x+32, y+8);
    gotoXY_printf47_sleep(x+31, y+9);
    gotoXY_printf196_sleep(x+30, y+10);
    gotoXY_printf196_sleep(x+29, y+10);
    gotoXY_printf196_sleep(x+28, y+10);
    gotoXY_printf196_sleep(x+27, y+10);
    gotoXY_printf196_sleep(x+26, y+10);
    gotoXY_printf196_sleep(x+25, y+10);
    gotoXY_printf196_sleep(x+24, y+10);
    gotoXY_printf196_sleep(x+23, y+10);
    gotoXY_printf196_sleep(x+22, y+10);
    gotoXY_printf196_sleep(x+21, y+10);
    gotoXY_printf196_sleep(x+20, y+10);

    /// Costado Izquierdo Letra A
    gotoXY_printf47_sleep(x+20, y+9);
    gotoXY_printf47_sleep(x+21, y+8);
    gotoXY_printf47_sleep(x+22, y+7);
    gotoXY_printf47_sleep(x+23, y+6);
    gotoXY_printf47_sleep(x+24, y+5);
    gotoXY_printf47_sleep(x+25, y+4);
    gotoXY_printf47_sleep(x+26, y+3);
    gotoXY_printf47_sleep(x+27, y+2);
    gotoXY_printf47_sleep(x+28, y+1);

    /// Centro Letra A
    gotoXY_printf196_sleep(x+36, y+5);
    gotoXY_printf196_sleep(x+35, y+5);
    gotoXY_printf92_sleep(x+36, y+4);
    gotoXY_printf92_sleep(x+35, y+3);
    gotoXY_printf47_sleep(x+32, y+4);
    gotoXY_printf47_sleep(x+33, y+3);
    gotoXY_printf196_sleep(x+32, y+5);
    gotoXY_printf196_sleep(x+34, y+5);
    gotoXY_printf196_sleep(x+33, y+5);
}
void letra_R(int x, int y) // Printea la Letra R.
{
    /// Techo Letra R
    gotoXY_printf196_sleep(x+52, y);
    gotoXY_printf196_sleep(x+53, y);
    gotoXY_printf196_sleep(x+54, y);
    gotoXY_printf196_sleep(x+55, y);
    gotoXY_printf196_sleep(x+56, y);
    gotoXY_printf196_sleep(x+57, y);
    gotoXY_printf196_sleep(x+58, y);
    gotoXY_printf196_sleep(x+59, y);
    gotoXY_printf196_sleep(x+60, y);
    gotoXY_printf196_sleep(x+61, y);
    gotoXY_printf196_sleep(x+62, y);
    gotoXY_printf196_sleep(x+63, y);
    gotoXY_printf196_sleep(x+64, y);

    /// Costado Derecho Letra R
    gotoXY_printf92_sleep(x+65, y+1);
    gotoXY_printf92_sleep(x+66, y+2);
    gotoXY_printf47_sleep(x+66, y+3);
    gotoXY_printf47_sleep(x+65, y+4);
    gotoXY_printf47_sleep(x+64, y+5);
    gotoXY_printf92_sleep(x+65, y+6);
    gotoXY_printf196_sleep(x+66, y+7);
    gotoXY_printf196_sleep(x+67, y+7);
    gotoXY_printf196_sleep(x+68, y+7);
    gotoXY_printf196_sleep(x+69, y+7);
    gotoXY_printf196_sleep(x+70, y+7);
    gotoXY_printf196_sleep(x+71, y+7);
    gotoXY_printf196_sleep(x+72, y+7);
    gotoXY_printf196_sleep(x+73, y+7);
    gotoXY_printf196_sleep(x+74, y+7);
    gotoXY_printf191_sleep(x+75, y+7);
    gotoXY_printf179_sleep(x+75, y+8);
    gotoXY_printf179_sleep(x+75, y+9);
    gotoXY_printf217_sleep(x+75, y+10);

    /// Piso Letra R
    gotoXY_printf196_sleep(x+74, y+10);
    gotoXY_printf196_sleep(x+73, y+10);
    gotoXY_printf196_sleep(x+72, y+10);
    gotoXY_printf196_sleep(x+71, y+10);
    gotoXY_printf196_sleep(x+70, y+10);
    gotoXY_printf196_sleep(x+69, y+10);
    gotoXY_printf196_sleep(x+68, y+10);
    gotoXY_printf196_sleep(x+67, y+10);
    gotoXY_printf196_sleep(x+66, y+10);
    gotoXY_printf196_sleep(x+65, y+10);
    gotoXY_printf196_sleep(x+64, y+10);
    gotoXY_printf196_sleep(x+63, y+10);
    gotoXY_printf196_sleep(x+62, y+10);
    gotoXY_printf196_sleep(x+61, y+10);
    gotoXY_printf92_sleep(x+60, y+9);
    gotoXY_printf92_sleep(x+59, y+8);
    gotoXY_printf218_sleep(x+57, y+7);
    gotoXY_printf179_sleep(x+57, y+8);
    gotoXY_printf179_sleep(x+57, y+9);
    gotoXY_printf217_sleep(x+57, y+10);
    gotoXY_printf196_sleep(x+56, y+10);
    gotoXY_printf196_sleep(x+55, y+10);
    gotoXY_printf196_sleep(x+54, y+10);
    gotoXY_printf196_sleep(x+53, y+10);
    gotoXY_printf192_sleep(x+52, y+10);

    /// Costado Derecho Letra R
    gotoXY_printf179_sleep(x+52, y+9);
    gotoXY_printf179_sleep(x+52, y+8);
    gotoXY_printf179_sleep(x+52, y+7);
    gotoXY_printf179_sleep(x+52, y+6);
    gotoXY_printf179_sleep(x+52, y+5);
    gotoXY_printf179_sleep(x+52, y+4);
    gotoXY_printf179_sleep(x+52, y+3);
    gotoXY_printf179_sleep(x+52, y+2);
    gotoXY_printf179_sleep(x+52, y+1);
    gotoXY_printf218_sleep(x+52, y);

    /// Centro Letra R
    gotoXY_printf218_sleep(x+56, y+2);
    gotoXY_printf179_sleep(x+56, y+3);
    gotoXY_printf192_sleep(x+56, y+4);
    gotoXY_printf196_sleep(x+57, y+4);
    gotoXY_printf196_sleep(x+58, y+4);
    gotoXY_printf196_sleep(x+59, y+4);
    gotoXY_printf217_sleep(x+60, y+4);
    gotoXY_printf179_sleep(x+60, y+3);
    gotoXY_printf191_sleep(x+60, y+2);
    gotoXY_printf196_sleep(x+59, y+2);
    gotoXY_printf196_sleep(x+58, y+2);
    gotoXY_printf196_sleep(x+57, y+2);
}
void letra_W(int x,int y) // Printea la Letra W.
{
    /// Costado Izquierdo Letra W
    gotoXY_printf218_sleep(x-16, y+12);
    gotoXY_printf179_sleep(x-16, y+13);
    gotoXY_printf179_sleep(x-16, y+14);
    gotoXY_printf179_sleep(x-16, y+15);
    gotoXY_printf179_sleep(x-16, y+16);
    gotoXY_printf179_sleep(x-16, y+17);
    gotoXY_printf179_sleep(x-16, y+18);
    gotoXY_printf179_sleep(x-16, y+19);
    gotoXY_printf179_sleep(x-16, y+20);
    gotoXY_printf179_sleep(x-16, y+21);
    gotoXY_printf192_sleep(x-16, y+22);

    /// Piso Letra W
    gotoXY_printf196_sleep(x-15, y+22);
    gotoXY_printf196_sleep(x-14, y+22);
    gotoXY_printf196_sleep(x-13, y+22);
    gotoXY_printf196_sleep(x-12, y+22);
    gotoXY_printf196_sleep(x-11, y+22);
    gotoXY_printf196_sleep(x-10, y+22);
    gotoXY_printf196_sleep(x-9, y+22);
    gotoXY_printf196_sleep(x-8, y+22);
    gotoXY_printf47_sleep(x-7, y+21);
    gotoXY_printf47_sleep(x-6, y+20);
    gotoXY_printf47_sleep(x-5, y+19);
    gotoXY_printf92_sleep(x-4, y+19);
    gotoXY_printf92_sleep(x-3, y+20);
    gotoXY_printf92_sleep(x-2, y+21);
    gotoXY_printf196_sleep(x-1, y+22);
    gotoXY_printf196_sleep(x, y+22);
    gotoXY_printf196_sleep(x+1, y+22);
    gotoXY_printf196_sleep(x+2, y+22);
    gotoXY_printf196_sleep(x+3, y+22);
    gotoXY_printf196_sleep(x+4, y+22);
    gotoXY_printf196_sleep(x+5, y+22);
    gotoXY_printf196_sleep(x+6, y+22);

    /// Costado Derecho W
    gotoXY_printf217_sleep(x+7, y+22);
    gotoXY_printf179_sleep(x+7, y+21);
    gotoXY_printf179_sleep(x+7, y+20);
    gotoXY_printf179_sleep(x+7, y+19);
    gotoXY_printf179_sleep(x+7, y+18);
    gotoXY_printf179_sleep(x+7, y+17);
    gotoXY_printf179_sleep(x+7, y+16);
    gotoXY_printf179_sleep(x+7, y+15);
    gotoXY_printf179_sleep(x+7, y+14);
    gotoXY_printf179_sleep(x+7, y+13);
    gotoXY_printf191_sleep(x+7, y+12);

    /// Techo Letra W
    gotoXY_printf196_sleep(x+6, y+12);
    gotoXY_printf196_sleep(x+5, y+12);
    gotoXY_printf196_sleep(x+4, y+12);
    gotoXY_printf196_sleep(x+3, y+12);
    gotoXY_printf218_sleep(x+2, y+12);
    gotoXY_printf179_sleep(x+2, y+13);
    gotoXY_printf179_sleep(x+2, y+14);
    gotoXY_printf179_sleep(x+2, y+15);
    gotoXY_printf179_sleep(x+2, y+16);
    gotoXY_printf179_sleep(x+2, y+17);
    gotoXY_printf179_sleep(x+2, y+18);
    gotoXY_printf179_sleep(x+2, y+19);
    gotoXY_printf92_sleep(x+1, y+19);
    gotoXY_printf196_sleep(x, y+18);
    gotoXY_printf92_sleep(x, y+18);
    gotoXY_printf92_sleep(x-1, y+17);
    gotoXY_printf92_sleep(x-2, y+16);
    gotoXY_printf92_sleep(x-3, y+15);
    gotoXY_printf92_sleep(x-4, y+14);
    gotoXY_printf47_sleep(x-5, y+14);
    gotoXY_printf47_sleep(x-6, y+15);
    gotoXY_printf47_sleep(x-7, y+16);
    gotoXY_printf47_sleep(x-8, y+17);
    gotoXY_printf47_sleep(x-9, y+18);
    gotoXY_printf47_sleep(x-10, y+19);
    gotoXY_printf179_sleep(x-11, y+19);
    gotoXY_printf179_sleep(x-11, y+18);
    gotoXY_printf179_sleep(x-11, y+17);
    gotoXY_printf179_sleep(x-11, y+16);
    gotoXY_printf179_sleep(x-11, y+15);
    gotoXY_printf179_sleep(x-11, y+14);
    gotoXY_printf179_sleep(x-11, y+13);
    gotoXY_printf191_sleep(x-11, y+12);
    gotoXY_printf196_sleep(x-12, y+12);
    gotoXY_printf196_sleep(x-13, y+12);
    gotoXY_printf196_sleep(x-14, y+12);
    gotoXY_printf196_sleep(x-15, y+12);
}
void letra_R_S(int x, int y) // Printea las Letras RS.
{
    /// Techo Letra R
    gotoXY_printf196_sleep(x+52, y);
    gotoXY_printf196_sleep(x+53, y);
    gotoXY_printf196_sleep(x+54, y);
    gotoXY_printf196_sleep(x+55, y);
    gotoXY_printf196_sleep(x+56, y);
    gotoXY_printf196_sleep(x+57, y);
    gotoXY_printf196_sleep(x+58, y);
    gotoXY_printf196_sleep(x+59, y);
    gotoXY_printf196_sleep(x+60, y);
    gotoXY_printf196_sleep(x+61, y);
    gotoXY_printf196_sleep(x+62, y);
    gotoXY_printf196_sleep(x+63, y);
    gotoXY_printf196_sleep(x+64, y);

    /// Costado Derecho Letra R
    gotoXY_printf92_sleep(x+65, y+1);
    gotoXY_printf92_sleep(x+66, y+2);
    gotoXY_printf92_sleep(x+67, y+3);
    gotoXY_printf47_sleep(x+67, y+4);
    gotoXY_printf47_sleep(x+66, y+5);
    gotoXY_printf47_sleep(x+65, y+6);
    gotoXY_printf192_sleep(x+65, y+7);

    ///Union Letras RS
    gotoXY_printf196_sleep(x+66, y+7);
    gotoXY_printf196_sleep(x+67, y+7);
    gotoXY_printf196_sleep(x+68, y+7);
    gotoXY_printf196_sleep(x+69, y+7);
    gotoXY_printf196_sleep(x+70, y+7);
    gotoXY_printf196_sleep(x+71, y+7);
    gotoXY_printf196_sleep(x+72, y+7);
    gotoXY_printf196_sleep(x+73, y+7);
    gotoXY_printf196_sleep(x+74, y+7);
    gotoXY_printf217_sleep(x+75, y+7);

    /// Costado Izquierdo Letra S
    gotoXY_printf92_sleep(x+75, y+6);
    gotoXY_printf92_sleep(x+73, y+4);
    gotoXY_printf92_sleep(x+74, y+5);
    gotoXY_printf47_sleep(x+73, y+3);
    gotoXY_printf47_sleep(x+74, y+2);
    gotoXY_printf47_sleep(x+75, y+1);

    /// Techo Letra S
    gotoXY_printf196_sleep(x+76, y);
    gotoXY_printf196_sleep(x+77, y);
    gotoXY_printf196_sleep(x+78, y);
    gotoXY_printf196_sleep(x+79, y);
    gotoXY_printf196_sleep(x+80, y);
    gotoXY_printf196_sleep(x+81, y);
    gotoXY_printf196_sleep(x+82, y);
    gotoXY_printf196_sleep(x+83, y);
    gotoXY_printf196_sleep(x+84, y);
    gotoXY_printf196_sleep(x+85, y);
    gotoXY_printf196_sleep(x+86, y);
    gotoXY_printf196_sleep(x+87, y);
    gotoXY_printf191_sleep(x+88, y);

    /// Costado Derecho Letra S
    gotoXY_printf179_sleep(x+88, y+1);
    gotoXY_printf179_sleep(x+88, y+2);
    gotoXY_printf217_sleep(x+88, y+3);
    gotoXY_printf196_sleep(x+87, y+3);
    gotoXY_printf196_sleep(x+86, y+3);
    gotoXY_printf196_sleep(x+85, y+3);
    gotoXY_printf196_sleep(x+84, y+3);
    gotoXY_printf196_sleep(x+83, y+3);
    gotoXY_printf196_sleep(x+82, y+3);
    gotoXY_printf92_sleep(x+82, y+4);
    gotoXY_printf92_sleep(x+83, y+5);
    gotoXY_printf92_sleep(x+84, y+6);
    gotoXY_printf47_sleep(x+85, y+7);
    gotoXY_printf47_sleep(x+84, y+8);
    gotoXY_printf47_sleep(x+83, y+9);

    /// Piso Letras RS
    gotoXY_printf196_sleep(x+82, y+10);
    gotoXY_printf196_sleep(x+81, y+10);
    gotoXY_printf196_sleep(x+80, y+10);
    gotoXY_printf196_sleep(x+79, y+10);
    gotoXY_printf196_sleep(x+78, y+10);
    gotoXY_printf196_sleep(x+77, y+10);
    gotoXY_printf196_sleep(x+76, y+10);
    gotoXY_printf196_sleep(x+75, y+10);
    gotoXY_printf196_sleep(x+74, y+10);
    gotoXY_printf196_sleep(x+73, y+10);
    gotoXY_printf196_sleep(x+72, y+10);
    gotoXY_printf196_sleep(x+71, y+10);
    gotoXY_printf196_sleep(x+70, y+10);
    gotoXY_printf196_sleep(x+69, y+10);
    gotoXY_printf196_sleep(x+68, y+10);
    gotoXY_printf196_sleep(x+67, y+10);
    gotoXY_printf196_sleep(x+66, y+10);
    gotoXY_printf196_sleep(x+65, y+10);
    gotoXY_printf196_sleep(x+64, y+10);
    gotoXY_printf196_sleep(x+63, y+10);
    gotoXY_printf196_sleep(x+62, y+10);
    gotoXY_printf196_sleep(x+61, y+10);
    gotoXY_printf92_sleep(x+60, y+9);
    gotoXY_printf92_sleep(x+59, y+8);
    gotoXY_printf218_sleep(x+57, y+7);
    gotoXY_printf179_sleep(x+57, y+8);
    gotoXY_printf179_sleep(x+57, y+9);
    gotoXY_printf217_sleep(x+57, y+10);
    gotoXY_printf196_sleep(x+56, y+10);
    gotoXY_printf196_sleep(x+55, y+10);
    gotoXY_printf196_sleep(x+54, y+10);
    gotoXY_printf196_sleep(x+53, y+10);

    /// Costado Izquierdo Letra R
    gotoXY_printf192_sleep(x+52, y+10);
    gotoXY_printf179_sleep(x+52, y+9);
    gotoXY_printf179_sleep(x+52, y+8);
    gotoXY_printf179_sleep(x+52, y+7);
    gotoXY_printf179_sleep(x+52, y+6);
    gotoXY_printf179_sleep(x+52, y+5);
    gotoXY_printf179_sleep(x+52, y+4);
    gotoXY_printf179_sleep(x+52, y+3);
    gotoXY_printf179_sleep(x+52, y+2);
    gotoXY_printf179_sleep(x+52, y+1);
    gotoXY_printf218_sleep(x+52, y);

    /// Centro Letra R
    gotoXY_printf218_sleep(x+56, y+2);
    gotoXY_printf179_sleep(x+56, y+3);
    gotoXY_printf192_sleep(x+56, y+4);
    gotoXY_printf196_sleep(x+57, y+4);
    gotoXY_printf196_sleep(x+58, y+4);
    gotoXY_printf196_sleep(x+59, y+4);
    gotoXY_printf196_sleep(x+60, y+4);
    gotoXY_printf217_sleep(x+61, y+4);
    gotoXY_printf179_sleep(x+61, y+3);
    gotoXY_printf191_sleep(x+61, y+2);
    gotoXY_printf196_sleep(x+60, y+2);
    gotoXY_printf196_sleep(x+59, y+2);
    gotoXY_printf196_sleep(x+58, y+2);
    gotoXY_printf196_sleep(x+57, y+2);
}
void gotoXY_printf218_sleep(int x, int y) // Printea ASCII 218.
{
    gotoxy(x, y);
    printf("%c", 218);
    Sleep(velocidadCreacionTexto);
}
void gotoXY_printf196_sleep(int x, int y) // Printea ASCII 196.
{
    gotoxy(x, y);
    printf("%c", 196);
    Sleep(velocidadCreacionTexto);
}
void gotoXY_printf191_sleep(int x, int y) // Printea ASCII 191.
{
    gotoxy(x, y);
    printf("%c", 191);
    Sleep(velocidadCreacionTexto);
}
void gotoXY_printf179_sleep(int x, int y) // Printea ASCII 179.
{
    gotoxy(x, y);
    printf("%c", 179);
    Sleep(velocidadCreacionTexto);
}
void gotoXY_printf217_sleep(int x, int y) // Printea ASCII 217.
{
    gotoxy(x, y);
    printf("%c", 217);
    Sleep(velocidadCreacionTexto);
}
void gotoXY_printf192_sleep(int x, int y) // Printea ASCII 192.
{
    gotoxy(x, y);
    printf("%c", 192);
    Sleep(velocidadCreacionTexto);
}
void gotoXY_printf47_sleep(int x, int y) // Printea ASCII 47.
{
    gotoxy(x, y);
    printf("%c", 47);
    Sleep(velocidadCreacionTexto);
}
void gotoXY_printf92_sleep(int x, int y) // Printea ASCII 92.
{
    gotoxy(x, y);
    printf("%c", 92);
    Sleep(velocidadCreacionTexto);
}
////////////////////////////////////////////////// Star Wars Logo.


////////////////////////////////////////////////// Star Wars Texto Intro.

void cargarArchivoTextoIntro() // Carga el Archivo 'textoIntro'.
{
    int i = 0;
    textoIntro a;
    FILE * archiTextoIntro;

    archiTextoIntro = fopen("ArchivoTextoIntro.bin", "ab");
    if(archiTextoIntro != NULL)
    {
        for(i = 0; i<30; i++)
        {
            printf("Ingrese texto: ");
            gets(a.texto);

            fwrite(&a, sizeof(textoIntro), 1, archiTextoIntro);
        }
        fclose(archiTextoIntro);
    }
}
void mostrarArchivoTextoIntro() // Muestra Archivo 'textoIntro'.
{
    textoIntro a;
    FILE * archiTextoIntro;

    archiTextoIntro = fopen("ArchivoTextoIntro.bin", "rb");
    if(archiTextoIntro != NULL)
    {
        while(fread(&a, sizeof(textoIntro), 1, archiTextoIntro) > 0)
        {
            printf("\t    %s\n", a.texto);
        }
        fclose(archiTextoIntro);
    }
}
void abrirArchivoTextoIntro() // Abre Archivo 'textoIntro'. Se llama a la funcion mostrarArchivoRecursivo.
{
    int contador = 1;
    FILE * archiTextoIntro;

    archiTextoIntro = fopen("ArchivoTextoIntro.bin", "rb");
    if(archiTextoIntro != NULL)
    {
        mostrarArchivoTextoIntroAutomatico(archiTextoIntro, contador);
        fclose(archiTextoIntro);
    }
    printf("\n\n\n");
}
void mostrarArchivoTextoIntroAutomatico(FILE * archivo, int contador) // Muestra Archivo 'textoIntro' Recursivo Automatico(Star Wars Text).
{
    if(contador < 31)
    {
        switch(contador)
        {
        case 1:
        {
            system("cls");
            printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
            muestraUnCaseArchivoTextoIntro(archivo, contador);
            mostrarArchivoTextoIntroAutomatico(archivo, contador+1);
            break;
        }
        case 2:
        {
            system("cls");
            printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
            muestraUnCaseArchivoTextoIntro(archivo, contador);
            mostrarArchivoTextoIntroAutomatico(archivo, contador+1);
            break;
        }
        case 3:
        {
            system("cls");
            printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
            muestraUnCaseArchivoTextoIntro(archivo, contador);
            mostrarArchivoTextoIntroAutomatico(archivo, contador+1);
            break;
        }
        case 4:
        {
            system("cls");
            printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
            muestraUnCaseArchivoTextoIntro(archivo, contador);
            mostrarArchivoTextoIntroAutomatico(archivo, contador+1);
            break;
        }
        case 5:
        {
            system("cls");
            printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
            muestraUnCaseArchivoTextoIntro(archivo, contador);
            mostrarArchivoTextoIntroAutomatico(archivo, contador+1);
            break;
        }
        case 6:
        {
            system("cls");
            printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
            muestraUnCaseArchivoTextoIntro(archivo, contador);
            mostrarArchivoTextoIntroAutomatico(archivo, contador+1);
            break;
        }
        case 7:
        {
            system("cls");
            printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
            muestraUnCaseArchivoTextoIntro(archivo, contador);
            mostrarArchivoTextoIntroAutomatico(archivo, contador+1);
            break;
        }
        case 8:
        {
            system("cls");
            printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
            muestraUnCaseArchivoTextoIntro(archivo, contador);
            mostrarArchivoTextoIntroAutomatico(archivo, contador+1);
            break;
        }
        case 9:
        {
            system("cls");
            printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
            muestraUnCaseArchivoTextoIntro(archivo, contador);
            mostrarArchivoTextoIntroAutomatico(archivo, contador+1);
            break;
        }
        case 10:
        {
            system("cls");
            printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
            muestraUnCaseArchivoTextoIntro(archivo, contador);
            mostrarArchivoTextoIntroAutomatico(archivo, contador+1);
            break;
        }
        case 11:
        {
            system("cls");
            printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
            muestraUnCaseArchivoTextoIntro(archivo, contador);
            mostrarArchivoTextoIntroAutomatico(archivo, contador+1);
            break;
        }
        case 12:
        {
            system("cls");
            printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
            muestraUnCaseArchivoTextoIntro(archivo, contador);
            mostrarArchivoTextoIntroAutomatico(archivo, contador+1);
            break;
        }
        case 13:
        {
            system("cls");
            printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
            muestraUnCaseArchivoTextoIntro(archivo, contador);
            mostrarArchivoTextoIntroAutomatico(archivo, contador+1);
            break;
        }
        case 14:
        {
            system("cls");
            printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
            muestraUnCaseArchivoTextoIntro(archivo, contador);
            mostrarArchivoTextoIntroAutomatico(archivo, contador+1);
            break;
        }
        case 15:
        {
            system("cls");
            printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
            muestraUnCaseArchivoTextoIntro(archivo, contador);
            mostrarArchivoTextoIntroAutomatico(archivo, contador+1);
            break;
        }
        case 16:
        {
            system("cls");
            printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
            muestraUnCaseArchivoTextoIntro(archivo, contador);
            mostrarArchivoTextoIntroAutomatico(archivo, contador+1);
            break;
        }
        case 17:
        {
            system("cls");
            printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
            muestraUnCaseArchivoTextoIntro(archivo, contador);
            mostrarArchivoTextoIntroAutomatico(archivo, contador+1);
            break;
        }
        case 18:
        {
            system("cls");
            printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
            muestraUnCaseArchivoTextoIntro(archivo, contador);
            mostrarArchivoTextoIntroAutomatico(archivo, contador+1);
            break;
        }
        case 19:
        {
            system("cls");
            printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
            muestraUnCaseArchivoTextoIntro(archivo, contador);
            mostrarArchivoTextoIntroAutomatico(archivo, contador+1);
            break;
        }
        case 20:
        {
            system("cls");
            printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
            muestraUnCaseArchivoTextoIntro(archivo, contador);
            mostrarArchivoTextoIntroAutomatico(archivo, contador+1);
            break;
        }
        case 21:
        {
            system("cls");
            printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
            muestraUnCaseArchivoTextoIntro(archivo, contador);
            mostrarArchivoTextoIntroAutomatico(archivo, contador+1);
            break;
        }
        case 22:
        {
            system("cls");
            printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
            muestraUnCaseArchivoTextoIntro(archivo, contador);
            mostrarArchivoTextoIntroAutomatico(archivo, contador+1);
            break;
        }
        case 23:
        {
            system("cls");
            printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
            muestraUnCaseArchivoTextoIntro(archivo, contador);
            mostrarArchivoTextoIntroAutomatico(archivo, contador+1);
            break;
        }
        case 24:
        {
            system("cls");
            printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
            muestraUnCaseArchivoTextoIntro(archivo, contador);
            mostrarArchivoTextoIntroAutomatico(archivo, contador+1);
            break;
        }
        case 25:
        {
            system("cls");
            printf("\n\n\n\n\n\n\n\n\n\n\n\n\n");
            muestraUnCaseArchivoTextoIntro(archivo, contador);
            mostrarArchivoTextoIntroAutomatico(archivo, contador+1);
            break;
        }
        case 26:
        {
            system("cls");
            printf("\n\n\n\n\n\n\n\n\n\n\n\n");
            muestraUnCaseArchivoTextoIntro(archivo, contador);
            mostrarArchivoTextoIntroAutomatico(archivo, contador+1);
            break;
        }
        case 27:
        {
            system("cls");
            printf("\n\n\n\n\n\n\n\n\n\n\n");
            muestraUnCaseArchivoTextoIntro(archivo, contador);
            mostrarArchivoTextoIntroAutomatico(archivo, contador+1);
            break;
        }
        case 28:
        {
            system("cls");
            printf("\n\n\n\n\n\n\n\n\n\n");
            muestraUnCaseArchivoTextoIntro(archivo, contador);
            mostrarArchivoTextoIntroAutomatico(archivo, contador+1);
            break;
        }
        case 29:
        {
            system("cls");
            printf("\n\n\n\n\n\n\n\n\n");
            muestraUnCaseArchivoTextoIntro(archivo, contador);
            mostrarArchivoTextoIntroAutomatico(archivo, contador+1);
            break;
        }
        }
    }
}
void muestraUnCaseArchivoTextoIntro(FILE * archivo, int contador) // Muestra un Case Archivo 'textoIntro'.
{
    int auxContador;
    textoIntro a;

    system("color 06");
    fseek(archivo, 0, SEEK_SET);
    for(auxContador = 0; auxContador <= contador; auxContador++)
    {
        fread(&a, sizeof(textoIntro), 1, archivo);
        printf("\t\t\t\t\t%s\n", a.texto);
    }
    Sleep(tiempoEsperaTextIntro);
}


////////////////////////////////////////////////// Star Wars Texto Intro.
