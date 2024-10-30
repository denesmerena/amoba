#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "debugmalloc.h"


char** tablaInicializalas(const char meret) {
    char **tabla;
    tabla = malloc(meret * sizeof(char*));
    for (int i = 0; i < meret; ++i) {
        tabla[i] = malloc(meret * sizeof(char));
        for (int j = 0; j < meret; ++j) {
            tabla[i][j] = '0';
        }
    }
    return tabla;
}

void jelBeir(char** tabla, const char meret, const char oszlop, const char sor, const char jel) {
    if (tabla == NULL) {
        printf("Inicailzalatlan tabla");
        return;
    }
    if (oszlop <= meret  && sor <= meret && (jel == 'X' || jel == 'O')) {
        tabla[sor-1][oszlop-1] = jel;
        printf("\nJel regisztralva: %c: %d %d\n", jel, oszlop, sor);
        return;
    }
    if (oszlop <= meret  && sor <= meret && !(jel == 'X' || jel == 'O')) {
        printf("\nRossz jel\n");
        return;
    }
    if (!(oszlop <= meret  && sor <= meret) && (jel == 'X' || jel == 'O')) {
        printf("\nRossz hely\n");
        return;
    }
    printf("\nRossz hely es rossz jel\n");
}

void tablaKiir(char** tabla, const char meret) {
    if (tabla != NULL) {
        for (int i = 0; i < meret; ++i) {
            for (int j = 0; j < meret; ++j) {
                printf("%c ", tabla[i][j]);
            }
            printf("\n");
        }
    }
    else
        printf("Inicializalatlan tabla");
}

void tablaTorles(char** tabla, const char meret) {
    for (int i = 0; i < meret; ++i) {
        free(tabla[i]);
    }
    free(tabla);
}

char nyeroMennyiseg(const char meret) {
    if (meret == 3 || meret == 4)
        return 3;
    if (meret == 5)
        return 4;
    if (meret > 5 && meret <= 20) {
        return 5;
    }
    else {
        printf("invalid tablameret");
        return -1;
    }
}

bool oszlopNyer(char** tabla, const char meret, const char sor, const char oszlop, char szamolo, const char jel) {
    if (szamolo == 0 && tabla[sor][oszlop] == jel && jel != '0')
        return true;
    if (szamolo == 0)
        return false;
    if (sor < meret - 1 && tabla[sor][oszlop] == jel && jel != '0') {
        return oszlopNyer(tabla, meret, sor + 1, oszlop, szamolo - 1, jel);
    } else
        return false;
}
bool sorNyer(char** tabla, const char meret, const char sor, const char oszlop, char szamolo, const char jel) {
    if (szamolo == 0 && tabla[sor][oszlop] == jel && jel != '0')
        return true;
    if (szamolo == 0)
        return false;
    if (oszlop < meret - 1 && tabla[sor][oszlop] == jel && jel != '0') {
        return sorNyer(tabla, meret, sor , oszlop + 1, szamolo - 1, jel);
    } else
        return false;
}
bool keresztJobbNyer(char** tabla, const char meret, const char sor, const char oszlop, char szamolo, const char jel) {
    if (szamolo == 0 && tabla[sor][oszlop] == jel && jel != '0')
        return true;
    if (szamolo == 0)
        return false;
    if (oszlop < meret - 1 && sor < meret -1 && tabla[sor][oszlop] == jel && jel != '0') {
        return keresztJobbNyer(tabla, meret, sor + 1 , oszlop + 1, szamolo - 1, jel);
    } else
        return false;
}
bool keresztBalNyer(char** tabla, const char meret, const char sor, const char oszlop, char szamolo, const char jel) {
    if (szamolo == 0 && tabla[sor][oszlop] == jel && jel != '0')
        return true;
    if (szamolo == 0)
        return false;
    if (oszlop > 0 && sor < meret - 1 && tabla[sor][oszlop] == jel && jel != '0') {
        return keresztBalNyer(tabla, meret, sor + 1 , oszlop - 1, szamolo - 1, jel);
    } else
        return false;
}


char nyerE(const char** tabla, const char meret) {
    for (int i = 0; i < meret; ++i) {
        for (int j = 0; j < meret; ++j) {
            if (oszlopNyer(tabla, meret, i, j, nyeroMennyiseg(meret) - 1 , tabla[i][j]) ||
                sorNyer(tabla, meret, i, j, nyeroMennyiseg(meret) - 1 , tabla[i][j]) ||
                keresztJobbNyer(tabla, meret, i, j, nyeroMennyiseg(meret) - 1 , tabla[i][j]) ||
                keresztBalNyer(tabla, meret, i, j, nyeroMennyiseg(meret) - 1 , tabla[i][j])) {
                return tabla[i][j];
            }
        }
    }
    return -1;
}

int main(void) {
    /*char** tabla = tablaInicializalas(20);
    jelBeir(tabla, 20, 13, 13, 'X');
    jelBeir(tabla, 20, 14, 14, 'X');
    jelBeir(tabla, 20, 15, 15, 'X');
    jelBeir(tabla, 20, 16, 16, 'X');
    jelBeir(tabla, 20, 17, 17, 'X');
    tablaKiir(tabla, 20);
    printf("%c", nyerE(tabla, 20));
    tablaTorles(tabla, 20);*/


    return 0;
}
