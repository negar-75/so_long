/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnasiri <nnasiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 14:41:57 by nnasiri           #+#    #+#             */
/*   Updated: 2024/04/09 14:56:05 by nnasiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int	ft_isascii(int c)
{
	return (c >= 0 && c <= 127);
}
