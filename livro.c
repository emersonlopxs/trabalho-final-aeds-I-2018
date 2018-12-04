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
    scanf("%s", A.titulo);

    gotoxy(50,16);
    scanf("%s", A.numerodepaginas);

    gotoxy(50,19);
    scanf("%s", A.anodelancamento);

    gotoxy(50,22);
    scanf("%s", A.numerodecapitulos);

    gotoxy(50,25);
    scanf("%s", A.editora);

    gotoxy(50,28);
    scanf("%s", A.autor);




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

