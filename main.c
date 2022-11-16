#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#include "urna.h"


int main(){
    UINT CPAGE_UTF8 = 65001;
    SetConsoleOutputCP(CPAGE_UTF8);
    Urna *Ur;
    menuUrna();
    return 0;
}