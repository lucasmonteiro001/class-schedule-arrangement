/*
 * functions.h
 *
 *  Created on: Apr 13, 2013
 *      Author: lucas
 */

#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_

#include <stdio.h>
#include <stdlib.h>
#include "general_lists.h"

/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------

Protótipo: TipoGrade AlocaVetorGrade()
Função: Recebe um TipoGrade e aloca seu tamanho de acordo com o número de classes que se tem no arquivo
Entrada: Nenhuma
Saída: Um TipoGrade do tamanho necessário para alocar as classes

-----------------------------------------------------------------------------------------------------------------------------------------------------------------*/
TipoGrade AlocaVetorGrade();

/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------

Protótipo: void PreencheVetorGrade(TipoGrade grade)
Função: Percorre o arquivo alocando as classes na matriz grade
Entrada: Matriz do TipoGrade
Saída: Nenhuma

-----------------------------------------------------------------------------------------------------------------------------------------------------------------*/
void PreencheVetorGrade(TipoGrade grade);

/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------

Protótipo: void ImprimeVetorGrade(TipoGrade grade)
Função: Imprime a matriz de grade contendo todas as classes que estão no arquivo
Entrada: Matriz do TipoGrade
Saída: Nenhuma

-----------------------------------------------------------------------------------------------------------------------------------------------------------------*/
void ImprimeVetorGrade(TipoGrade grade);

#endif /* FUNCTIONS_H_ */
