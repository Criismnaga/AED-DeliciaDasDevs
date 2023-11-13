#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct no {
  char pergunta[100];
  char resposta_correta[100];
  char resposta_errada1[100];
  int pontuacao;
  struct no *esquerdo;
  struct no *direito;
};

struct fase {
  int numero;
  int quantidade_perguntas;
  struct no *perguntas;
  struct fase *proxima_fase;
};

struct fase *fase_inicial; //= criar_fase(1, 10, NULL, NULL);
//struct fase *fase_intermediaria = criar_fase(2, 20, NULL, NULL);
//struct fase *fase_final = criar_fase(3, 30, NULL, NULL);

struct no *criar_no(char *pergunta, char *resposta_correta, char *resposta_errada1) {
  struct no *novo = malloc(sizeof(struct no));
  strcpy(novo->pergunta, pergunta);
  strcpy(novo->resposta_correta, resposta_correta);
  strcpy(novo->resposta_errada1, resposta_errada1);
  novo->esquerdo = NULL;
  novo->direito = NULL;
  return novo;
}

struct no *inserir_no(struct no *raiz, char *pergunta, char *resposta_correta, char *resposta_errada1) {
  if (raiz == NULL) {
    return criar_no(pergunta, resposta_correta, resposta_errada1);
  } else if (strcmp(pergunta, raiz->pergunta) < 0) {
    raiz->esquerdo = inserir_no(raiz->esquerdo, pergunta, resposta_correta, resposta_errada1);
  } else {
    raiz->direito = inserir_no(raiz->direito, pergunta, resposta_correta, resposta_errada1);
  }
  return raiz;
}

int main() {
    struct fase *fase_atual = fase_inicial;
    //struct jogador jogador;

    // Inicia o jogo na fase inicial
    while (fase_atual != NULL) {
        // Gera uma pergunta da fase atual
        struct no *no = gerar_pergunta_aleatoria(fase_atual);

        // Recebe a resposta do jogador
        char resposta[100];
        printf("%s\n", no->pergunta);
        scanf("%s", resposta);

        // Verifica a resposta do jogador
        if (strcmp(resposta, no->resposta_correta) == 0) {
            printf("A resposta está correta!\n");
        } else {
            printf("A resposta está incorreta. A resposta correta é: %s\n", no->resposta_correta);
        break;
    }

    // Atualiza a fase atual
    //fase_atual = no->proxima_fase;

    // Exibe a pontuação do jogador
    //printf("Sua pontuação é: %d\n", jogador.pontuacao);
  }

  return 0;
}

struct no *gerar_pergunta_aleatoria(struct fase *fase) {
  if (fase == NULL) {
    return NULL;
  }

  // Gera um número aleatório entre 0 e a quantidade de perguntas da fase
  int aleatorio = rand() % fase->quantidade_perguntas;

  // Retorna a pergunta na posição aleatória
  //struct no *no = fase->perguntas[aleatorio];

  // Atualiza a pontuação do jogador
  //if (strcmp(resposta, no->resposta_correta) == 0) {
    //no.pontuacao++;
  //}

  //return no;
}
