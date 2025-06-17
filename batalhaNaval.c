#include <stdio.h>
#include <stdlib.h>

#define TAM 10
#define TAM_HAB 5

// Função para imprimir o tabuleiro
void exibirTabuleiro(int tabuleiro[TAM][TAM]) {
    printf("Tabuleiro com habilidades:\n");
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Função para sobrepor uma matriz de habilidade ao tabuleiro
void aplicarHabilidade(int tabuleiro[TAM][TAM], int habilidade[TAM_HAB][TAM_HAB], int origem_linha, int origem_coluna) {
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            if (habilidade[i][j] == 1) {
                int lin = origem_linha + i - TAM_HAB / 2;
                int col = origem_coluna + j - TAM_HAB / 2;
                if (lin >= 0 && lin < TAM && col >= 0 && col < TAM && tabuleiro[lin][col] != 3) {
                    tabuleiro[lin][col] = 5; // Marca a área de efeito da habilidade
                }
            }
        }
    }
}

int main() {
    int tabuleiro[TAM][TAM] = {0};

    // Posiciona navios
    tabuleiro[1][2] = tabuleiro[1][3] = tabuleiro[1][4] = 3; // navio horizontal
    tabuleiro[5][7] = tabuleiro[6][7] = tabuleiro[7][7] = 3; // navio vertical
    tabuleiro[0][0] = tabuleiro[1][1] = tabuleiro[2][2] = 3; // diagonal ↘
    tabuleiro[0][9] = tabuleiro[1][8] = tabuleiro[2][7] = 3; // diagonal ↙

    // MATRIZ CONE (forma triangular para baixo)
    int cone[TAM_HAB][TAM_HAB] = {0};
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            if (j >= TAM_HAB/2 - i && j <= TAM_HAB/2 + i) {
                cone[i][j] = 1;
            }
        }
    }

    // MATRIZ CRUZ
    int cruz[TAM_HAB][TAM_HAB] = {0};
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            if (i == TAM_HAB/2 || j == TAM_HAB/2) {
                cruz[i][j] = 1;
            }
        }
    }

    // MATRIZ OCTAEDRO (losango)
    int octaedro[TAM_HAB][TAM_HAB] = {0};
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            if (abs(i - TAM_HAB/2) + abs(j - TAM_HAB/2) <= TAM_HAB/2) {
                octaedro[i][j] = 1;
            }
        }
    }

    // Aplicar habilidades em pontos específicos do tabuleiro
    aplicarHabilidade(tabuleiro, cone, 4, 4);
    aplicarHabilidade(tabuleiro, cruz, 6, 3);
    aplicarHabilidade(tabuleiro, octaedro, 2, 6);

    // Exibir resultado final
    exibirTabuleiro(tabuleiro);

    return 0;
}
