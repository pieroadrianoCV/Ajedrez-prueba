#include "chess.h"
#include "figures.h"

void display() {
    char **cuadroNegro = reverse(whiteSquare);
    char **cuadroBlanco = whiteSquare;
    char **unionCuadrados = join(cuadroNegro, cuadroBlanco);
    
    char **fila1 = repeatH(unionCuadrados, 4);

    interpreter(fila1);
}