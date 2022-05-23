/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthuysba <jthuysba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 14:22:08 by jthuysba          #+#    #+#             */
/*   Updated: 2022/05/23 12:34:42 by jthuysba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_char(char c)
{
	write(1, &c, 1);
	return (1);
}

int	print_str(char *s)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	if (!s)
	{
		len += print_str("(null)");
		return (len);
	}
	while (s[i])
	{
		len += print_char(s[i]);
		i++;
	}
	return (len);
}

int	check_nill(unsigned long int n)
{	
	int	len;

	len = 0;
	if (n == 0)
	{
		len += print_str("(nil)");
		return (len);
	}
	else
	{
		len += print_str("0x");
		len += print_base_point(n);
		return (len);
	}
}
