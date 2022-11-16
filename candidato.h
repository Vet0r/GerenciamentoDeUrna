#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "candidato.c"

Candidato* criarCandidato(void);
void inserirCandidato(Candidato **lista, char valor[20]);
Candidato* removerCandidato(Candidato **lista, int numero);
Candidato* buscarCandidato(Candidato **lista, int numero);
void imprimirCandidatos(Candidato *candidato);
Candidato* editarCandidato(Candidato **lista, int numero,int idade);