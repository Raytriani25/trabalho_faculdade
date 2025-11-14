/**
 * Desafio Nível Novato: Super Trunfo de Países
 * * Este programa cadastra os dados de duas cartas (cidades)
 * para o jogo Super Trunfo, conforme especificado no desafio.
 * Ele lê os dados do usuário e, em seguida, exibe as
 * informações formatadas na tela.
 *
 * Arquivo: super_trunfo.c
 * Autor: [Seu Nome Aqui]
 */

// Inclui a biblioteca padrão de entrada e saída
#include <stdio.h>

int main() {
    
    // --- Variáveis para a Carta 1 ---
    // 
    char estado1;
    char codigo1[10]; // Tamanho 10 para segurança (ex: "A01")
    char nomeCidade1[100]; // Tamanho 100 para nomes compostos
    int populacao1;
    float area1;
    float pib1;
    int pontosTuristicos1;

    // --- Variáveis para a Carta 2 ---
    // 
    char estado2;
    char codigo2[10];
    char nomeCidade2[100];
    int populacao2;
    float area2;
    float pib2;
    int pontosTuristicos2;

    // ---------------------------------------------
    // ETAPA 1: Cadastro da Carta 1
    // ---------------------------------------------
    // [cite: 17, 46, 50]
    
    printf("--- Cadastro da Carta 1 ---\n");

    printf("Digite o Estado (A-H): ");
    // Usamos " %c" (com espaço) para consumir qualquer 'enter' anterior
    scanf(" %c", &estado1);

    printf("Digite o Código da Carta (ex: A01): ");
    // Usamos " %s" (com espaço)
    scanf(" %s", codigo1);

    printf("Digite o Nome da Cidade: ");
    // " %[^\n]" lê uma string até o 'enter', permitindo espaços no nome
    scanf(" %[^\n]", nomeCidade1);

    printf("Digite a População: ");
    scanf("%d", &populacao1);

    printf("Digite a Área (em km²): ");
    scanf("%f", &area1);

    printf("Digite o PIB (em bilhões): ");
    scanf("%f", &pib1);

    printf("Digite o Número de Pontos Turísticos: ");
    scanf("%d", &pontosTuristicos1);

    // ---------------------------------------------
    // ETAPA 2: Cadastro da Carta 2
    // ---------------------------------------------
    // [cite: 17, 46, 50]
    
    printf("\n--- Cadastro da Carta 2 ---\n");

    printf("Digite o Estado (A-H): ");
    scanf(" %c", &estado2);

    printf("Digite o Código da Carta (ex: B02): ");
    scanf(" %s", codigo2);

    printf("Digite o Nome da Cidade: ");
    scanf(" %[^\n]", nomeCidade2);

    printf("Digite a População: ");
    scanf("%d", &populacao2);

    printf("Digite a Área (em km²): ");
    scanf("%f", &area2);

    printf("Digite o PIB (em bilhões): ");
    scanf("%f", &pib2);

    printf("Digite o Número de Pontos Turísticos: ");
    scanf("%d", &pontosTuristicos2);

    // ---------------------------------------------
    // ETAPA 3: Exibição das Cartas Cadastradas
    // ---------------------------------------------
    // [cite: 27, 48]
    
    printf("\n\n========================================");
    printf("\n--- Cartas Cadastradas com Sucesso ---");
    printf("\n========================================");

    // Exibindo Carta 1 conforme formato do exemplo [cite: 29-36]
    printf("\n\nCarta 1:\n");
    printf("Estado: %c\n", estado1);
    printf("Código: %s\n", codigo1);
    printf("Nome da Cidade: %s\n", nomeCidade1);
    printf("População: %d\n", populacao1);
    printf("Área: %.2f km²\n", area1); // "%.2f" para formatar com 2 casas decimais
    printf("PIB: %.2f bilhões de reais\n", pib1);
    printf("Número de Pontos Turísticos: %d\n", pontosTuristicos1);

    // Exibindo Carta 2 conforme formato do exemplo [cite: 37-44]
    printf("\nCarta 2:\n");
    printf("Estado: %c\n", estado2);
    printf("Código: %s\n", codigo2);
    printf("Nome da Cidade: %s\n", nomeCidade2);
    printf("População: %d\n", populacao2);
    printf("Área: %.2f km²\n", area2);
    printf("PIB: %.2f bilhões de reais\n", pib2);
    printf("Número de Pontos Turísticos: %d\n", pontosTuristicos2);

    printf("\n"); // Linha em branco no final

    // Retorna 0 para indicar que o programa terminou com sucesso
    return 0;
}