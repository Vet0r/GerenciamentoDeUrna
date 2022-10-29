#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "../utils/utils.h"

int exibirMenu(){
    int opcao=0;
    printf("\n\t╔═════════════════════════════════════════════════════════════════════════════════════════╗");
    printf("\n\t║█████████████████████████████████████████████████████████████████████████████████████████║");
    printf("\n\t║█████████████████╔═════════════════════════════╗█████████████████████████████████████████║");
    printf("\n\t║█████████████████║   Gerenciamento de Urnas    ║█████████████████████████████████████████║");
    printf("\n\t║█████████████████╚═════════════════════════════╝█████████████████████████████████████████║");
    printf("\n\t║█████████████████████████████████████████████████████████████████████████████████████████║");
    printf("\n\t║███╔═══╗ ╔════════════════════════════════════════════════╗██████████████████████████████║");
    printf("\n\t║███║ 1 ║ ║               Adicionar Candidato              ║██████████████████████████████║");
    printf("\n\t║███╚═══╝ ╚════════════════════════════════════════════════╝██████████████████████████████║");
    printf("\n\t║███╔═══╗ ╔════════════════════════════════════════════════╗██████████████████████████████║");
    printf("\n\t║███║ 2 ║ ║               Remover Candidato                ║██████████████████████████████║");
    printf("\n\t║███╚═══╝ ╚════════════════════════════════════════════════╝██████████████████████████████║");
    printf("\n\t║███╔═══╗ ╔════════════════════════════════════════════════╗██████████████████████████████║");
    printf("\n\t║███║ 3 ║ ║         Listar candidatos cadastrados          ║██████████████████████████████║");
    printf("\n\t║███╚═══╝ ╚════════════════════════════════════════════════╝██████████╔═════════╗ ╔═══╗███║");
    printf("\n\t║███╔═══╗ ╔════════════════════════════════════════════════╗██████████║  OPÇÃO  ║ ║   ║███║");
    printf("\n\t║███║ 4 ║ ║               Buscar candidato                 ║██████████╚═════════╝ ╚═══╝███║");
    printf("\n\t║███╚═══╝ ╚════════════════════════════════════════════════╝██████████████████████████████║");
    printf("\n\t║███╔═══╗ ╔════════════════════════════════════════════════╗██████████████████████████████║");
    printf("\n\t║███║ 5 ║ ║               Editar candidato                 ║██████████████████████████████║");
    printf("\n\t║███╚═══╝ ╚════════════════════════════════════════════════╝██████████████████████████████║");
    printf("\n\t║███╔═══╗ ╔════════════════════════════════════════════════╗██████████████████████████████║");
    printf("\n\t║███║ 6 ║ ║        Consultar localização de uma urna       ║██████████████████████████████║");
    printf("\n\t║███╚═══╝ ╚════════════════════════════════════════════════╝██████████████████████████████║");
    printf("\n\t║███╔═══╗ ╔════════════════════════════════════════════════╗██████████████████████████████║");
    printf("\n\t║███║ 7 ║ ║                     Sair                       ║██████████████████████████████║");
    printf("\n\t║███╚═══╝ ╚════════════════════════════════════════════════╝██████████████████████████████║");
    printf("\n\t║█████████████████████████████████████████████████████████████████████████████████████████║");
    printf("\n\t╚═════════════════════════════════════════════════════════════════════════════════════════╝\n");
    gotoxy(93,16);
    scanf("%i",&opcao);
    system("cls");
    return opcao;
}
    