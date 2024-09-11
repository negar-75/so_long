/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnasiri <nnasiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 17:55:06 by nnasiri           #+#    #+#             */
/*   Updated: 2024/08/21 18:58:18 by nnasiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
		err_msg("Please give the map");
	init_data(&data);
	map_validation(argv[1], &data);
	map_init(argv[1], &data);
	map_checker(&data);
	start_game(&data);
	init_image(&data);
	loop_images(data);
	data_clean_up(&data);
	return (0);
}
