/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_cspdi.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yookamot <yookamot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 18:18:48 by yookamot          #+#    #+#             */
/*   Updated: 2024/12/15 17:01:58 by yookamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_c(va_list args)
{
	char	c;

	c = va_arg(args, int);
	return (write(1, &c, 1));
}

int	print_s(va_list args)
{
	char	*str;
	int		len;

	str = va_arg(args, char *);
	if (!str)
		str = "(null)";
	len = ft_strlen(str);
	return (write(1, str, len));
}

int	print_p(va_list args)
{
	unsigned long	ptr;
	int				count;

	ptr = va_arg(args, unsigned long);
	count = 0;
	if (ptr == 0)
		return (count + write(1, "(nil)", 5));
	count = write(1, "0x", 2);
	if (count == -1)
		return (-1);
	return (count + print_hex(ptr, 0));
}

int	print_d(va_list args)
{
	int	num;
	int	count;

	num = va_arg(args, int);
	ft_putnbr_fd(num, 1);
	count = get_num_length(num);
	return (count);
}

int	print_i(va_list args)
{
	return (print_d(args));
}
