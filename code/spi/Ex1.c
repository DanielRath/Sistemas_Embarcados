#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <linux/spi/spidev.h>
#include <unistd.h>

int spi_fd;
void ctrl_c(int sig)
{
	close(spi_fd);
	exit(-1);
}

void SPI_Config(void)
{
	int mode;
	mode = 8;
	ioctl(spi_fd, SPI_IOC_WR_BITS_PER_WORD, &mode);
	mode = 500000;
	ioctl(spi_fd, SPI_IOC_WR_MAX_SPEED_HZ, &mode);
	ioctl(spi_fd, SPI_IOC_RD_MODE, &mode);
	printf("/dev/spidev0.0 aberto, e configurado como:\n   ");
	if(mode & SPI_NO_CS) printf("Sem chip select");
	else
	{
		printf("Com chip_select ativo em nivel ");
		if(mode & SPI_CS_HIGH) printf("alto");
		else printf("baixo");
	}
	printf("\n   Ordem de transmissao = ");
	if(mode & SPI_LSB_FIRST) printf("LSB->MSB");
	else printf("MSB->LSB");
	printf("\n   Estado inativo do clock em nivel ");
	if(mode & SPI_CPOL) printf("alto");
	else printf("baixo");
	printf("\n   Dados ");
	if(mode & SPI_CPHA)
	{
		printf("capturados na primeira borda do clock\n");
		printf("      e enviados na segunda borda");
	}
	else
	{
		printf("enviados na primeira borda do clock\n");
		printf("      e capturados na segunda borda");
	}
	ioctl(spi_fd, SPI_IOC_RD_BITS_PER_WORD, &mode);
	printf("\n   %d bits por transmissao", (mode&3)==0 ? 8 : (mode&3));
	ioctl(spi_fd, SPI_IOC_RD_MAX_SPEED_HZ, &mode);
	printf("\n   %d Hz\n\n",mode);
}

void SPI_Read_Write(int fd, unsigned char *data, int length)
{
	struct spi_ioc_transfer spi;
	memset (&spi, 0, sizeof (spi));
	spi.tx_buf        = (unsigned long)data;
	spi.rx_buf        = (unsigned long)data;
	spi.len           = length;
	spi.delay_usecs   = 0;
	spi.speed_hz      = 500000;
	spi.bits_per_word = 8;
	ioctl(fd, SPI_IOC_MESSAGE(1), &spi);
}

int main(void)
{
	unsigned char user_input=1, send_msp430;
	int mode;

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
