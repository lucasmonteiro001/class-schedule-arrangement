/*
 * general_lists.c
 *
 *  Created on: Apr 15, 2013
 *      Author: lucas
 */
#include "general_lists.h"


void ImprimeDiaSemana(int dia) {

	switch (dia) {
	case Domingo:
		printf("Dom\t");
		break;
	case Segunda:
		printf("2a\t");
		break;
	case Terca:
		printf("3a\t");
		break;
	case Quarta:
		printf("4a\t");
		break;
	case Quinta:
		printf("5a\t");
		break;
	case Sexta:
		printf("6a\t");
		break;
	case Sabado:
		printf("Sab\t");
		break;
	default:
		printf("\nNão existe este dia!\n");
	}
}

/*-----------------------------------------------------------------------------------------------------------------------------------------*/
/*
 * Funções específicas para lista e célula do TipoHorario
 */
/*-----------------------------------------------------------------------------------------------------------------------------------------*/

void PreencheParametrosHorarios(TipoCelulaHorario *horario, char *linha) {
	horario->itemHorario.dia = (int) (atoi(linha) / 100);
	horario->itemHorario.turno = ((int) (atoi(linha) / 10) % 10);
	horario->itemHorario.ordem = (int) (atoi(linha) % 10);
}

void FLHorarioVazia(TipoListaHorario *Lista) {
	Lista->Primeiro = (TipoCelulaHorario *) malloc(sizeof(TipoCelulaHorario));
	Lista->Ultimo = Lista->Primeiro;
	Lista->Primeiro->Prox = NULL;
}

int LHorarioVazia(TipoListaHorario Lista) {
	return (Lista.Primeiro == Lista.Ultimo);
}

void InsereHorario(TipoCelulaHorario horario, TipoListaHorario *Lista) {
	Lista->Ultimo->Prox = (TipoCelulaHorario *) malloc(sizeof(TipoCelulaHorario));
	Lista->Ultimo = Lista->Ultimo->Prox;
	Lista->Ultimo->itemHorario = horario.itemHorario;
	Lista->Ultimo->Prox = NULL;
}

void ImprimeHorario(TipoListaHorario Lista) {
	TipoCelulaHorario *Aux;
	int i = 0;
	Aux = Lista.Primeiro->Prox;
	while (Aux != NULL ) {
		printf("%d%d%d", Aux->itemHorario.dia, Aux->itemHorario.turno, Aux->itemHorario.ordem);
		i++;
		Aux = Aux->Prox;
		if(Aux  != NULL) printf(" ");
	}
}

/*-----------------------------------------------------------------------------------------------------------------------------------------*/
/*
 * Funções específicas para lista e célula do TipoDisciplina
 */
/*-----------------------------------------------------------------------------------------------------------------------------------------*/

void FLDisciplinaVazia(TipoListaDisciplina *Lista) {
	Lista->Primeiro = (TipoCelulaDisciplina *) malloc(sizeof(TipoCelulaDisciplina));
	Lista->Ultimo = Lista->Primeiro;
	Lista->Primeiro->Prox = NULL;
}

int LDisciplinaVazia(TipoListaDisciplina Lista) {
	return (Lista.Primeiro == Lista.Ultimo);
}

void InsereDisciplina(TipoCelulaDisciplina Disciplina, TipoListaDisciplina *Lista) {
	Lista->Ultimo->Prox = (TipoCelulaDisciplina *) malloc(sizeof(TipoCelulaDisciplina));
	Lista->Ultimo = Lista->Ultimo->Prox;
	strcpy(Lista->Ultimo->disciplina, Disciplina.disciplina);
	Lista->Ultimo->Prox = NULL;
}

void ImprimeListaDisciplinas(TipoListaDisciplina listaDisc) {
	TipoCelulaDisciplina *Aux;
	Aux = listaDisc.Primeiro->Prox;
	while(Aux != NULL) {
		printf(" %s", Aux->disciplina);
		Aux = Aux->Prox;
	}
	printf("\n");
}
