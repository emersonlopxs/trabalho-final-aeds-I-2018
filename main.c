
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>

#include "livro.h"




/// TODO: colocar o return fora da caixa quando o programa sair
int main()
{
    abrirAquivo();
    handleMenuOptions();
    fecharArquivo();
    return 0;
}
