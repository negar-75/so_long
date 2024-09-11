/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnasiri <nnasiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 14:28:33 by nnasiri           #+#    #+#             */
/*   Updated: 2024/08/21 14:48:20 by nnasiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;

	if (n == 0)
		return (0);
	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0' && i < n - 1)
	{
		i++;
	}
	return ((unsigned char)(s1[i]) - (unsigned char)s2[i]);
}
// int main()
// {
// 	printf("%d\n",(ft_strncmp("test\0", "test\200", 6)));
// 	printf("%d",strncmp("test\0", "test\2000", 6));
// 	return (0);
// }