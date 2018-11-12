1. Escreva um código em C para gerar uma onda quadrada de 1 Hz em um pino GPIO do Raspberry Pi.

2. Generalize o código acima para qualquer frequência possível.

>  possivel: o clock da pi e o tempo de processamento do cod são o que limite

3. Crie dois processos, e faça com que o processo-filho gere uma onda quadrada, enquanto o processo-pai lê um botão no GPIO, aumentando a frequência da onda sempre que o botão for pressionado. A frequência da onda quadrada deve começar em 1 Hz, e dobrar cada vez que o botão for pressionado. A frequência máxima é de 64 Hz, devendo retornar a 1 Hz se o botão for pressionado novamente.
````````
sleep: conta em segundos
usleep: conta em milisegundos
problema ao utilizá-las: há o tempo de se chamar mais o tempo do processamento
Para evitar isso: utilizar ualarm(): função alarme em microsegundos
Deve-se utilizar alarm(), pois é o único que suporta tais valores de tempo
````````
