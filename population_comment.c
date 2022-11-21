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

#include <stdio.h> // biblioteca para usar o printf
#include <cs50.h> // biblioteca para usar as funções do curso CS50

int main(void) 
{
    int lhamas; // variável para receber o número inicial de lhamas
    int lhamas_end; // variável para o número final de lhamas
    int borns; // varivável para receber o número de nascimentos
    int deaths; // varivável para receber o número de mortes
    int years; // varivável para os anos 
    
    do // repete-se a ação abaixo
    {
        lhamas = get_int("Número inicial de lhamas: "); // a variável lhamas recebe a quantidade inicial passada pelo usuário
    }
    while (lhamas < 9); // enquanto o número de lhamas for menor que 9
    
    do // repete-se a ação abaixo
    {
        lhamas_end = get_int("Número final de lhamas: "); // a variável lhamas_end recebe a quantidade final passada pelo usuário
    }
    while (lhamas_end < lhamas); // enquanto o número de lhamas_end for menor que o número de lhamas inicial
    
    years = 0; // os anos passados inicia-se em zero
    while (lhamas < lhamas_end) // enquanto a quantidade total de lhamas for menor que a população final
    {
        borns = (lhamas / 3); // os nascimentos ocorrem no valor de 1/3 dos animais do rebanho
        deaths = (lhamas / 4); // as mortes ocorrem no valor de 1/4 dos animais do rebanho
        lhamas = lhamas + borns - deaths; // lhamas totais = rebanho + nascidos - mortes
        years++; // variável dos anos aumenta 1
    }
    printf("Years: %d\n", years); // imprimi-se a quantidade de anos decorridas para atingir a população final
	return (0); // e retorne 0, pois convencionalmente assim se termina um main que funcionou
}
