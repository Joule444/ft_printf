/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthuysba <jthuysba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 16:50:49 by jthuysba          #+#    #+#             */
/*   Updated: 2022/05/19 17:24:49 by jthuysba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static size_t	nbr_len(int n)
{
	size_t	i;
	int	nb;

	i = 1;
	nb = n;
	if (nb < 0)
	{
		nb *= -1;
		i++;
	}
	while (nb > 9)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}

size_t	print_int(int n)
{
	int	i;

	if (n == -2147483648)
	{
		print_str("-2147483648");
		return (11);
	}
	if (n < 0)
	{
		n = n * -1;
		print_char('-');
	}
	i = n % 10;
	if (n > 9)
	{
		print_int(n / 10);
	}
	print_char(i + '0');
	return (nbr_len(n));
}

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

size_t	print_base_point(unsigned long int nb)
{
	char	*base;
	int		b_len;
	int		res;
	size_t	len;

	base = "0123456789abcdef";
	b_len = 0;
	res = 0;
	len = 0;
	b_len = ft_strlen(base);
	res = nb % b_len;
	if (nb >= b_len)
		print_base_point(nb / b_len);
	print_char(base[res]);
	return (nbr_len(nb));
}

size_t	check_nill(unsigned long int n)
{
	size_t	len;

	len = 0;
	if (n == 0)
	{
		len += print_str("(nill)");
		return (len);
	}
	else
		return (0);
}

size_t	print_base_hex(unsigned int nb, char *base)
{
	int	b_len;
	int	res;

	b_len = ft_strlen(base);
	res = nb % b_len;
	if (nb >= b_len)
		print_base_hex(nb / b_len, base);
	print_char(base[res]);
	return (nbr_len(nb));
}
