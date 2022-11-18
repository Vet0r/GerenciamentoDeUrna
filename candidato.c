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
char idUrna[12];
void clearCodUrna(){
    memset(idUrna,0,strlen(idUrna));
}
struct candidato* criarCandidato(){
    struct candidato * cand = (struct candidato*) malloc(sizeof(struct candidato));
    cand->proximo = NULL;
    cand->anterior = NULL;
    return cand;
}

struct candidato * getData(char *Urna){
    if (idUrna[0]=='\0'){
        strcat(Urna, ".txt");
        strcpy(idUrna,Urna);
    } 
    char linha[80];
    FILE *banco = fopen(idUrna,"r");

    struct candidato *lista=NULL;
    struct candidato *aux =NULL;
    BOOL isFirst=TRUE;
    while (fgets(linha, 80, banco) != NULL){    
        if (isFirst==TRUE){
            lista = criarCandidato();
        }                         
        sscanf(linha,"Nome: %s\tIdade: %d\tNumero: %d\tPartido: %s\tVice: %s\tEstado: %s\n",&lista->nome,&lista->idade,&lista->numero,&lista->partido,&lista->vice,&lista->estado);           
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
        char nome[20];
        int idade;
        int numero;
        char partido[10];
        char vice[20];
        char estado[20];
        exibirAdicionarCandidato(&novo->nome, &novo->idade, &novo->numero, &novo->partido, &novo->vice, &novo->estado);

        if(*lista == NULL){
            *lista = novo;
        }
        else if(novo->nome[0] < (*lista)->nome[0]){
            novo->proximo = *lista;
            (*lista)->anterior = novo;
            *lista = novo;
        }
        else{
           aux = *lista;
            while(aux->proximo && novo->nome[0] > aux->proximo->nome[0])
                aux = aux->proximo;
            novo->proximo = aux->proximo;
            if(aux->proximo)
                aux->proximo->anterior = novo;
            novo->anterior = aux;
            aux->proximo = novo;
        }
    }
    else{
        exibirTeladeErro();
        printf("Erro ao alocar memoria!\nRetornando a tela inicial");
        system("pause");
        menuUrna(lista);
    }
    aux = (*lista);

    FILE *banco;
    banco = fopen(idUrna,"w");
    while (aux != NULL){
        fprintf(banco,"Nome: %s\tIdade: %d\tNumero: %d\tPartido: %s\tVice: %s\tEstado: %s\n",aux->nome,aux->idade,aux->numero,aux->partido,aux->vice,aux->estado);
        aux = aux->proximo;
    }
    fclose(banco);

    exibirTeladeSucesso();
    system("pause");
    system("cls");
    menuUrna(lista);
}

void removerCandidato(struct candidato **lista){
    struct candidato *aux=NULL;
    struct candidato *remover = NULL;
    int numeroRemover;
    numeroRemover = exibirRemoverCandidato();
    if(*lista){
        if((*lista)->numero == numeroRemover){
            remover = (*lista);
            (*lista) = remover->proximo;
            if(*lista){
                free((*lista)->anterior);
                (*lista)->anterior = NULL;
            }
        }
        else{
            aux = *lista;
            while(aux->proximo && aux->proximo->numero != numeroRemover){
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
    banco = fopen(idUrna,"w");
    aux=(*lista);
    while (aux != NULL){
        fprintf(banco,"Nome: %s\tIdade: %d\tNumero: %d\tPartido: %s\tVice: %s\tEstado: %s\n",aux->nome,aux->idade,aux->numero,aux->partido,aux->vice,aux->estado);
        aux = aux->proximo;
    }
    fclose(banco);
    system("cls");
    menuUrna(lista);
}

void buscarCandidato(struct candidato **lista){
    struct candidato *aux = NULL; 
    struct candidato *candidato = NULL;
    int numero;
    numero = exibirBuscarCandidato();

    aux = (*lista);
    while(aux && aux->numero != numero){
        aux = aux->proximo;   
    }
    if(aux){
        candidato = aux;
    }
    if (candidato){
        exibirCabecarioListarCandidatos();
        exibirListarCandidatos(candidato->nome, candidato->idade, candidato->numero, candidato->partido, candidato->vice, candidato->estado);
    }else{
        printf("O candidato não existe\n\n");
    }
    system("pause");
    menuUrna(lista);
}

void listarCandidatos(struct candidato *lista){
    lista = getData(idUrna); 
    struct candidato *aux = lista;
    exibirCabecarioListarCandidatos();
    while(aux){
        exibirListarCandidatos(aux->nome,aux->idade,aux->numero,aux->partido,aux->vice,aux->estado);
        aux = aux->proximo;
    }
    printf("\n\n");
    system("pause");
    system("cls");
    menuUrna(&lista);
}

void editarCandidato(struct candidato **lista){
    struct candidato *aux = NULL; 
    struct candidato *candidato = NULL;
    char nome[20];
    int idade;
    int numero;
    char partido[10];
    char vice[20];
    char estado[20];
    int n=0,i;
    numero = exibirBuscarCandidato();

    aux = *lista;
    while(aux && aux->numero != numero){
        aux = aux->proximo;   
        n++;
    }
    if(aux){
        candidato = aux;
    }
    aux=(*lista);
    if (candidato){
        int opcao=0;
        while (opcao<=0||opcao>=6){
            opcao=choseEditor();
        }
        exibirEditarCandidato(candidato->nome, candidato->idade, candidato->partido, candidato->vice, candidato->estado, opcao);
        for (i = 0; i < n; i++){
            (*lista)=(*lista)->proximo;
        }
        (*lista)=aux;
        
        FILE *banco;
        banco = fopen(idUrna,"w");
        aux=(*lista);
        while (aux != NULL){
            fprintf(banco,"Nome: %s\tIdade: %d\tNumero: %d\tPartido: %s\tVice: %s\tEstado: %s\n",aux->nome,aux->idade,aux->numero,aux->partido,aux->vice,aux->estado);
            aux = aux->proximo;
        }
        fclose(banco);
    }else{
        exibirTeladeErro();
        printf("\t\tO candidadto não existe\t\t\n");
        system("pause");
    }
    
    menuUrna(lista);
}

void localizarUrna(Candidato **lista){
    //exibirLocalizacaoUrna(*u->candidatos->estado);
    exibirLocalizacaoUrna((*lista)->estado);
    system("cls");
    menuUrna(lista);
}

