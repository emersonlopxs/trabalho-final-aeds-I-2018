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

    if (fp == NULL)
    {

        fp = fopen("livro.txt", "wb+");
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

    int xy[4] = {30, 10, 20, 12};
    int c[4] = {20, 9, 100, 15};
    while(fread(&A, sizeof(livro), 1, fp))
    {

        if(!strcmp(A.titulo, "0") == 0)
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
}


void alterarArquivo(char str[], char str2[])
{
    int xy[4] = {30, 14, 20, 16};
    int c[4] = {20, 13, 100, 19};
    int op;
    int contador = 0;

    char pesquisa[100];
    livro A;
    system("cls");
    caixa(c[0],c[1],c[2],c[3]);
    //caixa();
    gotoxy(xy[0], xy[1], xy[2], xy[3]);
    printf("%s", str);

    scanf("%s", pesquisa);
//    fgets(pesquisa, sizeof(pesquisa), stdin);
//    fflush(stdin);

    system("cls");

    fseek(fp,0,SEEK_SET);
    while (!feof(fp))
    {
        if (fread(&A, sizeof(livro), 1, fp))
        {
            printf("%i\n",strcmp(A.titulo, pesquisa));
            printf("titulo %s\n",A.titulo);
            printf("pesquisa %s\n",pesquisa);

            if (strcmp(A.titulo, pesquisa) == 0)
            {
                //system("cls");
                contador++;
                caixa(c[0],c[1],c[2],c[3]);
                gotoxy(xy[0], xy[1], xy[2], xy[3]);
                printf("Titulo: %s\n", A.titulo);
                gotoxy(xy[0], xy[1] + 2, xy[2], xy[3]);
                printf("Autor: %s\n", A.autor);
                gotoxy(xy[0], xy[1] + 4, xy[2], xy[3]);
                printf("Codigo %s\n", A.codigo);

                gotoxy(xy[0], xy[1] - 2, xy[2], xy[3]);
                printf(str2);

                scanf("%i", &op);
//                fgets(op, sizeof(op), stdin);
//                fflush(stdin);


                if(op)
                {
                    livro A;
                    system("cls");
                    mostrarTelaCadastro();
                    A = novoLivro();
                    fseek(fp, -sizeof(livro), SEEK_CUR);
                    fwrite(&A, sizeof(livro), 1, fp);
                    system("cls");
                    gotoxy(30, 20, 20, 20);
                    printf("arquivo alterado!\n");

                }


                break;
            }
        }




    }

    /*
    if (strcmp(A.titulo, pesquisa) != 0)
        {
            caixa(c[0],c[1],c[2],c[3]);
            gotoxy(xy[0], xy[1], xy[2], xy[3]);
            printf("Livro nao encontrado\n");

        }
        */
    if(!contador)
    {
        caixa(c[0],c[1],c[2],c[3]);
        gotoxy(xy[0], xy[1], xy[2], xy[3]);
        printf("Livro nao encontrado\n");
    }

    gotoxy(xy[0], xy[1] + 3, xy[2], xy[3]);
    printf("Titulo: %s\n", A.titulo);
    gotoxy(xy[0], xy[1], xy[2], xy[3]);
    printf("%i", strcmp(A.titulo, pesquisa));
}

void excluirArquivo(char str[], char str2[])
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
//    fgets(pesquisa, sizeof(pesquisa), stdin);
//    fflush(stdin);

    system("cls");

    fseek(fp,0,SEEK_SET);
    while (!feof(fp))
    {
        if (fread(&A, sizeof(livro), 1, fp))
        {
            if (strcmp(A.titulo, pesquisa) == 0)
            {

                system("cls");

                caixa(c[0],c[1],c[2],c[3]);



                gotoxy(xy[0], xy[1], xy[2], xy[3]);
                printf("Titulo: %s\n", A.titulo);
                gotoxy(xy[0], xy[1] + 2, xy[2], xy[3]);
                printf("Autor: %s\n", A.autor);
                gotoxy(xy[0], xy[1] + 4, xy[2], xy[3]);
                printf("Codigo %s\n", A.codigo);

                gotoxy(xy[0], xy[1] - 2, xy[2], xy[3]);
                printf(str2);

                scanf("%i", &op);

                if(op)
                {
                    livro A;
                    system("cls");
                    strcpy(A.autor, "0");
                    strcpy(A.codigo, "0");
                    strcpy(A.titulo, "0");

//                    A = (const livro)
//                    {
//                        0
//                    };

                    fseek(fp, -sizeof(livro), SEEK_CUR);

                    fwrite(&A, sizeof(livro), 1, fp);

                    system("cls");

                    gotoxy(30, 20, 20, 20);
                    printf("arquivo apagado!\n");
                }

                system("cls");


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
//    fgets(pesquisa, sizeof(pesquisa), stdin);
//    fflush(stdin);

    system("cls");

    fseek(fp,0,SEEK_SET);
    while (!feof(fp))
    {
        if (fread(&A, sizeof(livro), 1, fp))
        {
            if (strcmp(A.titulo, pesquisa) == 0)
            {
                system("cls");
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

    livro A;
    fseek(fp,0,SEEK_SET);

    FILE *r;

    char arquivo[100];

    caixa(34, 9, 90, 13);
    gotoxy(36, 11);
    printf("Digite o nome to documento: ");
    gotoxy(64, 11);
    scanf("%s", arquivo);
//    fgets(arquivo, sizeof(arquivo), stdin);
//    fflush(stdin);
    strcat(arquivo, ".txt");

    r = fopen(arquivo, "w");

    char codigo[100];
    char titulo[100];
    char autor[100];


    while(fread(&A, sizeof(livro), 1, fp))
    {

        if(!strcmp(A.titulo, "0") == 0)
        {

            strcpy(codigo, A.codigo);
            strcpy(titulo, A.titulo);
            strcpy(autor, A.autor);

            fprintf(r, "Codigo: %s\n", codigo);
            fprintf(r, "Autor: %s\n", autor);
            fprintf(r, "Titulo: %s\n", titulo);
            fprintf(r, "\n\n");
        }
    }

    fclose(r);

    system("cls");
    gotoxy(30, 20, 20, 20);
    printf("Arquivo %s criado!", arquivo);
}

















