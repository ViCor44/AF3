#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include "header.h"

int main()
{
	Configtela();
    remove_scrollbar();
    InserirComando();
    system("pause >nul");
    release();
    return 0;
}
