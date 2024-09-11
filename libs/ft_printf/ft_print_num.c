/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_num.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnasiri <nnasiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 14:04:41 by nnasiri           #+#    #+#             */
/*   Updated: 2024/08/21 15:05:27 by nnasiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int	print_number(int num)
{
	char	*str_num;
	int		len;

	str_num = ft_itoa(num);
	if (!str_num)
		return (-1);
	len = print_str(str_num);
	free(str_num);
	return (len);
}

int	print_unsigned(unsigned int num)
{
	char	*str_num;
	int		len;

	str_num = ft_utoa(num);
	if (!str_num)
		return (-1);
	len = print_str(str_num);
	free(str_num);
	return (len);
}

int	print_hex(unsigned int num, char format)
{
	char	*str_num;
	int		len;

	str_num = convert_hex(num, format);
	if (!str_num)
		return (-1);
	len = print_str(str_num);
	free(str_num);
	return (len);
}

int	print_pointer(void *ptr)
{
	unsigned long	address;
	char			*num;
	int				length;

	if (!ptr)
		return (print_str("(nil)"));
	length = 0;
	address = (unsigned long)(ptr);
	num = convert_hex(address, 'x');
	if (!num)
		return (-1);
	length += print_str("0x");
	length += print_str(num);
	free(num);
	return (length);
}
