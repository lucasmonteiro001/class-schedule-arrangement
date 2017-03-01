/*
 * colision_lists.h
 *
 *  Created on: Apr 15, 2013
 *      Author: lucas
 */

#ifndef COLISION_LISTS_H_
#define COLISION_LISTS_H_

#include "general_lists.h"

// Matrizes criadas para serem os turnos: manhã, tarde e noite. Cada uma delas será 9x6. Nove é correspondente ao número maximo de turnos e
// seis é correspondente ao número de dias que é possível ter aula.
typedef TipoCelulaClasse *TipoManha[10][7];
typedef TipoCelulaClasse *TipoTarde[10][7];
typedef TipoCelulaClasse *TipoNoite[10][7];

/*-----------------------------------------------------------------------------------------------------------------------------------------*/
/*
 * Funções específicas para lista e célula do TipoDocente
 */
/*-----------------------------------------------------------------------------------------------------------------------------------------*/
typedef struct TipoCelulaColisaoDocentes {
	char professor[60];
	TipoListaHorario horarios;
	struct TipoCelulaColisaoDocentes *Prox;
} TipoCelulaColisaoDocentes;

typedef struct TipoListaColisaoDocentes {
	struct TipoCelulaColisaoDocentes *Primeiro, *Ultimo;
} TipoListaColisaoDocentes;

/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------

Protótipo: void FLColisaoDocentesVazia(TipoListaColisaoDocentes *Lista)
Função: Faz uma lista vazia para armazenar a colisão dos docentes
Entrada: Variável do TipoListaColisaoDocentes que armazenará as colisões
Saída: Nenhuma

-----------------------------------------------------------------------------------------------------------------------------------------------------------------*/
void FLColisaoDocentesVazia(TipoListaColisaoDocentes *Lista);

/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------

Protótipo: int LColisaoDocentesVazia(TipoListaColisaoDocentes Lista)
Função: Verifica se a lista está vazia
Entrada: Variável do TipoListaColisaoDocentes
Saída: Inteiro com valor 1 ou 0

-----------------------------------------------------------------------------------------------------------------------------------------------------------------*/
int LColisaoDocentesVazia(TipoListaColisaoDocentes Lista);

/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------

Protótipo: void InsereColisaoDocentes(TipoCelulaColisaoDocentes docente, TipoListaColisaoDocentes *Lista)
Função: Insere uma célula com os dados de uma colisão de docentes na lista
Entrada: Variável do TipoListaColisaoDocentes e lista que receberá a variável do tipo TipoCelulaColisaoDocentes
Saída: Nenhuma

-----------------------------------------------------------------------------------------------------------------------------------------------------------------*/
void InsereColisaoDocentes(TipoCelulaColisaoDocentes docente, TipoListaColisaoDocentes *Lista);

/*-----------------------------------------------------------------------------------------------------------------------------------------*/
/*
 * Funções específicas para lista e célula do TipoEspacoFisico
 */
/*-----------------------------------------------------------------------------------------------------------------------------------------*/
typedef struct TipoCelulaColisaoEspacoFisico {
	int sala;
	TipoListaHorario horarios;
	struct TipoCelulaColisaoEspacoFisico *Prox;
} TipoCelulaColisaoEspacoFisico;

typedef struct TipoListaColisaoEspacoFisico {
	struct TipoCelulaColisaoEspacoFisico *Primeiro, *Ultimo;
} TipoListaColisaoEspacoFisico;

/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------

Protótipo: void FLColisaoEspacoFisicoVazia(TipoListaColisaoEspacoFisico *Lista)
Função: Faz uma lista vazia para armazenar a colisão de espaço físico
Entrada: Variável do TipoListaColisaoEspacoFisico que armazenará as colisões
Saída: Nenhuma

-----------------------------------------------------------------------------------------------------------------------------------------------------------------*/
void FLColisaoEspacoFisicoVazia(TipoListaColisaoEspacoFisico *Lista);

/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------

Protótipo: int LColisaoEspacoFisicoVazia(TipoListaColisaoEspacoFisico Lista)
Função: Verifica se a lista está vazia
Entrada: Variável do TipoListaColisaoEspacoFisico
Saída: Inteiro com valor 1 ou 0

-----------------------------------------------------------------------------------------------------------------------------------------------------------------*/
int LColisaoEspacoFisicoVazia(TipoListaColisaoEspacoFisico Lista);

/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------

Protótipo: InsereColisaoEspacoFisico(TipoCelulaColisaoEspacoFisico sala, TipoListaColisaoEspacoFisico *Lista)
Função: Insere uma célula com os dados de uma colisão de espaço físico na lista
Entrada: Variável do TipoListaColisaoEspacoFisico e lista que receberá  a variável do tipo TipoCelulaColisaoEspacoFisico
Saída: Nenhuma

-----------------------------------------------------------------------------------------------------------------------------------------------------------------*/
void InsereColisaoEspacoFisico(TipoCelulaColisaoEspacoFisico sala, TipoListaColisaoEspacoFisico *Lista);

/*-----------------------------------------------------------------------------------------------------------------------------------------*/
/*
 * Funções específicas para lista e célula do TipoHorario
 */
/*-----------------------------------------------------------------------------------------------------------------------------------------*/
typedef struct TipoCelulaColisaoHorario {
	int periodo;
	TipoHorario horario;
	TipoListaDisciplina disciplinas;
	struct TipoCelulaColisaoHorario *Prox;
} TipoCelulaColisaoHorario;

typedef struct TipoListaColisaoHorario {
	struct TipoCelulaColisaoHorario *Primeiro, *Ultimo;
} TipoListaColisaoHorario;

/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------

Protótipo: void FLColisaoHorarioVazia(TipoListaColisaoHorario *Lista)
Função: Faz uma lista vazia para armazenar a colisão de horário
Entrada: Variável do TipoListaColisaoHorario que armazenará as colisões
Saída: Nenhuma

-----------------------------------------------------------------------------------------------------------------------------------------------------------------*/
void FLColisaoHorarioVazia(TipoListaColisaoHorario *Lista);

/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------

Protótipo: int LColisaoHorarioVazia(TipoListaColisaoHorario Lista)
Função: Verifica se a lista está vazia
Entrada: Variável do TipoListaColisaoHorario
Saída: Inteiro com valor 1 ou 0

-----------------------------------------------------------------------------------------------------------------------------------------------------------------*/
int LColisaoHorarioVazia(TipoListaColisaoHorario Lista);

/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------

Protótipo: void InsereColisaoHorario(TipoCelulaColisaoHorario horario, TipoListaColisaoHorario *Lista)
Função: Insere uma célula com os dados de uma colisão de horário na lista
Entrada: Variável do TipoListaColisaoHorario e lista que receberá  a variável do tipo TipoCelulaColisaoHorario
Saída: Nenhuma

-----------------------------------------------------------------------------------------------------------------------------------------------------------------*/
void InsereColisaoHorario(TipoCelulaColisaoHorario horario, TipoListaColisaoHorario *Lista);

/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------

Protótipo: int ExisteHorarioManha(int dia, int ordem, int turno, TipoGrade grade, TipoListaDisciplina *listaDisciplina, TipoListaColisaoHorario *listaColisaoHorario)
Função: Verifica se o horário sendo analisado existe na lista de disciplinas
Entrada: Variáveis representando o horário procurado(dia, ordem, turno), a grade que contém as disciplinas, uma lista para armazenar as disciplinas e outra
		 para armazenar a colisão de horários
Saída: A saída é 1 ou 0 (indicando se existe o horário ou não)

-----------------------------------------------------------------------------------------------------------------------------------------------------------------*/
int ExisteHorarioManha(int dia, int ordem, int turno, TipoGrade grade, TipoListaDisciplina *listaDisciplina, TipoListaColisaoHorario *listaColisaoHorario);

/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------

Protótipo: void ImprimeColisaoHorario(TipoListaColisaoHorario Lista)
Função: Imprime as colisões de horário
Entrada: Uma lista contendo as colisões de horário
Saída: Nenhuma

-----------------------------------------------------------------------------------------------------------------------------------------------------------------*/
void ImprimeColisaoHorario(TipoListaColisaoHorario Lista);

/*-----------------------------------------------------------------------------------------------------------------------------------------*/
/*
 * Funções específicas para a alocação dos tipos Manha, Tarde e Noite
 */
/*-----------------------------------------------------------------------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------

Protótipo: void ApontaVazioTipoManha(TipoManha Manha, TipoManha Tarde, TipoNoite Noite, TipoCelulaClasse *vazia)
Função: Faz todas as posições das matrizes apontarem para uma célula vazia
Entrada: Um TipoCelulaClasse vazio e matrizes do TipoManha, TipoTarde e TipoNoite
Saída: Nenhuma

-----------------------------------------------------------------------------------------------------------------------------------------------------------------*/
void ApontaParaCelulaVazia(TipoManha Manha, TipoManha Tarde, TipoNoite Noite, TipoCelulaClasse *vazia);

/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------

Protótipo: void PreecheMatrizTipoManha(TipoManha Manha, TipoGrade grade, TipoCelulaClasse *erro, TipoCelulaClasse *vazia)
Função: Preenche a posição que uma se matéria se encontrada, se houver conflito, é mostrado ERR
Entrada: Uma matriz do TipoManha, a grade contendo as aulas, uma célula que aponta para erro e outra para posição vazia
Saída: Nenhuma

-----------------------------------------------------------------------------------------------------------------------------------------------------------------*/
void PreecheMatrizTipoManha(TipoManha Manha, TipoGrade grade, TipoCelulaClasse *erro, TipoCelulaClasse *vazia);

/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------

Protótipo: void PreecheMatrizTipoTarde(TipoTarde Tarde, TipoGrade grade, TipoCelulaClasse *erro, TipoCelulaClasse *vazia)
Função: Preenche a posição que uma se matéria se encontrada, se houver conflito, é mostrado ERR
Entrada: Uma matriz do TipoTarde, a grade contendo as aulas, uma célula que aponta para erro e outra para posição vazia
Saída: Nenhuma

-----------------------------------------------------------------------------------------------------------------------------------------------------------------*/
void PreecheMatrizTipoTarde(TipoTarde Tarde, TipoGrade grade, TipoCelulaClasse *erro, TipoCelulaClasse *vazia);

/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------

Protótipo: void PreecheMatrizTipoNoite(TipoNoite Noite, TipoGrade grade, TipoCelulaClasse *erro, TipoCelulaClasse *vazia);
Função: Preenche a posição que uma se matéria se encontrada, se houver conflito, é mostrado ERR
Entrada: Uma matriz do TipoNoite, a grade contendo as aulas, uma célula que aponta para erro e outra para posição vazia
Saída: Nenhuma

-----------------------------------------------------------------------------------------------------------------------------------------------------------------*/
void PreecheMatrizTipoNoite(TipoNoite Noite, TipoGrade grade, TipoCelulaClasse *erro, TipoCelulaClasse *vazia);


#endif /* COLISION_LISTS_H_ */
