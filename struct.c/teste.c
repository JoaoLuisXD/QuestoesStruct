#include <stdio.h>
#include <stdlib.h>
struct pessoa
{
   int idade;
   float peso;
   char nome[100];
};
typedef struct pessoa pessoa;
int main()
{
   pessoa dados[3];
   int i;
   for(int i=0;i<3;i++)
   {
      scanf("%d",&dados[i].idade);
      scanf("%f",&dados[i].peso);
      scanf("%s",&dados[i].nome);
      fflush(stdin);
   }
   for(int i=0;i<3;i++)
   {
      printf("%d\n",dados[i].idade);
      printf("%.2f\n",dados[i].peso);
      printf("%s\n",dados[i].nome);
   }
}
