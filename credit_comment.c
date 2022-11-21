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

#include <stdio.h> // biblioteca para usar o printf
#include <cs50.h> // biblioteca para usar as funções da CS50

int main(void)
{
    long int credicard; //variável para receber o número do cartão mandado pelo usuário
    long int size; // variável que será o tamanho do número passado, que é uma cópia do número passado
    int i; //
    int nb; // vai percorrer as casas do número
    int check; // int para 
    int check2;
    
    i = 1;
    nb = 1; // o número que vai percorrer as "casas" do número inicia-se em 1
    size = 0;
    check = 0;
    check2 = 0;
    do // repita o comando abaixo
    {
        credicard = get_long("Digite um número de cartão para a conferência: "); // credicard recebe o valor do número passado pelo user
    }
    while (credicard < 0); // enquanto o valor for menor que zero
    

    size = credicard; // o size recebe o mesmo valor do cartão
    nb = 1; // o número que vai percorrer as "casas" do número inicia-se em 1
    while (credicard > 0) // enquanto o valor do credicard for maior que zero
    {
        i = 0; // i é zerado
        if ((nb % 2) == 0) // se o valor do nb é par
        {
            i = credicard % 10; // i recebe o módulo de credicard por 10
            if (i * 2 > 9) // se o dobro de i for maior que 9
            {
                check = check + ((i * 2) % 10) + 1; // checagem1 recebe o valor dela mais o dobro do i, passado de módulo pra 10 e somado mais 1 (Isso faz parte do Algoritmo de Luhn)
            }
            else // e se o dobro de i não for maior que 9
            {
                check = check + (i * 2); // checagem1 recebe o valor dela mais o dobro do i
            }
            credicard = credicard / 10; // dividimos credicard  por 10, e assim esse número perde a última casa
        }
        i = 0; // i é zerado
        if (nb % 2 != 0) // se nb não for par
        {
            i = credicard % 10; // i recebe o módulo do credicard por 10
            check2 = check2 + i; // a checagem2 recebe o valor dela mesma mais 1
            credicard = credicard / 10;  // dividimos credicard  por 10, e assim esse número perde a última casa
        }
        nb = nb + 1; // e avançamos para a próxima casa
    }
    
    if ((check2 + check) % 10 == 0) // o módulo de 10 da soma das checagens 1 e 2 for 0
    {
        if ((size >= 5100000000000000) && (size <= 5599999999999999)) // se o número estiver entre 5100 trilhões 5599 trilhões
        {
            printf("MASTERCARD\n"); // é um cartão válido e da bandeira mastercard, então imprimimos MASTERCARD e a quebra de linha
            return (0); // e retornamos 0, pois convencionalmente assim se termina um main que funcionou
        }

        if ((size / 10000000000000 == 34) || (size / 10000000000000 == 37)) // se o size dividido por 10 trilhões estiver entre 34 e 27
        {
            printf("AMEX\n"); // é um cartão válido e da bandeira american express, então imprimimos AMEX e a quebra de linha
            return (0); // e retornamos 0, pois convencionalmente assim se termina um main que funcionou
        }
        if ((size / 1000000000000 == 4) || (size / 10000000000000 == 4) || (size / 100000000000000 == 4) || (size / 1000000000000000 == 4)) // se tiver entre 13 e 16 dígitos mas começando com 4 
        {
            printf("VISA\n"); //é um cartão válido e da bandeira visa então imprimimos VISA e a quebra de linha
            return (0); // e retornamos 0, pois convencionalmente assim se termina um main que funcionou
        }
        else // caso não seja nenhuma das opções acima
        {
            printf("INVALID\n"); // apesar de ser um número de cartão válido, não é de nenhuma bandeira existente, o que o torna inválido
            return (0); // e retornamos 0, pois convencionalmente assim se termina um main que funcionou
        }
    }
    else // e se o módulo de 10 da soma das checagens 1 e 2 não for 0
    {
        printf("INVALID\n"); // é um cartão inválido, conferido pela checagem;
        return (0); // e retornamos 0, pois convencionalmente assim se termina um main que funcionou
    }
}
