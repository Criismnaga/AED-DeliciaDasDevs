#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHAR 255
#define DEFAULT_QUESTION "\nEscolha seu proximo passo: "


typedef struct BinaryTree{
  int id;
  char quest[MAX_CHAR];
  char step[MAX_CHAR];
  int answ;
  int points;
  struct BinaryTree *left;
  struct BinaryTree *right;
}BinaryTree;

typedef struct User{
  int idUser; //ou str idUser;
  int score;
}User;

BinaryTree *temp; // variavel global para ajudar na função de search 

void insert_level(BinaryTree **tree, int n, char *quest, char *step, int answ, int points);
void print_questions_inorder(BinaryTree *tree);
int binary_tree_search(BinaryTree *tree, int n);
void scoreSum(int *score, BinaryTree *tree);
BinaryTree* levelSearch(BinaryTree *tree, BinaryTree **temp, int *score);

int main(){
  BinaryTree *t1 = NULL;
  BinaryTree *t2 = NULL;
  BinaryTree *t3 = NULL;
  int input = 100;
  int score = 0;

  //////////////////////////// 
  insert_level(&t1, 20, DEFAULT_QUESTION, "Tomate", 1, 10);
  //print_questions_inorder(t1);
  insert_level(&t1, 18, DEFAULT_QUESTION, "Queijo Mussarela", 1, 10);
  insert_level(&t1, 22, DEFAULT_QUESTION, "Burrata", 2, 10);
  insert_level(&t1, 13, DEFAULT_QUESTION, "Óleo de Azeite", 1, 10);
  insert_level(&t1, 19, DEFAULT_QUESTION, "Óleo de GergeLim", 2, -10);
  insert_level(&t1, 2, DEFAULT_QUESTION, "Peito de Peru", 1, 10);
  insert_level(&t1, 17, DEFAULT_QUESTION, "Lingua de boi", 2, -10);
  insert_level(&t1, 1, DEFAULT_QUESTION, "Refogar maxixe com a proteina escolhida", 1, -10);
  insert_level(&t1, 9, DEFAULT_QUESTION, "Refogar cebola com a proteina escolhida", 2, 10);
  insert_level(&t1, 10, DEFAULT_QUESTION, "Assar mistura na churrasqueira", 2, -10);
  insert_level(&t1, 8, DEFAULT_QUESTION, "Rechear os tomates  com o que foi refogado", 1, 10);
  insert_level(&t1, 7, DEFAULT_QUESTION, "Parabéns você acertou a receita de tomate rechado", 3, 10);
   
  //até aqui montei todo o lado A da arvore 1

  insert_level(&t1, 21, DEFAULT_QUESTION, "Mostarda", 1, -10);
  insert_level(&t1, 30, DEFAULT_QUESTION, "Molho Pesto", 2, 10);
  insert_level(&t1, 28, DEFAULT_QUESTION, "Manjericão", 1, 10);
  insert_level(&t1, 31, DEFAULT_QUESTION, "Brócolis", 2, -10);
  insert_level(&t1, 24, DEFAULT_QUESTION, "Picar tomates e manjericão", 1, 10);
  insert_level(&t1, 29, DEFAULT_QUESTION, "Assar no microondas tomate e manjericão", 2, -10);
  insert_level(&t1, 23, DEFAULT_QUESTION, "Colocar tudo na airfrayer", 1, -10);
  insert_level(&t1, 27, DEFAULT_QUESTION, "Colocar tudo num prato e regar molho pesto", 2, 10);
  insert_level(&t1, 26, DEFAULT_QUESTION, "Parabéns você acertou a receita de Burrata com Molho Pesto", 3, 10);
  //até aqui montei todo o lado B da arvore 1

  insert_level(&t2, 40, DEFAULT_QUESTION,"Peito de Frango", 2, 10);
  //print_questions_inorder2(t2);
  insert_level(&t2, 38, DEFAULT_QUESTION, "Molho Teriaky", 1, 10);
  insert_level(&t2, 50, DEFAULT_QUESTION, "Molho de Tomate", 2, 10);
  insert_level(&t2, 28, DEFAULT_QUESTION, "Gengibre", 1, 10);
  insert_level(&t2, 39, DEFAULT_QUESTION, "Chimichurri", 2, -10);
  insert_level(&t2, 27, DEFAULT_QUESTION, "Semente de Chia", 1, -10);
  insert_level(&t2, 30, DEFAULT_QUESTION, "Semente de Gergelim", 2, 10);
  insert_level(&t2, 29, DEFAULT_QUESTION, "Castanha do Pará", 1, -10);
  insert_level(&t2, 35, DEFAULT_QUESTION, "Marinar Frango", 2, 10);
  insert_level(&t2, 34, DEFAULT_QUESTION, "Fritar o frango  e adicionar molho", 1, 10);
  insert_level(&t2, 36, DEFAULT_QUESTION, " Assar FRango no churrasqueira", 2, -10);
  insert_level(&t2, 33, DEFAULT_QUESTION, "Parabéns você acertou a receita de Frango Teriyaki", 3, 10);
  //até aqui montei todo o lado A da arvore 2

  insert_level(&t2, 49, DEFAULT_QUESTION, "Tofu", 1, -10);
  insert_level(&t2, 52, DEFAULT_QUESTION, "Queijo Mussarela", 2, 10);
  insert_level(&t2, 51, DEFAULT_QUESTION, "Chia", 1, -10);
  insert_level(&t2, 59, DEFAULT_QUESTION, "Farinha de Rosca", 2, 10);
  insert_level(&t2, 56, DEFAULT_QUESTION, "Empanar o Frango", 1, 10);
  insert_level(&t2, 60, DEFAULT_QUESTION, "Cortar Frango em Cubos", 2, -10);
  insert_level(&t2, 54, DEFAULT_QUESTION, "Fritar o frango. Depois cobrir com molho de tomate e assar no forno", 1, 10);
  insert_level(&t2, 57, DEFAULT_QUESTION, "Cozinhar Frango na água com molho de tomate", 2, -10);
  insert_level(&t2, 53, DEFAULT_QUESTION, "Parabéns você acertou a receita de Frango a Parmegiana", 3, 10);
  //até aqui montei todo o lado B da arvore 2

  insert_level(&t3, 30, DEFAULT_QUESTION, "Maçã", 3, 10);
  //print_questions_inorder3(t3);
  insert_level(&t3, 10, DEFAULT_QUESTION, "Massa Folhada", 1, 10);
  insert_level(&t3, 32, DEFAULT_QUESTION, "Aveia em Flocos", 2, 10);
  insert_level(&t3, 9, DEFAULT_QUESTION, "Gengibre", 1, -10);
  insert_level(&t3, 12, DEFAULT_QUESTION, "Canela em pó", 2, 10);
  insert_level(&t3, 11, DEFAULT_QUESTION, "Açúcar Demerara", 1, -10);
  insert_level(&t3, 14, DEFAULT_QUESTION, "Açúcar Mascavo", 2, 10);
  insert_level(&t3, 13, DEFAULT_QUESTION, "Misturar todos os ingredientes", 1, -10);
  insert_level(&t3, 16, DEFAULT_QUESTION, "Enrolar maçã na massa", 2, 10);
  insert_level(&t3, 15, DEFAULT_QUESTION, "Fritar e quando terminar polvilhar com açucar", 1, -10);
  insert_level(&t3, 18, DEFAULT_QUESTION, "Assar no forno e quando terminar polvilhar com açucar ", 2, 10);
  insert_level(&t3, 17, DEFAULT_QUESTION, "Parabéns você acertou a receita de Rolinhos de Maçã e Canela Assados", 3, 10);
  //até aqui montei todo o lado A da arvore 3

  insert_level(&t3, 31, DEFAULT_QUESTION, "Essência de Baunilha", 1, -10);
  insert_level(&t3, 50, DEFAULT_QUESTION, "Canela em pó", 2, 10);
  insert_level(&t3, 42, DEFAULT_QUESTION, "Açúcar Mascavo", 1, 10);
  insert_level(&t3, 51, DEFAULT_QUESTION, "Mel", 2, -10);
  insert_level(&t3, 41, DEFAULT_QUESTION, "Untar massa", 1, -10);
  insert_level(&t3, 44, DEFAULT_QUESTION, "Misturar todos os ingredientes", 2, 10);
  insert_level(&t3, 43, DEFAULT_QUESTION, "Assar na airfryer e depois montar com as maçãs no refratário", 1, -10);
  insert_level(&t3, 46, DEFAULT_QUESTION, "Colocar para assar e depois montar com as maçãs no refratário", 2, 10);
  insert_level(&t3, 45, DEFAULT_QUESTION, "Parabéns você acertou a receita de Crumble de Maçã", 3, 10);
  //até aqui montei todo o lado B da arvore 3

  ////////////////////// GAME BEGINS /////////////////////
  printf("\n\n");
  printf("Seja bem-vindo ao jogo Delícia das Devs\n\n");

  printf("Por qual ingrediente que deseja começar?\n");
  printf("1- ");
  binary_tree_search(t1, 20);
  printf("\n2- ");
  binary_tree_search(t2, 40);
  printf("\n3- ");
  binary_tree_search(t3, 30);
  printf("\n\nDigite o numero correspondente a sua escolha: ");

  while (1) {
    scanf("%d", &input);
    if (input == 1){
      levelSearch(t1, temp, &score);
      printf("Seu score é: %d", score);
      break;
    }else if(input == 2){
      levelSearch(t2, temp, &score);
      printf("Seu score é: %d", score);
      break;
    }else if(input == 3){
      levelSearch(t3, temp, &score);
      printf("Seu score é: %d", score);
      break;

    }else if (input == 0){
      printf("Jogo encerrado"); // pode ter uma pergunta de confirmação
      break;
    }else{
      printf("Número inválido. Tente novamente.\n");
    }
  } 
  return 0;
}

void insert_level(BinaryTree **tree, int n, char *quest, char *step, int answ, int points)
{
  if (*tree == NULL) {
    *tree = (BinaryTree *)malloc(sizeof(BinaryTree));
    if(tree != NULL){
      (*tree)->left = NULL;
      (*tree)->right = NULL;
      (*tree)->id = n;
      strncpy((*tree)->quest, quest, MAX_CHAR); // Copiando a pergunta para o nó
      strncpy((*tree)->step, step, MAX_CHAR); // copiando o passo.
      (*tree)->answ = answ; // Definindo a resposta correta
      (*tree)->points = points; // Definindo a pontuação
    }else{
      printf("Memory allocation failed\n");
    }
  } else {
    if (n < (*tree)->id) {
      insert_level(&(*tree)->left, n, quest, step, answ, points);
    }
    if (n > (*tree)->id) {
      insert_level(&(*tree)->right, n, quest, step, answ, points);
    }
  }
}


void print_questions_inorder(BinaryTree *tree) {
  if (tree != NULL){
    print_questions_inorder(tree->left); // Visita a subárvore esquerda
    printf("ID: %d, Pergunta: %s\n", tree->id, tree->step); // Imprime a pergunta do nó atual
    print_questions_inorder(tree->right); // Visita a subárvore direita
  }
}

int binary_tree_search(BinaryTree *tree, int n) {
  if (tree == (BinaryTree*)NULL)
    return (0);
  if (tree->id == n)
    printf("%s",tree->step);
    return tree->id;
  if (n < tree->id)
    binary_tree_search(tree->left, n);
  else
    binary_tree_search(tree->right, n);
}

void scoreSum(int *score, BinaryTree *tree){
  *score += tree->points;
}

BinaryTree* levelSearch(BinaryTree *tree, BinaryTree **temp, int *score){
  if (tree->left == NULL && tree->right == NULL && tree->points < 0){
    printf("oi, entrou no else points < 0\n");
    scoreSum(score, tree);
    return levelSearch(temp, temp, score); // deu errado esse temp  kakaka 
  }else{
    BinaryTree *aux;
    int input = 100; // valor arbritario pq a saida é 0
    scoreSum(score, tree);
    printf("oi, entrou no ultiimooo else\n");
     

    while (1) {
      

      if (tree->left != NULL) {
        if(tree->left->answ !=3){ // identifica se é o nó que o step é a receita final
          printf("%s\n", tree->quest);
          printf("1- %s\n", tree->left->step);
        }else if (tree->left->answ ==3){
          if(*score>=50){ // ganhou
            printf("score: %d\n", *score);
            printf("%s\n", tree->left->step);
          }else{ // perdeu
            printf("score: %d\n", *score);
            printf("Não foi dessa vez! Você não acertou a receita, tente novamente\n");
          }
        } else {
          printf("entrei num lugar errado, linha 235\n");
        }
      } else {
          return NULL;
      }

      if (tree->right != NULL) {
        if(tree->right->answ !=3){ // identifica se é o nó que o step é a receita final
          printf("2- %s\n", tree->right->step);
        }else if (tree->right->answ ==3){
          if(*score>=50){ // ganhou
            printf("score: %d", *score);
            printf("%s\n", tree->right->step);
          }else{ // perdeu
          printf("score: %d\n", *score);
          printf("Não foi dessa vez! Você não acertou a receita, tente novamente\n");
          }
        } else {
          printf("entrei num lugar errado, linha 253\n");
        }
      } else {
          return NULL;
      }

      printf("\nDigite o numero correspondente a sua escolha: ");
      scanf("%d", &input);

      if (input == 1){
        if (tree->right != NULL) {
          aux = tree->left;
          temp = tree->right;
          return levelSearch(aux, temp, score);
        }else{
          return NULL;
        }
               
      }else if(input == 2){
        if (tree->right != NULL){
            aux = tree->right;
            temp = tree->left;
            return levelSearch(aux, temp, score);
          }else{
          return NULL;
          }
      }else if (input == 0){
        printf("Jogo encerrado\n"); // pode ter uma pergunta de confirmação
        return NULL; // talvez um go to aqui pra redirecionar pro menu
      }else{
        printf("Número inválido. Tente novamente.\n");
      }
    } 
    
  }
  
}
