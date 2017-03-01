/*
 * lists.h
 *
 *  Created on: Apr 13, 2013
 *      Author: lucas
 */

#ifndef LISTS_H_
#define LISTS_H_

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "io.h"

int tamanho_vetor_grade;

// Definição do tipo enum para os dias da semana, conforme instrução dada na especificação
enum  dias {Domingo = 1, Segunda, Terca, Quarta, Quinta, Sexta, Sabado};

// Definição do tipo enum para os turnos, conforme instrução dada na especificação
enum turno {Manha = 1, Tarde, Noite};

// Definição dos tipos para manipulação das classes: TipoDia, TipoTurno e TipoSemana
typedef enum dias TipoDia;
typedef enum turno TipoTurno;
typedef int TipoOrdem;

// Declaração do conteúdo do TipoHorario
typedef struct TipoHorario {
    TipoDia dia;
    TipoTurno turno;
    TipoOrdem ordem;
} TipoHorario;

// Declaração da célula que contém o TipoHorario mais um apontador para a próxima célula
typedef struct TipoCelulaHorario {
    TipoHorario itemHorario;//
    struct TipoCelulaHorario *Prox;
} TipoCelulaHorario;

// Declaração da lista que contém as células do TipoHorario
typedef struct TipoListaHorario {
    TipoCelulaHorario *Primeiro, *Ultimo;
} TipoListaHorario;

// Declaração do conteúdo do TipoClasse
typedef struct TipoClasse {
    int periodo;                // Período de curso de aluno. Valor: 0 < periodo < 11
    char disciplina[8];         // Disciplina sendo ofertada. Possui de 2 a 7 caracteres alfa-numéricos, onde o primeiro é sempre
    							// um caractere literal entre A-Z. Além disso, todos caractere literal é representado em caixa alta.
    int sala;                   // Número do ambiente de aprendizagem. Valor: 999 < sala < 10000
    char *professor;       		// Nome do professor responsável pela classe
    TipoListaHorario horarios;  // Toda disciplina deverá possuir no mínimo 1 horário de aula previsto. Este é um atributo multi-valorado,
    							// o qual deverá utilizar uma lista encadeada para armazenar seus diversos valores
} TipoClasse;

// Declaração da célula que contém o TipoClasse
typedef struct TipoCelulaClasse {
    TipoClasse itemClasse;
} TipoCelulaClasse;

// Declaração de célula que contém o TipoDisciplina
typedef struct TipoCelulaDisciplina {
	char disciplina[8];
	struct TipoCelulaDisciplina *Prox;
} TipoCelulaDisciplina;

// Declaração da lista que contém as células do TipoDisciplina
typedef struct TipoListaDisciplina {
	TipoCelulaDisciplina *Primeiro, *Ultimo;
} TipoListaDisciplina;

// Vetor de apontadores para as células contendo as classes
typedef TipoCelulaClasse **TipoGrade;

/*-----------------------------------------------------------------------------------------------------------------------------------------*/
/*
 * Funções específicas para lista e célula do TipoHorario
 */
/*-----------------------------------------------------------------------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------

Protótipo: void FLHorarioVazia(TipoListaHorario *Lista)
Função: Faz uma lista vazia para armazenar os horários
Entrada: Variável do TipoListaHorário que armazenará os horários
Saída: Nenhuma

-----------------------------------------------------------------------------------------------------------------------------------------------------------------*/
void FLHorarioVazia(TipoListaHorario *Lista);

/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------

Protótipo: int LHorarioVazia(TipoListaHorario Lista)
Função: Verifica se a lista está vazia
Entrada: Variável do TipoListaHorario
Saída: Inteiro com valor 1 ou 0

-----------------------------------------------------------------------------------------------------------------------------------------------------------------*/
int LHorarioVazia(TipoListaHorario Lista);

/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------

Protótipo: void InsereHorario(TipoCelulaHorario horario, TipoListaHorario *Lista)
Função: Insere uma célula com os dados do horário na lista
Entrada: Variável do TipoHorario e lista do TipoListaHorário que receberá a variável
Saída: Nenhuma

-----------------------------------------------------------------------------------------------------------------------------------------------------------------*/
void InsereHorario(TipoCelulaHorario horario, TipoListaHorario *Lista);

/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------

Protótipo: void ImprimeHorario(TipoListaHorario Lista)
Função: Imprime os horários no formato %d%d%d(dia, turno e ordem)
Entrada: TipoListaHorario contendo as variáveis do TipoHorario
Saída: Nenhuma

-----------------------------------------------------------------------------------------------------------------------------------------------------------------*/
void ImprimeHorario(TipoListaHorario Lista);

/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------

Protótipo: void PreencheParametrosHorarios(TipoCelulaHorario *horario, char *linha)
Função: Recebe uma string contendo os horários e atribui para a célula do TipoHorario seus valores corretos e em ordem (dia, turno e ordem)
Entrada: Uma célula do TipoHorario e uma string
Saída: Nenhuma

-----------------------------------------------------------------------------------------------------------------------------------------------------------------*/
void PreencheParametrosHorarios(TipoCelulaHorario *horario, char *linha);

/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------

Protótipo: void ImprimeDiaSemana(int dia)
Função: Imprime o dia da semana (Domingo, Segunda ... Sabado)
Entrada: Um inteiro que representa o dia (Domingo = 1, Segunda = 2 ... Sabado = 7)
Saída: Nenhuma

-----------------------------------------------------------------------------------------------------------------------------------------------------------------*/
void ImprimeDiaSemana(int dia);

/*-----------------------------------------------------------------------------------------------------------------------------------------*/
/*
 * Funções específicas para lista e célula do TipoDisciplina
 */
/*-----------------------------------------------------------------------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------

Protótipo: void FLDisciplinaVazia(TipoListaDisciplina *Lista)
Função: Faz uma lista vazia para armazenar as disciplinas
Entrada: Variável do TipoListaDisciplina que armazenará as disciplinas
Saída: Nenhuma

-----------------------------------------------------------------------------------------------------------------------------------------------------------------*/
void FLDisciplinaVazia(TipoListaDisciplina *Lista);

/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------

Protótipo: int LDisciplinaVazia(TipoListaDisciplina Lista)
Função: Verifica se a lista está vazia
Entrada: Variável do TipoListaDisciplina
Saída: Inteiro com valor 1 ou 0

-----------------------------------------------------------------------------------------------------------------------------------------------------------------*/
int LDisciplinaVazia(TipoListaDisciplina Lista);

/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------

Protótipo: void InsereHorario(TipoCelulaHorario horario, TipoListaHorario *Lista)
Função: Insere uma célula do TipoDisciplina nas lista de disciplinas
Entrada: Variável do TipoCelulaDisciplina e lista do TipoListaDisciplina que receberá a variável
Saída: Nenhuma

-----------------------------------------------------------------------------------------------------------------------------------------------------------------*/
void InsereDisciplina(TipoCelulaDisciplina Disciplina, TipoListaDisciplina *Lista);

/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------

Protótipo: void ImprimeListaDisciplinas(TipoListaDisciplina listaDisc)
Função: Imprime as disciplinas presentes na lista
Entrada: Uma lista do tipo disciplina contendo as disciplinas que devem ser imprimidas
Saída: Nenhuma

-----------------------------------------------------------------------------------------------------------------------------------------------------------------*/
void ImprimeListaDisciplinas(TipoListaDisciplina listaDisc);


#endif /* LISTS_H_ */
