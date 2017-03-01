/*
 * io.h
 *
 *  Created on: Apr 13, 2013
 *      Author: lucas
 */

#ifndef IO_H_
#define IO_H_

#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>



/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------

Declaração global do arquivo de entrada e do arquivo de saída

-----------------------------------------------------------------------------------------------------------------------------------------------------------------*/
FILE *arqEntrada, *arqSaida;

/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------

Protótipo: void getOpt(int argc, char *argv[])
Função: Utiliza a biblioteca getopt para ler os arquivos passados por linha de comando com as flags [i-I] [o-O]
Entrada: Número de argumentos passados na linha de comando e arquivos e flags passados pela linha de comando também
Saída: Nenhuma

-----------------------------------------------------------------------------------------------------------------------------------------------------------------*/
void getOpt(int argc, char *argv[]);

/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------

Protótipo: void AbreArquivos(char *paramEntrada, char *paramSaida)
Função: Abre os arquivos de entrada e saida para leitura e escrita, respectivamente
Entrada: Nome do arquivo de entrada e nome do arquivo de saída
Saída: Nenhuma

-----------------------------------------------------------------------------------------------------------------------------------------------------------------*/
void AbreArquivos(char *paramEntrada, char *paramSaida);

/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------

Protótipo: void MostrarParametrosPassados(int argc, char *argv[])
Função: Mostra tudo o que foi passado na linha de comando. É uma função de auxílio para tratamento da linha de comando
Entrada: Número de argumentos passados na linha de comando e arquivos e flags passados pela linha de comando também
Saída: Nenhuma

-----------------------------------------------------------------------------------------------------------------------------------------------------------------*/
void MostrarParametrosPassados(int argc, char *argv[]);

/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------

Protótipo: FILE* AbreArquivo(char *arq)
Função: Abre um arquivo para leitura
Entrada: Nome do arquivo
Saída: Retorna um ponteiro para o arquivo

-----------------------------------------------------------------------------------------------------------------------------------------------------------------*/
FILE* AbreArquivo(char *arq);

#endif /* IO_H_ */
