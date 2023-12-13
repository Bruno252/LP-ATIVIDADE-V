#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

void pratileiraA() {
    printf("Livro:a\n");
    printf("Genero:a\n");
    printf("Autor:a\n");
}
void pratileiraB() {
    printf("Livro:b\n");
    printf("Genero:b\n");
    printf("Autor:b\n");

}

void a() {
    printf("---------------------------------\n");
}

void limpa()
{
    fflush(stdin);
    system("cls || clear");
}

void menu()
{
    printf("\n---------------------------------\n");
    printf("\tCadastro de Livro");
    printf("\n---------------------------------\n");
}

void menu2()
{
    printf("\n---------------------------------------\n");
    printf("\tEmprestimos De Livros");
    printf("\n\nLivros Disponiveis: \n");
    printf("\n1- Iracema");
    printf("\n---------------------------------------\n");
}

struct Gestaobiblioteca {

    char nomelivroautor[250];
    char nomelivro[50][200];
    char generolivro[50][200];
    char autorlivro[50][200];
    char editoralivro[200];
    char emailAutor[300];

    float livroPreco[5];
    float somaLivro;
    float somaTotal;
    int acumulador[5];
    int livro1;
    int livro2;

    char usuario[250];
    char senha[250];
    char usuarioSalvo[250];
    char senhaSalvo[250];
    int i;
    int q[5];
    int b;
    int c;
};

struct Gestaobiblioteca login(struct Gestaobiblioteca biblioteca) {
    int i;
    setbuf(stdin,NULL);
    a();
    printf("Usurname:\n");
    a();
    fgets(biblioteca.usuario,sizeof(biblioteca.usuario),stdin);

    a();
    printf("Senha:\n");
    a();
    fgets(biblioteca.senha,sizeof(biblioteca.senha),stdin);


    if(strcmp(biblioteca.usuario,biblioteca.usuarioSalvo)==0 && strcmp(biblioteca.senha,biblioteca.senhaSalvo)==0) {
        biblioteca.i=1;
        //CadastroLivro(biblioteca);
    } else {
        limpa();
        printf("Username ou Senha errada\n");
    }
    
    return biblioteca;
}


void loginECadastro(struct Gestaobiblioteca biblioteca) {

    int escolha;
    //struct Gestaobiblioteca biblioteca;
    biblioteca.i=0;
    do {
        a();
        printf("1 | para cadastro\n");
        printf("2 | para login\n");
        a();
        scanf("%d",&escolha);

        switch(escolha) {

        case 1:
            limpa();
            setbuf(stdin,NULL);
            fflush(stdin);
            a();
            printf("Username:\n");
            a();
            fgets(biblioteca.usuarioSalvo,sizeof(biblioteca.usuarioSalvo),stdin);
            
            a();
            printf("Senha:\n");
            a();
            fgets(biblioteca.senhaSalvo,sizeof(biblioteca.senhaSalvo),stdin);
            limpa();
            biblioteca.b++;
            break;

        case 2:
            limpa();
            fflush(stdin);
            biblioteca=login(biblioteca);
            break;

        default:
            limpa();
            printf("Escolha Invalida\n");

            break;

        }

    } while(biblioteca.i!=1);
    limpa();
    printf("Bem-Vindo\n");
}


void CadastroLivro(struct Gestaobiblioteca biblioteca) {
    //setlocale(LC_ALL, "portuguese");
    fflush(stdin);
    setbuf(stdin,NULL);
    limpa();
    menu();
    printf("\nDigite o nome do livro que deseja cadastrar: ");
    fgets(biblioteca.nomelivro,sizeof(biblioteca.nomelivro),stdin);

    printf("Digite o genero do livro: ");
    gets(biblioteca.generolivro);

    printf("Digite o nome do autor do livro: ");
    gets(biblioteca.autorlivro);

    printf("Digite o nome da editora do livro: ");
    gets(biblioteca.editoralivro);

    printf("Digite o email para contato: ");
    gets(biblioteca.emailAutor);
    limpa();

    menu();
    printf("\nDados do Livro cadastrado: \n");

    printf("\nNome do Livro: %s\n", biblioteca.nomelivro);
    printf("Genero do Livro: %s\n", biblioteca.generolivro);
    printf("Autor do Livro: %s\n", biblioteca.autorlivro);
    printf("Editora do Livro: %s\n", biblioteca.editoralivro);

    printf("\nSeu Livro esta em analise...");
    printf("\nEntraremos em contato após a analise.");

}


struct Gestaobiblioteca emprestimo(struct Gestaobiblioteca biblioteca)
{
    //setlocale(LC_ALL, "portuguese");

    int escolha;
    int escolha2;
    int acumulador[6];
    int i,q;

    for(i=0; i<6; i++) {
        acumulador[i]=0;
    }

    i=0;

    do {
        printf("-----------------------------------------------------------------\n");
        printf("Digite 1 | para pedir um livro emprestado:\n");
        printf("Digite 2 | para consultar livro emprestado e o prazo de entrega\n");
        printf("Digite 3 | para sair\n");
        printf("------------------------------------------------------------------\n");
        scanf("%d", &escolha);
        limpa();

        switch (escolha)
        {
        case 1:
            setbuf(stdin,NULL);
            printf("Opcoes Disponiveis:\n");
            a();
            printf("Numero do Livro:1\n");
            pratileiraA();
            a();
            printf("Numero do Livro:2\n");
            pratileiraB();
            a();
            printf("Numero do Livro:");
            scanf("%d",&escolha2);
            limpa();

            if(biblioteca.q[escolha2]<1) {
                if(escolha2>=1 && escolha2<3) {
                    biblioteca.q[escolha2]++;
                    biblioteca.acumulador[biblioteca.i]=escolha2;
                }
            } else {
                limpa();
                a();
                printf("Este Livro ja foi emprestado\n");
                a();
            }
            //printf("Nome do livro:");
            //fgets(biblioteca.nomelivro[biblioteca.i],sizeof(biblioteca.nomelivro[biblioteca.i]),stdin);

            biblioteca.i++;
            break;

        case 2:
            for(q=0; q<5; q++) {

                if(biblioteca.acumulador[q]==1) {
                    a();
                    pratileiraA();
                    a();
                }

                if(biblioteca.acumulador[q]==2) {
                    a();
                    pratileiraB();
                    a();
                }

                // printf("Nome do Livro:%s",biblioteca.nomelivro[q]);
                //printf("Prazo ate 7 dias para devolucao\n");
                //printf("\n");
            }
            printf("Prazo ate 7 dias para devolucao\n");
            break;

        case 3:

            break;

        default:
            printf("Opção Invalida!");
            break;
        }

    } while(escolha!=3);
    return biblioteca;
}

struct Gestaobiblioteca comprar(struct Gestaobiblioteca biblioteca) {

    int escolha;
    int escolha2;
    int acumulador[2];
    int livro1=0;
    int livro2=0;
    int i=0;
    float soma;

    do {
        a();
        printf("1 | para por uma livro no carrinho\n");
        printf("2 | para ver o carrinho\n");
        printf("3 | para voltar ao menu\n");
        a();
        scanf("%d",&escolha);
        switch(escolha) {

        case 1:
            limpa();
            a();
            printf("Numero do Livro:1\n");
            pratileiraA();
            printf("Preco:R$%2.f\n",biblioteca.livroPreco[1]);
            
            a();
            printf("Numero do Livro:2\n");
            pratileiraB();
            printf("Preco:R$%2.f\n",biblioteca.livroPreco[2]);
            a();
            scanf("%d",&escolha2);

            acumulador[i]=escolha2;

            if(acumulador[i]==1) {
                biblioteca.livro1++;
            } else if(acumulador[i]==2) {
                biblioteca.livro2++;
            }

            biblioteca.somaLivro+=biblioteca.livroPreco[escolha2];
            limpa();
            printf("Valor Total antes da compra:R$%.2f\n",biblioteca.somaLivro);
            break;

        case 2:
        if(biblioteca.livro1>0 || biblioteca.livro2>0){
            if(biblioteca.livro1>0) {
                limpa();
                a();
                pratileiraA();
                printf("Preco:R$%2.f\n",biblioteca.livroPreco[1]);
                printf("Quantidade:%d\n",biblioteca.livro1);
                a();

            } 
                if(biblioteca.livro2>0){
                a();
                pratileiraB();
                printf("Preco:R$%2.f\n",biblioteca.livroPreco[2]);
                printf("Quantidade:%d\n",biblioteca.livro2);
                a();

            }
            printf("Valor Total da Compra:R$%.2f\n",biblioteca.somaLivro);
            }else{
            limpa();
            printf("Nenhum livro foi comprado\n");
            
            }
            
            break;

        case 3:
            limpa();
            break;

        }
    } while(escolha!=3);
    return biblioteca;
}

void opcoes()
{
    printf("\n------------------------------------\n");
    printf("\tEscolha Opçao desejada");
    printf("\n1- Cadastro de Livros\n");
    printf("2- Emprestimo de livro\n");
    printf("3- Comprar Livro\n");
    printf("4- deslogar e sair");
    printf("\n------------------------------------\n");
}


int main() {
    setlocale(LC_ALL, "portuguese");
    int escolha;
    int i;
    struct Gestaobiblioteca biblioteca;
    loginECadastro(biblioteca);


    biblioteca.livroPreco[1]=50;
    biblioteca.livroPreco[2]=100;
    biblioteca.somaLivro=0;
    biblioteca.i=0;
    biblioteca.livro1=0;
    biblioteca.livro2=0;
    biblioteca.b=0;

    for(i=0; i<4; i++) {
        biblioteca.q[i]=0;
    }

    do {

        opcoes();
        printf("Escolha:");
        scanf("%d",&escolha);

        switch(escolha) {

        case 1:
            fflush(stdin);
            CadastroLivro(biblioteca);
            break;

        case 2:
            fflush(stdin);
            limpa();
            biblioteca=emprestimo(biblioteca);
            break;

        case 3:
            fflush(stdin);
            limpa();
            biblioteca=comprar(biblioteca);

            break;

        case 4:
        
            break;
        
        default:
            printf("Escolha Invalida");
            break;
        }

    } while(escolha!=4);
    limpa();
    printf("Obrigado e Volte Sempre\n");
    return 0;
}