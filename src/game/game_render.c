/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_render.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnasiri <nnasiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 14:40:57 by nnasiri           #+#    #+#             */
/*   Updated: 2024/08/21 17:22:46 by nnasiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	put_image_into_map(t_data *data, int width, int i, int j)
{
	if (data->map.map[i][j] == '1')
		mlx_put_image_to_window(data->mlx, data->win, data->img.wall, width, i
			* 48);
	else if (data->map.map[i][j] == '0')
		mlx_put_image_to_window(data->mlx, data->win, data->img.floor, width, i
			* 48);
	else if (data->map.map[i][j] == 'P')
		mlx_put_image_to_window(data->mlx, data->win, data->img.player, width, i
			* 48);
	else if (data->map.map[i][j] == 'E')
		mlx_put_image_to_window(data->mlx, data->win, data->img.exit, width, i
			* 48);
	else if (data->map.map[i][j] == 'C')
		mlx_put_image_to_window(data->mlx, data->win, data->img.collectible,
			width, i * 48);
}

int	render(t_data *data)
{
	int	i;
	int	j;
	int	width;

	if (data->win == NULL)
	{
		ft_free(data->map.map);
		return (1);
	}
	i = 0;
	j = 0;
	width = 0;
	while (data->map.map[i])
	{
		while (data->map.map[i][j] && data->map.map[i][j] != '\n')
		{
			put_image_into_map(data, width, i, j);
			width += 48;
			j++;
		}
		j = 0;
		width = 0;
		i++;
	}
	return (0);
}
