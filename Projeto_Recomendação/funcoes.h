#ifndef FUNCOES_H_INCLUDED
#define FUNCOES_H_INCLUDED
#endif // FUNCOES_H_INCLUDED

typedef struct{
    char nome[50];
    char genero[50];
    char tipo[10];
}FILME_LIVRO;

typedef struct{
    char artista[20];
    char nomeMusica[20];
}MUSICA;

void salvarMusica(MUSICA *ptrMusica);
void salvarFilmeLivro(FILME_LIVRO *ptrFilmeLivro);
void menu();
void recomendar();
void recuperarFilmeLivro();
void recuperarMusica();
void removerDados();
