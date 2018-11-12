1. Crie dois processos, e faça com que o processo-filho gere uma onda quadrada, enquanto o processo-pai faz polling de um botão no GPIO, aumentando a frequência da onda sempre que o botão for pressionado. A frequência da onda quadrada deve começar em 1 Hz, e dobrar cada vez que o botão for pressionado. A frequência máxima é de 64 Hz, devendo retornar a 1 Hz se o botão for pressionado novamente.


````
Informações Importantes:
processo_pai: GPIO_IN (o pai faz o polling)
Processo_filho: GPIO_OUT
Freqs: 1,2 , 4, 8, 16, 32, 64 z
T(s) = Ts: 1e6, 5e5, 25e4, 125000, 62500, 31250, 15625
T(s)/2 = HTs: 5e5, 25e4, 125000,62500, 31250, 15625, 7812
````








