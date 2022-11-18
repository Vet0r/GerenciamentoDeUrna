#include <stdio.h>
#include <stdlib.h>
#include "candidato.h"
#include "urna.h"
#include "utils/utils.h"
#include "screens/screens.h"

struct urna {
    int idUrna; 
    int numeroDeCandidatos;
    Candidato *candidatos;
    int votos;
};

void menuUrna(Candidato **lista){
    Urna u;
    u.candidatos=(*lista);

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
        editarCandidato(lista);
        break;
    case 6:
        localizarUrna(&u,lista);
        break;
    case 7:
        exit(0);
        break;
    default:
        menuUrna(lista);
        break;
    }
}