
1 - Escreva os trechos de código assembly do MSP430 para: 
	(a) Somente setar o bit menos significativo de R5. 
		bis #1, R5 #seta o LSB

	(b) Somente setar dois bits de R6: o menos significativo e o segundo menos significativo.
		bis #3,R6 #seta o LSB e o 2o LSB (11_b)

	(c) Somente zerar o terceiro bit menos significativo de R7. 
		bic.w #4, R7 #zera 3o LSB de R7

	(d) Somente zerar o terceiro e o quarto bits menos significativo de R8. 
		bic.w #12, R8 #zera 3o e 4o LSB de R8

	(e) Somente inverter o bit mais significativo de R9. 
		xor.w #32768, R9 #inverte o MSB de R9. 

	(f) Inverter o nibble mais significativo de R10, e setar o nibble menos significativo de R10.
		mov.w #61455, R15 #copia o valor (da constante) 61455 (MSNibble) no registrador temporário R15
		xor.w R15, R10 #inverte o MSNibble de R10.
		mov.w #15, R15 #copia o valor (da constante) 15 (LSNibble) no registrador temporário R15
		bis R15, R10 #seta o LSNibble


Para as questões 2 a 5, considere que as variáveis f, g, h, i e j são do tipo inteiro (16 bits na arquitetura do MSP430), e que o vetor A[] é do tipo inteiro. Estas variáveis estão armazenadas nos seguintes registradores: f: R4 g: R5 h: R6 i: R7 j: R8 A: R9 Utilize os registradores R11, R12, R13, R14 e R15 para armazenar valores temporários.

2 - "Traduza" o seguinte trecho de código em C para o assembly do MSP430:

	if(i>j) f = g+h+10;
	else f = g-h-10;

		cmp R7, R8 #R7=i, R8=j
		jl ELSE #jump to ELSE if i<j
		mov.w R5,R4 #copia o valor de R5(g) no registrador R4(f)
		add.w R6,R4 #soma o valor de R6(h) a R4(f)
		add.w #10,R4 #soma o valor (da constante) 10 a R4(f)
	ELSE:
		mov.w R5,R4 #copia o valor de R5(g) no registrador R4(f)
		sub.w R6,R4 #subtrai o valor de R6(h) a R4(f)
		sub.w #10,R4 #subtrai o valor (da constante) 10 a R4(f)	
	EXIT:
	...

3 - "Traduza" o seguinte trecho de código em C para o assembly do MSP430:
while(save[i]!=k) i++;

	LOOP: 
		mov.w R7,R11 #armazenando o valor de R7(i) em R11(registrador temporário)
		rla R11 #rla=i*2; o vetor save[] é do tipo inteiro. Multiplica-se i por 2 para andar pelas posições do vetor
		add.w R10,R11 #save=R10,R11=save+2*i=&save[i]; O vetor save[] está na memória exigindo a difinição do endereço save[i] antes de sua leitura
		cpm 0(R11),R9 #compara save[i] com k(R9)
		jeq EXIT #R11==R9
		inc.w R7 #i+=1
		jmp LOOP
	EXIT:
	...
	
4 - "Traduza" o seguinte trecho de código em C para o assembly do MSP430:
	for(i=0; i<100; i++) A[i] = i*2;
	//isso equivale a:
	//if (i<100) A[i] = i*2;


	LOOP:
		cmp #100, R7 #compara 100 com R7(i)
		jeq EXIT #i<=100
		mov.w R7,R11 #armazenando o valor de R7(i) em R11(registrador temporário)
		rla R11 #rla=i*2; o vetor A[] é do tipo inteiro. Multiplica-se i por 2 para andar pelas posições do vetor
		add.w R10,R11 #A=R10,R11=A+2*i=&A[i]; "=&" atribuição por operação lógica (and)
		inc.w R7 #i+=1
	EXIT:
	...

5 - "Traduza" o seguinte trecho de código em C para o assembly do MSP430:
for(i=99; i>=0; i--) A[i] = i*2;
	
		mov.w #99, R7 #i=99
	LOOP:
		cmp #0, R7
		jl EXIT #i<0
		mov.w R7,R11 #armazenando o valor de R7(i) em R11(registrador temporário)
		rla R11 #rla=i*2; o vetor A[] é do tipo inteiro. Multiplica-se i por 2 para andar pelas posições do vetor
		add.w R10,R11 #A=R10,R11=A+2*i=&A[i]; "=&" atribuição por operação lógica (and)
		dec.w R7 #i+=1
	EXIT:
	...