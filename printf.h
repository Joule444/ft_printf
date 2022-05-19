/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthuysba <jthuysba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 14:31:27 by jthuysba          #+#    #+#             */
/*   Updated: 2022/05/19 17:16:16 by jthuysba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

size_t	print_char(char c);
size_t	print_str(char *s);
size_t	print_point(unsigned long n);
size_t	print_int(int n);
size_t	print_base_point(unsigned long int nb);
size_t	print_base_hex(unsigned int nb, char *base);
size_t	check_nill(unsigned long int n);

#endif
