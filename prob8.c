#include "chess.h"
#include "figures.h"

void display() {
    char **cuadroNegro = reverse(whiteSquare);
    char **cuadroBlanco = whiteSquare;
    char **unionCuadrados = join(cuadroNegro, cuadroBlanco);

    char **reynaEnCuadroBlanco = superImpose(queen, cuadroBlanco);
    char **reynaEnCuadroNegro = superImpose(queen, cuadroNegro);
    // fila 1
    char **fila1 = join(join(reynaEnCuadroBlanco, repeatH(unionCuadrados,3)), cuadroNegro);
    // fila 2
    char **fila2Izquierda = join(repeatH(unionCuadrados, 2),reynaEnCuadroNegro);
    char **fila2Derecha = join(cuadroBlanco, unionCuadrados);
    char **fila2 = join(fila2Izquierda, fila2Derecha);
    //fila 3
    char **fila3 = join(repeatH(reverse(unionCuadrados), 3), join(cuadroBlanco,reynaEnCuadroNegro));
    //fila 4
    char **fila4Izquierda = join(repeatH(unionCuadrados, 2),cuadroNegro); 
    char **fila4Derecha = join(reynaEnCuadroBlanco,unionCuadrados);
    char **fila4 = join(fila4Izquierda, fila4Derecha);
    //fila 5
    char **fila5Izquierda = join(reverse(unionCuadrados), reynaEnCuadroBlanco);
    char **fila5Derecha = join(cuadroNegro,repeatH(reverse(unionCuadrados), 2));
    char **fila5 = join(fila5Izquierda, fila5Derecha);
    //fila 6
    char **fila6 = join(repeatH(unionCuadrados, 3), join(reynaEnCuadroNegro, cuadroBlanco));
    //fila7
    char **fila7 = join(join(cuadroBlanco, reynaEnCuadroNegro), repeatH(reverse(unionCuadrados), 3));
    //fila 8
    char **fila8Izquierda = join(join(unionCuadrados,cuadroNegro), reynaEnCuadroBlanco);
    char **fila8Derecha = repeatH(unionCuadrados, 2);
    char **fila8 = join(fila8Izquierda, fila8Derecha);
    //tablero final
    char **tablero[8] = {fila1, fila2, fila3, fila4, fila5, fila6, fila7, fila8};
    char **tableroFinal = tablero[0];

    for (int i = 1; i < 8; i++) {
        tableroFinal = up(tableroFinal, tablero[i]);
    }
    
    interpreter(tableroFinal);
}