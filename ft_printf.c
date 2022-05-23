/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthuysba <jthuysba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 12:26:18 by jthuysba          #+#    #+#             */
/*   Updated: 2022/05/23 12:39:51 by jthuysba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_args(va_list args, char c)
{
	int	len;

	len = 0;
	if (c == 'c')
		len += print_char(va_arg(args, int));
	if (c == 's')
		len += print_str(va_arg(args, char *));
	if (c == 'p')
		len += check_nill(va_arg(args, unsigned long int));
	if (c == 'd' || c == 'i')
		len += print_int(va_arg(args, int));
	if (c == 'u')
		len += print_unint(va_arg(args, unsigned int));
	if (c == 'x')
		len += print_base_hex(va_arg(args, unsigned int), "0123456789abcdef");
	if (c == 'X')
		len += print_base_hex(va_arg(args, unsigned int), "0123456789ABCDEF");
	if (c == '%')
		len += print_char('%');
	return (len);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		len;

	va_start(args, str);
	i = 0;
	len = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			len += check_args(args, str[i]);
			i++;
		}
		else
		{
			len += print_char(str[i]);
			i++;
		}
	}
	va_end(args);
	return (len);
}
