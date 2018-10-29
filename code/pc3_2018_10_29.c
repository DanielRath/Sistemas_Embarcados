#include <stdio.h>
#include <stdlib.h>

int opcao;


//to do list:
//identify pid of process: "gvfsd-gphoto2" and kill;
//create infinite loop for menu

void iniciando()
{
	//teste
}

void menu()
{
	printf("Bem-vindo ao dispositivo Smart\n");
        printf("1- Tirar foto\n");      
        printf("Escolha a opção desejada\n");
        scanf("%d", &opcao);
        printf ("Você escolheu a opção: %d\n", opcao);
        switch(opcao)
        {
                case 1:
                        system ("gphoto2 --trigger-capture");
                        printf("Tirando foto\n");
                break;
        }
}


int main (int argc, char *argv[])
{
	iniciando();
	menu();
	
	return 0;
}
