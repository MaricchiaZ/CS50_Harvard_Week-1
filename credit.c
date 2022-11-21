/* ************************************************************************** */
/*                                                                            */
/*   By: Maria Clara Zaine - 2022                                             */
/*   Follow me: github.com/MaricchiaZ                                         */
/*                                                                            */
/* ************************************************************************** */

/*
Proposta do exercício: um programa que solicite ao usuário um número de cartão de 
crédito e, em seguida, informe (via printf ) se é um número de cartão American Express,
MasterCard ou Visa válido , de acordo com as definições de formato de cada um neste 
documento. 

American Express usa números de 15 dígitos, MasterCard usa números de 16 dígitos e Visa
usa números de 13 e 16 dígitos. E esses são números decimais (0 a 9), não binários.

Todos os números American Express começam com 34 ou 37; a maioria dos números do MasterCard 
começa com 51, 52, 53, 54 ou 55 (eles também têm alguns outros números iniciais potenciais 
com os quais não nos preocupamos neste problema); e todos os números Visa começam com 4. 

Os números de cartão de crédito também têm um “checksum” embutido, uma relação matemática 
entre pelo menos um número e outros esse “checksum” é dado pelo Algoritmo de Luhn.
*/

#include <stdio.h>
#include <cs50.h>

int main(void)
{
    long int credicard;
    long int tam;
    int i;
    int casas;
    int check;
    int check2;
    
    i = 1;
    casas = 1;
    tam = 0;
    check = 0;
    check2 = 0;
    do
    {
        credicard = get_long("Digite um número de cartão para a conferência: ");
    }
    while (credicard < 0);
    

    tam = credicard;
    casas = 1;
    while (credicard > 0)
    {
        i = 0;
        if ((casas % 2) == 0)
        {
            i = credicard % 10;
            if (i * 2 > 9)
            {
                check = check + ((i * 2) % 10) + 1;
            }
            else
            {
                check = check + (i * 2);
            }
            credicard = credicard / 10;
        }
        i = 0;
        if (casas % 2 != 0)
        {
            i = credicard % 10;
            check2 = check2 + i;
            credicard = credicard / 10;  
        }
        casas = casas + 1;
    }
    
    if ((check2 + check) % 10 == 0)
    {
        if ((tam >= 5100000000000000) && (tam <= 5599999999999999))
        {
            printf("MASTERCARD\n");
            return (0);
        }

        if ((tam / 10000000000000 == 34) || (tam / 10000000000000 == 37))
        {
            printf("AMEX\n");
            return (0);
        }
        if ((tam / 1000000000000 == 4) || (tam / 10000000000000 == 4) || (tam / 100000000000000 == 4) || (tam / 1000000000000000 == 4))
        {
            printf("VISA\n");
            return (0);
        }
        else
        {
            printf("INVALID\n");
            return (0);
        }
    }
    else
    {
        printf("INVALID\n");
        return (0);
    }
}
