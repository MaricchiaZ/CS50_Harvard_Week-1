/* ************************************************************************** */
/*                                                                            */
/*   By: Maria Clara Zaine - 2022                                             */
/*   Follow me: github.com/MaricchiaZ                                         */
/*                                                                            */
/* ************************************************************************** */

/*
Proposta do exercício: Recriar duas pirâmides do Mário espelhadas em C, usando hashes ( # ) para 
os tijolos, como visto a seguir:
             #  #
            ##  ##
           ###  ###
          ####  ####
         #####  #####
        ######  ######
       #######  #######
      ########  ########
*/


#include <stdio.h> // biblioteca para usar o printf
#include <cs50.h> // biblioteca para usar as funções do curso CS50

int main(void)
{
    int a; // receberá a altura da pirâmide
    int line1; // inteiro relativo aos tijolos da parte inicial da linha/andar da pirâmide que estamos
    int line2; // inteiro relativo aos tijolos da parte final da linha/andar da pirâmide que estamos
    int floor; // inteiro relativo ao andar nós estamos
    int space; // inteiro relativo aos espaços antes do primeiro tijolo do andar
    
    do // faça o comando abaixo:
    {
        a = get_int("Insira o tamanho da pirâmide: "); // a recebe o a altura da pirâmide passada pelo usuário
    }
    while ((a < 1) || (a > 8)); // enquanto a for menor que um e maior que 8
    if (a == 1) // caso a seja 1
    {
        printf("#  #\n"); // imprima apenas 1 # 1 espaço e 1 # e a quebra de linha
        return (0); // e retorne 0, pois convencionalmente assim se termina um main que funcionou
    }    
   
    a++; // a ganha 1 unidade
    line1 = 1; // a linha1 é iniciada no valor de 1
    line2 = 1; // a linha2 é iniciada no valor de 1
    floor = 1; // a andar é iniciado no valor de 1

    while (floor < a)  // enquanto o anar a ser impresso for menor que a altura
    {
        space = a - line1 - 1;// o número de espaços a serem colocados é a altura total, menos a linha do andar que nos encontramos, menos 1 por que a linha inferior não tem espaço inicial
        while (line1 > 0) // enquanto a quantidade de tijolos dessa linha for maior que zero
        {

            while (space > 0) // enquanto os espaços para imprimir for maior que zero
            {
                printf(" "); //imprime os espaços 
                space--; // e a quantidade de espaços perde uma unidade
            }

            printf("#"); // imprime o tijolo
            line1--; // e a quantidade de tijolos da linha1 perde uma unidade
        }
        printf("  "); // imprime-se os espaços centrais
        while (line2 > 0) //enquanto a quantidade de tijolos da segunda parte da linha for maior que zero
        {

            printf("#"); // imprime-se o tijolo
            line2--; // e a quantidade de tijolos da linha2 perde uma unidade
        }
        printf("\n"); // imprime-se a quebra de linha
        floor++; // o andar que estamos ganha uma unidade
        line1 = floor; // a quantidade de tijolos da primeira parte da linha recebe o mesmo valor do andar
        line2 = floor; // a quantidade de tijolos da segunda parte da linha recebe o mesmo valor do andar       
    }
	return (0);  // e retorne 0, pois convencionalmente assim se termina um main que funcionou
}