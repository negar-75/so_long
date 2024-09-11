/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnasiri <nnasiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 14:40:24 by nnasiri           #+#    #+#             */
/*   Updated: 2024/08/21 19:31:50 by nnasiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	on_destroy(t_data *data)
{
	ft_free(data->map.map);
	data_clean_up(data);
	exit(0);
}

void	move_player(t_data *data, int i, int j)
{
	data->map.map[data->player_i][data->player_j] = '0';
	data->player_i = i;
	data->player_j = j;
	data->map.map[i][j] = 'P';
}

int	check_movement(t_data *data, int i, int j)
{
	if (i < 0 || j < 0 || data->map.map[i][j] == '1')
		return (1);
	data->step_counts++;
	if (data->map.map[i][j] == 'C')
	{
		data->map.collected--;
		data->map.map[i][j] = '0';
	}
	else if (data->map.map[i][j] == 'E')
	{
		if (data->map.collected == 0)
		{
			game_dashboard(data);
			data_clean_up(data);
			ft_free(data->map.map);
			exit(0);
		}
		else
			return (1);
	}
	move_player(data, i, j);
	game_dashboard(data);
	return (0);
}

int	key_handler(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
	{
		data_clean_up(data);
		ft_free(data->map.map);
		exit(0);
	}
	else if (keysym == XK_Up || keysym == XK_w)
		check_movement(data, data->player_i - 1, data->player_j);
	else if (keysym == XK_Down || keysym == XK_s)
		check_movement(data, data->player_i + 1, data->player_j);
	else if (keysym == XK_Right || keysym == XK_d)
		check_movement(data, data->player_i, data->player_j + 1);
	else if (keysym == XK_Left || keysym == XK_a)
		check_movement(data, data->player_i, data->player_j - 1);
	return (0);
}
