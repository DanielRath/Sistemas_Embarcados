#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int opcao;

//comandos importantes:
//ps -A
void opcao_invalida()
{
	        printf("\n-----------------------------------------------------------------------\n");  
                printf("\nEsta opção é inválida. Escolha uma opção válida.\n\n\n\n");
}

int escolha_opcao()
{
	scanf("%d", &opcao);
	printf("\n");
	printf("-----------------------------------------------------------------------\n"); 
	printf ("\nVocê escolheu a opção: %d\n", opcao);
	return opcao;
}

void ajustes()
{
	int teste_ajustes=1;
	while(teste_ajustes)
	{
		printf("\nAjustes de Captura\n");
		printf("-----------------------------------------------------------------------\n");        
        	printf("\nEscolha a opção desejada\n"); 
		printf("1- Velocidade do Obturador\n");
		printf("2- ISO\n");
		printf("3- Abertura do Diafragma\n");
		printf("4- Voltar ao Menu Principal\n");
		printf("\n");
		escolha_opcao();
		if (opcao<=4)
		{        
			switch(opcao)
			{
				case 1:
					system ("gphoto2 --get-config /main/capturesettings/shutterspeed");
					printf("\nEscolha a opção desejada\n"); 
					escolha_opcao();
					char string[]="gphoto2 --set-config /main/capturesettings/shutterspeed=";
					char opcao_char[4];
					sprintf(opcao_char, "%d", opcao);
					strcat(string, opcao_char);
					system (string);
					//system("gphoto2 --set-config /main/capturesettings/shutterspeed=52");
				break;
				case 2: 
					//inserir
				break;
				case 3: 
					//inserir
				break;
				case 4: 
					printf("\n");
					printf("Voltando ao Menu Principal\n");
					teste_ajustes=0;
					system("clear");
					}
		}
		else
		{
			opcao_invalida();
        	}
	}
	
}

void menu()
{
        int teste=1;
        system("clear");
	while(teste){
        printf("\nBem-vindo ao dispositivo Smart\n");
        printf("-----------------------------------------------------------------------\n");        
        printf("\nEscolha a opção desejada\n"); 
        printf("1- Tirar foto\n");
        printf("2- Importar fotos\n");
	printf("3- Ajustes de Captura\n");
        printf("4- Sair\n");
        escolha_opcao();
        if (opcao<=4){        
        switch(opcao)
{
                case 1:
                        //system ("gphoto2 --trigger-capture");
			system ("gphoto2 --capture-image-and-download");
                        printf("\nTirando foto\n");
			system ("clear");
			printf("Foto tirada\n");
                break;
                case 2: 
                        printf("\n");
                        system("cd ~/gphoto && gphoto2 --get-all-files --skip-existing");
			printf("\nImportando Imagens\n");
			system ("clear");
			printf("\nImagens Importadas\n");
                break;
		case 3: 
                        system ("clear");
                        ajustes();
                break;
                case 4: 
                        printf("\n");
                        printf("Saindo...\n");
                        teste=0;
			system("clear");
			printf("O programa foi encerrado\n");
        }}
        else{
		opcao_invalida();
        }
    }
}


int main (int argc, char *argv[])
{
	menu();
        return 0;
}

