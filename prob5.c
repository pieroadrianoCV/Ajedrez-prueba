#include "chess.h"
#include "figures.h"

void display() {
    char **cuadroNegro = reverse(whiteSquare);
    char **cuadroBlanco = whiteSquare;
    char **unionCuadrados = join(cuadroNegro, cuadroBlanco);
    char **fila1Cuadros = repeatH(unionCuadrados, 4);

    char **torreCaballoAlfilIzquierdo = join(join(rook, knight), bishop);
    char **reyYreyna = join(queen, king);
    char **torreCaballoAlfilDerecho = join(join(bishop, knight), rook);
    char **filaFichas = join(join(torreCaballoAlfilIzquierdo, reyYreyna), torreCaballoAlfilDerecho);

    char **filaUnida = superImpose(reverse(filaFichas), fila1Cuadros);
    
    interpreter(filaUnida);
}