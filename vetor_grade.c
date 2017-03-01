/*
 * functions.c
 *
 *  Created on: Apr 13, 2013
 *      Author: lucas
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vetor_grade.h"

TipoGrade AlocaVetorGrade() {
	int i = 0;
	char palavra;
	tamanho_vetor_grade = 0;

	while (1) {
		palavra = fgetc(arqEntrada);
		if (palavra == '\n') {
			tamanho_vetor_grade++;
		} else if (palavra == EOF)
			break;
	}

	TipoGrade grade = (TipoCelulaClasse**) malloc(tamanho_vetor_grade * sizeof(TipoCelulaClasse*));
	for (i = 0; i < tamanho_vetor_grade; i++) {
		grade[i] = (TipoCelulaClasse*) malloc(sizeof(TipoCelulaClasse*));
	}

	fseek(arqEntrada, 0, SEEK_SET);

	return grade;
}

void PreencheVetorGrade(TipoGrade grade) {

	TipoCelulaClasse classe;
	TipoCelulaHorario horario;
	TipoListaHorario listaHorarios;
	FLHorarioVazia(&listaHorarios);

	char linha[1000];
	    //char *professor;
	    char c;
	    int i = 0, j = 0;

	    while((fscanf(arqEntrada, "%s", linha)) > 0) {
	        if(i == 0) {
	            classe.itemClasse.periodo = atoi(linha);
	        } else if(i == 1) {
	            strcpy(classe.itemClasse.disciplina, linha);
	        } else if(i == 2) {
	            classe.itemClasse.sala = atoi(linha);
	        } else if(i == 3) {
	            // Se o nome é único
	            if(linha[0] == '"' && linha[strlen(linha) - 1] == '"') {
	                classe.itemClasse.professor = (char *)malloc(sizeof(strlen(linha)));
	                strcat(classe.itemClasse.professor, linha);
	            }
	            // Se o nome é composto
	            else {
	                classe.itemClasse.professor = (char *)malloc(sizeof(strlen(linha)) + 2);
	                strcat(classe.itemClasse.professor, linha);
	                fscanf(arqEntrada, "%s", linha);
	                while(linha[strlen(linha) - 1] != '"') {
	                    classe.itemClasse.professor = (char *)realloc(classe.itemClasse.professor, strlen(classe.itemClasse.professor) + strlen(linha) + 2);
	                    strcat(classe.itemClasse.professor, " ");
	                    strcat(classe.itemClasse.professor, linha);
	                    fscanf(arqEntrada, "%s", linha);
	                }
	                classe.itemClasse.professor = (char *)realloc(classe.itemClasse.professor, strlen(classe.itemClasse.professor) + strlen(linha) + 2);
	                strcat(classe.itemClasse.professor, " ");
	                strcat(classe.itemClasse.professor, linha);
	                //printf("[%d]\t%s\n", strlen(classe.itemClasse.professor), classe.itemClasse.professor);
	            }
	            strcpy(classe.itemClasse.professor, classe.itemClasse.professor);

	        } else {
	            PreencheParametrosHorarios(&horario, linha);// Preenche dia, turno e ordem
	            InsereHorario(horario, &listaHorarios);// insere o horário na lista de horários
	        }
	        c = fgetc(arqEntrada);
	        if(c == '\n') {

	            classe.itemClasse.horarios = listaHorarios;

	            grade[j]->itemClasse = classe.itemClasse;
	            j++;

	            FLHorarioVazia(&listaHorarios);

	            i = -1;
	        }
	        i++;
	    }
}

void ImprimeVetorGrade(TipoGrade grade) {
	int i = 0;
	for(i = 0; i < tamanho_vetor_grade; i++) {
		printf("pos(%d)\nPeríodo:\t%d\nDisciplina:\t%s\nSala:\t\t%d\nProfessor:\t%s\nHorários:\t", i, grade[i]->itemClasse.periodo, grade[i]->itemClasse.disciplina, grade[i]->itemClasse.sala, grade[i]->itemClasse.professor);
		ImprimeHorario(grade[i]->itemClasse.horarios);
		if(i < tamanho_vetor_grade - 1) printf("\n\n");
	}
}

