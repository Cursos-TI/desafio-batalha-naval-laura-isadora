#include <stdio.h>

#define TAM 10
#define TAM_NAVIO 3

int main() {
    int tabuleiro[TAM][TAM] = {0}; // Inicializa todas as posições com água (0)

    // Coordenadas dos navios
    int navio1_linha = 1, navio1_coluna = 2; // Horizontal
    int navio2_linha = 5, navio2_coluna = 7; // Vertical
    int navio3_linha = 0, navio3_coluna = 0; // Diagonal principal (↘)
    int navio4_linha = 0, navio4_coluna = 9; // Diagonal secundária (↙)

    // Validação e posicionamento do navio horizontal
    if (navio1_coluna + TAM_NAVIO <= TAM) {
        for (int i = 0; i < TAM_NAVIO; i++) {
            tabuleiro[navio1_linha][navio1_coluna + i] = 3;
        }
    }

    // Validação e posicionamento do navio vertical
    if (navio2_linha + TAM_NAVIO <= TAM) {
        for (int i = 0; i < TAM_NAVIO; i++) {
            tabuleiro[navio2_linha + i][navio2_coluna] = 3;
        }
    }

    // Validação e posicionamento do navio diagonal principal
    if (navio3_linha + TAM_NAVIO <= TAM && navio3_coluna + TAM_NAVIO <= TAM) {
        for (int i = 0; i < TAM_NAVIO; i++) {
            if (tabuleiro[navio3_linha + i][navio3_coluna + i] == 0)
                tabuleiro[navio3_linha + i][navio3_coluna + i] = 3;
        }
    }

    // Validação e posicionamento do navio diagonal secundária
    if (navio4_linha + TAM_NAVIO <= TAM && navio4_coluna - (TAM_NAVIO - 1) >= 0) {
        for (int i = 0; i < TAM_NAVIO; i++) {
            if (tabuleiro[navio4_linha + i][navio4_coluna - i] == 0)
                tabuleiro[navio4_linha + i][navio4_coluna - i] = 3;
        }
    }

    // Exibição do tabuleiro
    printf("Tabuleiro Batalha Naval:\n");
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
