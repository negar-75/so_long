/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   accessibility.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnasiri <nnasiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 14:41:48 by nnasiri           #+#    #+#             */
/*   Updated: 2024/08/21 15:59:34 by nnasiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

char	**copy_map(t_data *data)
{
	char	**map_cpy;
	int		i;

	i = 0;
	map_cpy = malloc((data->map.line_count + 1) * sizeof(char *));
	if (!map_cpy)
		ft_error("ALLOCATION FAILURE", data);
	while (i < data->map.line_count)
	{
		map_cpy[i] = ft_strdup_2(data->map.map[i], data, map_cpy);
		i++;
	}
	map_cpy[i] = NULL;
	return (map_cpy);
}

void	check_access_fds(t_data *data, char **map_cpy, int i, int j)
{
	if (i < 0 || j < 0 || i > data->map.line_count || j > data->map.line_len
		|| map_cpy[i][j] == '1' || map_cpy[i][j] == 'V')
		return ;
	if (map_cpy[i][j] == 'C')
		data->map.collected++;
	else if (map_cpy[i][j] == 'E')
		data->map.can_exit++;
	map_cpy[i][j] = 'V';
	check_access_fds(data, map_cpy, i + 1, j);
	check_access_fds(data, map_cpy, i - 1, j);
	check_access_fds(data, map_cpy, i, j + 1);
	check_access_fds(data, map_cpy, i, j - 1);
}

void	exit_is_accessible(t_data *data)
{
	char	**map_cpy;

	map_cpy = copy_map(data);
	check_access_fds(data, map_cpy, data->player_i, data->player_j);
	if (data->map.collected != data->map.count_c)
	{
		ft_free(map_cpy);
		ft_error("ALL COLLECTIBLE IS NOT IN ACCESS", data);
	}
	if (data->map.can_exit == 0)
	{
		ft_free(map_cpy);
		ft_error("EXIT IS NOT IN ACCESS", data);
	}
	ft_free(map_cpy);
}
