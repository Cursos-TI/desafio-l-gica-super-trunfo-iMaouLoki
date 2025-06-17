#include <stdio.h>

int main() {
    // Carta 1
    char estado1;
    char card_id1[4];
    char cidade1[50];
    unsigned long int populacao1;
    float area1, pib1, densidade1, pib_per_capita1, super_poder1;
    int pontos_turisticos1;

    // Carta 2
    char estado2;
    char card_id2[4];
    char cidade2[50];
    unsigned long int populacao2;
    float area2, pib2, densidade2, pib_per_capita2, super_poder2;
    int pontos_turisticos2;

    // Entrada dos dados
    printf("Cadastro da Carta 1:\n");
    printf("Estado (A~H): ");
    scanf(" %c", &estado1);
    printf("Código da carta (ex: A00): ");
    scanf(" %s", card_id1);
    printf("Nome da Cidade: ");
    scanf(" %s", cidade1);
    printf("População: ");
    scanf("%lu", &populacao1);
    printf("Área em km²: ");
    scanf("%f", &area1);
    printf("PIB em bilhões de reais: ");
    scanf("%f", &pib1);
    printf("Número de Pontos Turísticos: ");
    scanf("%d", &pontos_turisticos1);

    printf("\nCadastro da Carta 2:\n");
    printf("Estado (A~H): ");
    scanf(" %c", &estado2);
    printf("Código da carta (ex: A00): ");
    scanf(" %s", card_id2);
    printf("Nome da Cidade: ");
    scanf(" %s", cidade2);
    printf("População: ");
    scanf("%lu", &populacao2);
    printf("Área em km²: ");
    scanf("%f", &area2);
    printf("PIB em bilhões de reais: ");
    scanf("%f", &pib2);
    printf("Número de Pontos Turísticos: ");
    scanf("%d", &pontos_turisticos2);

    // Cálculos
    densidade1 = populacao1 / area1;
    densidade2 = populacao2 / area2;
    pib_per_capita1 = pib1 * 1000000000 / populacao1;
    pib_per_capita2 = pib2 * 1000000000 / populacao2;

    super_poder1 = (float)populacao1 + area1 + pib1 + pontos_turisticos1 + pib_per_capita1 + (1.0f / densidade1);
    super_poder2 = (float)populacao2 + area2 + pib2 + pontos_turisticos2 + pib_per_capita2 + (1.0f / densidade2);

    // Exibição das Cartas
    printf("\nCarta 1:\n");
    printf("Estado: %c\n", estado1);
    printf("Código: %s\n", card_id1);
    printf("Cidade: %s\n", cidade1);
    printf("População: %lu\n", populacao1);
    printf("Área: %.2f km²\n", area1);
    printf("PIB: %.2f bilhões de reais\n", pib1);
    printf("Pontos Turísticos: %d\n", pontos_turisticos1);
    printf("Densidade Populacional: %.2f hab/km²\n", densidade1);
    printf("PIB per Capita: %.2f reais\n", pib_per_capita1);
    printf("Super Poder: %.2f\n", super_poder1);

    printf("\nCarta 2:\n");
    printf("Estado: %c\n", estado2);
    printf("Código: %s\n", card_id2);
    printf("Cidade: %s\n", cidade2);
    printf("População: %lu\n", populacao2);
    printf("Área: %.2f km²\n", area2);
    printf("PIB: %.2f bilhões de reais\n", pib2);
    printf("Pontos Turísticos: %d\n", pontos_turisticos2);
    printf("Densidade Populacional: %.2f hab/km²\n", densidade2);
    printf("PIB per Capita: %.2f reais\n", pib_per_capita2);
    printf("Super Poder: %.2f\n", super_poder2);
/*
    // Comparações
    printf("\nComparação de Cartas:\n");
    printf("População: Carta 1 venceu (%d)\n", populacao1 > populacao2);
    printf("Área: Carta 1 venceu (%d)\n", area1 > area2);
    printf("PIB: Carta 1 venceu (%d)\n", pib1 > pib2);
    printf("Pontos Turísticos: Carta 1 venceu (%d)\n", pontos_turisticos1 > pontos_turisticos2);
    printf("Densidade Populacional: Carta 1 venceu (%d)\n", densidade1 < densidade2);  // menor vence
    printf("PIB per Capita: Carta 1 venceu (%d)\n", pib_per_capita1 > pib_per_capita2);
    printf("Super Poder: Carta 1 venceu (%d)\n", super_poder1 > super_poder2);
*/

printf("\n comparação de cartas:\n");
printf("Atributo : PIB por capital\n");
if (pib_per_capita1 > pib_per_capita2) {
    printf("Carta 1 - %s (%c): %.2f reais\n", cidade1, estado1, pib_per_capita1);
    printf("Carta 2 - %s (%c): %.2f reais\n", cidade2, estado2, pib_per_capita2);
    printf("Resultado: Carta 1 (%s) venceu!\n", cidade1);
} else if (pib_per_capita2 > pib_per_capita1) {
    printf("Carta 1 - %s (%c): %.2f reais\n", cidade1, estado1, pib_per_capita1);
    printf("Carta 2 - %s (%c): %.2f reais\n", cidade2, estado2, pib_per_capita2);
    printf("Resultado: Carta 2 (%s) venceu!\n", cidade2);
} else {
    printf("Carta 1 - %s (%c): %.2f reais\n", cidade1, estado1, pib_per_capita1);
    printf("Carta 2 - %s (%c): %.2f reais\n", cidade2, estado2, pib_per_capita2);
    printf("Resultado: Empate!\n");
}

    return 0;
}