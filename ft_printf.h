/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthuysba <jthuysba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 14:31:27 by jthuysba          #+#    #+#             */
/*   Updated: 2022/05/23 12:42:49 by jthuysba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int	ft_printf(const char *str, ...);
int	check_args(va_list args, char c);
int	print_char(char c);
int	print_str(char *s);
int	print_point(unsigned long n);
int	print_int(int n);
int	print_base_point(unsigned long int nb);
int	print_unint(unsigned int n);
int	print_base_hex(unsigned int nb, char *base);
int	check_nill(unsigned long int n);

#endif
