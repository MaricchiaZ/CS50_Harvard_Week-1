/* ************************************************************************** */
/*                                                                            */
/*   By: Maria Clara Zaine - 2022                                             */
/*   Follow me: github.com/MaricchiaZ                                         */
/*                                                                            */
/* ************************************************************************** */

/*
Copie o “código de distribuição” (ou seja, código inicial) a seguir em um novo 
arquivo em seu IDE chamado population.c.

Digamos que temos uma população de n lhamas. A cada ano, nascem n / 3 novas lhamas 
e n / 4 morrem.

Se o usuário inserir um número menor que 9 (o tamanho mínimo permitido da população),
Seu programa deve então calcular o número (inteiro) de anos necessários para que a 
população atinja pelo menos o tamanho do valor final.
Finalmente, seu programa deve imprimir o número de anos necessários para que a 
população de lhama alcance esse tamanho final, como ao imprimir no 
terminal Years: n , onde n é o número de anos.

`
#include
#include

int main(void)
{
      // TODO: Solicite o valor inicial ao usuário

     // TODO: Solicite o valor final ao usuário

     // TODO: Calcule o número de anos até o limite

     // TODO: Imprima o número de anos

}
`
*/

#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int lhamas;
    int lhamas_end;
    int borns;
    int deaths;
    int years;
    
    do
    {
        lhamas = get_int("Número inicial de lhamas: ");
    }
    while (lhamas < 9);
    
    do
    {
        lhamas_end = get_int("Número final de lhamas: ");
    }
    while (lhamas_end < lhamas);
    
    years = 0;
    while (lhamas < lhamas_end)
    {
        borns = (lhamas / 3);
        deaths = (lhamas / 4);
        lhamas = lhamas + borns - deaths;
        years++;
    }
    printf("Years: %d\n", years);
	return (0);
}
