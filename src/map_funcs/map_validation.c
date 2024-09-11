/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnasiri <nnasiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 18:03:43 by nnasiri           #+#    #+#             */
/*   Updated: 2024/08/21 14:55:07 by nnasiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	map_existence(char *map_name, t_data *data)
{
	int	fd;

	fd = open(map_name, O_RDONLY);
	if (fd < 0)
		ft_error("MAP DOES NOT EXIST", data);
	close(fd);
}

void	map_extension(char *map_name, t_data *data)
{
	int		len;
	int		len_after_slash;
	int		i;
	char	*l_slash;

	l_slash = ft_strrchr(map_name, '/');
	len_after_slash = ft_strlen(l_slash + 1);
	if (len_after_slash <= 4)
		ft_error("FILE IS TOO SHORT", data);
	len = ft_strlen(map_name);
	i = 0;
	while (map_name[i] && map_name[i] != '.')
		i++;
	if (ft_strncmp(map_name + len - 4, ".ber", 4) != 0)
		ft_error("FILE EXTENSION IS WRONG", data);
}

void	map_validation(char *map_name, t_data *data)
{
	map_existence(map_name, data);
	map_extension(map_name, data);
}
