/**
 * Desafio: Movimentação de Peças de Xadrez (Níveis Novato, Aventureiro e Mestre)
 *
 * Este programa simula o movimento de várias peças de xadrez
 * utilizando as técnicas exigidas em cada nível do desafio.
 *
 * O resultado final (Nível Mestre) inclui:
 * 1. Torre, Rainha e Bispo (movimentos com funções recursivas)
 * 2. Bispo (movimento com loops aninhados)
 * 3. Cavalo (movimento com loops complexos/aninhados)
 *
 * Arquivo: xadrez.c
 * Autor: Rayssa Triani
 */

#include <stdio.h>

// --- Declarações das Funções (Protótipos) ---

/**
 * Nível Mestre: Simula o movimento da Torre com recursividade.
 * Substitui o loop 'for' do nível novato.
 * 
 */
void moverTorreRecursivo(int casas);

/**
 * Nível Mestre: Simula o movimento da Rainha com recursividade.
 * Substitui o loop 'do-while' do nível novato.
 * 
 */
void moverRainhaRecursivo(int casas);

/**
 * Nível Mestre: Simula o movimento do Bispo com recursividade.
 * Substitui o loop 'while' do nível novato.
 * 
 */
void moverBispoRecursivo(int casas);

/**
 * Nível Mestre: Simula o movimento do Bispo com loops aninhados.
 * Requisito adicional do Nível Mestre.
 * 
 */
void moverBispoAninhado(int casas);

/**
 * Nível Mestre: Simula o movimento em "L" do Cavalo com loops aninhados complexos.
 * Substitui a lógica do nível aventureiro.
 * [cite: 715, 717]
 */
void moverCavaloComplexo(int vertical, int horizontal);


// --- Função Principal (main) ---
// Controla a execução e chama as simulações de cada peça.

int main() {
    
    // --- NÍVEL MESTRE: TORRE (Recursividade) ---
    // O desafio original pedia 5 casas para a direita [cite: 359]
    printf("--- Movimento da Torre (Recursivo) ---\n");
    moverTorreRecursivo(5);
    
    // Separador de saída [cite: 726]
    printf("\n");

    // --- NÍVEL MESTRE: RAINHA (Recursividade) ---
    // O desafio original pedia 8 casas para a esquerda [cite: 362]
    printf("--- Movimento da Rainha (Recursivo) ---\n");
    moverRainhaRecursivo(8);
    
    // Separador de saída [cite: 726]
    printf("\n");

    // --- NÍVEL MESTRE: BISPO (Recursividade) ---
    // O desafio original pedia 5 casas na diagonal cima-direita [cite: 360]
    printf("--- Movimento do Bispo (Recursivo) ---\n");
    moverBispoRecursivo(5);
    
    // Separador de saída [cite: 726]
    printf("\n");

    // --- NÍVEL MESTRE: BISPO (Loops Aninhados) ---
    // Requisito Mestre: Implementar Bispo também com loops aninhados [cite: 718]
    // Movimento: 5 casas na diagonal cima-direita [cite: 360]
    printf("--- Movimento do Bispo (Loops Aninhados) ---\n");
    moverBispoAninhado(5);

    // Separador de saída [cite: 726]
    printf("\n");

    // --- NÍVEL MESTRE: CAVALO (Loops Complexos/Aninhados) ---
    // Movimento: 2 casas para cima e 1 para a direita 
    printf("--- Movimento do Cavalo (Loop Complexo) ---\n");
    moverCavaloComplexo(2, 1);
    
    return 0; // Indica que o programa terminou com sucesso
}


// --- Implementações das Funções ---

/**
 * Função recursiva da Torre.
 * Imprime "Direita" e chama a si mesma com (casas - 1)
 * até que o caso-base (casas == 0) seja atingido.
 */
void moverTorreRecursivo(int casas) {
    // Caso-base: se não há mais casas para mover, para a recursão.
    if (casas <= 0) {
        return;
    }
    
    // Ação: Imprime o movimento de 1 casa
    printf("Direita\n"); // [cite: 368]
    
    // Passo recursivo: chama a função novamente com 1 casa a menos
    moverTorreRecursivo(casas - 1);
}

/**
 * Função recursiva da Rainha.
 * Imprime "Esquerda" e chama a si mesma com (casas - 1)
 * até que o caso-base (casas == 0) seja atingido.
 */
void moverRainhaRecursivo(int casas) {
    // Caso-base:
    if (casas <= 0) {
        return;
    }
    
    // Ação:
    printf("Esquerda\n"); // [cite: 368]
    
    // Passo recursivo:
    moverRainhaRecursivo(casas - 1);
}

/**
 * Função recursiva do Bispo.
 * Imprime "Cima, Direita" e chama a si mesma com (casas - 1)
 * até que o caso-base (casas == 0) seja atingido.
 */
void moverBispoRecursivo(int casas) {
    // Caso-base:
    if (casas <= 0) {
        return;
    }
    
    // Ação:
    printf("Cima, Direita\n"); // [cite: 361, 368]
    
    // Passo recursivo:
    moverBispoRecursivo(casas - 1);
}

/**
 * Função do Bispo com Loops Aninhados.
 * O loop externo controla o movimento vertical (linhas)[cite: 718].
 * O loop interno controla o movimento horizontal (colunas)[cite: 718].
 * O movimento diagonal acontece quando (linha == coluna).
 */
void moverBispoAninhado(int casas) {
    // Loop externo (vertical)
    for (int i = 0; i < casas; i++) {
        // Loop interno (horizontal)
        for (int j = 0; j < casas; j++) {
            // Um movimento diagonal real só ocorre se i == j.
            // Para simular as 5 casas, imprimimos apenas quando i == j.
            if (i == j) {
                printf("Cima, Direita (passo %d)\n", i + 1);
            }
        }
    }
}

/**
 * Função do Cavalo com Loops Aninhados/Complexos.
 * O movimento é sequencial: 2 passos Cima, DEPOIS 1 passo Direita.
 * Usamos um loop aninhado para satisfazer o requisito:
 * O loop externo controla a "fase" do movimento (Fase 1 = Vertical, Fase 2 = Horizontal).
 * Os loops internos executam os passos de cada fase.
 */
void moverCavaloComplexo(int vertical, int horizontal) {
    // Loop externo para as "fases" do movimento (Fase 1: Vertical, Fase 2: Horizontal)
    for (int fase = 1; fase <= 2; fase++) {
        
        if (fase == 1) {
            // Fase 1: Movimento Vertical (2 casas para Cima)
            // Loop interno para os passos verticais
            for (int i = 0; i < vertical; i++) {
                printf("Cima\n"); // [cite: 725]
            }
        } else {
            // Fase 2: Movimento Horizontal (1 casa para Direita)
            // Loop interno para os passos horizontais
            for (int j = 0; j < horizontal; j++) {
                printf("Direita\n"); // [cite: 725]
            }
        }
    }
}