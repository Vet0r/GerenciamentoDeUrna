#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "candidato.h"

typedef struct candidato {
    char nome[20];
    int idade;
    int numero;
    char partido[10];
    char vice[20];
    char estado[20];
    struct candidato *proximo;
    struct candidato *anterior;
} Candidato;

Candidato* criarCandidato(void){
    Candidato * cand = (Candidato*) malloc(sizeof(Candidato));
    cand->proximo = NULL;
    cand->anterior = NULL;
    return cand;
}

void inserirCandidato(Candidato **lista, char valor[20]){
    Candidato *aux = malloc(sizeof(Candidato));
    Candidato *novo = malloc(sizeof(Candidato));

    if(novo){
        strcpy(novo->nome,valor);
        if(*lista == NULL){
            novo->proximo = NULL;
            novo->anterior = NULL;
            *lista = novo;
        }
        else if(novo->nome < (*lista)->nome){
            novo->proximo = *lista;
            (*lista)->anterior = novo;
            *lista = novo;
        }
        else{
            aux = *lista;
            while((aux->proximo && novo->nome) > (aux->proximo->nome)){
                aux = aux->proximo;
            }
            novo->proximo = aux->proximo;
            if(aux->proximo){
                aux->proximo->anterior = novo;
            }
            novo->anterior = aux;
            aux->proximo = novo;
        }
    }
    else{
        printf("Erro ao alocar memoria!\n");
    }
}

Candidato* removerCandidato(Candidato **lista, int numero){
    Candidato *aux=NULL;
    Candidato *remover = NULL;

    if(*lista){
        if((*lista)->numero == numero){
            remover = *lista;
            *lista = remover->proximo;
            if(*lista){
                (*lista)->anterior = NULL;
            }
        }
        else{
            aux = *lista;
            while(aux->proximo && aux->proximo->numero != numero){
                aux = aux->proximo;
            }
            if(aux->proximo){
                remover = aux->proximo;
                aux->proximo = remover->proximo;
                if(aux->proximo){
                    aux->proximo->anterior = aux;
                }
            }
        }
    }
    return remover;
}

Candidato* buscarCandidato(Candidato **lista, int numero){
    Candidato *aux = NULL; 
    Candidato *Candidato = NULL;

    aux = *lista;
    while((aux && aux->numero) != (numero)){
        aux = aux->proximo;   
    }
    if(aux){
        Candidato = aux;
    }
    return Candidato;
}

void imprimirCandidatos(Candidato *candidato){
    if (!candidato){
        printf("não há candidatos\n");
    }else{
        printf("\n\tLista: ");
        while(candidato){
            printf("%d ", candidato->nome);
            candidato = candidato->proximo;
        }
        printf("\n\n");
    }
}

Candidato* editarCandidato(Candidato **lista, int numero,int idade){
    Candidato *aux = NULL; 
    Candidato *Candidato = NULL;

    aux = *lista;
    while((aux && aux->numero) != (numero)){
        aux = aux->proximo;   
    }
    if(aux){
        Candidato = aux;
    }
    Candidato->idade = idade;
    return Candidato;
}

