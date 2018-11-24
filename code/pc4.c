#include <stdio.h>
#include <stdlib.h>

int opcao;

//Msg pra a Pri:
//Ao abrir o terminal da rasp, dá o comando "mkdir gphoto",
// por favor?
//é para criarmos o diretório onde as imagens serão importadas


//to do list:


//comandos importantes:
//ps -A


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
        printf("3- Sair\n");
        printf("\n");
        scanf("%d", &opcao);
        printf("\n");
        printf("-----------------------------------------------------------------------\n"); 
        printf ("\nVocê escolheu a opção: %d\n", opcao);
        if (opcao<=3){        
        switch(opcao)
{
                case 1:
                        system ("gphoto2 --trigger-capture");
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
                        printf("\n");
                        printf("Saindo...\n");
                        teste=0;
			system("clear");
			printf("O programa foi encerrado\n");
        }}
        else{
        printf("\n-----------------------------------------------------------------------\n");  
                printf("\nEsta opção é inválida. Escolha uma opção válida.\nOpções válidas:\n1- Tirar foto\n2- Calendário\n\n\n\n");
        }
    }
}


int main (int argc, char *argv[])
{
	menu();
        return 0;
}

