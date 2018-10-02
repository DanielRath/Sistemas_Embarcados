1. Considerando a biblioteca-padrão da linguagem C, responda:

(a) Quais são as funções (e seus protótipos) para abrir e fechar arquivos?
> fopen:abrir (abre o arquivo direcionado pelo ponteiro, em um determinado modo)  F

> FILE *fopen(const char *filename, const char *mode)
 
 > close: fechar
 
 > int fclose(FILE *stream)

(b) Quais são as funções (e seus protótipos) para escrever em arquivos?
> fscanf

> size_t fwrite(const void *ptr, size_t size, size_t nmemb, FILE *stream)
> ptr: ponteiro do arquivo a ser lido; size: tamanho em bytes de cada elemento a ser lido; stream: "ponteiro para um objeto FILE que especifica um fluxo de saída"

(c) Quais são as funções (e seus protótipos) para ler arquivos?
>fread

> size_t fread (void * ptr, size_t tamanho, size_t nmemb, FILE * stream)

(d) Quais são as funções (e seus protótipos) para reposicionar um ponteiro para arquivo?
> fseek 

> int fseek(FILE *stream, long int offset, int whence)

> stream: ponteiro para um objeto que identifica o fluxo; offset: numero de bytes a ser deslocado; whence: é a posição onde o descolamento é adcionado, sedo especificada por uma das seguintes constantes: seek_set (início), seek_cur (posição atual do arquivo), seek_end (fim do arquivo)

(e) Quais bibliotecas devem ser incluídas no código para poder utilizar as funções acima?
> stdio.h

2. O que é a norma POSIX?
> A norma POSIX (Portable Operating System Interface) é um padrão para a compatibilidade de comandos entre sistemas operacionais, que define uma interface de aplicações comuns a eles, para possibilitar a portabilidade de um código fonte de um programa de um sistema para outro.

3. Considerando a norma POSIX, responda:

(a) Quais são as funções (e seus protótipos) para abrir e fechar arquivos?
> open: para abrir

> (fildes=) int open(const char* path, int oflag, …)

> path: caminho do arquivo, oflag: modo de abertura

> close: para fechar

> int close(int fildes)

> fildes: descritor do arquivo (nome)


(b) Quais são as funções (e seus protótipos) para escrever em arquivos?
> write

> ssize_t write(int fildes, const void *buf, size_t nbyte)

> ssize_t: número de bytes a serem lidos (EOF=0, Error=-1); *buf = endereço do buffer; nbytes: número de bytes a serem escritos

(c) Quais são as funções (e seus protótipos) para ler arquivos?
> read

> ssize_t read(int fildes, void *buf, size_t nbyte);

(d) Quais são as funções (e seus protótipos) para reposicionar um ponteiro para arquivo?
> lseek

> off_t lseek(int fd, off_t offset, int whence)

> off_t: offset (-1 se der erro), offset: valor da compensação - reposicionamento do ponteiro; whence: é a posição onde o descolamento é adcionado, sedo especificada por uma das seguintes constantes: seek_set (início), seek_cur (posição atual do arquivo), seek_end (fim do arquivo)

(e) Quais bibliotecas devem ser incluídas no código para poder utilizar as funções acima?
> fcntl.h;	unistd.h	


Referência Bibliográfica: https://www.tutorialspoint.com/c_standard_library/stdio_h.htm
