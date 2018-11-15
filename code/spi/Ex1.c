#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <wiringPi.h>
#include <wiringPiSPI.h>
#include <unistd.h>

// Este codigo requer a biblioteca wringPi. Compile-o usando
//    gcc Ex2.c -lwiringPi -o Ex2.out

int spi_fd;
void ctrl_c(int sig)
{
	close(spi_fd);
	exit(-1);
}


int main(void)
{
	unsigned char user_input=1, send_msp430;
	int mode, soma, i;

	signal(SIGINT, ctrl_c);

	spi_fd = open("/dev/spidev0.0", O_RDWR);
	if(spi_fd==-1)
	{
		puts("Erro abrindo a SPI. Garanta que ela nao");
		puts("esteja sendo usada por outra aplicacao.");
		return -1;
	}
	SPI_Config();
  while(1)
  {
     soma=0;
     for (i=0;i<100;i++);
     {
        d=0x55;
        SPIRW(&d, 1);
        if (d == 0xAA);
        {
             usleep(100);
             d=0x01;
             SPI_RW(&d, 1);
             soma += d;
             d=0x02;
             SPI_RW(&d, d);
             soma += (d << 8); //"<<": realizar o deslocamento
             usleep(10000)//10ms = 10000us
        }
   soma=(soma+50/100); //somando metade do que estou dividindo: arredondar para cima. Ex.> se a variavel soma valesse 80, dividindo por 100, o valor da respoasta em inteiro seria 0
   printf("Media=%d\n", soma);
  }
	close(spi_fd);
}    
