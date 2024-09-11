/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnasiri <nnasiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 15:52:33 by nnasiri           #+#    #+#             */
/*   Updated: 2024/08/21 14:49:36 by nnasiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static char	*str_cpy(char *dest, char *src)
{
	unsigned int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strdup_2(char *src, t_data *data, char **map_cpy)
{
	char			*dest_arr;
	unsigned int	len;

	len = ft_strlen(src);
	dest_arr = (char *)malloc((len + 1) * sizeof(char));
	if (!dest_arr)
	{
		ft_free(data->map.map);
		ft_free(map_cpy);
		err_msg("Could not allocate memory in map_cpy");
	}
	return (str_cpy(dest_arr, src));
}
