/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnasiri <nnasiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 14:17:46 by nnasiri           #+#    #+#             */
/*   Updated: 2024/04/24 16:28:39 by nnasiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/get_next_line.h"

static void	free_memory(char **stash)
{
	free(*stash);
	*stash = NULL;
}

static int	read_from_content(int fd, char **stash, char *buffer)
{
	char	*tmp;
	int		bytes;

	bytes = read(fd, buffer, BUFFER_SIZE);
	if (bytes < 0 || buffer == NULL)
	{
		free_memory(stash);
		return (-1);
	}
	if (bytes == 0)
		return (bytes);
	buffer[bytes] = '\0';
	tmp = ft_strjoin_2(*stash, buffer);
	if (*stash)
		free(*stash);
	*stash = tmp;
	return (bytes);
}

static void	remove_result(char **stash)
{
	char	*nl;
	char	*tmp;

	nl = ft_strchr(*stash, '\n');
	if (!nl)
	{
		free_memory(stash);
		return ;
	}
	tmp = malloc((ft_strlen(nl) + 1) * sizeof(char));
	if (!tmp)
	{
		free_memory(stash);
		return ;
	}
	ft_strcpy(tmp, nl + 1);
	free(*stash);
	*stash = tmp;
	if (**stash == '\0')
		free_memory(stash);
}

static void	get_result(char **stash, char **result)
{
	size_t	i;

	i = 0;
	while (!((*stash)[i] == '\n' || (*stash)[i] == '\0'))
		i++;
	if ((*stash)[i] == '\n')
		(*result) = malloc(sizeof(char) * (i + 2));
	if ((*stash)[i] == '\0')
		(*result) = malloc(sizeof(char) * (i + 1));
	if (*result == NULL)
	{
		free_memory(stash);
		return ;
	}
	i = -1;
	while ((*stash)[++i] != '\n' && (*stash)[i] != '\0')
		(*result)[i] = (*stash)[i];
	if ((*stash)[i] == '\n')
		(*result)[i++] = '\n';
	(*result)[i] = '\0';
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*result;
	char		buffer[BUFFER_SIZE + 1];
	int			bytes;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	bytes = 1;
	while (ft_strchr(stash, '\n') == NULL && bytes > 0)
		bytes = read_from_content(fd, &stash, buffer);
	if (bytes == -1)
		return (NULL);
	if (ft_strlen(stash) != 0)
	{
		get_result(&stash, &result);
		remove_result(&stash);
		return (result);
	}
	else
		return (NULL);
}

// int main()
// {
//   char *line;

//   int fd = open("text2.txt", 0);
//   if (fd == -1)
//   {
//     printf("Error opening file");
//     return (1);
//   }
//   line = get_next_line(fd);
//   while (line != NULL)
//   {
// 	printf("%s",line);
//     free(line);
//     line = get_next_line(fd);
//   }

//   close(fd);
//   return (0);
// }