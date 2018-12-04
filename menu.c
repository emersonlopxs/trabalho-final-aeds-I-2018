#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>

#include "livro.h"

// 8/10
// nao precisa ficar escovando bits vlws flws


int menu(){
    //caixa(20,2,100,25);
    //caixa do menu
    TextColor(9);
    caixa(20, 3, 120, 7);
    // this will return an option that you can use
    //char opcoes[4][15]={"Criar", "Alterar", "Apagar", "Sair"};

    char opcoes[6][15] = {"Cadastrar", "Alterar", "Excluir", "Pesquisar", "Listar", "Relatorio"};

    int cols[6] = {30, 45, 60, 75, 90, 105};
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
    TextColor(9);
    int co[4] = {20, 7, 120, 31};
    caixa(co[0], co[1], co[2], co[3]);
//    caixa(9,2,90,28);
    TextColor(14);
    // caixa do titulo

    //caixa(co[0] + 9, co[1] + 1, co[2] - 10, co[3] - 20);
   // caixa(18,3,80,5);


    TextColor(15);


                gotoxy(40,10);
                printf("Codigo: ");

                caixa(48,9,110,11);

                gotoxy(40,13);
                printf("Titulo: ");

               // printf("%s\n", A.titulo);
                caixa(48,12,110,14);

                gotoxy(29,16);
                printf("Numero de Paginas: ");

              //  printf("%s\n", A.numerodepaginas);
                caixa(48,15,110,17);

                gotoxy(29,19);
                printf("Ano de lancamento: ");

               // printf("%s\n", A.anodelancamento);
                caixa(48,18,110,20);

                gotoxy(27,22);
                printf("Numero de capitulos: ");

               // printf("%s\n", A.numerodecapitulos);
                caixa(48,21,110,23);

                gotoxy(39,25);
                printf("Editora: ");

               //printf("%s\n", A.editora);
                caixa(48,24,110,26);

                gotoxy(38,28);
                printf("Autor(a): ");

               // printf("%s\n", A.autor);
                caixa(48,27,110,29);

    /*

    gotoxy(65,5); printf("Cadastar Novo Livro");
    TextColor(15);

    gotoxy(35,8);printf("Codigo:");
    caixa(43,7,110,9);

    gotoxy(35,11);printf("Titulo:");
    caixa(43,10,110,12);

    gotoxy(35,14);printf("Autor:");
    caixa(43,13,110,15);

    gotoxy(35,17);printf("Numero de paginas:");
    caixa(54,16,110,18);

    gotoxy(35,20);printf("Ano de Lancamento:");
    caixa(54,19,110,21);

    gotoxy(35,23);printf("Total de capitulos:");
    caixa(54,22,110,24);

    gotoxy(35,26);printf("Editora:");
    caixa(43,25,110,27);

    */



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
                excluirArquivo("Digite o titulo do livro que voce quer excluir: ", "VOCE TEM CERTEZA QUE QUER EXCLUIR ESSE LIVRO? 0-NAO 1-SIM ");
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
