#ifndef LIVRO_H_INCLUDED
#define LIVRO_H_INCLUDED

// defining a structure
struct livros {
    char codigo[100];
    char titulo[100];
    char autor[100];
};

typedef struct livros livro;

// passing the functions used in another files
livro novoLivro();
void listarAquivo();
void abrirArquivo();
void fecharArquivo();
//void imprimir();


#endif // LIVRO_H_INCLUDED
