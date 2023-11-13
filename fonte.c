#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Arv1{
  int id;
  char quest[256];
  int correct_answ;
  int points;
  struct Arv1 *esq;
  struct Arv1 *dir;
}Arv1;

typedef struct Arv2{
  int id;
  char quest[256];
  int correct_answ;
  int points;
  struct Arv2 *esq;
  struct Arv2 *dir;
}Arv2;

typedef struct Arv3{
  int id;
  char quest[256];
  int correct_answ;
  int points;
  struct Arv3 *esq;
  struct Arv3 *dir;
}Arv3;

typedef struct User{
  int idUser; //ou str idUser;
  int pontuacao;
}User;

void insert_level1(Arv1 **t1, int num);
void insert_level2(Arv2 **t2, int num);
void insert_level3(Arv3 **t3, int num);

int main(){
  Arv1 *t1 = NULL;
  Arv2 *t2 = NULL;
  Arv3 *t3 = NULL;

  insert_level1(&t1, 10);
  insert_level1(&t1, 12);
  insert_level1(&t1, 8);
  insert_level1(&t1, 9);
  insert_level1(&t1, 6);
  insert_level1(&t1, 5);
  insert_level1(&t1, 7);
  //até aqui montei todo o lado A da arvore 1
  insert_level1(&t1, 11);
  insert_level1(&t1, 20);
  insert_level1(&t1, 18);
  insert_level1(&t1, 21);
  insert_level1(&t1, 15);
  insert_level1(&t1, 19);
  insert_level1(&t1, 14);
  insert_level1(&t1, 17);
  insert_level1(&t1, 16);
  //até aqui montei todo o lado B da arvore 1

  insert_level2(&t2, 40);
  insert_level2(&t2, 38);
  insert_level2(&t2, 50);
  insert_level2(&t2, 28);
  insert_level2(&t2, 39);
  insert_level2(&t2, 27);
  insert_level2(&t2, 30);
  insert_level2(&t2, 29);
  insert_level2(&t2, 35);
  insert_level2(&t2, 34);
  insert_level2(&t2, 36);
  insert_level2(&t2, 33);
  //até aqui montei todo o lado A da arvore 2
  insert_level2(&t2, 49);
  insert_level2(&t2, 52);
  insert_level2(&t2, 51);
  insert_level2(&t2, 59);
  insert_level2(&t2, 56);
  insert_level2(&t2, 60);
  insert_level2(&t2, 54);
  insert_level2(&t2, 57);
  insert_level2(&t2, 55);
  //até aqui montei todo o lado B da arvore 2

  insert_level3(&t3, 30);
  insert_level3(&t3, 10);
  insert_level3(&t3, 32);
  insert_level3(&t3, 9);
  insert_level3(&t3, 12);
  insert_level3(&t3, 11);
  insert_level3(&t3, 14);
  insert_level3(&t3, 13);
  insert_level3(&t3, 16);
  insert_level3(&t3, 15);
  insert_level3(&t3, 18);
  insert_level3(&t3, 17);
  //até aqui montei todo o lado A da arvore 3
  insert_level3(&t3, 31);
  insert_level3(&t3, 34);
  insert_level3(&t3, 33);
  insert_level3(&t3, 36);
  insert_level3(&t3, 35);
  insert_level3(&t3, 38);
  insert_level3(&t3, 37);
  insert_level3(&t3, 40);
  insert_level3(&t3, 39);
  //até aqui montei todo o lado B da arvore 3

  return 0;
}

void insert_level1(Arv1 **t1, int n)
{
  if (*t1 == NULL) {
    *t1 = (Arv1 *)malloc(sizeof(Arv1));
    (*t1)->esq = NULL;
    (*t1)->dir = NULL;
    (*t1)->id = n;
  } else {
    if (n < (*t1)->id) {
      inserir(&(*t1)->esq, n);
    }
    if (n > (*t1)->id) {
      inserir(&(*t1)->dir, n);
    }
  }
}

void insert_level2(Arv2 **t2, int n)
{
  if (*t2 == NULL) {
    *t2 = (Arv2 *)malloc(sizeof(Arv2));
    (*t2)->esq = NULL;
    (*t2)->dir = NULL;
    (*t2)->id = n;
  } else {
    if (n < (*t2)->id) {
      inserir(&(*t2)->esq, n);
    }
    if (n > (*t2)->id) {
      inserir(&(*t2)->dir, n);
    }
  }
}

void insert_level3(Arv3 **t3, int n)
{
  if (*t3 == NULL) {
    *t3 = (Arv3 *)malloc(sizeof(Arv3));
    (*t3)->esq = NULL;
    (*t3)->dir = NULL;
    (*t3)->id = n;
  } else {
    if (n < (*t3)->id) {
      inserir(&(*t3)->esq, n);
    }
    if (n > (*t3)->id) {
      inserir(&(*t3)->dir, n);
    }
  }
}