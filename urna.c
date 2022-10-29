#include <stdio.h>
#include <stdlib.h>
#include "urna.h"
#include "utils/utils.h"
#include "screens/screens.h"

struct urna {
    int idUrna; 
    int numeroDeCandidatos;
    char candidatos;
    int votos;
};

void menuUrna(){
    int opcao=exibirMenu();
    switch (opcao){
    case 1:
        /* Adicionar Candidato */
        break;
    case 2:
        /* Remover Candidato */
        break;
    case 3:
        /* Listar candidatos cadastrados */
        break;
    case 4:
        /* Buscar candidato */
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
        menuUrna();
        break;
    }
}