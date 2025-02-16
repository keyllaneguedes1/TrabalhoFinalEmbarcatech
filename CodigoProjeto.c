//O código permite o controle de dois LEDs através de dois botões, utilizando a biblioteca padrão da Pico. 
//Definição dos Pinos: 
//• BUTTON_5 (Pino 5): Botão que controla o LED_11. 
//• BUTTON_6 (Pino 6): Botão que controla o LED_12. 
//• LED_11 (Pino 11): LED acionado pelo botão BUTTON_5. 
//• LED_12 (Pino 12): LED acionado pelo botão BUTTON_6. 
//A função setup() prepara os botões para serem lidos corretamente e garante que eles 
//funcionem sem erros. Também define as luzes para que possam ser acesas e apagadas pelo código. 
//Na função main(), o código verifica continuamente o estado dos botões: Se BUTTON_5 
//estiver pressionado acende o LED_11, já se o BUTTON_6 estiver pressionado  acende o 
//LED_12. Caso contrário, os LEDs permanecem apagados. Um pequeno atraso de 10ms é 
//colocado para evitar que o botão registre cliques a mais por engano. 

#include "pico/stdlib.h"

#define BUTTON_5 5
#define BUTTON_6 6
#define LED_11 11
#define LED_12 12

void setup() {
    gpio_init(BUTTON_5);
    gpio_set_dir(BUTTON_5, GPIO_IN);
    gpio_pull_up(BUTTON_5);
    
    gpio_init(BUTTON_6);
    gpio_set_dir(BUTTON_6, GPIO_IN);
    gpio_pull_up(BUTTON_6);

    gpio_init(LED_11);
    gpio_set_dir(LED_11, GPIO_OUT);

    gpio_init(LED_12);
    gpio_set_dir(LED_12, GPIO_OUT);
}

int main() {
    setup();
    
    while (1) {
        if (!gpio_get(BUTTON_5)) {
            gpio_put(LED_11, 1);
        } else {
            gpio_put(LED_11, 0);
        }

        if (!gpio_get(BUTTON_6)) {
            gpio_put(LED_12, 1);
        } else {
            gpio_put(LED_12, 0);
        }

        sleep_ms(10); 
    }
}
