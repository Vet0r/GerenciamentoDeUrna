#include <windows.h>
#include "utils.h"

void gotoxy(int x, int y){//função que move o cursor para efeito visual
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),(COORD){x-1,y-1});
}   