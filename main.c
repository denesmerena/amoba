#include <stdio.h>
#include <stdlib.h>

char** tablaInicializalas(char meret) {
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

void jelBeolvas(char** tabla, char jel, int meret) {
    int x;
    int y;
    scanf("%d %d", &x, &y);
    if (x <= meret  && y <= meret && (jel == 'X' || jel == 'O')) {
        tabla[y-1][x-1] = jel;
        printf("\nLepes regisztralva\n");
        return;
    }
    if (x <= meret  && y <= meret && !(jel == 'X' || jel == 'O')) {
        printf("\nRossz jel\n");
        return;
    }
    if (!(x <= meret  && y <= meret) && (jel == 'X' || jel == 'O')) {
        printf("\nRossz hely\n");
        return;
    }
    printf("\nRossz hely es rossz jel\n");
}

void tablaKiir(char** tabla, int meret) {
    for (int i = 0; i < meret; ++i) {
        for (int j = 0; j < meret; ++j) {
            printf("%c ", tabla[i][j]);
        }
        printf("\n");
    }
}

int main(void) {
    char** matrix = tablaInicializalas(10);
    jelBeolvas(matrix, 'X', 10);
    tablaKiir(matrix, 10);
    free(matrix);
    return 0;
}
