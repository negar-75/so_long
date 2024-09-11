/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnasiri <nnasiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 14:41:48 by nnasiri           #+#    #+#             */
/*   Updated: 2024/08/21 15:59:34 by nnasiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	init_data(t_data *data)
{
	data->mlx = NULL;
	data->win = NULL;
	data->player_i = 0;
	data->player_j = 0;
	data->win_width = 0;
	data->win_height = 0;
	data->step_counts = 0;
	data->map.count_c = 0;
	data->map.count_e = 0;
	data->map.count_p = 0;
	data->map.collected = 0;
	data->map.can_exit = 0;
	data->map.line_count = 0;
	data->map.line_len = 0;
	data->map.path = NULL;
	data->map.map = NULL;
	data->map.fd = 0;
	data->img.player = NULL;
	data->img.wall = NULL;
	data->img.collectible = NULL;
	data->img.exit = NULL;
	data->img.floor = NULL;
	data->img.height = 48;
	data->img.width = 48;
}
