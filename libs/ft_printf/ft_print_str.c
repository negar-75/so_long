/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnasiri <nnasiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 14:04:53 by nnasiri           #+#    #+#             */
/*   Updated: 2024/08/21 15:05:33 by nnasiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int	print_char(char c)
{
	ssize_t	printed_letter;

	printed_letter = write(1, &c, 1);
	return ((int)(printed_letter));
}

int	print_str(char *s)
{
	ssize_t	printed_letter;

	if (!s)
		printed_letter = write(1, "(null)", 6);
	else
		printed_letter = write(1, s, ft_strlen(s));
	return ((int)printed_letter);
}
