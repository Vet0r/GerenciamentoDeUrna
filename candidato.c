#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "urna.h"
#include "candidato.h"
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

struct candidato * getData(){
    char linha[80];
    FILE *banco = fopen("banco.txt","r");

    struct candidato *lista=NULL;
    struct candidato *aux =NULL;
    BOOL isFirst=TRUE;
    while (fgets(linha, 80, banco) != NULL){    
        if (isFirst==TRUE){
            lista = criarCandidato();
        }                         
        sscanf(linha,"Numero: %d",&lista->numero);           
        lista->proximo=criarCandidato();  
        aux=lista;                  
        lista=lista->proximo;
        lista->anterior=aux;
        isFirst=FALSE;
    }
    if(lista!=NULL){
        lista=lista->anterior;
        free(lista->proximo);
        lista->proximo=NULL;
        while(lista->anterior){
            lista = lista->anterior;
        }
    }
    return (lista);
}

void inserirCandidato(struct candidato **lista){
     struct candidato *aux;
     struct candidato *novo = criarCandidato();

    if(novo){
        int numero;
        printf("Digite o numero do Candidato: ");
        scanf("%d",&numero);
        //strcpy(novo->numero,numero);
        novo->numero=numero;
        if(*lista == NULL){
            *lista = novo;
        }
        else if(novo->numero < (*lista)->numero){
            novo->proximo = *lista;
            (*lista)->anterior = novo;
            *lista = novo;
        }
        else{
           aux = *lista;
            while(aux->proximo && novo->numero > aux->proximo->numero)
                aux = aux->proximo;
            novo->proximo = aux->proximo;
            if(aux->proximo)
                aux->proximo->anterior = novo;
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
    aux = (*lista);

    FILE *banco;
    banco = fopen("banco.txt","w");
    while (aux != NULL){
        fprintf(banco,"Numero: %d \n",aux->numero);
        aux = aux->proximo;
    }
    fclose(banco);

    printf("Candidato criado com sucesso!!! \nRetornando a tela inicial");
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
    FILE *banco;
    banco = fopen("banco.txt","w");
    while (remover != NULL){
        fprintf(banco,"Numero: %d \n",remover->numero);
        remover = remover->proximo;
    }
    fclose(banco);
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
    lista = getData(); 
    struct candidato *aux = lista;
    printf("\n\tLista: ");
    while(aux){
        printf("%d ", aux->numero);
        aux = aux->proximo;
    }
    printf("\n\n");
    system("pause");
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

