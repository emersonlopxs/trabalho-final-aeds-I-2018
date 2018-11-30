
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
    TextColor(BACKGROUND_INTENSITY);
    printf("arquivo salvo\n");
}

void listarAquivo()
{
    system("cls");
    livro A;
    fseek(fp,0,SEEK_SET);

    int xy[6] = {30, 10, 20, 100};
    int f[4] = {27, 11, 84, 25};

    while(fread(&A, sizeof(livro), 1, fp))
    {

        if(!strcmp(A.titulo, "0") == 0)
        {
            TextColor(14);
            caixa(f[0],f[1],f[2],f[3]);
            TextColor(15);
            gotoxy(xy[0], xy[1] + 2, xy[2], xy[3], xy[4], xy[5], xy[6]);
            printf("Codigo: %s \n", A.codigo);
            gotoxy(xy[0], xy[1] + 4, xy[2], xy[3], xy[4], xy[5], xy[6]);
            //gotoxy(30, 22, 20, 20);
            printf("Titulo: %s \n", A.titulo);
            gotoxy(xy[0], xy[1] + 6, xy[2], xy[3], xy[4], xy[5], xy[6]);
            //gotoxy(30, 24, 20, 20);
            printf("Autor: %s \n", A.autor);
             gotoxy(xy[0], xy[1] + 8, xy[2], xy[3], xy[4], xy[5], xy[6]);
            //gotoxy(30, 24, 20, 20);
            printf("Editora: %s \n", A.editora);
             gotoxy(xy[0], xy[1] + 10, xy[2], xy[3], xy[4], xy[5], xy[6]);
            //gotoxy(30, 24, 20, 20);
            printf("Ano de lancamento: %s \n", A.anodelancamento);
             gotoxy(xy[0], xy[1] + 12, xy[2], xy[3], xy[4], xy[5], xy[6]);
            //gotoxy(30, 24, 20, 20);
            printf("Numero de capitulos: %s \n", A.numerodecapitulos);
             gotoxy(xy[0], xy[1] + 14, xy[2], xy[3], xy[4], xy[5], xy[6]);
            //gotoxy(30, 24, 20, 20);
            printf("Numero de paginas: %s \n", A.numerodepaginas);

           xy[1] += 14;
           // f[1] += 14;
            f[3] += 14;
        }


    }
}


void alterarArquivo(char str[], char str2[])
{
    int xy[4] = {30, 14, 20, 16};
    TextColor(14);
    int c[4] = {27, 12, 84, 17};
    int f[4] = {27, 9, 84, 28};
    int g[4] = {27, 12, 84, 23};
    int op;
    int contador = 0;
    char pesquisa[100];
    livro A;
    system("cls");
    caixa(c[0],c[1],c[2],c[3]);
    //caixa();
    TextColor(15);
    gotoxy(xy[0], xy[1], xy[2], xy[3], xy[4], xy[5], xy[6]);
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
            TextColor(15);
            printf("%i\n",strcmp(A.titulo, pesquisa));
            printf("titulo %s\n",A.titulo);
            printf("pesquisa %s\n",pesquisa);

            if (strcmp(A.titulo, pesquisa) == 0)
            {
                TextColor(14);
                //system("cls");
                contador++;

                caixa(f[0],f[1],f[2],f[3]);
                gotoxy(xy[0], xy[1], xy[2], xy[3], xy[4], xy[5], xy[6]);
                TextColor(15);
                printf("Titulo: %s\n", A.titulo);
                gotoxy(xy[0], xy[1] + 2, xy[2], xy[3], xy[4], xy[5], xy[6]);
                printf("Autor: %s\n", A.autor);
                gotoxy(xy[0], xy[1] + 4, xy[2], xy[3], xy[4], xy[5], xy[6]);
                printf("Codigo: %s\n", A.codigo);
                gotoxy(xy[0], xy[1] + 6, xy[2], xy[3], xy[4], xy[5], xy[6]);
                printf("Ano de lancamento: %s\n", A.anodelancamento);
                gotoxy(xy[0], xy[1] + 8, xy[2], xy[3], xy[4], xy[5], xy[6]);
                printf("Editora: %s\n", A.editora);
                gotoxy(xy[0], xy[1] + 10, xy[2], xy[3], xy[4], xy[5], xy[6]);
                printf("Numero de capitulos: %s\n", A.numerodecapitulos);
                gotoxy(xy[0], xy[1] + 12, xy[2], xy[3], xy[4], xy[5], xy[6]);
                printf("Numero de paginas: %s\n", A.numerodepaginas);

                gotoxy(xy[0], xy[1] - 2, xy[2], xy[3], xy[4], xy[5], xy[6]);
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
                    TextColor(14);
                    caixa(g[0], g[1], g[2], g[3]);
                    gotoxy(30, 20, 20, 20);
                    TextColor(15);
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
        TextColor(14);
        caixa(f[0],f[1],f[2],f[3]);
        TextColor(15);
        gotoxy(xy[0], xy[1], xy[2], xy[3], xy[4], xy[5], xy[6]);
        printf("Livro nao encontrado\n");
    }

    gotoxy(xy[0], xy[1] + 3, xy[2], xy[3], xy[4], xy[5], xy[6]);
    printf("Titulo: %s\n", A.titulo);
    gotoxy(xy[0], xy[1], xy[2], xy[3], xy[4], xy[5], xy[6]);
    printf("%i", strcmp(A.titulo, pesquisa));
}

void excluirArquivo(char str[], char str2[])
{
    int xy[6] = {30, 14, 20, 16};
    TextColor(14);
    int f[4] = {27, 10, 84, 27};
    int c[4] = {27, 12, 84, 17};
    int g[4] = {27, 12, 84, 17};
    int op;

    char pesquisa[100];
    livro A;
    TextColor(14);
    system("cls");
    caixa(c[0],c[1],c[2],c[3],c[4],c[5],c[6]);
    //caixa();
    gotoxy(xy[0], xy[1], xy[2], xy[3], xy[4], xy[5], xy[6]);
    TextColor(15);
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
                TextColor(14);

                caixa(f[0],f[1],f[2],f[3]);


                TextColor(15);
                gotoxy(xy[0], xy[1], xy[2], xy[3], xy[4], xy[5], xy[6]);
                printf("Titulo: %s\n", A.titulo);
                gotoxy(xy[0], xy[1] + 2, xy[2], xy[3], xy[4], xy[5], xy[6]);
                printf("Autor: %s\n", A.autor);
                gotoxy(xy[0], xy[1] + 4, xy[2], xy[3], xy[4], xy[5], xy[6]);
                printf("Codigo: %s\n", A.codigo);
                gotoxy(xy[0], xy[1] + 6, xy[2], xy[3], xy[4], xy[5], xy[6]);
                printf("Editora: %s\n", A.editora);
                gotoxy(xy[0], xy[1] + 8, xy[2], xy[3], xy[4], xy[5], xy[6]);
                printf("Ano de lancamento: %s\n", A.anodelancamento);
                gotoxy(xy[0], xy[1] + 10, xy[2], xy[3], xy[4], xy[5], xy[6]);
                printf("Numero total de paginas: %s\n", A.numerodecapitulos);
                gotoxy(xy[0], xy[1] + 12, xy[2], xy[3], xy[4], xy[5], xy[6]);
                printf("Numero total de capitulos: %s\n", A.numerodepaginas);

                gotoxy(xy[0], xy[1] - 2, xy[2], xy[3], xy[4], xy[5], xy[6]);
                printf(str2);

                scanf("%i", &op);

                if(op)
                {
                    livro A;
                    system("cls");
                    strcpy(A.autor, "0");
                    strcpy(A.codigo, "0");
                    strcpy(A.titulo, "0");
                    strcpy(A.editora, "0");
                    strcpy(A.anodelancamento, "0");
                    strcpy(A.numerodecapitulos, "0");
                    strcpy(A.numerodepaginas, "0");



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
//
        }
    }
    if (strcmp(A.titulo, pesquisa) != 0)
    {
        TextColor(14);
        caixa(g[0],g[1],g[2],g[3]);
        TextColor(15);
        gotoxy(xy[0], xy[1], xy[2], xy[3], xy[4], xy[5], xy[6]);
        printf("Livro nao encontrado\n");

    }

}

void pesquisarArquivo(char str[])
{
    int xy[6] = {30, 10, 20, 12};
    int c[4] = {27, 7, 84, 13};
    int f[4] = {27, 9, 84, 25};
    int g[4] = {27, 9, 84, 13};


    char pesquisa[100];
    livro A;

    system("cls");
    TextColor(14);
    caixa(c[0],c[1],c[2],c[3]);
    //caixa();
    gotoxy(xy[0], xy[1], xy[2], xy[3], xy[4], xy[5], xy[6]);
    TextColor(15);
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
                TextColor(14);
                system("cls");
                caixa(f[0],f[1],f[2],f[3]);
                TextColor(15);
                gotoxy(xy[0], xy[1], xy[2], xy[3], xy[4], xy[5], xy[6]);
                printf("Titulo: %s\n", A.titulo);
                gotoxy(xy[0], xy[1] + 2, xy[2], xy[3], xy[4], xy[5], xy[6]);
                printf("Autor: %s\n", A.autor);
                gotoxy(xy[0], xy[1] + 4, xy[2], xy[3], xy[4], xy[5], xy[6]);
                printf("Codigo: %s\n", A.codigo);
                gotoxy(xy[0], xy[1] + 6, xy[2], xy[3], xy[4], xy[5], xy[6]);
                printf("Editora: %s\n", A.editora);
                gotoxy(xy[0], xy[1] + 8, xy[2], xy[3], xy[4], xy[5], xy[6]);
                printf("Ano de lancamento: %s\n", A.anodelancamento);
                gotoxy(xy[0], xy[1] + 10, xy[2], xy[3], xy[4], xy[5], xy[6]);
                printf("Numero total de capitulos: %s\n", A.numerodecapitulos);
                gotoxy(xy[0], xy[1] + 12, xy[2], xy[3], xy[4], xy[5], xy[6]);
                printf("Numero total de paginas: %s\n", A.numerodepaginas);

                break;
            }

        }
    }

    if (strcmp(A.titulo, pesquisa) != 0)
    {
        TextColor(14);
        caixa(g[0],g[1],g[2],g[3]);
        TextColor(15);
        gotoxy(xy[0], xy[1], xy[2], xy[3], xy[4], xy[5]);
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
    TextColor(14);
    caixa(27, 9, 90, 13);
    gotoxy(36, 11);
    TextColor(15);
    printf("Digite o nome do documento: ");
    gotoxy(64, 11);
    scanf("%s", arquivo);
//    fgets(arquivo, sizeof(arquivo), stdin);
//    fflush(stdin);
    strcat(arquivo, ".txt");

    r = fopen(arquivo, "w");

    char codigo[100];
    char titulo[100];
    char autor[100];
    char anodeLancamento[100];
    char editora[100];
    char numeroDeCapitulos[100];
    char numerodepaginas[100];


    while(fread(&A, sizeof(livro), 1, fp))
    {

        if(!strcmp(A.titulo, "0") == 0)
        {

            strcpy(codigo, A.codigo);
            strcpy(titulo, A.titulo);
            strcpy(autor, A.autor);
            strcpy(editora, A.editora);
            strcpy(anodeLancamento, A.anodelancamento);
            strcpy(numeroDeCapitulos, A.numerodecapitulos);
            strcpy(numerodepaginas, A.numerodepaginas);

            fprintf(r, "Codigo: %s\n", codigo);
            fprintf(r, "Autor: %s\n", autor);
            fprintf(r, "Titulo: %s\n", titulo);
            fprintf(r, "Autor: %s\n", autor);
            fprintf(r, "Ano de lancamento: %s\n",anodeLancamento);
            fprintf(r, "Numero de capitulos: %s\n", numeroDeCapitulos);
            fprintf(r, "Numero total de paginas: %s\n", numerodepaginas);
            fprintf(r, "\n\n");
        }
    }

    fclose(r);

    system("cls");
    gotoxy(30, 20, 20, 20);
    printf("Arquivo %s criado!", arquivo);
}

