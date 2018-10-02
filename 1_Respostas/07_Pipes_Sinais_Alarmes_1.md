1. Quantos pipes serão criados após as linhas de código a seguir? Por quê?

(a)
```C
int pid;
int fd[2];
pipe(fd);
pid = fork();
```
> É criado um pipe: buffer de comunicação fifo entre um processo pai e um processo filho.
(b)
```C
int pid;
int fd[2];
pid = fork();
pipe(fd);
```
> É criada a primitiva pipe apenas após a duplicação dos processos. Como a execução dos comenados de um programa em C se dá de forma sequencial, o pipe fica disponível apenas para um dos processos, ão sendo possível a comunicação entre os processos.

2. Apresente mais cinco sinais importantes do ambiente Unix, além do `SIGSEGV`, `SIGUSR1`, `SIGUSR2`, `SIGALRM` e `SIGINT`. Quais são suas características e utilidades?
> SIGKILL: para eleminar os processos

> SIGCLD: enviado por um processo-pai para relatar o encerramento de um processo-filho.

> SIGBUS: indica erro no barramento

> SIGFPE: relacionado ao uso de números floar point (ponto flutuante), relatando uso em formato ilegal ou erro de cálculo.

> SIGTERM: indica a terminação de modo normal de um processo.

3. Considere o código a seguir:

```C
#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void tratamento_alarme(int sig)
{
	system("date");
	alarm(1);
}

int main()
{
	signal(SIGALRM, tratamento_alarme);
	alarm(1);
	printf("Aperte CTRL+C para acabar:\n");
	while(1);
	return 0;
}
```

Sabendo que a função `alarm()` tem como entrada a quantidade de segundos para terminar a contagem, quão precisos são os alarmes criados neste código? De onde vem a imprecisão? Este é um método confiável para desenvolver aplicações em tempo real?
