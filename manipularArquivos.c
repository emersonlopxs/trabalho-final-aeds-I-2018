
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <conio.h>

#include "livro.h"

FILE *fp;


// abrindo e fechando o arquivo apenas uma vez
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
void fecharArquivo()
{
    fclose(fp);
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
    TextColor(10);

    int co[4] = {20, 9, 120, 13};

    caixa(co[0], co[1], co[2], co[3]);
    gotoxy(30,11);
    printf("arquivo salvo!\n");

}

void listarAquivo()
{
    system("cls");
    livro A;
    fseek(fp,0,SEEK_SET);
    int co[4] = {20, 3, 120, 26};
    int contador = 0;

    int y = 12;
    int coord[4] = {20, 12, 120, 35};


    while(fread(&A, sizeof(livro), 1, fp))
    {

        if(!strcmp(A.codigo, "0") == 0)
        {
            TextColor(5);
            caixa(coord[0], coord[1], coord[2], coord[3]);
            contador++;

            TextColor(15);

            gotoxy(40,y + 3);
            printf("Codigo: ");
            gotoxy(50,y + 3);
            printf("%s\n", A.codigo);
            caixa(48,y + 2,110, y + 4);

            gotoxy(40,y + 6);
            printf("Titulo: ");
            gotoxy(50, y + 6);
            printf("%s\n", A.titulo);
            caixa(48,y + 5,110, y + 7);

            gotoxy(29, y + 9);
            printf("Numero de Paginas: ");
            gotoxy(50, y + 9);
            printf("%s\n", A.numerodepaginas);
            caixa(48,y + 8,110, y + 10);

            gotoxy(29,y + 12);
            printf("Ano de lancamento: ");
            gotoxy(50,y + 12);
            printf("%s\n", A.anodelancamento);
            caixa(48,y + 11,110, y + 13);

            gotoxy(27, y + 15);
            printf("Numero de capitulos: ");
            gotoxy(50, y + 15);
            printf("%s\n", A.numerodecapitulos);
            caixa(48, y + 14,110, y + 16);

            gotoxy(39,y + 18);
            printf("Editora: ");
            gotoxy(50,y + 18);
            printf("%s\n", A.editora);
            caixa(48,y + 17,110, y + 19);

            gotoxy(38,y + 21);
            printf("Autor(a): ");
            gotoxy(50, y + 21);
            printf("%s\n", A.autor);
            caixa(48, y + 20,110, y + 22);

            y += 27;
            coord[1] += 27;
            coord[3] += 27;
        }

        //if(!contador) fix this
        if(0)
        {
            system("cls");
            TextColor(4);
            caixa(co[0], co[1] + 5, co[2], co[3] - 14);
            gotoxy(30,10);
            printf("NAO HA LIVROS CADASTRADOS!\n");
            printf("hello\n");
        }
    }

    gotoxy(65,10);
    TextColor(BACKGROUND_BLUE);
    printf("%i LIVRO(S) ENCONTRADOS\n", contador);
}


void alterarArquivo(char str[], char str2[])
{
    TextColor(11);
    int co[4] = {20, 3, 120, 26};
    int contador = 0;
    int xy[2] = {30, 10};
    int op;
    char pesquisa[100];
    livro A;

    system("cls");
    gotoxy(65, 7);
    TextColor(BACKGROUND_BLUE);
    printf("ALTERAR LIVRO");
    int co2[4] = {20, 10, 120, 13};
    TextColor(15);
    caixa(co2[0], co[1] + 2, co[2], co[3] -13);
    gotoxy(30,10);
    printf("%s", str);
    caixa(55,9,110,11);
    gotoxy(56, 10);
    scanf("%s", pesquisa);
    system("cls");

    fseek(fp,0,SEEK_SET);
    while (!feof(fp))
    {
        if (fread(&A, sizeof(livro), 1, fp))
        {
            if (strcmp(A.codigo, pesquisa) == 0)
            {
                contador++;
                TextColor(1);
                system("cls");
                caixa(co[0], co[1], co[2], co[3] + 8);

                gotoxy(65,6);
                TextColor(BACKGROUND_BLUE);
                printf("ALTERAR LIVRO\n");
                TextColor(15);

                gotoxy(40,10);
                printf("Codigo: ");
                gotoxy(50,10);
                printf("%s\n", A.codigo);
                caixa(48,9,110,11);

                gotoxy(40,13);
                printf("Titulo: ");
                gotoxy(50,13);
                printf("%s\n", A.titulo);
                caixa(48,12,110,14);

                gotoxy(29,16);
                printf("Numero de Paginas: ");
                gotoxy(50,16);
                printf("%s\n", A.numerodepaginas);
                caixa(48,15,110,17);

                gotoxy(29,19);
                printf("Ano de lancamento: ");
                gotoxy(50,19);
                printf("%s\n", A.anodelancamento);
                caixa(48,18,110,20);

                gotoxy(27,22);
                printf("Numero de capitulos: ");
                gotoxy(50,22);
                printf("%s\n", A.numerodecapitulos);
                caixa(48,21,110,23);

                gotoxy(39,25);
                printf("Editora: ");
                gotoxy(50,25);
                printf("%s\n", A.editora);
                caixa(48,24,110,26);

                gotoxy(38,28);
                printf("Autor(a): ");
                gotoxy(50,28);
                printf("%s\n", A.autor);
                caixa(48,27,110,29);

                gotoxy(55,32);
                TextColor(11);
                printf(str2);

                scanf("%i", &op);

                if(op)
                {
                    livro A;
                    system("cls");
                    mostrarTelaCadastro();
                    A = novoLivro();
                    fseek(fp, -sizeof(livro), SEEK_CUR);
                    fwrite(&A, sizeof(livro), 1, fp);
                    system("cls");


                    system("cls");

                    TextColor(1);
                    caixa(co[0], co[1] + 5, co[2], co[3] - 14);
                    gotoxy(30,10);
                    printf("LIVRO ALTERADO!\n");
                }
                else
                {
                    system("cls");
                    TextColor(10);
                    caixa(co[0], co[1] + 5, co[2], co[3] - 14);
                    gotoxy(30,10);
                    printf("LIVRO NAO ALTERADO!\n");
                }
                break;
            }
        }
    }

    if(!contador)
    {
        int co2[4] = {20, 10, 120, 13};

        TextColor(4);
        caixa(co[0], co[1] + 5, co[2], co[3] - 14);
        gotoxy(30,10);
        printf("LIVRO NAO ENCONTRADO!\n");

    }
}

void excluirArquivo(char str[], char str2[])
{
    int co[4] = {20, 3, 120, 26};
    int xy[2] = {30, 10};
    int op;

    char pesquisa[100];
    livro A;

    system("cls");
    gotoxy(65, 7);
    TextColor(BACKGROUND_RED);
    printf("EXCLUIR LIVRO");
    int co2[4] = {20, 10, 120, 13};
    TextColor(15);
    caixa(co2[0], co[1] + 2, co[2], co[3] -13);
    gotoxy(30,10);
    printf("%s", str);
    caixa(55,9,110,11);
    gotoxy(56, 10);
    scanf("%s", pesquisa);
    system("cls");

    fseek(fp,0,SEEK_SET);
    while (!feof(fp))
    {
        if (fread(&A, sizeof(livro), 1, fp))
        {
            if (strcmp(A.codigo, pesquisa) == 0)
            {
                TextColor(4);
                system("cls");
                //caixa(f[0],f[1],f[2],f[3]);
                caixa(co[0], co[1], co[2], co[3] + 8);
                //TextColor(15);

                gotoxy(65,6);
                TextColor(BACKGROUND_RED);
                printf("EXCLUIR LIVRO\n");
                TextColor(15);

                gotoxy(40,10);
                printf("Codigo: ");
                gotoxy(50,10);
                printf("%s\n", A.codigo);
                caixa(48,9,110,11);

                gotoxy(40,13);
                printf("Titulo: ");
                gotoxy(50,13);
                printf("%s\n", A.titulo);
                caixa(48,12,110,14);

                gotoxy(29,16);
                printf("Numero de Paginas: ");
                gotoxy(50,16);
                printf("%s\n", A.numerodepaginas);
                caixa(48,15,110,17);

                gotoxy(29,19);
                printf("Ano de lancamento: ");
                gotoxy(50,19);
                printf("%s\n", A.anodelancamento);
                caixa(48,18,110,20);

                gotoxy(27,22);
                printf("Numero de capitulos: ");
                gotoxy(50,22);
                printf("%s\n", A.numerodecapitulos);
                caixa(48,21,110,23);

                gotoxy(39,25);
                printf("Editora: ");
                gotoxy(50,25);
                printf("%s\n", A.editora);
                caixa(48,24,110,26);

                gotoxy(38,28);
                printf("Autor(a): ");
                gotoxy(50,28);
                printf("%s\n", A.autor);
                caixa(48,27,110,29);

                gotoxy(48,32);
                TextColor(4);
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

                    fseek(fp, -sizeof(livro), SEEK_CUR);

                    fwrite(&A, sizeof(livro), 1, fp);

                    system("cls");

                    TextColor(4);
                    caixa(co[0], co[1] + 5, co[2], co[3] - 14);
                    gotoxy(30,10);
                    printf("LIVRO APAGADO!\n");
                }
                else
                {
                    system("cls");
                    TextColor(10);
                    caixa(co[0], co[1] + 5, co[2], co[3] - 14);
                    gotoxy(30,10);
                    printf("LIVRO NAO APAGADO!\n");
                }

                break;
            }

        }
    }

    if (strcmp(A.codigo, pesquisa) != 0)
    {
        int co2[4] = {20, 10, 120, 13};

        TextColor(4);
        caixa(co[0], co[1] + 5, co[2], co[3] - 14);
        gotoxy(30,10);
        printf("LIVRO NAO ENCONTRADO!\n");

    }
}

void pesquisarArquivo(char str[])
{
    int co[4] = {20, 3, 120, 26};
    int xy[2] = {30, 10};

    char pesquisa[100];
    livro A;

    system("cls");
    gotoxy(65, 7);
    TextColor(BACKGROUND_GREEN);
    printf("PESQUISAR LIVRO");
    int co2[4] = {20, 10, 120, 13};
    TextColor(15);
    caixa(co2[0], co[1] + 2, co[2], co[3] -13);
    gotoxy(30,10);
    printf("%s", str);
    caixa(55,9,110,11);
    gotoxy(56, 10);
    scanf("%s", pesquisa);
    system("cls");

    fseek(fp,0,SEEK_SET);
    while (!feof(fp))
    {
        if (fread(&A, sizeof(livro), 1, fp))
        {
            if (strcmp(A.codigo, pesquisa) == 0)
            {
                TextColor(10);
                system("cls");
                caixa(co[0], co[1] + 5, co[2], co[3] + 5);
                TextColor(15);

                gotoxy(40,10);
                printf("Codigo: ");
                gotoxy(50,10);
                printf("%s\n", A.codigo);
                caixa(48,9,110,11);

                gotoxy(40,13);
                printf("Titulo: ");
                gotoxy(50,13);
                printf("%s\n", A.titulo);
                caixa(48,12,110,14);

                gotoxy(29,16);
                printf("Numero de Paginas: ");
                gotoxy(50,16);
                printf("%s\n", A.numerodepaginas);
                caixa(48,15,110,17);

                gotoxy(29,19);
                printf("Ano de lancamento: ");
                gotoxy(50,19);
                printf("%s\n", A.anodelancamento);
                caixa(48,18,110,20);

                gotoxy(27,22);
                printf("Numero de capitulos: ");
                gotoxy(50,22);
                printf("%s\n", A.numerodecapitulos);
                caixa(48,21,110,23);

                gotoxy(39,25);
                printf("Editora: ");
                gotoxy(50,25);
                printf("%s\n", A.editora);
                caixa(48,24,110,26);

                gotoxy(38,28);
                printf("Autor(a): ");
                gotoxy(50,28);
                printf("%s\n", A.autor);
                caixa(48,27,110,29);

                break;
            }

        }
    }

    if (strcmp(A.codigo, pesquisa) != 0)
    {
        int co2[4] = {20, 10, 120, 13};

        TextColor(4);
        caixa(co[0], co[1] + 5, co[2], co[3] - 14);
        gotoxy(30,10);
        printf("LIVRO NAO ENCONTRADO!\n");

    }

}

void criarRelatorio()
{
    system("cls");

    livro A;
    fseek(fp,0,SEEK_SET);

    FILE *r;

    char arquivo[100];
    int co[4] = {20,2, 120, 26};
    int contador = 0;
    system("cls");

    gotoxy(68, 7);
    TextColor(BACKGROUND_INTENSITY);
    printf("CRIAR RELATORIO");
    int co2[4] = {20, 10, 120, 13};
    TextColor(15);
    caixa(co2[0], co[1] + 2, co[2], co[3] -13);
    gotoxy(30,10);
    printf("Digite o nome do documento: ");
    caixa(58,9,110,11);
    gotoxy(60, 10);

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
            contador++;

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
            fprintf(r, "Editora: %s\n", editora);
            fprintf(r, "Ano de lancamento: %s\n",anodeLancamento);
            fprintf(r, "Numero de capitulos: %s\n", numeroDeCapitulos);
            fprintf(r, "Numero total de paginas: %s\n", numerodepaginas);
            fprintf(r, "\n\n");
        }
    }


    fclose(r);

    system("cls");

    if(!contador)
    {
        system("cls");
        TextColor(4);
        caixa(co[0], co[1] + 6, co[2], co[3] - 14);
        gotoxy(30,10);
        printf("NAO HA LIVROS CADASTRADOS!\n");
    }

    else
    {
        TextColor(10);
        caixa(co[0], co[1] + 6, co[2], co[3] -13);

        gotoxy(30,10);
        printf("Arquivo %s criado!", arquivo);
    }


}

