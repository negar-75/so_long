/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnasiri <nnasiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 14:50:51 by nnasiri           #+#    #+#             */
/*   Updated: 2024/08/21 15:05:52 by nnasiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int	format_validation(const char *format)
{
	int	i;
	int	count;

	i = -1;
	count = 0;
	while (format[++i])
	{
		if (format[i] == '%')
		{
			i++;
			if (!(format[i] == '%' || format[i] == 's' || format[i] == 'c'
					|| format[i] == 'd' || format[i] == 'i' || format[i] == 'u'
					|| format[i] == 'x' || format[i] == 'X'
					|| format[i] == 'p'))
			{
				count++;
			}
		}
	}
	return (count);
}
