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
	unsigned char user_input=1, send_msp430;
	int i=0, soma=0;
	unsigned char d;
	
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
        wiringPiSPIDataRW(0, &d, 1);
        if (d == 0xAA);
        {
             usleep(100);
             d=0x01;
             wiringPiSPIDataRW(0, &d, 1);
             soma += d;
             d=0x02;
             wiringPiSPIDataRW(0, &d, d);
             soma += (d << 8); //"<<": realizar o deslocamento
             usleep(10000);//10ms = 10000us
        }
   soma=(soma+50/100); //somando metade do que estou dividindo: arredondar para cima. Ex.> se a variavel soma valesse 80, dividindo por 100, o valor da respoasta em inteiro seria 0
   printf("Media=%d\n", soma);
      }
	close(spi_fd);
    }    
}
