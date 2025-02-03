/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mergarci <mergarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 19:37:53 by mergarci          #+#    #+#             */
/*   Updated: 2025/02/03 21:30:15 by mergarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void ft_printf_hex(char c, char type)
{
    //printf("\n%c %c\n", c, type);
    if ((type == 'x') || (type == 'p'))
        ft_putchar_fd(c, 1);
    else
        ft_putchar_fd(ft_toupper(c), 1);
}

int ft_convertir(long int nb, char type, int n_written)
{
    long int    num;
    long int    mod;
    
    num = nb / 16;
    mod = nb % 16;
    if ((type == 'p') && (n_written == 0))
    {
        ft_putstr_fd("0x", 1);
        n_written = 2;
    }
    if (num > 16)
        n_written = ft_convertir(num, type, n_written++);
    else if (num > 0)
    {
        ft_printf_hex(HEX[num], type);
        n_written++;
    }
    //printf("\n~%d~\n", n_written);
    ft_printf_hex(HEX[mod], type);
    //ft_putchar_fd(ft_toupper(HEX[mod]), 1);
    n_written++;
    return (n_written);
}

int	ft_placeholder_hex_2(va_list vargs, char type)
{
	/*char		*str;
	char		*str_aux;*/
	long int	num;
	int			n_written;
    unsigned int complement;

	n_written = 0;
	//str_aux = NULL;
	num = (long int)va_arg(vargs, long int);
    complement = 0;
    if (num == LONG_MIN)
		num = 0;
    if (num < 0)
    {
        printf("\n***%ld***\n", num);
        complement = (unsigned int)(-num); 
        printf("\n**%x**\n", complement);
        complement = ~complement + 1;
        printf("\n*%x*\n", complement);
        n_written = ft_convertir(complement, type, n_written);
        //complement = -num; //convertir numero a complemento a 2
    }
    else
        n_written = ft_convertir(num, type, n_written);
    //printf("\n*%d*\n", n_written);
    return (n_written);
}
