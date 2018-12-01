#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//teste
int opcao;
char opcao_char[4], string[70];

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
		printf("\nPor favor, coloque a camera em um dos modos manuais\n");
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
					strcpy(string,"gphoto2 --set-config /main/capturesettings/shutterspeed=");
					sprintf(opcao_char, "%d", opcao);
					strcat(string, opcao_char);
					system (string);
				break; 
				case 2: 
					system ("gphoto2 --get-config /main/imgsettings/iso");
					printf("\nEscolha a opção desejada\n"); 
					escolha_opcao();
					strcpy(string,"gphoto2 --set-config /main/imgsettings/iso=");
					sprintf(opcao_char, "%d", opcao);
					strcat(string, opcao_char);
					system (string);
				break;
				case 3: 
					system ("gphoto2 --get-config /main/capturesettings/aperture");
					printf("\nEscolha a opção desejada\n"); 
					escolha_opcao();
					strcpy(string,"gphoto2 --set-config /main/capturesettings/aperture=");
					sprintf(opcao_char, "%d", opcao);
					strcat(string, opcao_char);
					system (string);
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
        printf("1- Tirar e importar foto\n");
        //printf("2- Importar fotos\n");
	printf("2- Ajustes de Captura\n");
        printf("3- Sair\n");
        escolha_opcao();
        if (opcao<=4){        
        switch(opcao)
{
                case 1:
                        system ("gphoto2 --trigger-capture");
			sleep(1);
			system("cd ~/CanonT5i && gphoto2 --get-all-files --skip-existing");
                        printf("\nTirando foto\n");
			//system ("clear");
			printf("Foto tirada\n");
                break;
                /*case 2: 
                        printf("\n");
                        system("cd ~/CanonT5i && gphoto2 --get-all-files --skip-existing");
			printf("\nImportando Imagens\n"); //impoartar para pasta e importar para o drop
			system ("clear");
			printf("\nImagens Importadas\n");
                break;*/
		case 2: 
                        system ("clear");
                        ajustes();
                break;
                case 3: 
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

