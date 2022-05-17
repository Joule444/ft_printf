/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthuysba <jthuysba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 12:26:18 by jthuysba          #+#    #+#             */
/*   Updated: 2022/05/17 16:57:20 by jthuysba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_printf(const char *str, ...)
{
	va_list	args;
	size_t	i;

	va_start(args, str);
	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			if (str[i] == 'c')
			{
				print_char(va_arg(args, int));
			}
			if (str[i] == 's')
			{
				print_str(va_arg(args, char *));
			}
			/*if (str[i] == 'p')
			{
				print_point((unsigned long)va_arg(args, void *))
			}*/
			if (str[i] == 'd' || str[i] == 'i')
			{
				print_int(va_arg(args, int));
			}
			/*
			if (str[i] == 'u')
			{

			}
			if (str[i] == 'x')
			{

			}
			if (str[i] == 'X')
			{

			}
			if (str[i] == '%')
			{

			}*/
			i++;
		}
		else
		{
			print_char(str[i]);
			i++;
		}
	}
	va_end(args);
}

int main()
{
	ft_printf("%cee %d%i%s", 32, 42, -42, "Salut a tous");
}
