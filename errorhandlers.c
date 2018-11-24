//#include <stdio.h>
//#include <stdlib.h>
//#include <windows.h>
//#include <conio.h>
//
//#include "livro.h"
//
//
//int handleErrors()
//{
///*
//    while(menu() != -1) {
//        if(menu() == 0)
//        {
//            salvarArquivo();
//        }
//        if(menu() == 5 )
//        {
//            imprimirAquivos();
//        }
//    }
//    */
//    /*
//
//    if(handleMenuOptions() == 1)
//    {
//        printf("ahsdhash");
//        gotoxy(5, 20);
//        printf("Houve um erro");
//        return 1;
//    }
//
//    menu();
//
//    */
//
//    gotoxy(5, 35);
//    printf("Adeus!\n");
//
//
//    return 0;
//}

/*

FILE *fp;
void Abrirarquivo()
{
    int *nullPointer;
    nullPointer = NULL;
    fp=fopen("Arquivo.txt", "rb+");
    if (fp==nullPointer)
    {
        fp=fopen("Arquivo.txt", "wb+");
        if (fp==nullPointer)
        {
            printf("Erro ao criar arquivo\n");
            exit(1);
        }
    }

}


Profissoes DigitarProfissao()
{
    Profissoes A,B;
    printf("Profissão: \n");
    scanf("%s", A.profissao);
    printf("A Profissão é Regulamentada?: \n");
    scanf("%s", A.regulamentacao);
    printf("O Tipo de Tarefa Exercída Envolve Riscos?: \n");
    scanf("%s", A.risco);
    printf("Área de Conhecimento: \n");
    scanf("%s", A.areadeconhecimento);
    printf("Exigência de Escolaridade: Médio - Técnico - Superior \n");
    scanf("%s", A.exigenciadeescolaridade);
    printf("Jornada de Trabalho em Horas: \n");
    scanf("%d", &A.jornadadetrabalho);
    printf("Salário Médio: \n");
    scanf("%lf", &A.salariomedio);
    printf("\n");
    B=A;

    fwrite(&B, sizeof(Profissoes), 1, fp);

    return A;
}

void ImprimeProfissao()
{
    Profissoes A;
    fseek(fp,0, SEEK_SET);

    while(fread(&A, sizeof(Profissoes), 1, fp))
    {
        printf("Profissao: %s\n", A.profissao);
        printf("Regulamentacao: %s\n", A.regulamentacao);
        printf("Risco: %s\n", A.risco);
        printf("Area de conhecimento: %s\n", A.areadeconhecimento);
        printf("Escolaridade: %s\n", A.exigenciadeescolaridade);
        printf("Jornada: %d\n", A.jornadadetrabalho);
        printf("Salario: %.2lf\n", A.salariomedio);
        printf("\n");
    }

}

void Pesquisar()
{
    char pesq[51];
    Profissoes A;
    printf("Digite o nome da Profissão\n");
    scanf("%s", pesq);
    printf("\n");
    fseek(fp,0,SEEK_SET);
    while (!feof(fp))
    {
        if (fread(&A, sizeof(Profissoes), 1, fp))
        {
            if (strcmp(A.profissao, pesq) == 0)
            {
                printf("Profissão encontrada!\n\n");

                printf("Profissao: %s\n", A.profissao);
                printf("Regulamentacao: %s\n", A.regulamentacao);
                printf("Risco: %s\n", A.risco);
                printf("Area de conhecimento: %s\n", A.areadeconhecimento);
                printf("Escolaridade: %s\n", A.exigenciadeescolaridade);
                printf("Jornada: %d\n", A.jornadadetrabalho);
                printf("Salario: %.2lf\n", A.salariomedio);
                printf("\n");
                break;
            }

        }
    }
     if (strcmp(A.profissao, pesq) != 0)
            {
                printf("Profissão não encontrada\n");
                printf("\n");
            }

}


void Alterar()
{
    char pesq[51];
    Profissoes A;
    printf("Digite o nome da Profissão\n");
    scanf("%s", pesq);
    printf("\n");
    fseek(fp,0,SEEK_SET);
    while (!feof(fp))
    {
        if (fread(&A, sizeof(Profissoes), 1, fp))
        {
            if (strcmp(A.profissao, pesq) == 0)
            {
                printf("Profissão encontrada!\n\n");

                fseek(fp,-sizeof(Profissoes),SEEK_CUR);
                printf("Digite os novos dados\n");
                DigitarProfissao();
                printf("\n");
                break;
            }

        }
    }
     if (strcmp(A.profissao, pesq) != 0)
            {
                printf("Profissão não encontrada\n");
                printf("\n");
            }

}

*/
