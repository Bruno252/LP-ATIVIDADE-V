#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

void a(){
    printf("---------------------------------\n");
}

void menu()
{
    printf("\n---------------------------------\n");
    printf("\tCadastro de Livro");
    printf("\n---------------------------------\n");
}

struct Gestaobiblioteca{

    char nomelivro[200];
    char generolivro[200];
    char autorlivro[200];
    char editoralivro[200];
    char emailAutor[300];

    char usuario[250];
    char senha[250];
    char usuarioSalvo[250];
    char senhaSalvo[250];
    int i;
};

void login(struct Gestaobiblioteca biblioteca){
    a();
    printf("Usurname:\n");
    a();
    fgets(biblioteca.usuario,sizeof(biblioteca.usuario),stdin);

    a();
    printf("Senha:\n");
    a();
    fgets(biblioteca.senha,sizeof(biblioteca.senha),stdin);
    
    if(strcmp(biblioteca.usuario,biblioteca.usuarioSalvo)==0 && strcmp(biblioteca.senha,biblioteca.senhaSalvo)==0){
        a();
        printf("Bem-Vindo\n");
        a();
        biblioteca.i++;
        //CadastroLivro(biblioteca);
    }else{
        printf("Error");
    }
}


void loginECadastro(struct Gestaobiblioteca biblioteca){

    int escolha;
    //struct Gestaobiblioteca biblioteca;


do{
    biblioteca.i=0;
    a();
    printf("1 | para cadastro\n");
    printf("2 | para login\n");
    a();
    scanf("%d",&escolha);

    switch(escolha){

        case 1:
                limpa();
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
        break;

        case 2:
                limpa();
                fflush(stdin);
                login(biblioteca);
                limpa();
        break; 

    }
    
}while(escolha!=2 && biblioteca.i<1);
}

void limpa()
{
    fflush(stdin);
    system("cls || clear");
}

void CadastroLivro(struct Gestaobiblioteca biblioteca){
    //setlocale(LC_ALL, "portuguese");

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

void menu2()
{
    printf("\n---------------------------------------\n");
    printf("\tEmprestimos De Livros");
    printf("\n\nLivros Disponiveis: \n");
    printf("\n1- Iracema");
    printf("\n---------------------------------------\n");
}

void emprestimo()
{
    //setlocale(LC_ALL, "portuguese");

    int escolha;

    menu2();
    printf("Digite o numero do livro que deseja: ");
    scanf("%d", &escolha);
    limpa();

    switch (escolha)
    {
    case 1:
        printf("Livro escolhido: Iracema\n");
        printf("Prazo de devolção: 14 Dias");
        break;
    case 2:
        printf("Livro escolhido: Dom Casmurro\n");
        printf("Prazo de devolção: 14 Dias");
        break;

    default:
        printf("Opção Invalida!");
        break;
    }

    
}

void opcoes()
{
    printf("\n------------------------------------\n");
    printf("\tEscolha Opçao desejada");
    printf("\n1- Cadastro de Livros\n");
    printf("2- Emprestimo de livro\n");
    printf("3- para ver prazo de entrega do livro\n");
    printf("4- deslogar e sair");
    printf("\n------------------------------------\n");
}

void prazo(struct Gestaobiblioteca biblioteca){
    printf("Nome do Livro:Iracema");
    printf("Prazo de entrega:%d",7);
}

int main(){
    setlocale(LC_ALL, "portuguese");
    int escolha;
    struct Gestaobiblioteca biblioteca;
    loginECadastro(biblioteca);
    
    do{

    opcoes();
    printf("Escolha:");
    scanf("%d",&escolha);

    switch(escolha){

        case 1:
        fflush(stdin);
        CadastroLivro(biblioteca);
        break;

        case 2:
        fflush(stdin);
        emprestimo();
        break;

        case 3:
        prazo(biblioteca);

        break;

        case 4:
        
        break;

        default:
        printf("Escolha Invalida");
        break;
    }

    }while(escolha!=4);
    printf("Obrigado e Volte Sempre");
    return 0;
}

