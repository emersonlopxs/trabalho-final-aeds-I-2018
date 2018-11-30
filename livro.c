#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#include "livro.h"

livro novoLivro()
{

    livro A;
    /// TODO: Validar o input to usuario
    // todos sao strings

    gotoxy(36,8);
    scanf("%s", A.codigo);
    gotoxy(36,11);
    scanf("%s", A.titulo);
    gotoxy(36, 14);
    scanf("%s", A.autor);
    gotoxy(47,17);
    scanf("%s", A.numerodepaginas);
    gotoxy(47,20);
    scanf("%s", A.anodelancamento);
    gotoxy(47,23);
    scanf("%s", A.numerodecapitulos);
    gotoxy(36,26);
    scanf("%s", A.editora);



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

