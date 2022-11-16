#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#include "urna.h"
#include "candidato.h"


int main(){
    UINT CPAGE_UTF8 = 65001;
    SetConsoleOutputCP(CPAGE_UTF8);
    Candidato *lista=NULL;
    menuUrna(&lista);
    return 0;
}