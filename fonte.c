#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define MAX_CHAR 255
#define DEFAULT_QUESTION "\nEscolha seu proximo passo: "
#define QTD_LEVELS 3


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
  int scoreArray[QTD_LEVELS]
  
}User;

BinaryTree *temp; // variavel global para ajudar na função de search 

void insert_level(BinaryTree **tree, int n, char *quest, char *step, int answ, int points);
void print_questions_inorder(BinaryTree *tree);
int binary_tree_search(BinaryTree *tree, int n);
void score_sum(int *score, BinaryTree *tree);
BinaryTree* level_search(BinaryTree *tree, BinaryTree **temp, int *score);
void clear_screen();
void insertion_sort_descending(int array[], int qtd_levels);


int main(){
  BinaryTree *t1 = NULL;
  BinaryTree *t2 = NULL;
  BinaryTree *t3 = NULL;
  User *user = (struct User *)malloc(sizeof(struct User));
  int input = 100;
  int score = 0;
  int flagQ1 = 1;
  int flagQ2 = 1;
  int flagQ3 = 1;
  int flagMenuJogo = 0;
  int totalScore =0; 
  int help = 1;
  char input_mainHome;


  //////////////////////////// 
  insert_level(&t1, 20, DEFAULT_QUESTION, "Tomate", 1, 10);
  //print_questions_inorder(t1);
  insert_level(&t1, 18, DEFAULT_QUESTION, "Queijo Mussarela", 1, 10);
  insert_level(&t1, 22, DEFAULT_QUESTION, "Burrata", 2, 10);
  insert_level(&t1, 13, DEFAULT_QUESTION"\nDICA: Fui criado por soldados romanos :o\n", "Óleo de Azeite", 1, 10);
  insert_level(&t1, 19, DEFAULT_QUESTION, "Óleo de GergeLim", 2, -10);
  insert_level(&t1, 2, DEFAULT_QUESTION"\nDICA: Minha origem é das aves\n", "Peito de Peru", 1, 10);
  insert_level(&t1, 17, DEFAULT_QUESTION, "Lingua de boi", 2, -10);
  insert_level(&t1, 1, DEFAULT_QUESTION"\nDICA: Sou em camadas\n", "Refogar maxixe com a proteina escolhida", 1, -10);
  insert_level(&t1, 9, DEFAULT_QUESTION, "Refogar cebola com a proteina escolhida", 2, 10);
  insert_level(&t1, 10, DEFAULT_QUESTION, "Assar mistura na churrasqueira", 2, -10);
  insert_level(&t1, 8, DEFAULT_QUESTION"\nDICA: Não gosto de ambientes quentes\n", "Rechear os tomates com o que foi refogado", 1, 10);
  insert_level(&t1, 7, DEFAULT_QUESTION, "Parabéns você acertou a receita de Tomate Recheado", 3, 10);
   
  //até aqui montei todo o lado A da arvore 1

  insert_level(&t1, 21, DEFAULT_QUESTION"\nDICA: Sou feito com folhas verdes i.i\n", "Mostarda", 1, -10);
  insert_level(&t1, 30, DEFAULT_QUESTION, "Molho Pesto", 2, 10);
  insert_level(&t1, 28, DEFAULT_QUESTION"\nDICA: Sou time folhas e não flores\n", "Manjericão", 1, 10);
  insert_level(&t1, 31, DEFAULT_QUESTION, "Brócolis", 2, -10);
  insert_level(&t1, 24, DEFAULT_QUESTION"\nDICA: Não gosto de eletricidade\n", "Picar tomates e manjericão", 1, 10);
  insert_level(&t1, 29, DEFAULT_QUESTION, "Assar no microondas tomate e manjericão", 2, -10);
  insert_level(&t1, 23, DEFAULT_QUESTION"\nDICA: Adoro me molhar\n", "Colocar tudo na airfrayer", 1, -10);
  insert_level(&t1, 27, DEFAULT_QUESTION, "Colocar tudo num prato e regar molho pesto", 2, 10);
  insert_level(&t1, 26, DEFAULT_QUESTION, "Parabéns você acertou a receita de Burrata com Molho Pesto", 3, 10);
  //até aqui montei todo o lado B da arvore 1

  insert_level(&t2, 40, DEFAULT_QUESTION,"Peito de Frango", 2, 10);
  //print_questions_inorder2(t2);
  insert_level(&t2, 38, DEFAULT_QUESTION, "Molho Teriaky", 1, 10);
  insert_level(&t2, 50, DEFAULT_QUESTION, "Molho de Tomate", 2, 10);
  insert_level(&t2, 28, DEFAULT_QUESTION"\nDICA: Minha origem é asiática :)\n", "Gengibre", 1, 10);
  insert_level(&t2, 39, DEFAULT_QUESTION, "Chimichurri", 2, -10);
  insert_level(&t2, 27, DEFAULT_QUESTION"\nDICA: Também posso ser usado no pão\n", "Semente de Chia", 1, -10);
  insert_level(&t2, 30, DEFAULT_QUESTION, "Semente de Gergelim", 2, 10);
  insert_level(&t2, 29, DEFAULT_QUESTION"\nDICA: Gosto de me misturar\n", "Castanha do Pará", 1, -10);
  insert_level(&t2, 35, DEFAULT_QUESTION, "Marinar Frango", 2, 10);
  insert_level(&t2, 34, DEFAULT_QUESTION"\nDICA: Adoro oléo quente\n", "Fritar o frango e adicionar molho", 1, 10);
  insert_level(&t2, 36, DEFAULT_QUESTION, " Assar Frango no churrasqueira", 2, -10);
  insert_level(&t2, 33, DEFAULT_QUESTION, "Parabéns você acertou a receita de Frango Teriyaki", 3, 10);
  //até aqui montei todo o lado A da arvore 2

  insert_level(&t2, 49, DEFAULT_QUESTION"\nDICA: Sou cheinho de lactose i.i\n", "Tofu", 1, -10);
  insert_level(&t2, 52, DEFAULT_QUESTION, "Queijo Mussarela", 2, 10);
  insert_level(&t2, 51, DEFAULT_QUESTION"\nDICA: Sou cheinho de glúten\n", "Chia", 1, -10);
  insert_level(&t2, 59, DEFAULT_QUESTION, "Farinha de Rosca", 2, 10);
  insert_level(&t2, 56, DEFAULT_QUESTION"\nDICA: Tenho medo de objetos pontiagudos\n", "Empanar o Frango", 1, 10);
  insert_level(&t2, 60, DEFAULT_QUESTION, "Cortar Frango em Cubos", 2, -10);
  insert_level(&t2, 54, DEFAULT_QUESTION"\nDICA: Gosto de óleos quentes\n", "Fritar o frango. Depois cobrir com molho de tomate e assar no forno", 1, 10);
  insert_level(&t2, 57, DEFAULT_QUESTION, "Cozinhar Frango na água com molho de tomate", 2, -10);
  insert_level(&t2, 53, DEFAULT_QUESTION, "Parabéns você acertou a receita de Frango a Parmegiana", 3, 10);
  //até aqui montei todo o lado B da arvore 2

  insert_level(&t3, 30, DEFAULT_QUESTION, "Maçã", 3, 10);
  //print_questions_inorder3(t3);
  insert_level(&t3, 10, DEFAULT_QUESTION, "Massa Folhada", 1, 10);
  insert_level(&t3, 32, DEFAULT_QUESTION, "Aveia em Flocos", 2, 10);
  insert_level(&t3, 9, DEFAULT_QUESTION"\nDICA: Sou cilíndrica ;)\n", "Gengibre", 1, -10);
  insert_level(&t3, 12, DEFAULT_QUESTION, "Canela em pó", 2, 10);
  insert_level(&t3, 11, DEFAULT_QUESTION"\nDICA: Meus nutrientes são mais conservados\n", "Açúcar Demerara", 1, -10);
  insert_level(&t3, 14, DEFAULT_QUESTION, "Açúcar Mascavo", 2, 10);
  insert_level(&t3, 13, DEFAULT_QUESTION"\nDICA: Gosto de me cobrir\n", "Misturar todos os ingredientes", 1, -10);
  insert_level(&t3, 16, DEFAULT_QUESTION, "Enrolar maçã na massa", 2, 10);
  insert_level(&t3, 15, DEFAULT_QUESTION"\nDICA: Não gosto de ficar oleosa\n", "Fritar e quando terminar polvilhar com açucar", 1, -10);
  insert_level(&t3, 18, DEFAULT_QUESTION, "Assar no forno e quando terminar polvilhar com açucar ", 2, 10);
  insert_level(&t3, 17, DEFAULT_QUESTION, "Parabéns você acertou a receita de Rolinhos de Maçã e Canela Assados", 3, 10);
  //até aqui montei todo o lado A da arvore 3

  insert_level(&t3, 31, DEFAULT_QUESTION"\nDICA: Esse ingrediente vem de uma vagem(fava) =)\n", "Essência de Baunilha", 1, -10);
  insert_level(&t3, 50, DEFAULT_QUESTION, "Canela em pó", 2, 10);
  insert_level(&t3, 42, DEFAULT_QUESTION"\nDICA: Não gosto de insetos\n", "Açúcar Mascavo", 1, 10);
  insert_level(&t3, 51, DEFAULT_QUESTION, "Mel", 2, -10);
  insert_level(&t3, 41, DEFAULT_QUESTION"\nDICA: Gosto de ficar junto de todos\n", "Untar massa", 1, -10);
  insert_level(&t3, 44, DEFAULT_QUESTION, "Misturar todos os ingredientes", 2, 10);
  insert_level(&t3, 43, DEFAULT_QUESTION"\nDICA: Não gosto de fã clubes\n", "Assar na airfryer e depois montar com as maçãs no refratário", 1, -10);
  insert_level(&t3, 46, DEFAULT_QUESTION, "Colocar para assar e depois montar com as maçãs no refratário", 2, 10);
  insert_level(&t3, 45, DEFAULT_QUESTION, "Parabéns você acertou a receita de Crumble de Maçã", 3, 10);
  //até aqui montei todo o lado B da arvore 3

  ////////////////////// GAME BEGINS /////////////////////
  void clear_screen();
  //printf("\n\n");
  //printf("Seja bem-vindo ao jogo Delícia das Devs");
  
  while(input_mainHome != 'Q'){

    mainhome:
    printf("\n   Seja bem-vindo ao jogo Delícia das Devs\n ");
    printf("\n   Acerte os ingredientes e ganhe a receita\n");
    printf("\n > Pressione S para iniciar o jogo");
    printf("\n > Press H se precisa de ajuda");
    printf("\n > press Q para encerrar o jogo");
    printf("\n__________________________________________________\n\n");
    scanf("%c", &input_mainHome);
    help = 1;

    if(input_mainHome == 'S'){
      flagMenuJogo = 1;

    }else if(input_mainHome == 'H' && help == 1){
      printf("\nO jogo tem o objetivo de acertar a receita por dicas do que são os ingredintes que vão ser usados\n");
      printf("\nO jogo possui 3 fases, e duas opções de receita em cada \n");
      printf("\nDigite 0 para voltar para o menu\n");
      scanf("%d", &help);
      if(help == 0){
        while ((getchar()) != '\n');
        input_mainHome = ' ';
        goto mainhome;
      }
      
    }else if(input_mainHome != 'S' && input_mainHome != 'Q' && input_mainHome != 'H'){
      printf("\nCaractere inválido por favor digite novamente\n");
      
    }
    //void clear_screen();

    while (flagMenuJogo == 1) {
      
      if (flagQ1 == 1 || flagQ2 == 1 || flagQ3 == 1 ){
        printf("\n\nPor qual ingrediente que deseja começar?\n");
        if (flagQ1 == 1){
          printf("1- ");
          binary_tree_search(t1, 20);
        }
        if (flagQ2 == 1){
          printf("\n2- ");
          binary_tree_search(t2, 40);
        }
        if (flagQ3 == 1){
          printf("\n3- ");
          binary_tree_search(t3, 30);
        }
      }  

      if (flagQ1 == 0 && flagQ2 == 0 && flagQ3 == 0){// terminu todos os niveis
        printf("\nParabéns vc terminou todas as fases do jogo!\nSua melhor pontuação em cada nível foi:\n");
        char arrayLevels[][MAX_CHAR] = {"Prato de Entrada", "Prato Principal", "Sobremesa"};
        int arrayOldScore[QTD_LEVELS];
        int i, j;
        
        for (i=0; i<QTD_LEVELS; i++){
          arrayOldScore[i] = user->scoreArray[i];
        }

        insertion_sort_descending(user->scoreArray, QTD_LEVELS);
        
        for(i=0; i<QTD_LEVELS; i++){
          for(j=0; j<QTD_LEVELS; j++){
            if (user->scoreArray[i] == arrayOldScore [j]){
              printf("\n\t%d- Level %s: %d pontos\n", i+1, arrayLevels[j], user->scoreArray[i]);
              arrayOldScore[j] = 0;
            }
          }
        }
        printf("\nSua pontuação total foi:");
        for (i=0; i<QTD_LEVELS; i++){
          totalScore = totalScore + user->scoreArray[i];
        }

        printf("\n%d pontos\n\n\n", totalScore);
        sleep(2);// por enquanto volta ao menu depois de 5 segundos
        flagMenuJogo=0;
        while ((getchar()) != '\n');
        input_mainHome = ' ';
        break;
      }

      
      if (flagQ1 == 1 || flagQ2 == 1 || flagQ3 == 1 ){
        printf("\n\n(0- Voltar ao menu principal)\n");
        printf("\nDigite o numero correspondente a sua escolha: ");
        scanf("%d", &input);
      }

      if (input == 1 && flagQ1 == 1){
        level_search(t1, temp, &score);
        printf("\nSeu score na fase de Pratos de Entradas é: %d pontos\n", score);
        user->scoreArray[0] = score;
        score = 0; 
        sleep(2);
        if (user->scoreArray[0] >= 50){
          flagQ1 = 0;
        }

      }else if(input == 2 && flagQ2 == 1){
        level_search(t2, temp, &score);
        printf("\nSeu score na fase de Pratos Principais é: %d pontos\n", score);
        user->scoreArray[1] = score;
        score = 0; 
        sleep(2);
        if (user->scoreArray[1]  >= 50){
          flagQ2 = 0;
        }

      }else if(input == 3 && flagQ3 == 1){
        level_search(t3, temp, &score);
        printf("\nSeu score na fase de Sobremesa é: %d pontos\n", score);
        user->scoreArray[2] = 50;
        score = 0; 
        sleep(2);
        if (user->scoreArray[2] >= 50){
          flagQ3 = 0;
        }

      }else if (input == 0){
        printf("\nJogo encerrado, Voltando ao menu principal\n"); // pode ter uma pergunta de confirmação
        flagMenuJogo = 0;
        while ((getchar()) != '\n');
        input_mainHome = ' ';
        goto mainhome;
      }else{
        printf("\nNúmero inválido. Tente novamente.\n");
        clear_screen();
      }
    } 
  }
  return 0;
}

void insert_level(BinaryTree **tree, int n, char *quest, char *step, int answ, int points){
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

void score_sum(int *score, BinaryTree *tree){
  *score += tree->points;
}

BinaryTree* level_search(BinaryTree *tree, BinaryTree **temp, int *score){
  clear_screen();
  if (tree->left == NULL && tree->right == NULL && tree->points < 0){
    //printf("oi, entrou no else points < 0\n");
    score_sum(score, tree);
    return level_search(temp, temp, score); // deu errado esse temp  kakaka 
  }else{
    BinaryTree *aux;
    int input = 100; // valor arbritario pq a saida é 0
    score_sum(score, tree);
    //printf("oi, entrou no ultiimooo else\n");
     

    while (1) {
    
      if (tree->left != NULL) {
        if(tree->left->answ !=3){ // identifica se é o nó que o step é a receita final
          printf("%s\n", tree->left->quest);

          printf("1- %s\n", tree->left->step);
        }else if (tree->left->answ ==3){
          if(*score>=50){ // ganhou nó esquerda
            clear_screen();
            printf("\n%s\n", tree->left->step);
            sleep(2);
          }else{ // perdeu nó esquerda
            clear_screen();
            printf("\nNão foi dessa vez! Você não acertou a receita, tente novamente\n");
            sleep(2);
          }
        } else {
          printf("\nentrei num lugar errado, linha 235\n");
        }
      } else {
          return NULL;
      }

      if (tree->right != NULL) {
        if(tree->right->answ !=3){ // identifica se é o nó que o step é a receita final
          printf("2- %s\n", tree->right->step);
          printf("\n(0- Voltar ao menu de Ingredientes)\n");
        }else if (tree->right->answ ==3){
          if(*score>=50){ // ganhou nó direita
            clear_screen();
            printf("%s\n", tree->right->step);
            sleep(5);
          }else{ // perdeu nó na direit
            clear_screen();
            printf("Não foi dessa vez! Você não acertou a receita, tente novamente\n");
            sleep(2);
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
          return level_search(aux, temp, score);
        }else{
          return NULL;
        }
               
      }else if(input == 2){
        if (tree->right != NULL){
            aux = tree->right;
            temp = tree->left;
            return level_search(aux, temp, score);
          }else{
          return NULL;
          }
      }else if (input == 0){
        printf("Jogo encerrado\n"); // pode ter uma pergunta de confirmação
        return NULL; // talvez um go to aqui pra redirecionar pro menu
      }else{
        printf("\nNúmero inválido. Tente novamente.\n");
        clear_screen();
      }
    } 
    
  }

}

void clear_screen() {
    #ifdef _WIN32
    //system("cls");
    #else
    system("clear");
    #endif
}

void insertion_sort_descending(int array[], int qtd_levels) {
  int i, key, j;
  for (i = 1; i < qtd_levels; i++) {
    key = array[i];
    j = i - 1;
    while (j >= 0 && array[j] < key) {
        array[j + 1] = array[j];
        j = j - 1;
    }
    array[j + 1] = key;
  }
}