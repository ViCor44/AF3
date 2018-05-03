#include<windows.h>
#include<stdio.h>
#include<stdlib.h>
#include "header.h"

int main(void){
	int i;	
	char comando[16];		
    Configtela();
    CriaLinha();
    gotoxy(2, 2);
    printf(" Insira comando: ");
	gets(comando);
	AnalisaTexto(comando);		
    system("pause >nul");
    return 0;
}
