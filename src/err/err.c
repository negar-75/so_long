/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnasiri <nnasiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 18:02:56 by nnasiri           #+#    #+#             */
/*   Updated: 2024/09/03 13:15:11 by nnasiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	err_msg(char *str)
{
	write(1, "Error\n", 6);
	ft_putstr_fd(str, 1);
	exit(EXIT_FAILURE);
}

void	ft_error(char *str, t_data *data)
{
	if (data->map.map)
		ft_free(data->map.map);
	if (data->map.fd)
		close(data->map.fd);
	write(1, "Error\n", 6);
	ft_putstr_fd(str, 1);
	exit(EXIT_FAILURE);
}
