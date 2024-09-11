/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_unsigned.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnasiri <nnasiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 14:04:29 by nnasiri           #+#    #+#             */
/*   Updated: 2024/08/21 15:05:20 by nnasiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

static int	un_num_len(long unsigned int nbr)
{
	int	i;

	i = 0;
	if (nbr == 0)
		return (1);
	while (nbr > 0)
	{
		nbr = nbr / 10;
		i++;
	}
	return (i);
}

char	*ft_utoa(unsigned int nbr)
{
	long unsigned	num;
	int				len;
	char			*arr;

	num = nbr;
	len = un_num_len(num);
	arr = malloc((len + 1) * sizeof(char));
	if (!arr)
		return (NULL);
	arr[len] = '\0';
	if (num == 0)
	{
		arr[0] = '0';
		return (arr);
	}
	len--;
	while (num > 0)
	{
		arr[len] = num % 10 + '0';
		num = num / 10;
		len--;
	}
	return (arr);
}
