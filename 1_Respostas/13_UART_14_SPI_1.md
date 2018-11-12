1. Cite as vantagens e desvantagens das comunicação serial:
 (a) Assíncrona (UART).
 > Vantagem: Por não ter ser síncrona, não apresenta o pino de clock; portanto, apresenta menos um pino.
 > Desvatagem> Quanto mais alta é a frequência de transmissão, menor o período e, consequentemente,  a chance de ter erro, visto que ele vai se propagando.
(b) SPI.
 > manda o clock, leitura é na borda; não há preocupação com a temporização, apenas em obedecer o mestre.
 
 2. Considere o caso em que a Raspberry Pi deve receber leituras analógico/digitais de um MSP430, e que a comunicação entre os dois é UART. É tecnicamente possível que o MSP430 mande os resultados da conversão A/D a qualquer hora, ou ele deve aguardar a Raspberry Pi fazer um pedido ao MSP430? Por quê?
 > qq hora, pois não tem mestre e escravo
 3. Considere o caso em que a Raspberry Pi deve receber leituras analógico/digitais de um MSP430, que a comunicação entre os dois seja SPI, e que o MSP430 seja o escravo. É tecnicamente possível que o MSP430 mande os resultados da conversão A/D a qualquer hora, ou ele deve aguardar a Raspberry Pi fazer um pedido ao MSP430? Por quê?
 > deve aguardar o rap, pois o rasp é o mestre
 > deve aguardar o rap, pois o rasp é o mestre; so pode mandar quando tem clock: o mestre transmite algo e recebe algo
 4. Se o Raspberry Pi tiver de se comunicar com dois dispositivos via UART, como executar a comunicação com o segundo dispositivo?
 > conectar o tx do rasp aos 2 rx, e ter dois bits extra
 
 > no protopcolo uart h o bit de endereço. 
 5. Se o Raspberry Pi tiver de se comunicar com dois dispositivos via SPI, como executar a comunicação com o segundo dispositivo?
 > chip-select ou daisy chain
