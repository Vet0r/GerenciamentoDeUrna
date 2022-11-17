#include <stdio.h>
#include <stdlib.h>
#include "candidato.h"
#include "urna.h"
#include "utils/utils.h"
#include "screens/screens.h"

struct urna {
    int idUrna; 
    int numeroDeCandidatos;
    char candidatos;
    int votos;
};

void menuUrna(Candidato **lista){

    int opcao=exibirMenu();
    switch (opcao){
    case 1:
        inserirCandidato(lista);
        break;
    case 2:
        removerCandidato(lista);
        break;
    case 3:
        listarCandidatos(*lista);
        break;
    case 4:
        buscarCandidato(lista);
        break;
    case 5:
        /* Editar candidato */
        break;
    case 6:
        /* Consultar localização de uma urna */
        break;
    case 7:
        exit(0);
        break;
    default:
        menuUrna(lista);
        break;
    }
}