// Importando as bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Defenindo a variáveis globais
#define MAX_NOME 30      // Tamanho máximo do nome do território (incluindo '\0')
#define MAX_COR 10       // Tamanho máximo do nome da cor
#define TAM_TERRITORIO 5 // Número total de territórios a serem cadastrados

// Definição de estrutura que armazena dados de um territorio no jogo
struct Territorio
{
    char nome[MAX_NOME]; // Nome do território (aceita espaços)
    char cor[MAX_COR];   // Cor do exército que o domina
    int tropas;          // Quantidade de tropas alocadas
};

// Limpa o buffer de entrada (após o scanf) para evitar problemas de leitura futura
void limparBufferEntrada()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
};

// Função auxiliar para remover o '\n' que o fgets adiciona
void limparNovaLinha(char *str)
{
    // strcspn busca o primeiro '\n' na string. Se encontrar, substitui por '\0'.
    str[strcspn(str, "\n")] = 0;
}

// Função principal. Inicia o cadastro de N territórios e exibe o relatório.
int main()
{
    // Declara um vetor (array) de 5 estruturas Territorio para guardar os dados
    struct Territorio nomeTerritorio[TAM_TERRITORIO];
    // Variável de controle do loop, usada como índice do vetor
    int totalTerritorio;

    // Mensagens de inicialização
    printf("--- Cadastro de Territorios ----\n");
    printf("================================\n");

    // Loop principal para cadastrar todos os territórios (de 0 até 4)
    for (totalTerritorio = 0; totalTerritorio < TAM_TERRITORIO; totalTerritorio++)
    {

        // Exibe qual território está sendo cadastrado (totalTerritorio + 1)
        printf("--- Territorio %d ----\n", totalTerritorio + 1);

        // --- Leitura do NOME (usando fgets) ---
        printf("Nome do Territorio: ");
        // Lê a string do console e armazena no campo 'nome' do struct atual
        fgets(nomeTerritorio[totalTerritorio].nome, MAX_NOME, stdin);
        // Remove o '\n' inserido pelo fgets para evitar quebras de linha indesejadas
        limparNovaLinha(nomeTerritorio[totalTerritorio].nome);

        // --- Leitura da COR (usando fgets) ---
        printf("Cor do Exército (ex:Azul, Verde): ");
        // Lê a string da cor
        fgets(nomeTerritorio[totalTerritorio].cor, MAX_COR, stdin);
        // Remove o '\n'
        limparNovaLinha(nomeTerritorio[totalTerritorio].cor);

        // --- Leitura das TROPAS (usando scanf) ---
        printf("Número de Tropas: ");
        // Tenta ler um inteiro e verifica se a leitura falhou (se retornou != 1)
        if (scanf("%d", &nomeTerritorio[totalTerritorio].tropas) != 1)
        {
            printf("Erro na leitura, permitido apenas número inteiros!\n");
            // Nota: Em um programa mais robusto, você faria um loop para tentar ler de novo.
        }
        // Limpa o buffer após o scanf para remover o '\n' que ele deixou
        limparBufferEntrada();

        printf("-----------------------------------\n");
    }; // Fim do loop de cadastro

    // Mensagens de conclusão da fase de entrada
    printf("Cadastro inicial concluido com sucesso!\n\n");
    printf("=======================================\n");
    printf("MAPA DO MUNDO - ESTADO ATUAL\n");
    printf("=======================================\n\n");

    // Loop de exibição: percorre e imprime os dados de cada território
    for (totalTerritorio = 0; totalTerritorio < TAM_TERRITORIO; totalTerritorio++)
    {
        // Imprime o cabeçalho do território
        printf("TERRITORIO %d:\n", totalTerritorio + 1);

        // Imprime o Nome
        printf(" - Nome: %s\n", nomeTerritorio[totalTerritorio].nome);

        // Imprime a Cor
        printf(" - Dominado por: %s\n", nomeTerritorio[totalTerritorio].cor);

        // Imprime as Tropas
        printf(" - Tropas: %d\n\n", nomeTerritorio[totalTerritorio].tropas);
    }

    // Retorna 0, indicando que o programa foi executado com sucesso
    return 0;
}
