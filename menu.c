#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>

#include "livro.h"


int menu(){
    //caixa(20,2,100,25);
    //caixa do menu
    caixa(20, 2, 100, 8);
    // this will return an option that you can use
    //char opcoes[4][15]={"Criar", "Alterar", "Apagar", "Sair"};

    char opcoes[6][15] = {"Cadastro", "Alteracao", "Exclusao", "Pesquisa", "Listagem", "Relatorio"};

    int cols[6] = {30, 40, 50, 60, 70, 80};
    int opcao = 0, i, tecla;
    TextColor(7);
    for(i=0;i<6;i++)
    {
        gotoxy(cols[i], 5);
        printf("%-8s", opcoes[i]);
    }
    while(1){
        TextColor(BACKGROUND_GREEN);
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
    // caixa principal
    // caixa(5,2,70,20);
    caixa(20,2,100,25);
    // caixa do titulo
    caixa(30,3,90,5);

    TextColor(BACKGROUND_GREEN);

    gotoxy(50,4);printf("Cadastar Novo Livro");
    TextColor(7);

    gotoxy(25,8);printf("Codigo:");
    caixa(35,7,55,9);

    gotoxy(25,11);printf("Titulo:");
    caixa(35,10,75,12);

    gotoxy(25,14);printf("Autor:");
    caixa(35,13,75,15);
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
                alterarArquivo("Digite o titulo do livro que voce quer alterar: ", "voce quer alterar esse livro? 0-nao 1-sim ");
                break;
            case 2:
                excluirArquivo("Digite o titulo do livro que voce quer excluir: ", "voce quer excluir esse livro? 0-nao 1-sim ");
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
