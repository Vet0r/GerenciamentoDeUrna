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
        sscanf(linha,"Nome: %s\tIdade: %d\tNumero: %d\tPartido: %s\tVice: %s\tEstado: %s\n",lista->nome,lista->idade,lista->numero,lista->partido,lista->vice,lista->estado);           
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
        printf("Digite o nome do Candidato: ");
        scanf("%20s",&nome);
        printf("Digite o numero do Candidato: ");
        scanf("%d",&numero);
        printf("Digite a idade do Candidato: ");
        scanf("%d",&idade);
        printf("Digite o partido do Candidato: ");
        scanf("%s",&partido);
        printf("Digite o nome do vice do Candidato: ");
        scanf("%20s",&vice);
        printf("Digite a sigla do estado do Candidato: ");
        scanf("%4s",&estado);

        strcpy(novo->nome,nome);
        novo->numero=numero;
        novo->idade = idade;
        strcpy(novo->partido,partido);
        strcpy(novo->vice,vice);
        strcpy(novo->estado,estado);

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
        fprintf(banco,"Nome: %s\tIdade: %d\tNumero: %d\tPartido: %s\tVice: %s\tEstado: %s\n",aux->nome,aux->idade,aux->numero,aux->partido,aux->vice,aux->estado);
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
    banco = fopen("banco.txt","w");
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
    printf("Digie o numero a ser buscado: ");
    scanf("%d", &numero);

    aux = (*lista);
    while(aux && aux->numero != numero){
        aux = aux->proximo;   
    }
    if(aux){
        candidato = aux;
    }
    if (candidato){
        printf("candidato %d\n\n",candidato->numero);
    }else{
        printf("O candidato não existe\n\n");
    }
    system("pause");
    menuUrna(lista);
}

void listarCandidatos(struct candidato *lista){
    lista = getData(); 
    struct candidato *aux = lista;
    exibirCabecarioListarCandidatos();
    while(aux){
       // char *nome,int idade,int numero,char *partido,char *vice,char *estado
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
    int numero;
    int idade;
    int n=0,i;
    printf("digite o numero do candidato que deseja editar:");
    scanf("%d",&numero);

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
        printf("Digite a idade do coandidato: ");
        scanf("%d",&idade);
        for (i = 0; i < n; i++){
            (*lista)=(*lista)->proximo;
        }
        (*lista)->idade = idade;
        (*lista)=aux;
        
        FILE *banco;
        banco = fopen("banco.txt","w");
        aux=(*lista);
        while (aux != NULL){
            fprintf(banco,"Nome: %s\tIdade: %d\tNumero: %d\tPartido: %s\tVice: %s\tEstado: %s\n",aux->nome,aux->idade,aux->numero,aux->partido,aux->vice,aux->estado);
            aux = aux->proximo;
        }
        fclose(banco);
    }else{
        printf("O candidadto não existe\n");
        system("pause");
    }
    
    menuUrna(lista);
}

