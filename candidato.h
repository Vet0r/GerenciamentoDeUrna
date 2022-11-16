#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct candidato Candidato;

Candidato* criarCandidato(void);
void inserirCandidato(Candidato **list);
Candidato* removerCandidato(Candidato **lista, int numero);
Candidato* buscarCandidato(Candidato **lista, int numero);
void listarCandidatos(Candidato *candidato);
Candidato* editarCandidato(Candidato **lista, int numero,int idade);