/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnasiri <nnasiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 12:57:42 by nnasiri           #+#    #+#             */
/*   Updated: 2024/09/03 15:30:08 by nnasiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	map_wall(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->map.line_len)
	{
		if (data->map.map[0][i] != '1' || data->map.map[data->map.line_count
			- 1][i] != '1')
			ft_error("WALL ERROR", data);
		i++;
	}
	i = 0;
	while (data->map.map[i] != NULL)
	{
		if (data->map.map[i][0] != '1' || data->map.map[i][data->map.line_len
			- 1] != '1')
			ft_error("WALL ERROR", data);
		i++;
	}
}

void	sub_map_elements_counts(t_data *data)
{
	int	i;
	int	j;

	i = 1;
	while (i < data->map.line_count - 1)
	{
		j = 1;
		while (j < data->map.line_len - 1)
		{
			if (data->map.map[i][j] == 'C')
				data->map.count_c++;
			else if (data->map.map[i][j] == 'E')
				data->map.count_e++;
			else if (data->map.map[i][j] == 'P')
			{
				data->map.count_p++;
				data->player_i = i;
				data->player_j = j;
			}
			j++;
		}
		i++;
	}
}

void	check_strange_param(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map.map[i])
	{
		j = 0;
		while (data->map.map[i][j] != '\0' && data->map.map[i][j] != '\n')
		{
			if (data->map.map[i][j] != 'C' && data->map.map[i][j] != 'P'
				&& data->map.map[i][j] != '0' && data->map.map[i][j] != 'E'
				&& data->map.map[i][j] != '1')
				ft_error("PARAMETER ERROR", data);
			j++;
		}
		i++;
	}
}

void	map_elements_counts(t_data *data)
{
	sub_map_elements_counts(data);
	if (data->map.count_c < 1 || data->map.count_p > 1 || data->map.count_e > 1
		|| data->map.count_e == 0 || data->map.count_p == 0)
		ft_error("PARAMETER ERROR", data);
}
