/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_hex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnasiri <nnasiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 14:04:06 by nnasiri           #+#    #+#             */
/*   Updated: 2024/08/21 15:05:09 by nnasiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

static int	len_in_hex(long unsigned int nbr)
{
	int	i;

	i = 0;
	if (nbr == 0)
		return (1);
	while (nbr > 0)
	{
		nbr = nbr / 16;
		i++;
	}
	return (i);
}

static char	*check_base(char c)
{
	char	*base;

	if (c == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	return (base);
}

char	*convert_hex(unsigned long int num, char format)
{
	char			*base;
	int				len;
	char			*num_in_hex;

	base = check_base(format);
	len = len_in_hex(num);
	num_in_hex = (char *)malloc(len + 1 * sizeof(char));
	if (!num_in_hex)
		return (NULL);
	num_in_hex[len] = '\0';
	len--;
	while (len >= 0)
	{
		num_in_hex[len] = base[num % 16];
		num = num / 16;
		len--;
	}
	return (num_in_hex);
}
