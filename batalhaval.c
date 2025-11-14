/**
 * Desafio: Jogo de Batalha Naval (Nível Mestre)
 *
 * Este programa completo atende aos requisitos de todos os níveis:
 * 1. (Novato) Cria um tabuleiro 10x10 e posiciona navios.
 * 2. (Aventureiro) Adiciona navios na diagonal.
 * 3. (Mestre) Implementa habilidades (Cone, Cruz, Octaedro)
 * usando loops aninhados e condicionais para sobrepor
 * ao tabuleiro.
 *
 * Arquivo: batalha_naval.c
 * Autor: Rayssa Triani
 */

#include <stdio.h>
#include <stdlib.h> // Para a função abs()

// --- Constantes do Jogo ---
#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3
#define TAMANHO_HABILIDADE 5 // Tamanho da matriz de habilidade (ex: 5x5) [cite: 716]

// Códigos do tabuleiro [cite: 725, 726, 727]
#define AGUA 0
#define NAVIO 3
#define HABILIDADE 5

// --- Protótipos das Funções ---

/**
 * @brief Preenche o tabuleiro com AGUA (0).
 */
void inicializar_tabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]);

/**
 * @brief Exibe o estado atual do tabuleiro no console.
 */
void exibir_tabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]);

/**
 * @brief Aplica a habilidade Cone (triângulo) em uma origem.
 * [cite: 712]
 */
void aplicar_habilidade_cone(int tab[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int origem_linha, int origem_col);

/**
 * @brief Aplica a habilidade Cruz em uma origem.
 * [cite: 714]
 */
void aplicar_habilidade_cruz(int tab[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int origem_linha, int origem_col);

/**
 * @brief Aplica a habilidade Octaedro (losango/diamond) em uma origem.
 * [cite: 715]
 */
void aplicar_habilidade_octaedro(int tab[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int origem_linha, int origem_col);


// --- Função Principal ---

int main() {
    // 1. Definir o Tabuleiro [cite: 709]
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];
    
    // Inicializa o tabuleiro com 0s (Água)
    inicializar_tabuleiro(tabuleiro);

    // 2. Posicionar Navios (Nível Aventureiro) [cite: 508]
    // (Coordenadas definidas no código) [cite: 529]
    
    // Navio 1 (Horizontal)
    tabuleiro[1][1] = NAVIO;
    tabuleiro[1][2] = NAVIO;
    tabuleiro[1][3] = NAVIO;

    // Navio 2 (Vertical)
    tabuleiro[3][3] = NAVIO;
    tabuleiro[4][3] = NAVIO;
    tabuleiro[5][3] = NAVIO;

    // Navio 3 (Diagonal '\') [cite: 510, 511]
    tabuleiro[5][5] = NAVIO;
    tabuleiro[6][6] = NAVIO;
    tabuleiro[7][7] = NAVIO;

    // Navio 4 (Diagonal '/') [cite: 510, 511]
    tabuleiro[1][8] = NAVIO;
    tabuleiro[2][7] = NAVIO;
    tabuleiro[3][6] = NAVIO;

    // 3. Integrar Habilidades ao Tabuleiro (Nível Mestre) [cite: 717]
    // (Pontos de origem definidos no código) [cite: 755]
    
    // Aplica Habilidade Cone na origem (2, 4)
    aplicar_habilidade_cone(tabuleiro, 2, 4);

    // Aplica Habilidade Cruz na origem (4, 7)
    aplicar_habilidade_cruz(tabuleiro, 4, 7);

    // Aplica Habilidade Octaedro na origem (7, 2)
    aplicar_habilidade_octaedro(tabuleiro, 7, 2);

    // 4. Exibir o Tabuleiro Final [cite: 723]
    printf("--- Tabuleiro Final Batalha Naval (Nível Mestre) ---\n");
    printf("Legenda: %d = Água | %d = Navio | %d = Habilidade\n\n", AGUA, NAVIO, HABILIDADE);
    
    exibir_tabuleiro(tabuleiro);

    return 0;
}


// --- Implementação das Funções Auxiliares ---

/**
 * @brief Preenche o tabuleiro 10x10 com o valor de AGUA (0).
 */
void inicializar_tabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    // Usa loops aninhados para percorrer a matriz
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = AGUA; // [cite: 332]
        }
    }
}

/**
 * @brief Usa loops aninhados para imprimir a matriz 10x10.
 */
void exibir_tabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    // Imprime coordenadas da coluna para facilitar
    printf("  ");
    for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
        printf("%d ", j);
    }
    printf("\n");

    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        printf("%d ", i); // Imprime coordenadas da linha
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n"); // Pula para a próxima linha [cite: 339]
    }
}

/**
 * @brief Lógica da Habilidade Cone.
 * Usa loops aninhados e condicionais para calcular a área.
 */
void aplicar_habilidade_cone(int tab[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int origem_linha, int origem_col) {
    int centro = TAMANHO_HABILIDADE / 2; // Centro da matriz 5x5 (posição 2)

    // Loops aninhados para varrer a matriz de habilidade 5x5 [cite: 728]
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            
            // Condicional que define a forma de Cone (triângulo) [cite: 712, 730]
            if (abs(j - centro) <= i) {
                // Calcula a posição real no tabuleiro 10x10
                int linha_tab = origem_linha - centro + i;
                int col_tab = origem_col - centro + j;

                // Condicional para validar limites do tabuleiro [cite: 729]
                if (linha_tab >= 0 && linha_tab < TAMANHO_TABULEIRO &&
                    col_tab >= 0 && col_tab < TAMANHO_TABULEIRO) {
                    
                    // Só marca se for ÁGUA (não apaga navios)
                    if (tab[linha_tab][col_tab] == AGUA) {
                        tab[linha_tab][col_tab] = HABILIDADE; // [cite: 722]
                    }
                }
            }
        }
    }
}

/**
 * @brief Lógica da Habilidade Cruz.
 * Usa loops aninhados e condicionais para calcular a área.
 */
void aplicar_habilidade_cruz(int tab[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int origem_linha, int origem_col) {
    int centro = TAMANHO_HABILIDADE / 2;

    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            
            // Condicional que define a forma de Cruz [cite: 714, 734]
            if (i == centro || j == centro) { // Se está na linha central OU coluna central
                int linha_tab = origem_linha - centro + i;
                int col_tab = origem_col - centro + j;

                // Validar limites [cite: 729]
                if (linha_tab >= 0 && linha_tab < TAMANHO_TABULEIRO &&
                    col_tab >= 0 && col_tab < TAMANHO_TABULEIRO) {
                    
                    if (tab[linha_tab][col_tab] == AGUA) {
                        tab[linha_tab][col_tab] = HABILIDADE;
                    }
                }
            }
        }
    }
}

/**
 * @brief Lógica da Habilidade Octaedro (Losango).
 * Usa loops aninhados e condicionais para calcular a área.
 */
void aplicar_habilidade_octaedro(int tab[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int origem_linha, int origem_col) {
    int centro = TAMANHO_HABILIDADE / 2;

    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            
            // Condicional que define a forma de Losango (Distância de Manhattan) [cite: 715, 738]
            if (abs(i - centro) + abs(j - centro) <= centro) {
                int linha_tab = origem_linha - centro + i;
                int col_tab = origem_col - centro + j;

                // Validar limites [cite: 729]
                if (linha_tab >= 0 && linha_tab < TAMANHO_TABULEIRO &&
                    col_tab >= 0 && col_tab < TAMANHO_TABULEIRO) {
                    
                    if (tab[linha_tab][col_tab] == AGUA) {
                        tab[linha_tab][col_tab] = HABILIDADE;
                    }
                }
            }
        }
    }
}