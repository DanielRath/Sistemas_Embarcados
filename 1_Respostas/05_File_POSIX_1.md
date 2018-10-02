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

(e) Quais bibliotecas devem ser incluídas no código para poder utilizar as funções acima?

2. O que é a norma POSIX?

3. Considerando a norma POSIX, responda:

(a) Quais são as funções (e seus protótipos) para abrir e fechar arquivos?

(b) Quais são as funções (e seus protótipos) para escrever em arquivos?

(c) Quais são as funções (e seus protótipos) para ler arquivos?

(d) Quais são as funções (e seus protótipos) para reposicionar um ponteiro para arquivo?

(e) Quais bibliotecas devem ser incluídas no código para poder utilizar as funções acima?


Referência Bibliográfica: https://www.tutorialspoint.com/c_standard_library/c_function_fwrite.htm
