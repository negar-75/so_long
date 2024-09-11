/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnasiri <nnasiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 14:40:06 by nnasiri           #+#    #+#             */
/*   Updated: 2024/08/21 18:46:25 by nnasiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	init_image(t_data *data)
{
	data->img.collectible = mlx_xpm_file_to_image(data->mlx,
			"assets/collectible.xpm", &data->img.width, &data->img.height);
	data->img.exit = mlx_xpm_file_to_image(data->mlx, "assets/exit.xpm",
			&data->img.width, &data->img.height);
	data->img.floor = mlx_xpm_file_to_image(data->mlx, "assets/floor.xpm",
			&data->img.width, &data->img.height);
	data->img.player = mlx_xpm_file_to_image(data->mlx, "assets/player.xpm",
			&data->img.width, &data->img.height);
	data->img.wall = mlx_xpm_file_to_image(data->mlx, "assets/wall.xpm",
			&data->img.width, &data->img.height);
	if (!data->img.wall || !data->img.exit || !data->img.player
		|| !data->img.floor || !data->img.collectible)
	{
		ft_free(data->map.map);
		data_clean_up(data);
		err_msg("image file is missing\n");
	}
}

void	start_game(t_data *data)
{
	data->mlx = mlx_init();
	if (data->mlx == NULL)
	{
		ft_free(data->map.map);
		err_msg("Couldn't find mlx pointer.");
	}
	data->win_width = data->map.line_len;
	data->win_height = data->map.line_count;
	data->win = mlx_new_window(data->mlx, data->win_width * 48, data->win_height
			* 48, "SO_LONG!");
	if (data->win == NULL)
	{
		free(data->mlx);
		ft_free(data->map.map);
		err_msg("Couldn't create the Window.");
	}
}
