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


#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int a;
    int line1;
    int line2;
    int floor;
    int space;
    
    do
    {
        a = get_int("Insira o tamanho da pirâmide: ");
    }
    while ((a < 1) || (a > 8));
    if (a == 1)
    {
        printf("#  #\n");
        return (0);
    }    
   
    a++;
    line1 = 1;
    line2 = 1;
    floor = 1;
    
    while (floor < a)
    {
        space = a - line1 - 1;
        while (line1 > 0)
        {

            while (space > 0)
            {
                printf(" ");
                space--;
            }

            printf("#");
            line1--;
        }
        printf("  ");
        while (line2 > 0)
        {

            printf("#");
            line2--;
        }
        printf("\n");
        floor++;
        line1 = floor;
        line2 = floor;
    }
	return (0);
}