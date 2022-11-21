/* ************************************************************************** */
/*                                                                            */
/*   By: Maria Clara Zaine - 2022                                             */
/*   Follow me: github.com/MaricchiaZ                                         */
/*                                                                            */
/* ************************************************************************** */

/*
Proposta do exercício: Um programa que primeiro pergunta ao usuário quanto dinheiro 
deve ser dado de troco e depois imprime o número mínimo de moedas com as quais esse 
troco pode ser dado.
*/

#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    float change;
    int coins;
    float decimal;
    float inte;
    int cents;
    
    do
    {
        change = get_float("O troco é: ");
    }
    while (change < 0.00);
    
    coins = 0;
    inte = floor(change);
    decimal = change - inte;
    cents = round(decimal * 100);
    while (inte > 0)
    {
        inte = inte - 1;
        coins = coins + 4;
    }    
    while (cents / 25 > 0)
    {
        cents = cents - 25;
        coins = coins + 1;
    }
    while (cents / 10 > 0)
    {
        cents = cents - 10;
        coins = coins + 1;
    }
    while (cents / 5 > 0)
    {
        cents = cents - 5;
        coins = coins + 1;
    }
    while (cents > 0)
    {
        cents = cents - 1;
        coins = coins + 1;
    }
    printf("%i\n", coins);
	return (0);
}
