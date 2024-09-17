#include "chess.h"
#include "figures.h"

void display() {
    char **cuadroNegro = reverse(whiteSquare);
    char **cuadroBlanco = whiteSquare;
    char **unionCuadrados = join(cuadroNegro, cuadroBlanco);

    char **caballos = join(knight, rotateR(knight));
    char **caballosRotados = join(rotateL(knight), flipV(knight));
    char **caballosUnidos = up(caballos, caballosRotados);

    char **tableroSimetrico = up(unionCuadrados, reverse(unionCuadrados));
    char **tableroUnido = superImpose(caballosUnidos, tableroSimetrico);

    interpreter(tableroUnido);
}