#include <stdio.h>
#include <stdlib.h>

typedef struct{
  char nome[30];
  char apelido[30];
  char sexo;
  char bi[15];
  int idade;
} Pessoa;

//funcoes/procedimentos
void menu();
void mostrar();
Pessoa ler_dados();

int main() {
  int i,n;
  char n1, *linha;
  
  Pessoa p1;

  FILE *fptr;

  fptr = fopen("cadastro.csv", "r");
  if( fptr == NULL){
      printf("Erro na criacao ou abertura do ficheiro!");
      exit(1);
  } else {
    p1=ler_dados();
       fprintf(fptr, "%s;%s;%d;%c;%d\n", p1.nome, p1.apelido,p1.bi, p1.sexo, p1.idade);
   //ler_dados();
  //se quiser mostrar o menu descomente a seguinte linha
  do{
    system("cls");
    menu();
    printf("Selecione a opcao:");
    n1 = getchar();
    switch(n1){
    case '1': system("cls");
              linha = malloc(sizeof(Pessoa));
              while(fscanf(fptr,"%[^\n]",linha)!= EOF){
                printf("%s\n",linha);
              }
              break;
    case '2':system("cls");
             mostrar(p1);
             break;
    //case '3':adicionar();
       //break;
   }
 }while( n1 != '0');
  //mostrar dados
  //mostrar(p1);
  }
  fclose(fptr);
  return 0;
}

//Esta funcao recebe como argumento o tipo pessoa e mostra os dados
void mostrar(Pessoa p){

  printf("==========================================================\n");
      printf("Nome Completo: %s %s\n", p.nome, p.apelido);
      printf("BI No.: %d\n", p.bi);
      printf("Sexo: %c\n", p.sexo);
      printf("Idade: %d\n", p.idade);

  printf("==========================================================\n");
}

//Mostra menu
void menu(){
   printf("==========================================================\n");
   printf("||                     CADASTRO                         ||\n");
   printf("==========================================================\n");
   printf("||                                                      ||\n");
   printf("||  1.  Mostrar Todas Pessoas                           ||\n");
   printf("||  2.  Mostrar Pessoa                                  ||\n");
   printf("||  3.  Remover Pessoa                                  ||\n");
   printf("||  4.  Adicionar Pessoa                                ||\n");
   printf("||  0.  Para Sair                                       ||\n");
   printf("||                                                      ||\n");
   printf("==========================================================\n");

}

//Esta funcao retorna uma pessoa com dados
Pessoa ler_dados(){
  Pessoa pessoa1;
      printf("Nome: ");
      scanf("%[^\n]%*c", pessoa1.nome);
      printf("Apelido: ");
      scanf("%[^\n]%*c", pessoa1.apelido);
      printf("BI No: ");
      scanf("%[^\n]%*c", pessoa1.bi);
      printf("Sexo (m/f): ");
      scanf("%c", &pessoa1.sexo);
      printf("Idade: ");
      scanf("%d", &pessoa1.idade);
      system("cls");
  return pessoa1;
}
