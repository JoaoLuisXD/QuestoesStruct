#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct cadastro
{
   char nome[100];
   int numero;
   float saldo;
};
typedef struct cadastro cadastro;

void funcaocadastro(cadastro *cadastrocl, int total)
{


    for(int i=0;i<total;i++)
    {
        printf("nome: ");
        fgets(cadastrocl[i].nome, 100, stdin);
        cadastrocl[i].nome[strcspn(cadastrocl[i].nome, "\n")] = 0;
        printf("numero da conta: ");
        scanf("%d", &cadastrocl[i].numero);
        printf("salario: ");
        scanf("%f", &cadastrocl[i].saldo);
        getchar();
    }

}

void funcaovercontas(cadastro *cadastrocl, int total) {
    char procurar[100];
    printf("Escreva o nome que quer procurar: ");
    fgets(procurar, 100, stdin);
    procurar[strcspn(procurar, "\n")] = 0;  // Remove o '\n'

    for (int i = 0; i < total; i++) {
        if (strcmp(cadastrocl[i].nome, procurar) == 0)
        {  // Compara strings corretamente
            printf("Dados do cliente encontrado:\n");
            printf("|Nome: %s|\n", cadastrocl[i].nome);
            printf("|Numero da conta: %d|\n", cadastrocl[i].numero);
            printf("|Saldo: %.2f|\n", cadastrocl[i].saldo);
            return;  // Sai ap�s encontrar o cliente
        }
    }

    printf("Cliente n�o encontrado.\n");
}

void funcaoexcluir(cadastro *cadastrocl, int *total)
{
    int menor=0;
    for(int i=0;i<*total;i++)
    {
        if(cadastrocl[i].saldo<cadastrocl[menor].saldo)
        {
            menor=i;
        }
    }
    printf("Cliente com o menor saldo:\n");
    printf("| nome: %s |\n", cadastrocl[menor].nome);
    printf("| numero da conta: %d |\n", cadastrocl[menor].numero);
    printf("| saldo: %.2f |\n\n", cadastrocl[menor].saldo);
    for(int i=menor;i<*total-1;i++)
    {
       cadastrocl[i] = cadastrocl[i + 1];
    }

    (*total)--;
    printf("|a conta com menor saldo foi excluida com sucesso!|\n");
    printf("|valores apos excluir o cliente com o menor saldo|\n");
    for(int i=0;i<*total;i++)
    {
         printf("cliente %s: Saldo: %.2f\n",cadastrocl[i].nome , cadastrocl[i].saldo);
    }
}
int main()
{
    int total = 4;
    int cadastrocl;
    char procurar;
    int escolha;
    cadastro clientes[total];
    do
    {
        printf("escolha uma das seguintes opcoes\n");
        printf("1. Cadastrar contas.\n");
        printf("2. Visualizar todas as contas de determinado cliente.\n");
        printf("3. Excluir a conta com menor saldo \n");
        printf("4.Sair.\n");
        scanf("%d",&escolha);
        getchar();
        switch(escolha)
        {
            case 1:
                funcaocadastro(clientes,total);
                break;
            case 2:
                funcaovercontas(clientes,total);
                break;
            case 3:
                funcaoexcluir(clientes,&total);
                break;
            case 4:
                return 0;
        }
    }
     while(escolha!=4);





   return 0;
}
