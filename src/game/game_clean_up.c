/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_clean_up.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnasiri <nnasiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 15:31:15 by nnasiri           #+#    #+#             */
/*   Updated: 2024/09/03 15:31:18 by nnasiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	data_clean_up(t_data *data)
{
	if (data->img.player)
		mlx_destroy_image(data->mlx, data->img.player);
	if (data->img.wall)
		mlx_destroy_image(data->mlx, data->img.wall);
	if (data->img.collectible)
		mlx_destroy_image(data->mlx, data->img.collectible);
	if (data->img.exit)
		mlx_destroy_image(data->mlx, data->img.exit);
	if (data->img.floor)
	{
		mlx_destroy_image(data->mlx, data->img.floor);
	}
	if (data->win != NULL)
		mlx_destroy_window(data->mlx, data->win);
	if (data->mlx != NULL)
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
	}
	if (data->map.fd)
		close(data->map.fd);
}
