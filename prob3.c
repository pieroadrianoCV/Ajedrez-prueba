#include "chess.h"
#include "figures.h"

void display() {
    char **cuadroNegro = reverse(whiteSquare);
    char **cuadroBlanco = whiteSquare;
    char **unionCuadrados = join(cuadroNegro, cuadroBlanco);

    char **fila1 = repeatH(unionCuadrados, 4);
    char **fila2 = reverse(fila1);
    char **unionFilas = up(fila1, fila2);

    char **tablero = repeatV(unionFilas, 2);

    interpreter(tablero);
}