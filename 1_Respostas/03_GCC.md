Para todas as questões, compile-as com o gcc e execute-as via terminal.

1. Crie um "Olá mundo!" em C.

> Primeiramente, criou-se o arquivo olamundo.c :

```
#include <stdio.h>
int main (void)
{
	printf("Ola mundo! \n");
	return 0;
}

```

Para compilá-lo: 
gcc -o ola olamundo.c

Para executálo:
./ola

2. Crie um código em C que pergunta ao usuário o seu nome, e imprime no terminal "Ola " e o nome do usuário. Por exemplo, considerando que o código criado recebeu o nome de 'ola_usuario_1':

```bash
$ ./ola_usuario_1
$ Digite o seu nome: Eu
$ Ola Eu
```
```
#include <stdio.h>
int main (void)
{
	char nome[15];
	printf("Digite o seu nome:");
	scanf("%s", nome);
	printf("Ola %s",nome);
	return 0;
}
```

3. Apresente os comportamentos do código anterior nos seguintes casos:

(a) Se o usuário insere mais de um nome.
```bash
$ ./ola_usuario_1
$ Digite o seu nome: Eu Mesmo
```
> É apresentado como saída final: Ola Eu

(b) Se o usuário insere mais de um nome entre aspas duplas. Por exemplo:
```bash
$ ./ola_usuario_1
$ Digite o seu nome: "Eu Mesmo"
```
> É apresentado como saída final: "Ola Eu

(c) Se é usado um pipe. Por exemplo:
```bash
$ echo Eu | ./ola_usuario_1
```

> É apresentado como saída final: Digite o seu nome: Ola Eu


(d) Se é usado um pipe com mais de um nome. Por exemplo:
```bash
$ echo Eu Mesmo | ./ola_usuario_1
```

> É apresentado como saída final: Digite o seu nome: Ola Eu | ou seja, só a primeira palavra foi apresentada


(e) Se é usado um pipe com mais de um nome entre aspas duplas. Por exemplo:
```bash
$ echo "Eu Mesmo" | ./ola_usuario_1
```
> É apresentado como saída final: Digite o seu nome: Ola Eu | ou seja, só a primeira palavra foi apresentada, sendo suprimida as aspas duplas que a antecedia

(f) Se é usado o redirecionamento de arquivo. Por exemplo:
```bash
$ echo Ola mundo cruel! > ola.txt
$ ./ola_usuario_1 < ola.txt
```
> É apresentado como saída final: Digite o seu nome: Ola Ola

4. Crie um código em C que recebe o nome do usuário como um argumento de entrada (usando as variáveis argc e *argv[]), e imprime no terminal "Ola " e o nome do usuário. Por exemplo, considerando que o código criado recebeu o nome de 'ola_usuario_2':

```bash
$ ./ola_usuario_2 Eu
$ Ola Eu
```

#include <stdio.h>
#include <stdlib.h>
int main (char argc, char *argv[])
//passagem de parâmetros através da linha de comando, quando o programa s$
//argc: é um valor inteiro que indica a quantidade de parâmetros passados
//argv: é um vetor char que contém os argumentos  
{
        printf("Ola %s",argv[argc-1]);
//argv[0]: apresenta as palavras a partir da primeira posição do vetor
        return 0;
}

>comandos executados no terminal:
gcc -o ola_usuario_2 ola_usuario_2.c

Resposta:
Ola Eu


5. Apresente os comportamentos do código anterior nos seguintes casos:

(a) Se o usuário insere mais de um nome.
```bash
$ ./ola_usuario_2 Eu Mesmo
```

>Resposta:
Ola Eu Mesmo

(b) Se o usuário insere mais de um nome entre aspas duplas. Por exemplo:
```bash
$ ./ola_usuario_2 "Eu Mesmo"
```

Resposta:
Ola Eu Mesmo | ou seja, é apresentado o conteúdo sem as aspas

(c) Se é usado um pipe. Por exemplo:
```bash
$ echo Eu | ./ola_usuario_2
```
>Resposta:
Ola ./ola_usuario_2 

(d) Se é usado um pipe com mais de um nome. Por exemplo:
```bash
$ echo Eu Mesmo | ./ola_usuario_2
```
>Resposta:
Ola ./ola_usuario_2 


(e) Se é usado um pipe com mais de um nome entre aspas duplas. Por exemplo:
```bash
$ echo "Eu Mesmo" | ./ola_usuario_2
```
>Resposta:
Ola ./ola_usuario_2 

(f) Se é usado o redirecionamento de arquivo. Por exemplo:
```bash
$ echo Ola mundo cruel! > ola.txt
$ ./ola_usuario_2 < ola.txt
```
>Resposta:
Ola ./ola_usuario_2 

6. Crie um código em C que faz o mesmo que o código da questão 4, e em seguida imprime no terminal quantos valores de entrada foram fornecidos pelo usuário. Por exemplo, considerando que o código criado recebeu o nome de 'ola_usuario_3':

```bash
$ ./ola_usuario_3 Eu
$ Ola Eu
$ Numero de entradas = 2
```

7. Crie um código em C que imprime todos os argumentos de entrada fornecidos pelo usuário. Por exemplo, considerando que o código criado recebeu o nome de 'ola_argumentos':

```bash
$ ./ola_argumentos Eu Mesmo e Minha Pessoa
$ Argumentos: Eu Mesmo e Minha Pessoa
```
```
#include <stdio.h>
#include <stdlib.h>
int main (int argc, char *argv[])
//passagem de parâmetros através da linha de comando, quando o programa s$
//argc: é um valor inteiro que indica a quantidade de parâmetros passados
//argv: é um vetor char que contém os argumentos  
{
        printf("Ola %s \n",argv[argc-1]);
//argv[0]: apresenta as palavras a partir da primeira posição do vetor
        printf("Numero de entradas = %d \n", argc); //deve apresentar um $
        return 0;
}
```

>Resposta:
Ola Eu 
Numero de entradas = 2 


8. Crie uma função que retorna a quantidade de caracteres em uma string, usando o seguinte protótipo:
`int Num_Caracs(char *string);` Salve-a em um arquivo separado chamado 'num_caracs.c'. Salve o protótipo em um arquivo chamado 'num_caracs.h'. Compile 'num_caracs.c' para gerar o objeto 'num_caracs.o'.

9. Re-utilize o objeto criado na questão 8 para criar um código que imprime cada argumento de entrada e a quantidade de caracteres de cada um desses argumentos. Por exemplo, considerando que o código criado recebeu o nome de 'ola_num_caracs_1':

```bash
$ ./ola_num_caracs_1 Eu Mesmo
$ Argumento: ./ola_num_caracs_1 / Numero de caracteres: 18
$ Argumento: Eu / Numero de caracteres: 2
$ Argumento: Mesmo / Numero de caracteres: 5
```

10. Crie um Makefile para a questão anterior.

11. Re-utilize o objeto criado na questão 8 para criar um código que imprime o total de caracteres nos argumentos de entrada. Por exemplo, considerando que o código criado recebeu o nome de 'ola_num_caracs_2':

```bash
$ ./ola_num_caracs_2 Eu Mesmo
$ Total de caracteres de entrada: 25
```

12. Crie um Makefile para a questão anterior.
