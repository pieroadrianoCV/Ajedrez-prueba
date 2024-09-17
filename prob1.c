#include "chess.h"
#include "figures.h"

void display() {
    char **cuadroNegro = reverse(whiteSquare);
    char **cuadroBlanco = whiteSquare;
    char **unionCuadrados = join(cuadroBlanco, cuadroNegro);
    
    char **fila1 = repeatH(unionCuadrados, 4);

    interpreter(fila1);
}