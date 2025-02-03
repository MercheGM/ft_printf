/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mergarci <mergarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 11:21:59 by mergarci          #+#    #+#             */
/*   Updated: 2025/02/03 20:53:20 by mergarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*Print a decimal number*/
int	ft_placeholder_d(va_list vargs)
{
	int		n_written;
	char	*str_num;

	str_num = ft_itoa(va_arg(vargs, int));
	n_written = ft_strlen(str_num);
	ft_putstr_fd(str_num, 1);
	str_num = ft_memfree(str_num);
	return (n_written);
}

int	ft_placeholder_u(va_list vargs)
{
	int				n_written;
	unsigned int	num;
	unsigned int	divisor;

	n_written = 0;
	divisor = 1;
	num = va_arg(vargs, unsigned int);
	while (num / divisor >= 10)
		divisor *= 10;
	while (divisor > 0)
	{
		ft_putnbr_fd(num / divisor, 1);
		num %= divisor;
		divisor /= 10;
		n_written++;
	}
	return (n_written);
}

/*int	ft_placeholder_hex(va_list vargs, char type)
{
	char		*str;
	char		*str_aux;
	long int	num;
	int			n_written;

	n_written = 0;
	str_aux = NULL;
	num = (long int)va_arg(vargs, long int);
	if (num == LONG_MIN)
		num = 0;
	str = ft_atoi_hex(num, type);
	n_written = ft_strlen(str);
	if (((type == 'X') || (type == 'x')) && n_written > 8)
	{
		str_aux = ft_substr(str, 8, 10);
		n_written = ft_strlen(str_aux);
		ft_putstr_fd(str_aux, 1);
	}
	if (str_aux != NULL)
		str_aux = ft_memfree(str_aux);
	else
		ft_putstr_fd(str, 1);
	str = ft_memfree(str);
	return (n_written);
}*/

/*Print a string and it returns number of character 
printed*/
int	ft_print_str(char *str)
{
	int		n;

	n = 0;
	while (str[n])
	{
		ft_putchar_fd(str[n], 1);
		n++;
	}
	return (n);
}

/*Free memory function*/
char	*ft_memfree(char *ptr)
{
	free(ptr);
	return (NULL);
}
