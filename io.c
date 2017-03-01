/*
 * io.c
 *
 *  Created on: Apr 13, 2013
 *      Author: lucas
 */

#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include "io.h"

void getOpt(int argc, char *argv[]) {
    int opcao;
    char *paramEntrada = NULL, *paramSaida = NULL;
    /*
        O while abaixo lê a linha de comando usando a função ǵetOpt e define os arquivos de entrada e saída
    */
    while((opcao = getopt(argc, argv, "i:o:I:O:")) != -1) {
        if(opcao == 'i' || opcao == 'I') {
            paramEntrada = optarg;
            printf("\nParametro de entrada aceito = %s\n", paramEntrada);
        } else if (opcao == 'o' || opcao == 'O') {
            paramSaida = optarg;
            printf("\nParametro de saida aceito = %s\n\n", paramSaida);
        } else {
            printf("\nParametro incorreto!\n");
            exit(0);
        }
    }

    AbreArquivos(paramEntrada, paramSaida);
}

void AbreArquivos(char *paramEntrada, char *paramSaida) {


    if(!(arqEntrada = fopen(paramEntrada, "r"))) {
        printf("Erro na leitura do arquivo de entrada.\n\n");
        exit(0);
    } else {
        printf("Arquivo aberto com sucesso!\n");
    }

    if(!(arqSaida = fopen(paramSaida, "w"))) {
        printf("Erro na leitura do arquivo de saida.\n\n");
        exit(0);
    } else {
        printf("Arquivo criado com sucesso!\n\n\n");
    }
}

void MostrarParametrosPassados(int argc, char *argv[]) {

    int count;

    printf ("\nO programa foi chamado pelo caminho: \"%s\".\n\n", argv[0]);

    if (argc > 1)
        for (count = 1; count < argc; count++)
            printf("argv[%d] = %s\n", count, argv[count]);
    else
        printf("O comando não possui argumentos.\n");
    printf("\n");
}

FILE* AbreArquivo(char *arq) {
    FILE *arquivo;
    if(!(arquivo = fopen(arq, "r"))) {
        printf("\nO arquivo não foi aberto corretamente!\n");
        exit(1);
    }
    return arquivo;
}
