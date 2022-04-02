#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "funcoes.h"

FILE *file;
FILME_LIVRO *ptrFilmeLivro, filmeLivro;
MUSICA *ptrMusica, musica;
char *c;
char ch;

void menu(){
    ptrFilmeLivro = &filmeLivro;
    ptrMusica = &musica;
    int opcao;
    bool sair = false;
    bool sair2 = false;



    while(sair == false){
        sair2 = false;
        system("cls");
        printf("---Bem Vindo---");
        printf("\n1 - Recomendar\n2 - Ver Recomendação\n3 - Remover dados\n4 - Sair");
        printf("\nO que deseja fazer? Digite o número de uma das opções: ");
        scanf("%d", &opcao);
        scanf("%c", &c);

        switch(opcao){
        case 1:
            recomendar();
            break;
        case 2:

            while(sair2 == false){
                system("cls");
                printf("1 - Filme e livro\n2 - Musica\n3 - Voltar\nQual recomendação deseja ver?: ");
                scanf("%d", &opcao);
                scanf("%c", &c);
                switch(opcao){
                case 1:
                    recuperarFilmeLivro();
                    sair2 = true;
                    break;
                case 2:
                    recuperarMusica();
                    sair2 = true;
                    break;
                case 3:
                    sair2 = true;
                    break;
                default:
                    sair2 = false;
                }

            }
            break;
        case 3:
            removerDados();
            break;
        case 4:
            sair = true;
            break;
        default:
            sair = false;
        }
    }
}

void recomendar(){
    ptrFilmeLivro = &filmeLivro;
    ptrMusica = &musica;
    int opcao;
    bool sair = false;

    while(sair == false){
        system("cls");
        printf("1 - Filme ou livro\n2 - Música\n3 - Voltar");
        printf("\nO que vai recomendar? Selecione uma opção: ");
        scanf("%d", &opcao);
        scanf("%c", &c);

        switch(opcao){
        case 1:
            system("cls");
            printf("Digite o nome: ");
            fgets(filmeLivro.nome, 50, stdin);
            strtok(filmeLivro.nome, "\n");
            if (strlen(filmeLivro.nome) ==  50 - 1){
                while ((ch = getchar()) != '\n' && ch != EOF);
            }

            printf("Digite os gêneros: ");
            fgets(filmeLivro.genero, 50, stdin);
            strtok(filmeLivro.genero, "\n");
            if (strlen(filmeLivro.genero) ==  50 - 1){
                while ((ch = getchar()) != '\n' && ch != EOF);
            }
            printf("Filme ou livro?: ");
            fgets(filmeLivro.tipo, 10, stdin);
            strtok(filmeLivro.tipo, "\n");
            if (strlen(filmeLivro.tipo) ==  10 - 1){
                while ((ch = getchar()) != '\n' && ch != EOF);
            }
            salvarFilmeLivro(ptrFilmeLivro);
            break;
        case 2:
            system("cls");
            printf("Digite o nome da música: ");
            fgets(musica.nomeMusica, sizeof(musica.nomeMusica), stdin);
            strtok(musica.nomeMusica, "\n");
            if (strlen(musica.nomeMusica)== sizeof(musica.nomeMusica) - 1){
                while((ch = getchar()) != '\n' && ch != EOF);
            }
            printf("Digite o nome do artista: ");
            fgets(musica.artista, sizeof(musica.artista), stdin);
            strtok(musica.artista, "\n");
            if (strlen(musica.artista) == sizeof(musica.artista) - 1){
                while((ch = getchar()) != '\n' && ch != EOF);
            }
            salvarMusica(ptrMusica);
            break;
        case 3:
            sair = true;
            break;
        default:
            sair = false;

        }
    }
}

void salvarFilmeLivro(FILME_LIVRO *ptrFilmeLivro){

    file = fopen("FilmeLivro.bin", "ab");

    if(!file){
        printf("Erro ao abrir arquivo");
        getchar();
        exit(1);
    }

    fwrite(ptrFilmeLivro, sizeof(FILME_LIVRO), 1, file);

    fclose(file);
    printf("\nDados salvo com sucesso! Pressione enter para continuar");
    getchar();

}

void salvarMusica(MUSICA *ptrMusica){
    file = fopen("Musica.bin", "ab");

    if(!file){
        printf("Erro ao abrir o arquivo");
        getchar();
        exit(1);
    }

    fwrite(ptrMusica, sizeof(MUSICA), 1, file);

    fclose(file);

    printf("\nDados salvo com sucesso! Pressione enter para continuar");
    getchar();

}

void recuperarFilmeLivro(){
    system("cls");
    file = fopen("FilmeLivro.bin", "rb");

    if(!file){
        printf("Erro ao abrir o arquivo");
        getchar();
        exit (1);
    }
    while(fread(ptrFilmeLivro, sizeof(FILME_LIVRO), 1, file)){
        printf("Nome: %s\nGeneros: %s\nTipo: %s\n\n", &ptrFilmeLivro->nome, &ptrFilmeLivro->genero, &ptrFilmeLivro->tipo);
    }
    fclose(file);
    getchar();
}

void recuperarMusica(){
    system("cls");
    file = fopen("Musica.bin", "rb");

    if(!file){
        printf("Erro ao abrir o arquivo");
        getchar();
        exit (1);
    }
    while (fread(ptrMusica, sizeof(MUSICA), 1, file)){
        printf("Artista: %s\nMúsica: %s\n\n", &ptrMusica -> artista, &ptrMusica -> nomeMusica);
    }

    fclose(file);
    getchar();


}

void removerDados(){
    int opcao;
    bool sair = false;

    while(sair == false){
        system("cls");
        printf("1 - Remover Filme/Livro\n2 - Remover Música\n3 - Remover Tudo\n4 - Voltar\nO que quer remover?: ");
        scanf("%d", &opcao);
        scanf("%c", &c);

        switch(opcao){
            case 1:
                remove("FilmeLivro.bin");
                printf("Dados Removidos com sucesso. Pressione enter para continuar");
                getchar();
                break;
            case 2:
                remove("Musica.bin");
                printf("Dados Removidos com sucesso. Pressione enter para continuar");
                getchar();
                break;
            case 3:
                remove("FilmeLivro.bin");
                remove("Musica.bin");
                printf("Dados Removidos com sucesso. Pressione enter para continuar");
                getchar();
                break;
            case 4:
                sair = true;
                break;
            default:
                sair = false;

        }
    }
}
