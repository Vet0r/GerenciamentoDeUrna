#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "urna.h"
struct candidato {
    char nome[20];
    int idade;
    int numero;
    char partido[10];
    char vice[20];
    char estado[20];
    struct candidato *proximo;
    struct candidato *anterior;
};

int i;
struct candidato* criarCandidato(){
    struct candidato * cand = (struct candidato*) malloc(sizeof(struct candidato));
    cand->proximo = NULL;
    cand->anterior = NULL;
    return cand;
}

void inserirCandidato(struct candidato **lista){
     struct candidato *aux, *novo = malloc(sizeof(struct candidato));

    if(novo){
        int numero;
        printf("Digite o numero do candidato: ");
        scanf("%d",&numero);
        //strcpy(novo->numero,numero);
        novo->numero=numero;
        if(*lista == NULL){
            novo->proximo = NULL;
            novo->anterior = NULL;
            *lista = novo;
        }
        else if(novo->numero < (*lista)->numero){
            printf("meio");
            novo->proximo = *lista;
            (*lista)->anterior = novo;
            *lista = novo;
        }
        else{
            aux = *lista;
            while((aux->proximo && novo->numero) > (aux->proximo->numero)){
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
        printf("Erro ao alocar memoria!\nRetornando a tela inicial");
        for (i = 0; i < 3; i++)
        {
            Sleep(500);
            printf(".");
        }
        system("cls");
        menuUrna(lista);
    }
    printf("struct candidato alocado com sucesso!!! \nRetornando a tela inicial");
    for (i = 0; i < 3; i++)
    {
        Sleep(500);
        printf(".");
    }
    system("cls");
    menuUrna(lista);
}

struct candidato* removerCandidato(struct candidato **lista, int numero){
    struct candidato *aux=NULL;
    struct candidato *remover = NULL;

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

struct candidato* buscarCandidato(struct candidato **lista, int numero){
    struct candidato *aux = NULL; 
    struct candidato *candidato = NULL;

    aux = *lista;
    while((aux && aux->numero) != (numero)){
        aux = aux->proximo;   
    }
    if(aux){
        candidato = aux;
    }
    return candidato;
}

void listarCandidatos(struct candidato *lista){ 
    printf("\n\tLista: ");
    while(lista){
        printf("%d ", lista->numero);
        lista = lista->proximo;
    }
    printf("\n\n");
    printf("Pressione qualquer tecla para retornar ao menú");
    for (i = 0; i < 3; i++)
    {
        Sleep(500);
        printf(".");
    }
    system("cls");
    menuUrna(&lista);
}

struct candidato* editarCandidato(struct candidato **lista, int numero,int idade){
    struct candidato *aux = NULL; 
    struct candidato *candidato = NULL;

    aux = *lista;
    while((aux && aux->numero) != (numero)){
        aux = aux->proximo;   
    }
    if(aux){
        candidato = aux;
    }
    candidato->idade = idade;
    return candidato;
}

