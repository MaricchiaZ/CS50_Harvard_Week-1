/* ************************************************************************** */
/*                                                                            */
/*   By: Maria Clara Zaine - 2022                                             */
/*   Follow me: github.com/MaricchiaZ                                         */
/*                                                                            */
/* ************************************************************************** */

/*
Proposta do exercício: Recriar a pirâmide do Mário em C, usando hashes ( # ) para 
os tijolos, como visto a seguir:
             #
            ##
           ###
          ####
         #####
        ######
       #######
      ########
*/

#include <stdio.h> // biblioteca para usar o printf
#include <cs50.h> // biblioteca para usar as funções do curso CS50

int main(void)
{
    int a; // receberá a altura da pirâmide
    int line; // inteiro relativo aos tijolos de cada andar da pirâmide estamos (variável que imprime a linha)
    int floor; // inteiro relativo ao andar nós estamos
    int space; // inteiro relativo aos espaços antes do primeiro tijolo do andar
    
    do // faça o comando abaixo:
    {
        a = get_int("Insira o tamanho da pirâmide: "); // a recebe o a altura da pirâmide passada pelo usuário
    }
    while ((a < 1) || (a > 8)); // enquanto a for menor que um e maior que 8
    if (a == 1) // caso a seja 1
    {
        printf("#\n"); // imprima apenas 1 # e a quebra de linha
        return (0); // e retorne 0, pois convencionalmente assim se termina um main que funcionou
    }

    a++; // a ganha 1 unidade
    line = 1; // a linha é iniciada no valor de 1
    floor = 1; // a variável do andar é iniciada no valor de 1
    
    while (floor < a) // enquanto o andar for menor que a altura
    {
        space = a - line - 1; // o número de espaços a serem colocados é a altura total, menos a linha do andar que nos encontramos, menos 1 por que a linha inferior não tem espaço inicial
        while (line > 0) // enquanto a linha for maior que 0
        {

            while (space > 0) // e enquanto a quantidade de espaços for maior que zero
            {
                printf(" "); // imprimimos um espaço
                space--; // o valor dos espaços perde 1 unidade
            }
            printf("#"); // e imprimimos os tijolos/#
            line--; // a quantidade de tijolos da linha perde uma unidade
        }
        printf("\n"); // imprimimos uma quebra de linha
        floor++; // o andar ganha uma unidade
        line = floor;  // a quantidade de tijolos da linha recebe o mesmo valor do andar
    }
	return (0);  // e retorne 0, pois convencionalmente assim se termina um main que funcionou
}
