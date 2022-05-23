/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthuysba <jthuysba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 16:50:49 by jthuysba          #+#    #+#             */
/*   Updated: 2022/05/23 12:40:29 by jthuysba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_int(int n)
{
	int	i;
	int	len;

	len = 0;
	if (n == -2147483648)
	{
		print_str("-2147483648");
		return (11);
	}
	if (n < 0)
	{
		n = n * -1;
		len += print_char('-');
	}
	i = n % 10;
	if (n > 9)
		len += print_int(n / 10);
	len += print_char(i + '0');
	return (len);
}

int	print_unint(unsigned int n)
{
	int	i;
	int	len;

	len = 0;
	i = n % 10;
	if (n > 9)
		len += print_int(n / 10);
	len += print_char(i + '0');
	return (len);
}

int	print_base_hex(unsigned int nb, char *base)
{
	unsigned int	b_len;
	int				res;
	int				len;

	len = 0;
	b_len = 16;
	res = nb % b_len;
	if (nb >= b_len)
		len += print_base_hex(nb / b_len, base);
	len += print_char(base[res]);
	return (len);
}

int	print_base_point(unsigned long int nb)
{
	char			*base;
	unsigned int	b_len;
	int				res;
	int				len;

	len = 0;
	base = "0123456789abcdef";
	b_len = 16;
	res = 0;
	res = nb % b_len;
	if (nb >= b_len)
		len += print_base_point(nb / b_len);
	len += print_char(base[res]);
	return (len);
}
