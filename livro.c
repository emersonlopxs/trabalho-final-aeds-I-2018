#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#include "livro.h"

livro novoLivro(){

    livro A;
    /// TODO: Validar o input to usuario
    // todos sao strings
    gotoxy(36,8);
    // permitir espacos
    scanf("[^\n]s", A.codigo);
    //fgets(A.codigo, sizeof(A.codigo), stdin);
    gotoxy(36,11);
    scanf("%s", A.titulo);
    //fgets(A.titulo, sizeof(A.titulo), stdin);
    gotoxy(36, 14);
    scanf("%s", A.autor);
    //fgets(A.autor, sizeof(A.autor), stdin);

    return A;
}




