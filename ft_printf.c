/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mergarci <mergarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 11:13:29 by mergarci          #+#    #+#             */
/*   Updated: 2025/02/03 20:51:04 by mergarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(char const *s, ...)
{
	int		cont;
	int		i;
	va_list	vargs;

	i = 0;
	cont = 0;
	va_start(vargs, s);
	while (s[i])
	{
		if (s[i] == '%')
			cont += ft_check_placeholder(s, &i, vargs);
		else
		{
			ft_putchar_fd(s[i], 1);
			cont++;
		}
		i++;
	}
	va_end(vargs);
	return (cont);
}

int	ft_check_placeholder(char const *s, int *i, va_list vargs)
{
	int	cont;

	cont = 0;
	if (s[*i + 1] == 'c')
		cont = ft_placeholder_c(vargs, 'c');
	else if (s[*i + 1] == 's')
		cont = ft_placeholder_s(vargs);
	else if (s[*i + 1] == 'p')
		cont = ft_placeholder_p(vargs);
	else if ((s[*i + 1] == 'd') || (s[*i + 1] == 'i'))
		cont = ft_placeholder_d(vargs);
	else if (s[*i + 1] == 'u')
		cont = ft_placeholder_u(vargs);
	else if (s[*i + 1] == 'x')
		//cont = ft_placeholder_hex(vargs, 'x');
		cont = ft_placeholder_hex_2(vargs, 'x');
	else if (s[*i + 1] == 'X')
		cont = ft_placeholder_hex_2(vargs, 'X');
		//cont = ft_placeholder_hex(vargs, 'X');
	else if (s[*i + 1] == '%')
		cont = ft_placeholder_c(vargs, '%');
	*i += 1;
	return (cont);
}

/*Print a character. It needs to know if it's called 
from c or % placeholder*/
int	ft_placeholder_c(va_list vargs, char type)
{
	int	n_written;
	int	character;

	character = '\0';
	n_written = 1;
	if (type == '%')
		character = '%';
	else
		character = va_arg(vargs, int);
	ft_putchar_fd(character, 1);
	return (n_written);
}

/*Print an array of character*/
int	ft_placeholder_s(va_list vargs)
{
	char	*s_aux;

	s_aux = va_arg(vargs, char *);
	if (s_aux == NULL)
		return (ft_print_str("(null)"));
	return (ft_print_str(s_aux));
}

/*Print a void pointer address in hexadecimal*/
/*int	ft_placeholder_p(va_list vargs)
{
	int				n_written;
	unsigned long	dir_ptr;
	char			*str_aux;

	n_written = 0;
	dir_ptr = va_arg(vargs, unsigned long );
	if (dir_ptr != 0)
	{
		ft_putchar_fd('0', 1);
		ft_putchar_fd('x', 1);
		n_written = 2;
		str_aux = ft_atoi_hex((dir_ptr), 'p');
		n_written += ft_print_str(str_aux);
		str_aux = ft_memfree(str_aux);
	}
	else
		return (ft_print_str("(nil)"));
	return (n_written);
}*/

/*Print a void pointer address in hexadecimal*/
int	ft_placeholder_p(va_list vargs)
{
	int				n_written;
	unsigned long	dir_ptr;
	//char			*str_aux;

	n_written = 0;
	dir_ptr = va_arg(vargs, unsigned long );
	if (dir_ptr != 0)
	{
		n_written = ft_convertir(dir_ptr, 'p', n_written);
    	//printf("\n*%d*\n", n_written);
		//ft_placeholder_hex_2(dir_ptr, 'p');
	}
	else
		return (ft_print_str("(nil)"));
	return (n_written);
}