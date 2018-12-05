#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#include "livro.h"

livro novoLivro()
{

    livro A;
    /// TODO: Validar o input to usuario
    // todos sao strings

    gotoxy(50,10);
    scanf("%s", A.codigo);

    gotoxy(50,13);
    scanf(" %[^\n]", A.titulo);

    gotoxy(50,16);
    scanf(" %[^\n]", A.numerodepaginas);

    gotoxy(50,19);
    scanf(" %[^\n]", A.anodelancamento);

    gotoxy(50,22);
    scanf(" %[^\n]", A.numerodecapitulos);

    gotoxy(50,25);
    scanf(" %[^\n]", A.editora);

    gotoxy(50,28);
    scanf(" %[^\n]", A.autor);




//    gotoxy(36,8);
//    // permitir espacos
//    fgets(A.codigo, sizeof(A.codigo), stdin);
//    fflush(stdin);
//    gotoxy(36,11);
//    fgets(A.titulo, sizeof(A.titulo), stdin);
//    fflush(stdin);
//    gotoxy(36, 14);
//    fgets(A.autor, sizeof(A.autor), stdin);
//    fflush(stdin);

    return A;
}

