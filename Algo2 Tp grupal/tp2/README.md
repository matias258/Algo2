# SCRABBLE 

## Descripción Informal

El objetivo del TP1 y el TP2 de la materia va a ser <b> diseñar</b> e <b>implementar</b> en <b>C++</b> un servidor para un juego de varios jugadores que se alternan ubicando fichas sobre un tablero para formar palabras<sup>1</sup>.

Resumimos algunas características del juego que vamos a modelar:

## El juego de palabras

Un tablero es una grilla cuadrada de N × N celdas. El tamaño exacto del tablero depende de la variante del juego de la que se trate. Todas las celdas del tablero son iguales; no modelaremos multiplicadores de letra ni de palabra.

En el juego intervienen K jugadores, que juegan por turnos (en ronda). Cada jugador tiene siempre en su posesión una cantidad F de fichas. La cantidad de fichas puede diferir de acuerdo con la variante del juego.

Cada ficha tiene asociada una letra del alfabeto y tiene asociado además un valor, que queda determinado por la letra en cuestión. El valor de cada letra puede diferir de acuerdo con la variante del juego.

Inicialmente, el tablero se encuentra vacío. A medida que el juego avanza, algunas celdas pasan a estar ocupadas por fichas. Una ocurrencia de una palabra en el tablero es una secuencia maximal de fichas consecutivas dispuestas en fila o columna en las que se puede leer esa palabra. Cuando decimos "maximal" nos referimos a que no debe existir otra secuencia de fichas consecutivas más larga que la contenga. Por ejemplo, en el siguiente tablero hay ocurrencias de las palabras CALLES, AHONDAN y PONIENTE, pero no hay ocurrencias de las palabras CAL, ONDA ni ENTE.

En cada turno, un jugador puede elegir un subconjunto (posiblemente vacío) de las fichas que tiene en su posesión y ubicar cada una de esas fichas en alguna celda del tablero que todavía no se encuentre ocupada. Para que la jugada sea válida, deben reunirse las dos condiciones siguientes:

1. Debe existir una ocurrencia de una palabra en el tablero que contenga a todas las fichas ubicadas. Por ejemplo, un jugador puede ubicar las fichas M, S, T, E porque, a pesar de que la M está separada de la S, forman parte de una única palabra contigua, "ASOMASTE".
2. Todas las palabras que se forman en el tablero deben ser legítimas. El conjunto de palabras legítimas puede diferir de acuerdo con la variante del juego.

Cada jugador tiene un puntaje. Cuando un jugador ubica fichas, gana puntos por cada una de las palabras que se hayan formado en el tablero, es decir, palabras que tengan ocurrencias en el tablero e incluyan al menos una de las fichas ubicadas por el jugador. En el ejemplo de arriba, se deben sumar los puntos de la palabra "ASOMASTE" (leída horizontalmente), así como de las palabras "AMA", "ESA", "T" y "E" (leídas verticalmente).



## TP1

En este TP vamos a especificar nuestro problema siguiendo la consigna de TP1_Enunciado.pdf dentro de la carpeta <b>tp1</b>

## TP2

En este TP vamos a implementar nuestro problema siguiendo la consigna de TP2_Enunciado.pdf dentro de la carpeta <b>tp2</b>



