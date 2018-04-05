1. Quais as diferen�as entre os barramentos de dados e de endere�os?
O barramento de dados � utilizado na transmiss�o de informa��es entre os dispositivos, j� o de endere�os � utilizado na sele��o da origem ou destino dos sinais transmitidos.

2. Quais s�o as diferen�as entre as mem�rias RAM e ROM?
O conceito da RAM consiste em uma mem�ria de acesso aleat�rio, que � vol�tio - quando h� perda da alimenta��o, perde-se tamb�m os dados. A ROM (Read-only memory), por outro lado, n�o � vol�til, entretanto apresenta uma escrita bem mais lenta.

3.Considere o c�digo abaixo:

#include <stdio.h>
int main(void)
{
	int i;
	printf("Insira um n�mero inteiro: ");
	scanf("%d", &i);
	if(i%2)
		printf("%d eh impar.\n");
	else
		printf("%d eh par.\n");
	return 0;
}
Para este c�digo, responda: (a) A vari�vel i � armazenada na mem�ria RAM ou ROM? Por qu�? (b) O programa compilado a partir deste c�digo � armazenado na mem�ria RAM ou ROM? Por qu�?
(a) � armazenada na mem�ria RAM, por devido � necessidade de alta velocidade para a escrita, e por ser vol�til.
(b) o programa compilado � armazenado na mem�ria ROM, visto que, ao desligar a alimenta��o e conect�-la novamente, h� a necessidade do programa ser encontrado novamente.


4. Quais s�o as diferen�as, vantagens e desvantagens das arquiteturas Harvard e Von Neumann?
A arquitetura Harvard � mais complexa, � geralmente RISC (�nfase no software) e apresenta como vantagem apresentar uma maior velocidade, pois permite o simult�neo acesso �s mem�rias.
A arquitetura Von Neuman � mais simples e � geralmente CISC (�nfase no hardware). Por n�o apresentar um acesso simult�neo �s mem�rias, � mais lenta, sendo essa sua principal desvantagem.

5. Considere a vari�vel inteira i, armazenando o valor 0x8051ABCD. Se i � armazenada na mem�ria a partir do endere�o 0x0200, como ficam este byte e os seguintes, considerando que a mem�ria �: (a) Little-endian; (b) Big-endian.
(a)CD AB 51 80
(b)80 51 AB CD

6. Sabendo que o processador do MSP430 tem registradores de 16 bits, como ele soma duas vari�veis de 32 bits?
Para serem realizadas opera��es com 32 bits, devem ser utilizados dois registradores: um armazenar� os dados dos 16 bits mais significativos e o outr do 16 menos significativos.