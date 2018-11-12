1. Cite as vantagens e desvantagens das comunicação serial:

 (a) Assíncrona (UART).
 > Vantagem: Por não ser síncrona, não apresenta o pino de clock; portanto, apresenta menos um pino.
 
 > Desvatagem: Quanto mais alta é a frequência de transmissão, menor o período e, consequentemente, maior chance de se ter erro de transmissão, visto que o erro se propaga. Para se minimizar isso, utiliza-se um bit de paridade, entretanto, isso faz com que a baud rate seja menor.
 
(b) SPI.
 > Vantagem: por ser síncrona, apresenta clock, e não há preocupação com a temporização, apenas em se obedecer o mestre.

> Desvantagem: necessita de mais um pino (clock), em relação à UART; 
 
 2. Considere o caso em que a Raspberry Pi deve receber leituras analógico/digitais de um MSP430, e que a comunicação entre os dois é UART. É tecnicamente possível que o MSP430 mande os resultados da conversão A/D a qualquer hora, ou ele deve aguardar a Raspberry Pi fazer um pedido ao MSP430? Por quê?
 > Devido ao fato da comunicação UART ser assíncrona, não ter "mestre" e "escravo", o MSP430 pode enviar os dados a qualquer hora.
 
 3. Considere o caso em que a Raspberry Pi deve receber leituras analógico/digitais de um MSP430, que a comunicação entre os dois seja SPI, e que o MSP430 seja o escravo. É tecnicamente possível que o MSP430 mande os resultados da conversão A/D a qualquer hora, ou ele deve aguardar a Raspberry Pi fazer um pedido ao MSP430? Por quê?
> O MSP430 não pode mandar os dados a qualquer momento, só quando há sinal de clock. Por ser "escravo", deve aguardar o "mestre" (rasp) fazer um pedido (clock). Ele transmite e recebe algo.

4. Se o Raspberry Pi tiver de se comunicar com dois dispositivos via UART, como executar a comunicação com o segundo dispositivo?
 > Deve-se conectar o tx (transmissão), da rasp, aos 2 rx (recepção), dos dispositivos e ter o bit correspondente ao endereço em cada.
 
 5. Se o Raspberry Pi tiver de se comunicar com dois dispositivos via SPI, como executar a comunicação com o segundo dispositivo?
 > Chip-select ou daisy chain
