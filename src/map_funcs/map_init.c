/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnasiri <nnasiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 18:03:32 by nnasiri           #+#    #+#             */
/*   Updated: 2024/08/14 18:03:33 by nnasiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	ft_free(char **map)
{
	int	i;

	i = 0;
	while (map[i] != NULL)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

int	line_number(char *map_name)
{
	int		fd;
	char	*line;
	int		line_count;

	line_count = 0;
	fd = open(map_name, O_RDONLY);
	if (fd < 0)
		err_msg("COULD NOT OPEN THE FILE");
	line = get_next_line(fd);
	if (line == NULL)
	{
		close(fd);
		err_msg("The file is empty");
	}
	while (line != NULL)
	{
		line_count++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (line_count);
}

void	put_input_in_map(t_data *data, int i, int row, int col)
{
	char	*line;

	line = get_next_line(data->map.fd);
	while (line != NULL)
	{
		data->map.map[row] = malloc((ft_strlen(line) + 2) * sizeof(char));
		if (!data->map.map[row])
		{
			free(line);
			ft_error("COULD NOT ALLOCATE", data);
		}
		while (line[i] != '\0' && line[i] != '\r' && line[i] != '\n')
			data->map.map[row][col++] = line[i++];
		data->map.map[row][col++] = '\n';
		data->map.map[row++][col] = '\0';
		col = 0;
		i = 0;
		free(line);
		line = get_next_line(data->map.fd);
	}
	data->map.map[row] = NULL;
	data->map.line_len = ft_strlen(data->map.map[0]) - 1;
}

void	map_init(char *map_name, t_data *data)
{
	int	row;
	int	i;
	int	col;

	i = 0;
	row = 0;
	col = 0;
	data->map.line_count = line_number(map_name);
	data->map.path = map_name;
	data->map.map = malloc((data->map.line_count + 1) * sizeof(char *));
	if (data->map.map == NULL)
		ft_error("Could not allocate memory for map", data);
	data->map.fd = open(map_name, O_RDONLY);
	if (data->map.fd < 0)
		ft_error("Could not open the map", data);
	put_input_in_map(data, i, row, col);
	close(data->map.fd);
}
