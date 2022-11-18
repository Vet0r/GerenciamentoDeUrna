#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#include "urna.h"
#include "candidato.h"


int main(){
    UINT CPAGE_UTF8 = 65001;
    SetConsoleOutputCP(CPAGE_UTF8);
    system("cls");
    clearCodUrna();
    char Urna[12];
    printf("Digite o código da urna: ");
    scanf("%s",&Urna);
    Candidato *lista=getData(Urna);
    menuUrna(&lista);
    return 0;
}