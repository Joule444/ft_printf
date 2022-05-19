/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthuysba <jthuysba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 12:26:18 by jthuysba          #+#    #+#             */
/*   Updated: 2022/05/19 17:25:23 by jthuysba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdio.h>

int	ft_printf(const char *str, ...)
{
	va_list	args;
	size_t	i;
	size_t	len;

	va_start(args, str);
	i = 0;
	len = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			if (str[i] == 'c')
			{
				len += print_char(va_arg(args, int));
			}
			if (str[i] == 's')
			{
				len += print_str(va_arg(args, char *));
			}
			if (str[i] == 'p')
			{
				if(check_nill(va_arg(args, unsigned long int)) == 0)
					len += print_base_point(va_arg(args, unsigned long int));
			}
			if (str[i] == 'd' || str[i] == 'i')
			{
				len += print_int(va_arg(args, int));
			}/*
			if (str[i] == 'u')
			{
				len += print_unint();
			}*/
			if (str[i] == 'x')
			{
				len += print_base_hex(va_arg(args, unsigned int), "0123456789abcdef");
			}
			if (str[i] == 'X')
			{
				len += print_base_hex(va_arg(args, unsigned int), "0123456789ABCDEF");
			}
			if (str[i] == '%')
			{
				len += print_char('%');
			}
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

int main()
{
	char *d = "lol";
	printf("%x %X %p \n", -42, -1234, d);
	ft_printf("%x %X %p ", -42, -1234, d);
}
