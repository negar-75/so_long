/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_msg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnasiri <nnasiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 14:40:36 by nnasiri           #+#    #+#             */
/*   Updated: 2024/09/03 15:30:57 by nnasiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	map_print(t_data *data)
{
	int	i;

	i = 0;
	while (data->map.map[i])
	{
		ft_printf("%s", data->map.map[i]);
		i++;
	}
}

void	game_dashboard(t_data *data)
{
	ft_printf("you took %d steps\n", data->step_counts);
	ft_printf("%d collectible is left\n", data->map.collected);
}
