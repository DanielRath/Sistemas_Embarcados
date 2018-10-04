1. Quais são as vantagens e desvantagens em utilizar:

(a) fork?
> Vantagens: A comunicação entre processos se dá por mecanimos IPC como pipes e sinais; o que minimiza o risco de corrupção dos dados. Cada processo-filho realiza suas tarefas em um espaço de memória protegido

> Desvantagens: A comunicação é mais complexa, visto que não há o compartilhamento do mesmo espaço de memória 

(b) threads?
> Vantagens: Por se usar memória compartilhada, a comunicação se dá de forma mais simples.

> Desvantagens: Há risco de serem corrompidos os dados, visto que a comunicação não se dá por mecanismos IPC.


2. Quantas threads serão criadas após as linhas de código a seguir? Quantas coexistirão? Por quê?

(a)

```C
void* funcao_thread_1(void *arg);
void* funcao_thread_2(void *arg);

int main (int argc, char** argv)
{
	pthread_t t1, t2; //criação do thread_id
	pthread_create(&t1, NULL, funcao_thread_1, NULL); //criação da thread t1
	pthread_create(&t2, NULL, funcao_thread_2, NULL); //criação da thread t2
	pthread_join(t1, NULL); //execução da thread t1
	pthread_join(t2, NULL); //execução da thread t2 após termino da execução da thread t1
	return 0;
}
```
> Serão criadas duas threads, sendo que ambas coexistirão até o final da execução da thread t1, visto que a função pthread_join() faz com que a próxima linha de código só seja executada após o termino da execução dessa thread.

(b)
```C
void* funcao_thread_1(void *arg);
void* funcao_thread_2(void *arg);

int main (int argc, char** argv)
{
	pthread_t t1, t2;
	pthread_create(&t1, NULL, funcao_thread_1, NULL);
	pthread_join(t1, NULL);
	pthread_create(&t2, NULL, funcao_thread_2, NULL);
	pthread_join(t2, NULL);
	return 0;
}
```
> Serão criadas duas threads, sendo que ambas não coexistirão, visto que a thread t2 só será criada pós o termino da execução da thread t1.

3. Apresente as características e utilidades das seguintes funções:

(a) `pthread_setcancelstate()`
> "altera o estado de cancelamento para o encadeamento de chamada - ou seja, se as solicitações de cancelamento são ignoradas ou não. O argumento de estado é o novo estado de cancelamento: PTHREAD_CANCEL_ENABLE para ativar o cancelamento ou PTHREAD_CANCEL_DISABLE para desativar o cancelamento (solicitações de cancelamento são ignoradas). Se oldstate não for NULL , o estado de cancelamento anterior é armazenado no local apontado por oldstate e, portanto , pode ser restaurado posteriormente por outra chamada para pthread_setcancelstate ."

(b) `pthread_setcanceltype()`
> "pthread_setcanceltype altera o tipo de respostas para pedidos de cancelamento para o encadeamento de chamada: assíncrono (imediato) ou adiado. O argumento de tipo é o novo tipo de cancelamento: PTHREAD_CANCEL_ASYNCHRONOUS para cancelar o encadeamento de chamada assim que a solicitação de cancelamento for recebida ou PTHREAD_CANCEL_DEFERRED para manter a solicitação de cancelamento pendente até o próximo ponto de cancelamento. Se oldtype não for NULL , o estado de cancelamento anterior será armazenado no local apontado por oldtype e, assim, poderá ser restaurado posteriormente por outra chamada para pthread_setcanceltype ."

> Fonte: https://sourceware.org/pthreads-win32/manual/pthread_cancel.html

(DICA: elas são relacionadas à função pthread_cancel().)

````
MUITO IMPORTANTE! para compilar códigos com thread: gcc (nome do arquivo.c) -lpthread

-lpthread: função para executar threads - não está presente na biblioteca padrão em c.
-A execução das threads não ocorrem necessariamente na ordem em que foi feito o programa; não há um sincronismo natural das threads.
- & nesse caso indica "endereço de".
````
