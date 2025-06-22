#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NOME 100

void listar() {
  FILE *arquivo = fopen("estoque.txt", "r");
  int lines = 0;

  if (arquivo == NULL) {
    printf("Erro ao abrir o arquivo.\n");
    return;
  }

  while (feof(arquivo) == 0) {
    char atual = fgetc(arquivo);
    if (atual == EOF)
      break;
    printf("Nome: %c", atual);
    while (atual != '\n' && feof(arquivo) == 0) {
      atual = fgetc(arquivo);
      printf("%c", atual);
    }
    atual = ' ';
    printf("Quantidade: ");
    while (atual != '\n' && feof(arquivo) == 0) {
      atual = fgetc(arquivo);
      printf("%c", atual);
    }
    printf("\n");
    lines++;
  }

  if (lines == 0)
    printf("O estoque está vazio.\n");

  fclose(arquivo);

  return;
}

void adicionar() {
  FILE *arquivo = fopen("estoque.txt", "a");
  char nome[MAX_NOME];
  int quantidade;

  if (arquivo == NULL) {
    printf("Erro ao abrir o arquivo.\n");
    return;
  }

  getchar();
  printf("Digite o nome do produto: ");
  fgets(nome, MAX_NOME, stdin);
  nome[strcspn(nome, "\n")] = '\0';
  printf("Digite a quantidade: ");
  scanf("%d", &quantidade);
  fprintf(arquivo, "%s\n", nome);
  fprintf(arquivo, "%d\n", quantidade);
  printf("Item adicionado com sucesso!\n");

  fclose(arquivo);

  return;
}

void remover() {
  char nome[MAX_NOME];
  int quantidadeRemover;

  getchar();
  printf("Digite o nome do item: ");
  fgets(nome, MAX_NOME, stdin);
  nome[strcspn(nome, "\n")] = '\0';

  printf("Digite a quantidade a ser removida: ");
  scanf("%d", &quantidadeRemover);

  FILE *arquivo = fopen("estoque.txt", "r");
  FILE *temp = fopen("temp.txt", "w");

  if (arquivo == NULL || temp == NULL) {
    printf("Erro ao abrir os arquivos!\n");
    return;
  }

  char nomeAtual[MAX_NOME];
  int quantidadeAtual;
  int encontrado = 0;

  while (fgets(nomeAtual, MAX_NOME, arquivo) != NULL) {
    nomeAtual[strcspn(nomeAtual, "\n")] = '\0';
    fscanf(arquivo, "%d\n", &quantidadeAtual);

    if (strcmp(nomeAtual, nome) == 0) {
      encontrado = 1;

      if (quantidadeAtual < quantidadeRemover) {
        printf("Estoque insuficiente. Quantidade disponível: %d\n",
               quantidadeAtual);
        fprintf(temp, "%s\n%d\n", nomeAtual, quantidadeAtual);
      } else if (quantidadeAtual == quantidadeRemover) {
        printf("Item removido do estoque!\n");

      } else {
        quantidadeAtual -= quantidadeRemover;
        fprintf(temp, "%s\n%d\n", nomeAtual, quantidadeAtual);
        printf("Quantidade atualizada com sucesso!\n");
      }
    } else {
      fprintf(temp, "%s\n%d\n", nomeAtual, quantidadeAtual);
    }
  }

  if (!encontrado) {
    printf("Item não encontrado.\n");
  }

  fclose(arquivo);
  fclose(temp);

  remove("estoque.txt");
  rename("temp.txt", "estoque.txt");
}
int main() {
  char opcao;

do {
    printf("================================\n");
    printf("   Controle de Estoque\n");
    printf("================================\n");
    printf("Selecione uma opção:\n");
    printf("1. Adicionar Item\n");
    printf("2. Remover Item\n");
    printf("3. Listar Estoque\n");
    printf("4. Sair\n");
    printf("Opção: ");
    scanf(" %c", &opcao);  // CORRIGIDO: usar %c e limpar espaços anteriores

    switch (opcao) {
    case '1':
      adicionar();
      break;
    case '2':
      remover();
      break;
    case '3':
      listar();
      break;
    case '4':
      printf("Obrigado por usar o Controle de Estoques! Até a próxima.\n");
      return 0;
    default:
      printf("Opção inválida! Tente novamente.\n");
      continue;
    }

    printf("Deseja realizar outra operação? (s/n): ");
    scanf(" %c", &opcao);  // CORRIGIDO: usar %c com espaço

    if (opcao == 'n' || opcao == 'N') {
      printf("Obrigado por usar o Controle de Estoques! Até a próxima.\n");
      return 0;
    }

  } while (1);
}
