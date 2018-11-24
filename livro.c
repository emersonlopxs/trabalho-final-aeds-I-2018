#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#include "livro.h"

livro novoLivro(){

    livro A;
    /// TODO: Validar o input to usuario
    // todos sao strings
    gotoxy(36,8);
    scanf("%s", A.codigo);
    gotoxy(36,11);
    scanf("%s", A.titulo);
    gotoxy(36, 14);
    scanf("%s", A.autor);

    return A;
}




