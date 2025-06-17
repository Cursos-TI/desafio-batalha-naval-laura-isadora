#include <stdio.h>

// Tamanho fixo do tabuleiro
#define TAMANHO 10

// Valor para representar parte do navio
#define NAVIO 3

int main() {
    // matriz do tabuleiro
    int tabuleiro[TAMANHO][TAMANHO];

    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // Tamanho fixo dos navios
    int tamanho_navio = 3;

    // Coordenadas dos navios
    int linha_horizontal = 2, coluna_horizontal = 1; // navio horizontal começando em (2,1)
    int linha_vertical = 5, coluna_vertical = 6;     // navio vertical começando em (5,6)

    if (coluna_horizontal + tamanho_navio <= TAMANHO) {
        int pode_posicionar = 1;
        for (int i = 0; i < tamanho_navio; i++) {
            if (tabuleiro[linha_horizontal][coluna_horizontal + i] == NAVIO) {
                pode_posicionar = 0;
                break;
            }
        }
        if (pode_posicionar) {
            for (int i = 0; i < tamanho_navio; i++) {
                tabuleiro[linha_horizontal][coluna_horizontal + i] = NAVIO;
            }
        }
    }

    if (linha_vertical + tamanho_navio <= TAMANHO) {
        int pode_posicionar = 1;
        for (int i = 0; i < tamanho_navio; i++) {
            if (tabuleiro[linha_vertical + i][coluna_vertical] == NAVIO) {
                pode_posicionar = 0;
                break;
            }
        }
        if (pode_posicionar) {
            for (int i = 0; i < tamanho_navio; i++) {
                tabuleiro[linha_vertical + i][coluna_vertical] = NAVIO;
            }
        }
    }

    // Impressão do tabuleiro no console
    printf("Tabuleiro Batalha Naval (0 = água, 3 = navio):\n\n");
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
