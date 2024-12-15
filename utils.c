/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yookamot <yookamot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 19:40:58 by yookamot          #+#    #+#             */
/*   Updated: 2024/12/15 17:16:53 by yookamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_hex(unsigned long num, int is_upper)
{
	int		count;
	char	digit;

	if (num == 0)
		return (0);
	count = print_hex(num / 16, is_upper);
	if (count == -1)
		return (-1);
	digit = num % 16;
	if (digit < 10)
		digit += '0';
	else
	{
		if (is_upper)
			digit += 'A' - 10;
		else
			digit += 'a' - 10;
	}
	return (count + write(1, &digit, 1));
}

int	get_num_length(int nbr)
{
	int	count;

	count = 0;
	if (nbr == -2147483648)
		return (11);
	if (nbr == 0)
		return (1);
	if (nbr < 0)
	{
		nbr = -nbr;
		count++;
	}
	while (nbr > 0)
	{
		nbr /= 10;
		count++;
	}
	return (count);
}

void	ft_putnbr_unsigned(unsigned int nbr)
{
	char	num;

	if (nbr >= 10)
	{
		ft_putnbr_unsigned(nbr / 10);
	}
	num = nbr % 10 + '0';
	write(1, &num, 1);
	return ;
}

int	get_num_length_unsigned(unsigned int nbr)
{
	int	count;

	count = 0;
	if (nbr == 0)
		return (1);
	while (nbr > 0)
	{
		nbr /= 10;
		count++;
	}
	return (count);
}
