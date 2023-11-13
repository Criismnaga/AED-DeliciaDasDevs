#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Arv1{
  int id;
  char quest[256];
  int answ;
  int points;
  struct Arv1 *esq;
  struct Arv1 *dir;
}Arv1;

typedef struct Arv2{
  int id;
  char quest[256];
  int answ;
  int points;
  struct Arv2 *esq;
  struct Arv2 *dir;
}Arv2;

typedef struct Arv3{
  int id;
  char quest[256];
  int answ;
  int points;
  struct Arv3 *esq;
  struct Arv3 *dir;
}Arv3;

typedef struct User{
  int idUser; //ou str idUser;
  int pontuacao;
}User;

void insert_level1(Arv1 **t1, int n, char *quest, int answ, int points);
void insert_level2(Arv2 **t2, int n, char *quest, int answ, int points);
void insert_level3(Arv3 **t3, int n, char *quest, int answ, int points);
void print_questions_inorder1(Arv1 *t1);
void print_questions_inorder2(Arv2 *t2);
void print_questions_inorder3(Arv3 *t3);

int main(){
  Arv1 *t1 = NULL;
  Arv2 *t2 = NULL;
  Arv3 *t3 = NULL;

  insert_level1(&t1, 10, "Tomate", 1, 10);
  print_questions_inorder1(t1);
  insert_level1(&t1, 12, "Queijo Mussarela", 1, 10);
  insert_level1(&t1, 8, "Burrata", 2, 10);
  insert_level1(&t1, 6, "Óleo de Azeite", 1, 10);
  insert_level1(&t1, 9, "Óleo de GergeLim", 2, -10);
  insert_level1(&t1, 5, "Peito de Peru", 1, 10);
  insert_level1(&t1, 7, "Frango Desfiado", 2, 10);
  //até aqui montei todo o lado A da arvore 1
  
  insert_level1(&t1, 11, "Óleo de Azeite", 1, 10);
  insert_level1(&t1, 20, "Molho Pesto", 2, 10);
  insert_level1(&t1, 18, "Manjericão", 1, 10);
  insert_level1(&t1, 21, "Brócolis", 2, -10);
  insert_level1(&t1, 15, "Picar tomates e manjericão", 1, 10);
  insert_level1(&t1, 19, "Assar no microondas tomate e manjericão", 2, -10);
  insert_level1(&t1, 14, "Colocar tudo na airfrayer", 1, -10);
  insert_level1(&t1, 17, "Colocar tudo num prato", 2, 10);
  insert_level1(&t1, 16, "Adicionar o azeite ou o molho pesto", 1, 10);
  //até aqui montei todo o lado B da arvore 1

  insert_level2(&t2, 40, "Peito de Frango", 2, 10);
  print_questions_inorder2(t2);
  insert_level2(&t2, 38, "Molho Teriaky", 1, 10);
  insert_level2(&t2, 50, "Molho de Tomate", 2, 10);
  insert_level2(&t2, 28, "Gengibre", 1, 10);
  insert_level2(&t2, 39, "Chimichurri", 2, -10);
  insert_level2(&t2, 27, "Semente de Chia", 1, -10);
  insert_level2(&t2, 30, "Semente de Gergelim", 2, 10);
  insert_level2(&t2, 29, "Castanha do Pará", 1, -10);
  insert_level2(&t2, 35, "Marinar Frango", 2, 10);
  insert_level2(&t2, 34, "Frigideira", 1, 10);
  insert_level2(&t2, 36, "Churrasqueira", 2, -10);
  insert_level2(&t2, 33, "Polvilhar o gergelim", 2, 10);
  //até aqui montei todo o lado A da arvore 2
  
  insert_level2(&t2, 49, "Tofu", 1, -10);
  insert_level2(&t2, 52, "Queijo Mussarela", 2, 10);
  insert_level2(&t2, 51, "Chia", 1, -10);
  insert_level2(&t2, 59, "Farinha de Rosca", 2, 10);
  insert_level2(&t2, 56, "Empanar o Frango", 1, 10);
  insert_level2(&t2, 60, "Cortar Frango em Cubos", 2, -10);
  insert_level2(&t2, 54, "Fritar Frango", 1, 10);
  insert_level2(&t2, 57, "Cozinhar Frango na água", 2, -10);
  insert_level2(&t2, 55, "Cobrir com Molho de Tomate e assar no forno", 1, 10);
  //até aqui montei todo o lado B da arvore 2

  insert_level3(&t3, 30, "Maçã", 3, 10);
  print_questions_inorder3(t3);
  insert_level3(&t3, 10, "Massa Folhada", 1, 10);
  insert_level3(&t3, 32, "Aveia em Flocos", 2, 10);
  insert_level3(&t3, 9, "Gengibre", 1, -10);
  insert_level3(&t3, 12, "Canela em pó", 2, 10);
  insert_level3(&t3, 11, "Açúcar Demerara", 1, -10);
  insert_level3(&t3, 14, "Açúcar Mascavo", 2, 10);
  insert_level3(&t3, 13, "Misturar todos os ingredientes", 1, -10);
  insert_level3(&t3, 16, "Enrolar maçã na massa", 2, 10);
  insert_level3(&t3, 15, "Frigideira", 1, -10);
  insert_level3(&t3, 18, "Forno", 2, 10);
  insert_level3(&t3, 17, "Polvilhar com açúcar", 1, 10);
  //até aqui montei todo o lado A da arvore 3
  
  insert_level3(&t3, 31, "Essência de Baunilha", 1, -10);
  insert_level3(&t3, 35, "Canela em pó", 2, 10);
  insert_level3(&t3, 34, "Açúcar Mascavo", 1, 10);
  insert_level3(&t3, 36, "Mel", 2, -10);
  insert_level3(&t3, 33, "Untar massa", 1, 10);
  insert_level3(&t3, 38, "Misturar todos os ingredientes", 2, -10);
  insert_level3(&t3, 37, "Airfryer", 1, -10);
  insert_level3(&t3, 39, "Forno", 2, 10);
  insert_level3(&t3, 40, "Montar a maçã no refratário", 1, 10);
  //até aqui montei todo o lado B da arvore 3

  //se chamar as funções aqui ele percorre corrido, toda as árvores
  //print_questions_inorder1(t1);
  //print_questions_inorder2(t2);
  //print_questions_inorder3(t3);

  return 0;
}

void insert_level1(Arv1 **t1, int n, char *quest, int answ, int points)
{
  if (*t1 == NULL) {
    *t1 = (Arv1 *)malloc(sizeof(Arv1));
    if(t1 != NULL){
      (*t1)->esq = NULL;
      (*t1)->dir = NULL;
      (*t1)->id = n;
      strncpy((*t1)->quest, quest, 100); // Copiando a pergunta para o nó
      (*t1)->answ = answ; // Definindo a resposta correta
      (*t1)->points = points; // Definindo a pontuação
    }else{
      printf("Memory allocation failed\n");
    }
  } else {
    if (n < (*t1)->id) {
      insert_level1(&(*t1)->esq, n, quest, answ, points);
    }
    if (n > (*t1)->id) {
      insert_level1(&(*t1)->dir, n, quest, answ, points);
    }
  }
}

void insert_level2(Arv2 **t2, int n, char *quest, int answ, int points)
{
  if (*t2 == NULL) {
    *t2 = (Arv2 *)malloc(sizeof(Arv2));
    if(t2 != NULL){
      (*t2)->esq = NULL;
      (*t2)->dir = NULL;
      (*t2)->id = n;
      strncpy((*t2)->quest, quest, 100); // Copiando a pergunta para o nó
      (*t2)->answ = answ; // Definindo a resposta correta
      (*t2)->points = points; // Definindo a pontuação
    }else{
      printf("Memory allocation failed\n");
    }
  } else {
    if (n < (*t2)->id) {
      insert_level2(&(*t2)->esq, n, quest, answ, points);
    }
    if (n > (*t2)->id) {
      insert_level2(&(*t2)->dir, n, quest, answ, points);
    }
  }
}

void insert_level3(Arv3 **t3, int n, char *quest, int answ, int points)
{
  if (*t3 == NULL) {
    *t3 = (Arv3 *)malloc(sizeof(Arv3));
    if(t3 != NULL){
      (*t3)->esq = NULL;
      (*t3)->dir = NULL;
      (*t3)->id = n;
      strncpy((*t3)->quest, quest, 100); // Copiando a pergunta para o nó
      (*t3)->answ = answ; // Definindo a resposta correta
      (*t3)->points = points; // Definindo a pontuação
    }else{
      printf("Memory allocation failed\n");
    }
  } else {
    if (n < (*t3)->id) {
      insert_level3(&(*t3)->esq, n, quest, answ, points);
    }
    if (n > (*t3)->id) {
      insert_level3(&(*t3)->dir, n, quest, answ, points);
    }
  }
}

void print_questions_inorder1(Arv1 *t1) {
  if (t1 != NULL){
    print_questions_inorder1(t1->esq); // Visita a subárvore esquerda
    printf("ID: %d, Pergunta: %s\n", t1->id, t1->quest); // Imprime a pergunta do nó atual
    print_questions_inorder1(t1->dir); // Visita a subárvore direita
  }
}

void print_questions_inorder2(Arv2 *t2) {
  if (t2 != NULL){
    print_questions_inorder2(t2->esq); // Visita a subárvore esquerda
    printf("ID: %d, Pergunta: %s\n", t2->id, t2->quest); // Imprime a pergunta do nó atual
    print_questions_inorder2(t2->dir); // Visita a subárvore direita
  }
}

void print_questions_inorder3(Arv3 *t3) {
  if (t3 != NULL){
    print_questions_inorder3(t3->esq); // Visita a subárvore esquerda
    printf("ID: %d, Pergunta: %s\n", t3->id, t3->quest); // Imprime a pergunta do nó atual
    print_questions_inorder3(t3->dir); // Visita a subárvore direita

  }
}
