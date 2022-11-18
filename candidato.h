#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct candidato Candidato;

Candidato* criarCandidato(void);
Candidato * getData(char *Urna);
void clearCodUrna();
void inserirCandidato(Candidato **list);
void removerCandidato(Candidato **lista);
void buscarCandidato(Candidato **lista);
void listarCandidatos(Candidato *candidato);
void editarCandidato(Candidato **lista);
void localizarUrna(Urna *u,Candidato **lista);