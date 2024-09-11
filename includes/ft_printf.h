/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnasiri <nnasiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 14:58:03 by nnasiri           #+#    #+#             */
/*   Updated: 2024/08/21 14:58:58 by nnasiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "./libft.h"
# include <stdarg.h>
# include <stdio.h>

int		print_char(char c);
int		print_number(int num);
int		print_str(char *s);
char	*ft_utoa(unsigned int nbr);
int		print_unsigned(unsigned int num);
int		print_pointer(void *ptr);
char	*convert_hex(unsigned long int num, char format);
int		print_hex(unsigned int num, char format);
int		format_validation(const char *format);
int		ft_printf(const char *format, ...);

#endif
