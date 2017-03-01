/*
 * colision_lists.c
 *
 *  Created on: Apr 15, 2013
 *      Author: lucas
 */
#include "colision_lists.h"

/*-----------------------------------------------------------------------------------------------------------------------------------------*/
/*
 * Funções específicas para lista e célula do TipoDocente
 */
/*-----------------------------------------------------------------------------------------------------------------------------------------*/

void FLColisaoDocentesVazia(TipoListaColisaoDocentes *Lista) {
	Lista->Primeiro = (TipoCelulaColisaoDocentes *) malloc(sizeof(TipoCelulaColisaoDocentes));
	Lista->Ultimo = Lista->Primeiro;
	Lista->Primeiro->Prox = NULL;
}

int LColisaoDocentesVazia(TipoListaColisaoDocentes Lista) {
	return(Lista.Primeiro == Lista.Ultimo);
}

void InsereColisaoDocentes(TipoCelulaColisaoDocentes docente, TipoListaColisaoDocentes *Lista) {
	Lista->Ultimo->Prox = (TipoCelulaColisaoDocentes *) malloc(sizeof(TipoCelulaColisaoDocentes));
	Lista->Ultimo = Lista->Ultimo->Prox;
	strcpy(Lista->Ultimo->professor, docente.professor);
	Lista->Ultimo->horarios = docente.horarios;
	Lista->Ultimo->Prox = NULL;
}

/*-----------------------------------------------------------------------------------------------------------------------------------------*/
/*
 * Funções específicas para lista e célula do TipoEspacoFisico
 */
/*-----------------------------------------------------------------------------------------------------------------------------------------*/

void FLColisaoEspacoFisicoVazia(TipoListaColisaoEspacoFisico *Lista) {
	Lista->Primeiro = (TipoCelulaColisaoEspacoFisico *) malloc(sizeof(TipoCelulaColisaoEspacoFisico));
	Lista->Ultimo = Lista->Primeiro;
	Lista->Primeiro->Prox = NULL;
}

int LColisaoEspacoFisicoVazia(TipoListaColisaoEspacoFisico Lista) {
	return (Lista.Primeiro == Lista.Ultimo);
}

void InsereColisaoEspacoFisico(TipoCelulaColisaoEspacoFisico sala, TipoListaColisaoEspacoFisico *Lista) {
	Lista->Ultimo->Prox = (TipoCelulaColisaoEspacoFisico *) malloc(sizeof(TipoCelulaColisaoEspacoFisico));
	Lista->Ultimo = Lista->Ultimo->Prox;
	Lista->Ultimo->sala = sala.sala;
	Lista->Ultimo->horarios = sala.horarios;
	Lista->Ultimo->Prox = NULL;
}

/*-----------------------------------------------------------------------------------------------------------------------------------------*/
/*
 * Funções específicas para lista e célula do TipoHorario
 */
/*-----------------------------------------------------------------------------------------------------------------------------------------*/

void FLColisaoHorarioVazia(TipoListaColisaoHorario *Lista) {
	Lista->Primeiro = (TipoCelulaColisaoHorario *) malloc(sizeof(TipoCelulaColisaoHorario));
	Lista->Ultimo = Lista->Primeiro;
	Lista->Primeiro->Prox = NULL;
}

int LColisaoHorarioVazia(TipoListaColisaoHorario Lista) {
	return (Lista.Primeiro == Lista.Ultimo);
}

void InsereColisaoHorario(TipoCelulaColisaoHorario horario, TipoListaColisaoHorario *Lista) {
	Lista->Ultimo->Prox = (TipoCelulaColisaoHorario *) malloc(sizeof(TipoCelulaColisaoHorario));
	Lista->Ultimo = Lista->Ultimo->Prox;
	Lista->Ultimo->periodo = horario.periodo;
	Lista->Ultimo->horario = horario.horario;
	Lista->Ultimo->disciplinas = horario.disciplinas;
	Lista->Ultimo->Prox = NULL;
}

int ExisteHorarioManha(int dia, int ordem, int turno, TipoGrade grade, TipoListaDisciplina *listaDisciplina, TipoListaColisaoHorario *listaColisaoHorario) {
	int i, j = 0;
	TipoCelulaHorario *Aux;
	TipoGrade *Aux_Colisao_Sala;
	int contaExistenciasMesmoHorario = 0;
	int cont_i = 0, cont_j = 0;

	TipoCelulaDisciplina disciplina;
	TipoCelulaColisaoHorario colisaoHorario;
	TipoCelulaColisaoEspacoFisico colisaoSala;


	for(i = 0; i < tamanho_vetor_grade; i++) {
		Aux = grade[i]->itemClasse.horarios.Primeiro->Prox;
		while (Aux != NULL ) {
			if(Aux->itemHorario.turno == turno && Aux->itemHorario.dia == dia && Aux->itemHorario.ordem == ordem) {
				contaExistenciasMesmoHorario++;
				if(contaExistenciasMesmoHorario == 1) {
					j = i;// Guarda a posição da classe que contém o horário
				}
				else if(contaExistenciasMesmoHorario > 1) {
					if(contaExistenciasMesmoHorario == 2) {
						strcpy(disciplina.disciplina, grade[j]->itemClasse.disciplina);
						InsereDisciplina(disciplina, listaDisciplina);
						//Agora verifica colisão de sala

						//Se as salas dos dois primeiros são iguais
					}

					strcpy(disciplina.disciplina, grade[i]->itemClasse.disciplina);
						InsereDisciplina(disciplina, listaDisciplina);
					j = i;
				}

			}
			Aux = Aux->Prox;
		}
	}


	if(contaExistenciasMesmoHorario == 1) { // Se foi encontrado apenas um horário correspondente nas classes, retorna sua posição
		return j;
	}
	else if(contaExistenciasMesmoHorario > 1) {// Criação de uma célula de colisão, a qual conterá o horário
		TipoHorario horarioDeConflito;
		horarioDeConflito.dia = dia;
		horarioDeConflito.ordem = ordem;
		horarioDeConflito.turno = turno;

		colisaoHorario.disciplinas = *listaDisciplina;
		colisaoHorario.horario = horarioDeConflito;
		colisaoHorario.periodo = grade[j]->itemClasse.periodo;

		InsereColisaoHorario(colisaoHorario, listaColisaoHorario);
		FLDisciplinaVazia(listaDisciplina);

		return (-2);
	}

	return (-1);
}

void ImprimeColisaoHorario(TipoListaColisaoHorario Lista) {
	TipoCelulaColisaoHorario *Aux;
	Aux = Lista.Primeiro->Prox;
	while(Aux != NULL) {
		printf("%d %d%d%d", Aux->periodo, Aux->horario.dia, Aux->horario.turno, Aux->horario.ordem);
		ImprimeListaDisciplinas(Aux->disciplinas);
		Aux = Aux->Prox;
	}
}

/*-----------------------------------------------------------------------------------------------------------------------------------------*/
/*
 * Funções específicas para a alocação dos tipos Manha, Tarde e Noite
 */
/*-----------------------------------------------------------------------------------------------------------------------------------------*/
void ApontaParaCelulaVazia(TipoManha Manha, TipoTarde Tarde, TipoNoite Noite, TipoCelulaClasse *vazia) {
	int i = 0;
	int j = 0;

	for(i = 0; i < 9; i++) {
		for(j = 0; j < 7; j++) {
			Manha[i][j] = vazia;
			Tarde[i][j] = vazia;
			Noite[i][j] = vazia;
		}
	}
}

void PreecheMatrizTipoManha(TipoManha Manha, TipoGrade grade, TipoCelulaClasse *erro, TipoCelulaClasse *vazia) {
	int i = 0;
	int j = 0;printf("\n\nManhã\n\n");
	int aux = 0;

	TipoListaDisciplina listaDisciplina;
	FLDisciplinaVazia(&listaDisciplina);// Lista das disciplinas que estão em colisão em um determinado horário

	TipoListaColisaoHorario listaColisaoHorario;
	FLColisaoHorarioVazia(&listaColisaoHorario);


	for(i = 0; i < 9; i++) {
		for(j = 0; j < 7; j++) {
			aux = ExisteHorarioManha(j + 1, i + 1, 1, grade, &listaDisciplina, &listaColisaoHorario);

			if(!(LDisciplinaVazia(listaDisciplina))) {// Se a lista de disciplinas que veio do callback da função ExisteHorarioManha() estiver cheia,
												  //quer dizer que há inconsistências, então imprime-se a colisão
				printf("\n\n=====\n\n");
			}

			if(aux != -1 && aux != -2) // Se horário pertence a grade, porém é único
				Manha[i][j] = grade[aux];

			else if(aux == -2)// Se horário aparece mais de duas vezes
				Manha[i][j] = erro;

		}
	}

	printf("\t"); for(i = 0; i < 7; i++) ImprimeDiaSemana(i+1); printf("\n");

	for(i = 0; i < 9; i++) { printf("%d\t", i + 1);
		for(j = 0; j < 7; j++)
			if(Manha[i][j] == erro)
				printf("ERR\t");
			else
				printf("%s\t", Manha[i][j]->itemClasse.disciplina);
		printf("\n");
	}printf("\n\n");

	ImprimeColisaoHorario(listaColisaoHorario);


}

void PreecheMatrizTipoTarde(TipoTarde Tarde, TipoGrade grade, TipoCelulaClasse *erro, TipoCelulaClasse *vazia) {
	int i = 0;
		int j = 0;printf("\n\nManhã\n\n");
		int aux = 0;

		TipoListaDisciplina listaDisciplina;
		FLDisciplinaVazia(&listaDisciplina);// Lista das disciplinas que estão em colisão em um determinado horário

		TipoListaColisaoHorario listaColisaoHorario;
		FLColisaoHorarioVazia(&listaColisaoHorario);


		for(i = 0; i < 9; i++) {
			for(j = 0; j < 7; j++) {
				aux = ExisteHorarioManha(j + 1, i + 1, 1, grade, &listaDisciplina, &listaColisaoHorario);

				if(!(LDisciplinaVazia(listaDisciplina))) {// Se a lista de disciplinas que veio do callback da função ExisteHorarioManha() estiver cheia,
													  //quer dizer que há inconsistências, então imprime-se a colisão
					printf("\n\n=====\n\n");
					//FLDisciplinaVazia(&listaDisciplina);// Zera a lista de dsiciplinas para possível próximo preenchimento
				}

				if(aux != -1 && aux != -2) // Se horário pertence a grade, porém é único
					Tarde[i][j] = grade[aux];

				else if(aux == -2)// Se horário aparece mais de duas vezes
					Tarde[i][j] = erro;

			}
		}

		printf("\t"); for(i = 0; i < 7; i++) ImprimeDiaSemana(i+1); printf("\n");

		for(i = 0; i < 9; i++) { printf("%d\t", i + 1);
			for(j = 0; j < 7; j++)
				if(Tarde[i][j] == erro)
					printf("ERR\t");
				else
					printf("%s\t", Tarde[i][j]->itemClasse.disciplina);
			printf("\n");
		}printf("\n\n");

		ImprimeColisaoHorario(listaColisaoHorario);

}

void PreecheMatrizTipoNoite(TipoNoite Noite, TipoGrade grade, TipoCelulaClasse *erro, TipoCelulaClasse *vazia) {
	int i = 0;
		int j = 0;printf("\n\nManhã\n\n");
		int aux = 0;

		TipoListaDisciplina listaDisciplina;
		FLDisciplinaVazia(&listaDisciplina);// Lista das disciplinas que estão em colisão em um determinado horário

		TipoListaColisaoHorario listaColisaoHorario;
		FLColisaoHorarioVazia(&listaColisaoHorario);


		for(i = 0; i < 9; i++) {
			for(j = 0; j < 7; j++) {
				aux = ExisteHorarioManha(j + 1, i + 1, 1, grade, &listaDisciplina, &listaColisaoHorario);

				if(!(LDisciplinaVazia(listaDisciplina))) {// Se a lista de disciplinas que veio do callback da função ExisteHorarioManha() estiver cheia,
													  //quer dizer que há inconsistências, então imprime-se a colisão
					printf("\n\n=====\n\n");
					//FLDisciplinaVazia(&listaDisciplina);// Zera a lista de dsiciplinas para possível próximo preenchimento
				}

				if(aux != -1 && aux != -2) // Se horário pertence a grade, porém é único
					Noite[i][j] = grade[aux];

				else if(aux == -2)// Se horário aparece mais de duas vezes
					Noite[i][j] = erro;

			}
		}

		printf("\t"); for(i = 0; i < 7; i++) ImprimeDiaSemana(i+1); printf("\n");

		for(i = 0; i < 9; i++) { printf("%d\t", i + 1);
			for(j = 0; j < 7; j++)
				if(Noite[i][j] == erro)
					printf("ERR\t");
				else
					printf("%s\t", Noite[i][j]->itemClasse.disciplina);
			printf("\n");
		}printf("\n\n");

		ImprimeColisaoHorario(listaColisaoHorario);

}
