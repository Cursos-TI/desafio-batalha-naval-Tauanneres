#include <stdio.h>

#define TAMANHO 10

void exibirTabuleiro(int tabuleiro[TAMANHO][TAMANHO]) {
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void posicionarNavios(int tabuleiro[TAMANHO][TAMANHO]) {
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            tabuleiro[i][j] = 0;
        }
    }
    
    for (int i = 2; i < 6; i++) tabuleiro[i][3] = 3;
    for (int j = 1; j < 5; j++) tabuleiro[7][j] = 3;
    for (int i = 0; i < 4; i++) tabuleiro[i][i] = 3;
    for (int i = 0; i < 4; i++) tabuleiro[i][9 - i] = 3;
}

void aplicarHabilidade(int tabuleiro[TAMANHO][TAMANHO], int tipo) {
    int meio = TAMANHO / 2;
    if (tipo == 1) {
        tabuleiro[meio][meio] = 1;
        for (int i = 1; i <= 2; i++) {
            for (int j = -i; j <= i; j++) {
                tabuleiro[meio + i][meio + j] = 1;
            }
        }
    } else if (tipo == 2) {
        for (int i = 0; i < TAMANHO; i++) tabuleiro[meio][i] = 1;
        for (int i = 0; i < TAMANHO; i++) tabuleiro[i][meio] = 1;
    } else if (tipo == 3) {
        tabuleiro[meio - 1][meio] = tabuleiro[meio + 1][meio] = 1;
        tabuleiro[meio][meio - 1] = tabuleiro[meio][meio + 1] = 1;
        tabuleiro[meio][meio] = 1;
    }
}

int main() {
    int tabuleiro[TAMANHO][TAMANHO];
    posicionarNavios(tabuleiro);
    exibirTabuleiro(tabuleiro);
    
    aplicarHabilidade(tabuleiro, 1);
    exibirTabuleiro(tabuleiro);
    
    return 0;
}