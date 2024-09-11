/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnasiri <nnasiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 14:58:10 by nnasiri           #+#    #+#             */
/*   Updated: 2024/09/03 15:31:53 by nnasiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../minilibx-linux/mlx.h"
# include "./ft_printf.h"
# include "./get_next_line.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_map
{
	int		fd;
	int		line_count;
	int		line_len;
	int		count_p;
	int		count_e;
	int		count_c;
	char	*path;
	char	**map;
	int		can_exit;
	int		collected;

}			t_map;
typedef struct s_img
{
	void	*player;
	void	*exit;
	void	*floor;
	void	*wall;
	void	*collectible;
	int		height;
	int		width;

}			t_img;
typedef struct s_data
{
	void	*mlx;
	void	*win;
	int		step_counts;
	int		player_i;
	int		player_j;
	int		win_height;
	int		win_width;
	t_map	map;
	t_img	img;
}			t_data;

char		*ft_strdup_2(char *src, t_data *data, char **map_cpy);
void		map_validation(char *map_name, t_data *data);
void		map_init(char *map_name, t_data *data);
void		map_checker(t_data *data);
void		map_wall(t_data *data);
void		check_strange_param(t_data *data);
void		map_elements_counts(t_data *data);
void		exit_is_accessible(t_data *data);
void		ft_free(char **map);
void		start_game(t_data *data);
void		init_image(t_data *data);
void		init_data(t_data *data);
int			render(t_data *data);
void		loop_images(t_data data);
void		game_dashboard(t_data *data);
int			key_handler(int keysym, t_data *data);
int			on_destroy(t_data *data);
void		loop_images(t_data data);
void		ft_error(char *str, t_data *data);
void		err_msg(char *str);
void		map_print(t_data *data);
void		data_clean_up(t_data *data);

#endif