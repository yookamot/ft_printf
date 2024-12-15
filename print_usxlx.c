/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_usxlx.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yookamot <yookamot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 18:24:44 by yookamot          #+#    #+#             */
/*   Updated: 2024/12/15 17:12:51 by yookamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_u(va_list args)
{
	unsigned int	num;
	int				count;

	num = va_arg(args, unsigned int);
	ft_putnbr_unsigned(num);
	count = get_num_length_unsigned(num);
	return (count);
}

int	print_small_x(va_list args)
{
	unsigned int	num;
	int				count;

	num = va_arg(args, unsigned int);
	if (num == 0)
		return (write(1, "0", 1));
	count = print_hex((unsigned long)num, 0);
	return (count);
}

int	print_large_x(va_list args)
{
	unsigned int	num;
	int				count;

	num = va_arg(args, unsigned int);
	if (num == 0)
		return (write(1, "0", 1));
	count = print_hex((unsigned long)num, 1);
	return (count);
}
