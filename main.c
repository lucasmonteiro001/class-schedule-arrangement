/*
 * main.c
 *
 *  Created on: Apr 13, 2013
 *      Author: lucas
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <getopt.h>
#include "vetor_grade.h"
#include "io.h"
#include "colision_lists.h"

int main(int argc, char *argv[]) {

    //MostrarParametrosPassados(argc, argv);

    // A função getOpt() já inicializa os arquivos para leitura e escrita
    getOpt(argc, argv);

    // Define um TipoGrade grade, a aloca seu tamanho de acordo com o número de classes
    TipoGrade grade = AlocaVetorGrade();

    // Preenche o Vetor grade com todas as classes passadas no arquivo
    PreencheVetorGrade(grade);

    ImprimeVetorGrade(grade);

    TipoManha Manha;		// Declaração de uma matriz do TipoManha, onde seu tamanho é 10(ordens) x 7(dias da semana)
    TipoTarde Tarde;		// Declaração de uma matriz do TipoTarde, onde seu tamanho é 10(ordens) x 7(dias da semana)
    TipoNoite Noite;		// Declaração de uma matriz do TipoNoite, onde seu tamanho é 10(ordens) x 7(dias da semana)
    TipoCelulaClasse erro;	// A celula erro serve para referenciar para uma posicao de conflito
    TipoCelulaClasse vazia;	// Celula quer servirá como indicação do horário que não foi preenchido

    // Inicia todas as posições da matriz apontando para uma célula indicadora de posição vazia
    ApontaParaCelulaVazia(Manha, Tarde, Noite, &vazia);


    // Realiza o preenchimento e verificação das colisões das matrizes que indicam os turnos
    PreecheMatrizTipoManha(Manha, grade, &erro, &vazia);
    PreecheMatrizTipoTarde(Tarde, grade, &erro, &vazia);
    PreecheMatrizTipoNoite(Noite, grade, &erro, &vazia);

    fclose(arqEntrada);
    printf("\n");
    return 0;
}
