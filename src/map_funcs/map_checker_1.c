/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnasiri <nnasiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 12:57:42 by nnasiri           #+#    #+#             */
/*   Updated: 2024/09/03 16:44:27 by nnasiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	check_empty_line(char *str, t_data *data)
{
	if (str[0] == '\n' || str[0] == '\r')
		ft_error("EMPTY LINE", data);
}

void	map_rectangle(t_data *data)
{
	int	i;
	int	count;

	i = 0;
	while (data->map.map[i] != NULL)
	{
		check_empty_line(data->map.map[i], data);
		count = 0;
		while (data->map.map[i][count] != '\0'
			&& data->map.map[i][count] != '\n')
			count++;
		if (count != data->map.line_len)
			ft_error("NOT RECTANGULAR", data);
		i++;
	}
}

void	map_checker(t_data *data)
{
	map_rectangle(data);
	check_strange_param(data);
	map_wall(data);
	map_elements_counts(data);
	exit_is_accessible(data);
}
