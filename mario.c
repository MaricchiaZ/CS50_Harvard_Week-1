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

#include <stdio.h>
#include <cs50.h> 

int main(void)
{
    int a;
    int line;
    int floor;
    int space;
    
    do
    {
        a = get_int("Insira o tamanho da pirâmide: ");
    }
    while ((a < 1) || (a > 8));
    if (a == 1)
    {
        printf("#\n");
        return (0);
    }
    a++;
    line = 1;
    floor = 1;
    
    while (floor < a)
    {
        space = a - line - 1;
        while (line > 0)
        {

            while (space > 0)
            {
                printf(" ");
                space--;
            }
            printf("#");
            line--;
        }
        printf("\n");
        floor++;
        line = floor;
    }
	return (0);
}
