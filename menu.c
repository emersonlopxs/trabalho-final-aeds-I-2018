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
    TextColor(14);


    TextColor(15);


                gotoxy(40,10);
                printf("Codigo: ");

                caixa(48,9,110,11);

                gotoxy(40,13);
                printf("Titulo: ");

                caixa(48,12,110,14);

                gotoxy(29,16);
                printf("Numero de Paginas: ");

                caixa(48,15,110,17);

                gotoxy(29,19);
                printf("Ano de lancamento: ");

                caixa(48,18,110,20);

                gotoxy(27,22);
                printf("Numero de capitulos: ");

                caixa(48,21,110,23);

                gotoxy(39,25);
                printf("Editora: ");

                caixa(48,24,110,26);

                gotoxy(38,28);
                printf("Autor(a): ");

                caixa(48,27,110,29);

}

int handleMenuOptions()
{
    int opcao = menu();

      while(opcao != 8) {
            system("cls");

        switch(opcao) {

            case 0:

                salvarArquivo();
                break;
            case 1:
                alterarArquivo("Digite o codigo do livro: ", "VOCE QUER ALTERAR ESSE LIVRO? 0 - nao 1 - sim ");
                break;
            case 2:
                excluirArquivo("Digite o codigo do livro: ", "VOCE TEM CERTEZA QUE QUER EXCLUIR ESSE LIVRO? 0-NAO 1-SIM ");
                break;
            case 3:

                pesquisarArquivo("Digite o codigo do livro: ");
                break;
            case 4:

                listarAquivo();
                break;
            case 5:

                criarRelatorio();
                break;
        }

        opcao = menu();


    }
}
