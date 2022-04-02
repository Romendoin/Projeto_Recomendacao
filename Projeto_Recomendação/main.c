#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "funcoes.h"
/*
Programador: Rodrigo Sousa A. Martins
Objetivo: Pegar recomendações de filmes, livros ou músicas. Salvar esses dados em arquivos e recuperar esses dados
O programa serve apenas para trenar a função de salvar e recuperar arquivos de dados.
Programa feito em windows com funções que pode não funcionar em outros sistemas operacionais.
Data: 17/03/2022
*/

int main()
{   setlocale(LC_ALL, "Portuguese");

    menu();

    return 0;
}
