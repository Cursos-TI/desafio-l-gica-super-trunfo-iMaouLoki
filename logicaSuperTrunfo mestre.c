#include <stdio.h>

int main() {
    // Cartas cadastradas
    char estado1 = 'A', estado2 = 'B';
    char cidade1[] = "Cidade1", cidade2[] = "Cidade2";
    unsigned long int populacao1 = 7500000, populacao2 = 900000;
    float area1 = 650.0, area2 = 550.0;
    float pib1 = 60.0, pib2 = 55.0; // em bilhões
    int pontos_turisticos1 = 120, pontos_turisticos2 = 150;

    // Atributos derivados
    float densidade1 = populacao1 / area1;
    float densidade2 = populacao2 / area2;

    int escolha1, escolha2;

    float valor1_carta1 = 0, valor1_carta2 = 0;
    float valor2_carta1 = 0, valor2_carta2 = 0;

    // Menu interativo para o primeiro atributo
    printf("\n===== SUPER TRUNFO: COMPARAÇÃO COM DOIS ATRIBUTOS =====\n");
    printf("Escolha o PRIMEIRO atributo:\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Pontos Turísticos\n");
    printf("5 - Densidade Demográfica\n");
    printf("Sua opção: ");
    scanf("%d", &escolha1);

    // Menu interativo para o segundo atributo (dinâmico)
    printf("\nEscolha o SEGUNDO atributo (diferente do primeiro):\n");
    for (int i = 1; i <= 5; i++) {
        if (i != escolha1) {
            switch (i) {
                case 1: printf("1 - População\n"); break;
                case 2: printf("2 - Área\n"); break;
                case 3: printf("3 - PIB\n"); break;
                case 4: printf("4 - Pontos Turísticos\n"); break;
                case 5: printf("5 - Densidade Demográfica\n"); break;
            }
        }
    }
    printf("Sua opção: ");
    scanf("%d", &escolha2);

    // Função auxiliar para atribuir os valores dos atributos selecionados
    for (int i = 1; i <= 2; i++) {
        int atributo = (i == 1) ? escolha1 : escolha2;
        float *v1 = (i == 1) ? &valor1_carta1 : &valor2_carta1;
        float *v2 = (i == 1) ? &valor1_carta2 : &valor2_carta2;

        switch (atributo) {
            case 1: *v1 = populacao1; *v2 = populacao2; break;
            case 2: *v1 = area1; *v2 = area2; break;
            case 3: *v1 = pib1; *v2 = pib2; break;
            case 4: *v1 = pontos_turisticos1; *v2 = pontos_turisticos2; break;
            case 5: *v1 = densidade1; *v2 = densidade2; break;
            default: printf("Atributo inválido.\n"); return 1;
        }
    }

    // Mostrar valores e regras
    printf("\nComparando %s (Estado %c) vs %s (Estado %c):\n", cidade1, estado1, cidade2, estado2);
    for (int i = 1; i <= 2; i++) {
        int atributo = (i == 1) ? escolha1 : escolha2;
        float v1 = (i == 1) ? valor1_carta1 : valor2_carta1;
        float v2 = (i == 1) ? valor1_carta2 : valor2_carta2;

        switch (atributo) {
            case 1:
                printf("População -> %s: %.0f | %s: %.0f\n", cidade1, v1, cidade2, v2); break;
            case 2:
                printf("Área (km²) -> %s: %.2f | %s: %.2f\n", cidade1, v1, cidade2, v2); break;
            case 3:
                printf("PIB (bi) -> %s: %.2f | %s: %.2f\n", cidade1, v1, cidade2, v2); break;
            case 4:
                printf("Pontos Turísticos -> %s: %.0f | %s: %.0f\n", cidade1, v1, cidade2, v2); break;
            case 5:
                printf("Densidade (hab/km²) -> %s: %.2f | %s: %.2f (vence o MENOR)\n", cidade1, v1, cidade2, v2); break;
        }
    }

    // Lógica de comparação com inversão para densidade
    float soma1 = 0, soma2 = 0;
    for (int i = 1; i <= 2; i++) {
        int atributo = (i == 1) ? escolha1 : escolha2;
        float v1 = (i == 1) ? valor1_carta1 : valor2_carta1;
        float v2 = (i == 1) ? valor1_carta2 : valor2_carta2;

        // Para densidade (opção 5), vence o menor
        if (atributo == 5) {
            soma1 += (v1 < v2) ? 1 : (v1 > v2 ? 0 : 0.5);
            soma2 += (v2 < v1) ? 1 : (v2 > v1 ? 0 : 0.5);
        } else {
            soma1 += (v1 > v2) ? 1 : (v1 < v2 ? 0 : 0.5);
            soma2 += (v2 > v1) ? 1 : (v2 < v1 ? 0 : 0.5);
        }
    }

    // Mostrar resultado
    printf("\n--- RESULTADO FINAL ---\n");
    printf("Soma de Pontos:\n");
    printf("%s: %.1f pontos\n", cidade1, soma1);
    printf("%s: %.1f pontos\n", cidade2, soma2);

    // Veredito final
    if (soma1 > soma2) {
        printf("Vencedor: %s!\n", cidade1);
    } else if (soma2 > soma1) {
        printf("Vencedor: %s!\n", cidade2);
    } else {
        printf("Resultado: Empate!\n");
    }

    return 0;
}
