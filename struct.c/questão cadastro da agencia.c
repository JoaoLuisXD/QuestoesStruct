#include <string.h>
#include <stdlib.h>
#include <stdio.h>
void funcao()
{
    printf("escolha uma das seguintes opcoes\n");
    printf("1. Cadastrar contas.\n");
    printf("2. Visualizar todas as contas de determinado cliente.\n");
    printf("3. Excluir a conta com menor saldo \n");
    printf("4.Sair.\n");
}
typedef struct cadastro
{
  char nome[100];
  int numero;
  float saldo;

};
struct cadastro cadastro[2];
int main()
{

    funcao();
    int escolha;
    char acharnome;
    int cont=0;
    int contascadastradas=0;
    do
    {
        scanf("%d",&escolha);
    switch(escolha)
    {
        case 1:
        for(int i=0;i<2;i++)
        {
           printf("digite o nome: ");
           scanf("%s",&cadastro[i].nome);
           printf("digite o numero: ");
           scanf("%d",&cadastro[i].numero);
           printf("digite o saldo: ");
           scanf("%f",&cadastro[i].saldo);
           contascadastradas++;
        }
        break;
        case 2:
            printf("escolha o nome que deseja procurar: ");
            char nomeesc[100];
            int cont=0;
            scanf("%s",nomeesc);
            for(int i=0;i<2;i++)
            {
               if(cadastro.nome == nomeesc)
               {
                   printf("|%d|,|%f|", cadastro.numero,cadastro.saldo);
                   cont = 1;
               }
            }
            if(cont==0)
            {
                printf("nao existe uma conta com esse nome");
            }

        /*int cont=0;
        char nome_cliente[100];
        printf("digite um nome para buscar a conta");
        gets(nome_cliente);
        for(int i=0; i<contascadastradas; i++)
        {
        if(strcmp(nome_cliente,conta[i].nome)==0)
        {
            printf("nome: %s\n",conta[i].nome);
            printf("nomero da conta: %d\n",conta[i].numero);
            printf("saldo disponivel: %.2f",conta[i].saldo);
            cont++;
        }
        else if(cont==0)
        {
            printf("esse usario nao possue uma conta.");
        }
    }*/






            break;
     }




    }while(escolha!=4);
   return 0;
}
