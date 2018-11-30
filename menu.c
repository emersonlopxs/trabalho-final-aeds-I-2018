#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>


#include "livro.h"


int menu(){
    //caixa(20,2,100,25);
    //caixa do menu
    TextColor(14);
    caixa(27, 3, 84, 7);
    // this will return an option that you can use
    //char opcoes[4][15]={"Criar", "Alterar", "Apagar", "Sair"};

    char opcoes[6][15] = {"Cadastrar", "Alterar", "Excluir", "Pesquisar", "Listar", "Relatorio"};

    int cols[6] = {30, 40, 48, 56, 66, 73};
    int opcao = 0, i, tecla;
    TextColor(15);
    for(i=0;i<6;i++)
    {
        gotoxy(cols[i], 5);
        printf("%-8s", opcoes[i]);
    }
    while(1){
        TextColor(BACKGROUND_INTENSITY);
        gotoxy(cols[opcao], 5);
        printf("%-8s", opcoes[opcao]);
        tecla = getch();
        if (tecla == 27) break;
        TextColor(7);
        gotoxy(cols[opcao],5);
        printf("%-8s", opcoes[opcao]);
        if (tecla == 77) opcao++;
        if (tecla == 75) opcao--;
        if (tecla == 13) {
            // printf("%i", opcao);
            return opcao;
        }

        if (opcao < 0) opcao = 5;
        if (opcao > 5) opcao = 0;
    }

}

void mostrarTelaCadastro(){
  TextColor(14);
    caixa(9,2,90,28);
    TextColor(14);
    // caixa do titulo
    caixa(18,3,80,5);


    TextColor(15);


    gotoxy(39,4);printf("Cadastar Novo Livro");
    TextColor(15);

    gotoxy(25,8);printf("Codigo:");
    caixa(33,7,75,9);

    gotoxy(25,11);printf("Titulo:");
    caixa(33,10,75,12);

    gotoxy(25,14);printf("Autor:");
    caixa(33,13,75,15);

    gotoxy(25,17);printf("Numero de paginas:");
    caixa(44,16,75,18);

    gotoxy(25,20);printf("Ano de Lancamento:");
    caixa(44,19,75,21);

    gotoxy(25,23);printf("Total de capitulos:");
    caixa(44,22,75,24);

     gotoxy(25,26);printf("Editora:");
    caixa(33,25,75,27);



}

int handleMenuOptions()
{
    int opcao = menu();

      while(opcao != 8) {

        switch(opcao) {

            case 0:

                salvarArquivo();
                break;
            case 1:
                alterarArquivo("Digite o titulo do livro que voce quer alterar: ", "voce quer alterar esse livro? 0 - nao 1 - sim ");
                break;
            case 2:
                excluirArquivo("Digite o titulo do livro que voce quer excluir: ", "voce quer excluir esse livro? 0 - nao 1 - sim ");
                break;
            case 3:

                pesquisarArquivo("Digite o titulo do livro que voce quer encontrar: ");
                break;
            case 4:

                listarAquivo();
                break;
            case 5:

                criarRelatorio();
                break;
        }

            /*

        if(opcao == 0)
        {
            salvarArquivo();
        }

        //char opcoes[6][15] = {"Cadastro", "Alteracao", "Exclusao", "Pesquisa", "Listagem", "Relatorio"};

        else if(opcao == 1)
        {
            alterarArquivo();
        }
        else if(opcao)
        else if(opcao == 4 )
        {
//            system("cls");
//            printf("handle\n");
            imprimirAquivos();
        }
        */

        opcao = menu();


    }
    /*
     if(menu() == 0)
    {
        livro A;
        MostrarTela();
        // pegar um novo livro
        //A = novoLivro();
        salvarArquivo(A);

        system("cls");

//        menu();

        return 0;
    }
    if(menu() == 5)
    {
        system("cls");
        printf("hello");
        imprimirAquivos();
//        menu();
        return 0;
    }

    printf("nothing");

    return 1;
    */
}
