/* ************************************************************************** */
/*                                                                            */
/*   By: Maria Clara Zaine - 2022                                             */
/*   Follow me: github.com/MaricchiaZ                                         */
/*                                                                            */
/* ************************************************************************** */

/*
Proposta do exercício: Um programa que primeiro pergunta ao usuário quanto dinheiro 
deve ser dado de troco e depois imprime o número mínimo de moedas com as quais esse 
troco pode ser dado. O troco só pode ser dado por moedas de 25, 10, 5 e 1 centavos.
*/

#include <cs50.h> // biblioteca para usar as funções do curso CS50
#include <stdio.h> // biblioteca para usar o printf
#include <math.h> // biblioteca para usar as funções de matemática

int main(void)
{
    float change; // uma variável para recever o valor do troco
    int coins; // um int que será a quantidade de moedas
    float decimal; // uma variável que será a parte decimal do troco
    float inte; // uma variável que será a parte inteira do troco
    int cents; // uma variável que será a parte dos centavos do troco
    
    do // faça o comando abaixo: 
    {
        change = get_float("O troco é: "); // troco recebe o valor passado pelo usuário
    }
    while (change < 0.00); // enquanto o troco for menor do que zero
    
    coins = 0; // a quantidade de moedas começa zerada
    inte = floor(change); // o inte recebe a parte inteira do troco retornada pela função floor(change)
    decimal = change - inte; // decimal recebe o troco total menos a parte inteira (logo recebe a pate decimal)
    cents = round(decimal * 100); // cent recebe a parte decimal concertida em centavos
	
    while (inte > 0) // enquanto a quantidade de inteiros for maior que zero
    {
        inte = inte - 1; // inteiros perde uma unidade
        coins = coins + 4; // e as moedas ganham 4 unidades
    }    
    while (cents / 25 > 0) // enquanto os centavos dividido por 25 for maior que zero
    {
        cents = cents - 25; // centavos perde 25 unidades
        coins = coins + 1; // e as moedas ganham 1 unidade
    }
    while (cents / 10 > 0) // enquanto os centavos dividido por 10 for maior que zero
    {
        cents = cents - 10; // centavos perde 10 unidades
        coins = coins + 1; // e as moedas ganham 1 unidade
    }
    while (cents / 5 > 0) // enquanto os centavos dividido por 5 for maior que zero
    {
        cents = cents - 5; // centavos perde 5 unidades
        coins = coins + 1; // e as moedas ganham 1 unidade
    }
    while (cents > 0) // enquanto os centavos for for maior que zero
    {
        cents = cents - 1; // centavos perde 1 unidade
        coins = coins + 1; // e as moedas ganham 1 unidade
    }
    printf("%i\n", coins); // imprimimos aqui a quantidade de moedas necessárias para dar esse troco (coins)
	return (0); // e retornamos 0, pois convencionalmente assim se termina um main que funcionou
}
