

    #include <stdio.h>
    #include <string.h>
    
    // Definindo a estrutura para representar uma carta
    struct Carta {
        char estado[3]; // Estado (ex: A, B, C, etc.)
        char codigo[4]; // Código da carta (ex: A01, B02)
        char nome_cidade[50]; // Nome da cidade
        long long populacao;
        double area;
        long long pib;
        int pontos_turisticos;
        double densidade_populacional;
    };
    
    // Função para calcular a densidade populacional
    void calcularDensidade(struct Carta *carta) {
        carta->densidade_populacional = (double)carta->populacao / carta->area;
    }
    
    // Função para comparar duas cartas com base em uma propriedade
    void compararCartas(struct Carta carta1, struct Carta carta2, char propriedade[]) {
        printf("\nComparando %s e %s com base em %s:\n", carta1.codigo, carta2.codigo, propriedade);
    
        if (strcmp(propriedade, "populacao") == 0) {
            if (carta1.populacao > carta2.populacao) {
                printf("%s vence com população %lld!\n", carta1.codigo, carta1.populacao);
            } else if (carta1.populacao < carta2.populacao) {
                printf("%s vence com população %lld!\n", carta2.codigo, carta2.populacao);
            } else {
                printf("Empate em população!\n");
            }
        } else if (strcmp(propriedade, "area") == 0) {
            if (carta1.area > carta2.area) {
                printf("%s vence com área %.2f km²!\n", carta1.codigo, carta1.area);
            } else if (carta1.area < carta2.area) {
                printf("%s vence com área %.2f km²!\n", carta2.codigo, carta2.area);
            } else {
                printf("Empate em área!\n");
            }
        } else if (strcmp(propriedade, "pib") == 0) {
            if (carta1.pib > carta2.pib) {
                printf("%s vence com PIB %lld!\n", carta1.codigo, carta1.pib);
            } else if (carta1.pib < carta2.pib) {
                printf("%s vence com PIB %lld!\n", carta2.codigo, carta2.pib);
            } else {
                printf("Empate em PIB!\n");
            }
        } else if (strcmp(propriedade, "pontos_turisticos") == 0) {
            if (carta1.pontos_turisticos > carta2.pontos_turisticos) {
                printf("%s vence com %d pontos turísticos!\n", carta1.codigo, carta1.pontos_turisticos);
            } else if (carta1.pontos_turisticos < carta2.pontos_turisticos) {
                printf("%s vence com %d pontos turísticos!\n", carta2.codigo, carta2.pontos_turisticos);
            } else {
                printf("Empate em pontos turísticos!\n");
            }
        } else if (strcmp(propriedade, "densidade_populacional") == 0) {
            if (carta1.densidade_populacional < carta2.densidade_populacional) {
                printf("%s vence com densidade populacional %.2f hab/km²!\n", carta1.codigo, carta1.densidade_populacional);
            } else if (carta1.densidade_populacional > carta2.densidade_populacional) {
                printf("%s vence com densidade populacional %.2f hab/km²!\n", carta2.codigo, carta2.densidade_populacional);
            } else {
                printf("Empate em densidade populacional!\n");
            }
        } else {
            printf("Propriedade inválida!\n");
        }
    }
    
    int main() {
        struct Carta carta1, carta2;
        char propriedade[20];
    
        // Cadastro da primeira carta
        printf("Cadastro da Carta 1\n");
    
        printf("Digite o estado (ex: A, B, C): ");
        scanf("%s", carta1.estado);
    
        printf("Digite o código da carta (ex: A01): ");
        scanf("%s", carta1.codigo);
    
        printf("Digite o nome da cidade: ");
        scanf(" %[^\n]", carta1.nome_cidade); // Lê uma linha inteira
    
        printf("Digite a população: ");
        scanf("%lld", &carta1.populacao);
    
        printf("Digite a área (em km²): ");
        scanf("%lf", &carta1.area);
    
        printf("Digite o PIB: ");
        scanf("%lld", &carta1.pib);
    
        printf("Digite o número de pontos turísticos: ");
        scanf("%d", &carta1.pontos_turisticos);
    
        // Cadastro da segunda carta
        printf("\nCadastro da Carta 2\n");
    
        printf("Digite o estado (ex: A, B, C):\n");
        scanf("%s", carta2.estado);
    
        printf("Digite o código da carta (ex: B02):\n");
        scanf("%s", carta2.codigo);
    
        printf("Digite o nome da cidade:\n");
        scanf(" %[^\n]", carta2.nome_cidade); // Lê uma linha inteira
    
        printf("Digite a população:\n");
        scanf("%lld", &carta2.populacao);
    
        printf("Digite a área (em km²):\n");
        scanf("%lf", &carta2.area);
    
        printf("Digite o PIB:\n");
        scanf("%lld", &carta2.pib);
    
        printf("Digite o número de pontos turísticos:\n");
        scanf("%d", &carta2.pontos_turisticos);
    
        // Calcular densidade populacional
        calcularDensidade(&carta1);
        calcularDensidade(&carta2);
    
        // Exibir dados das cartas
        printf("\nDados da Carta %s:\n", carta1.codigo);
        printf("Estado: %s\n", carta1.estado);
        printf("Nome da Cidade: %s\n", carta1.nome_cidade);
        printf("População: %lld\n", carta1.populacao);
        printf("Área: %.2f km²\n", carta1.area);
        printf("PIB: %lld\n", carta1.pib);
        printf("Pontos Turísticos: %d\n", carta1.pontos_turisticos);
        printf("Densidade Populacional: %.2f hab/km²\n", carta1.densidade_populacional);
    
        printf("\nDados da Carta %s:\n", carta2.codigo);
        printf("Estado: %s\n", carta2.estado);
        printf("Nome da Cidade: %s\n", carta2.nome_cidade);
        printf("População: %lld\n", carta2.populacao);
        printf("Área: %.2f km²\n", carta2.area);
        printf("PIB: %lld\n", carta2.pib);
        printf("Pontos Turísticos: %d\n", carta2.pontos_turisticos);
        printf("Densidade Populacional: %.2f hab/km²\n", carta2.densidade_populacional);
    
        // Escolher propriedade para comparação
        printf("\nEscolha a propriedade para comparação (populacao, area, pib, pontos_turisticos, densidade_populacional): ");
        scanf("%s", propriedade);
    
        // Comparar as cartas
        compararCartas(carta1, carta2, propriedade);
    
        return 0;
    }
 
