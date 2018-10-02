1. Como se utiliza o comando `ps` para:

(a) Mostrar todos os processos rodando na máquina?
> $ ps -ef

(b) Mostrar os processos de um usuário?
> $ ps -f -u nome_do_usuario 

(c) Ordenar todos os processos de acordo com o uso da CPU?
> $ ps aux --sort=-pcpu

(d) Mostrar a quanto tempo cada processo está rodando?
> ps -e -o pid,comm,etime 

2. De onde vem o nome `fork()`?
> o nome `fork()` significa bifurcação. Se assemelha ao conceito de mitose: é criado um processo novo a partir do que está sendo rodado.

3. Quais são as vantagens e desvantagens em utilizar:

(a) `system()`? 
> É uma função da biblioteca stdlib.h, permite criar um subprocesso por meio da execução de um comando dentro de um programa. Como sua execução depende de muito do sistema, ela não é muito recomendada. 

(b) `fork()` e `exec()`? 
> Para se criar um novo processo: função fork() cria uma cópia do processo atual e a função exec() substituiu o conteúdo do novo processo por um novo programa.

4. É possível utilizar o `exec()` sem executar o `fork()` antes?
> Sim, mas isso resultará na alteração do conteúdo de execução do processo atual sem a criação de um novo processo.

5. Quais são as características básicas das seguintes funções:

(a) `execp()`?
> Aceita que o nome ou procura do programa não contenha o caminho completo do programa a ser executado, aceita que esteja no current path.

(b) `execv()`?
> Aceita que a lista de argumentos do programa a ser criado seja nula.
```
Macete para memorizar: provide	 an  array  ofpointers	 to  null-terminated  strings that represent the argument lista(v)ailable to the new  program)
```     

(c) `exece()`?
> A função aceita um argumento adicional.

(d) `execvp()`?
> Aceita que o programa a ser criado tenha uma lista nula de argumentos e que esteja no caminho atual (current path) e que 

(e) `execve()`?
> Aceita que o programa a ser criado tenha uma lista nula de argumento e que aceita um argumento adicional.

(f) `execle()`?
````
A função execle especifica também o ambiente do processo executado através de um parâmetro
adicional  que  vem  depois do ponteiro NULL que termina a lista de argumentos na lista de
parâmetros ou depois do ponteiro para o vetor argv.
````

Referência Bibliográfica: 
````
https://www.hostinger.com.br/tutoriais/como-gerenciar-processos-no-linux-usando-linha-de-comando/
http://manpages.ubuntu.com/manpages/bionic/pt/man3/exec.3.html
````
