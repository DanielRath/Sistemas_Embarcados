#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <wiringPi.h>
#include <wiringPiSPI.h>
#include <unistd.h>

// Este codigo requer a biblioteca wringPi. Compile-o usando
//    gcc Ex1.c -lwiringPi -o Ex1

int spi_fd;
void ctrl_c(int sig)
{
	close(spi_fd);
	exit(-1);
}


int main(void)
{
	unsigned char send_msp430;
	int i=0, soma=0, int d=0;
	
	signal(SIGINT, ctrl_c);
	if(wiringPiSetup() == -1)
	{
		puts("Erro em wiringPiSetup().");
		return -1;
	}
	spi_fd = wiringPiSPISetup (0, 500000);
	if(spi_fd==-1)
	{
		puts("Erro abrindo a SPI. Garanta que ela nao");
		puts("esteja sendo usada por outra aplicacao.");
		return -1;
	}
  while(1)
  {
     soma=0;
     for (i=0;i<100;i++);
     {
        d=0x55;
	     
	     
	     //não funciona a partir daqui: quando era para exibir o valor recebido está exibindo o valor enviado
	     send_msp430 = d; //alteração ainda não testada
	     //ver se funciona, ir alterando abaixo caso sim
        wiringPiSPIDataRW(0, &send_msp430, 1);
	     //para consertar: ateção ao len
	     //wiringPiSPIDataRW (int channel, unsigned char *data, int len) ; 
	     //channel: a rasp tem 2 canais spi (spi0 e spi1)
	     //len - length of characters in string
	     
	     
	     //duvida: a função manda um unsigned char, mas o msp está configurado para ler um inteiro 
	     //(se fosse um char o numero estaria entre aspas); seria isso a causa de problemas?
	     
	     printf("valor1=%d\n", send_msp430); //coloquei isso para teste
        if (send_msp430 == 0xAA)
        {
        
		usleep(100);
             send_msp430=0x01;
             wiringPiSPIDataRW(0, &send_msp430, 1);
		printf("valor2=%d\n", send_msp430); //coloquei isso para teste
             soma += send_msp430;
             send_msp430=0x02;
             wiringPiSPIDataRW(0, &send_msp430, send_msp430);
		printf("valor3=%d\n", send_msp430); //coloquei isso para teste
             soma += (send_msp430 << 8); //"<<": realizar o deslocamento
             usleep(10000);//10ms = 10000us
        }
   soma=(soma+50/100); //somando metade do que estou dividindo: arredondar para cima. Ex.> se a variavel soma valesse 80, dividindo por 100, o valor da respoasta em inteiro seria 0
   printf("Media=%d\n", soma);
      }
	close(spi_fd);
    }    
}
