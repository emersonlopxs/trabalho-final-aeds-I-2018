#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <conio.h>

#include "livro.h"

FILE *fp;

void fecharArquivo()
{
    fclose(fp);
}

void abrirAquivo()
{
    fp = fopen("livro.txt", "rb+");

        /// quando cadastro apos abrir ele sobrescreve
//        livro A;
//        strcpy(A.autor, "xxx");
//        strcpy(A.titulo, "xxx");
//        strcpy(A.codigo, "xxx");
//
//        fwrite(&A, sizeof(livro), 1, fp);


    if (fp == NULL)
    {

        fp = fopen("livro.txt", "wb+");

//        livro A;
//        strcpy(A.autor, "xxx");
//        strcpy(A.titulo, "xxx");
//        strcpy(A.codigo, "xxx");
//
//        fwrite(&A, sizeof(livro), 1, fp);

        if (fp == NULL)
        {
            printf("Erro ao criar arquivo\n");
            exit(1);
        }

    }
}

void salvarArquivo()
{
    livro A;
    system("cls");
    mostrarTelaCadastro();
    A = novoLivro();

    // salvar no final do arquivo
    fseek(fp,0,SEEK_END);

    fwrite(&A, sizeof(livro), 1, fp);

    system("cls");

    gotoxy(30, 20, 20, 20);
    printf("arquivo salvo\n");
}

void listarAquivo()
{
    system("cls");

    livro A;

    fseek(fp,0,SEEK_SET);

    int a = fread(&A, sizeof(livro), 1, fp);
    int b = sizeof(livro);
    printf("a: %i\nb: %i\n", a, b);

    int xy[4] = {30, 10, 20, 12};
    int c[4] = {20, 9, 100, 15};



    printf("%i", feof(fp));

    while(fread(&A, sizeof(livro), 1, fp))
    {
        caixa(c[0],c[1],c[2],c[3]);
        gotoxy(xy[0], xy[1], xy[2], xy[3]);
        printf("Codigo: %s \n", A.codigo);
        gotoxy(xy[0], xy[1] + 2, xy[2], xy[3]);
        //gotoxy(30, 22, 20, 20);
        printf("Titulo: %s \n", A.titulo);
        gotoxy(xy[0], xy[1] + 4, xy[2], xy[3]);
        //gotoxy(30, 24, 20, 20);
        printf("Autor: %s \n", A.autor);

        xy[1] += 8;
        c[1] += 8;
        c[3] += 8;

    }
}


void alterarArquivo()
{
    system("cls");
    gotoxy(30, 20, 20, 20);
    printf("alterar");
}

void excluirArquivo(char str[])
{
    int xy[4] = {30, 14, 20, 16};
    int c[4] = {20, 13, 100, 19};
    int op;

    char pesquisa[100];
    livro A;
    system("cls");
    caixa(c[0],c[1],c[2],c[3]);
    //caixa();
    gotoxy(xy[0], xy[1], xy[2], xy[3]);
    printf("%s", str);
    scanf("%s", pesquisa);

    system("cls");

    fseek(fp,0,SEEK_SET);
    while (!feof(fp))
    {
        if (fread(&A, sizeof(livro), 1, fp))
        {
            if (strcmp(A.titulo, pesquisa) == 0)
            {

                caixa(c[0],c[1],c[2],c[3]);



                gotoxy(xy[0], xy[1], xy[2], xy[3]);
                printf("Titulo: %s\n", A.titulo);
                gotoxy(xy[0], xy[1] + 2, xy[2], xy[3]);
                printf("Autor: %s\n", A.autor);
                gotoxy(xy[0], xy[1] + 4, xy[2], xy[3]);
                printf("Codigo %s\n", A.codigo);

                gotoxy(xy[0], xy[1] - 2, xy[2], xy[3]);
                printf("voce quer excluir esse livro? 0-nao 1-sim ");

                scanf("%i", &op);

                if(op)
                {

                }







                break;
            }

        }
    }
     if (strcmp(A.titulo, pesquisa) != 0)
            {
                caixa(c[0],c[1],c[2],c[3]);
                gotoxy(xy[0], xy[1], xy[2], xy[3]);
                printf("Livro nao encontrado\n");

            }

}

void pesquisarArquivo(char str[])
{
    int xy[4] = {30, 10, 20, 12};
    int c[4] = {20, 9, 100, 15};

    char pesquisa[100];
    livro A;
    system("cls");
    caixa(c[0],c[1],c[2],c[3]);
    //caixa();
    gotoxy(xy[0], xy[1], xy[2], xy[3]);
    printf("%s", str);
    scanf("%s", pesquisa);

    system("cls");

    fseek(fp,0,SEEK_SET);
    while (!feof(fp))
    {
        if (fread(&A, sizeof(livro), 1, fp))
        {
            if (strcmp(A.titulo, pesquisa) == 0)
            {
                caixa(c[0],c[1],c[2],c[3]);
                gotoxy(xy[0], xy[1], xy[2], xy[3]);
                printf("Titulo: %s\n", A.titulo);
                gotoxy(xy[0], xy[1] + 2, xy[2], xy[3]);
                printf("Autor: %s\n", A.autor);
                gotoxy(xy[0], xy[1] + 4, xy[2], xy[3]);
                printf("Codigo %s\n", A.codigo);

                break;
            }

        }
    }
     if (strcmp(A.titulo, pesquisa) != 0)
            {
                caixa(c[0],c[1],c[2],c[3]);
                gotoxy(xy[0], xy[1], xy[2], xy[3]);
                printf("Livro nao encontrado\n");

            }

}

void criarRelatorio()
{
    system("cls");
    gotoxy(30, 20, 20, 20);
    printf("criar relatorio");
}

















