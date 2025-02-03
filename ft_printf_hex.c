/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mergarci <mergarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 10:02:09 by mergarci          #+#    #+#             */
/*   Updated: 2025/02/03 19:41:31 by mergarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_digit_hex(long nb)
{
	int	iter;

	iter = 1;
	while (nb >= 16)
	{
		nb = nb / 16;
		iter++;
	}
	return (iter);
}

static void	ft_fillbytes(int index, char *s)
{
	while (index)
		s[--index] = HEX[15];
}

static void	ft_toupper_hex(char *s, int digits)
{
	int	index;

	index = 0;
	while (index < digits)
	{
		s[index] = ft_toupper(s[index]);
		index++;
	}
	s[index] = '\0';
	return ;
}

static void	ft_convert(long int n, char *s, int index, bool is_negative)
{
	long int	num;
	long int	mod;

	num = n / 16;
	mod = n % 16;
	if (is_negative)
		mod = 15 - mod;
	if (num > 16)
		ft_convert(num, s, index - 1, is_negative);
	else
	{
		if (is_negative)
			num = 15 - num;
		if (is_negative && index > 0)
			ft_fillbytes(index, s);
		if (index > 0)
			s[index - 1] = HEX[num];
	}
	s[index] = HEX[mod];
	return ;
}

char	*ft_atoi_hex(long int n, char type)
{
	int		digits;
	char	*s;
	bool	is_negative;

	is_negative = false;
	if (n < 0)
	{
		is_negative = true;
		digits = 8;
		n = -(n + 1);
	}
	else
		digits = ft_digit_hex(n);
	s = ft_calloc(digits + 1, sizeof(char));
	ft_convert(n, s, digits - 1, is_negative);
	if (type == 'X')
		ft_toupper_hex(s, digits);
	return (s);
}
