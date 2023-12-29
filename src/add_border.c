/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_border.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: picatrai <picatrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 12:52:37 by picatrai          #+#    #+#             */
/*   Updated: 2023/12/29 11:22:07 by picatrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

char	*ft_border(char **str)
{
	char	*bord;
	int		j;

	bord = malloc((ft_strlen(str[0]) + 24) * sizeof(char));
	if (bord == NULL)
		return (NULL);
	j = 0;
	while (j < ft_strlen(str[0]) + 23)
		bord[j++] = '1';
	bord[j] = '\0';
	return (bord);
}

char	*ft_complet(char **str, int i)
{
	char	*complet;
	int		j;

	complet = malloc((ft_strlen(str[0]) + 24) * sizeof(char));
	if (complet == NULL)
		return (NULL);
	j = 0;
	while (j < ft_strlen(str[0]) + 23)
	{
		if (j <= 10 || j >= ft_strlen(str[0]) + 10)
			complet[j] = '1';
		else
			complet[j] = str[i][j - 11];
		j++;
	}
	complet[j] = '\0';
	return (complet);
}

char	**add_border(char **str)
{
	char	**map;
	int		i;

	map = malloc((ft_strlen_2d(str) + 23) * sizeof(char *));
	if (map == NULL)
		return (NULL);
	i = 0;
	while (i < ft_strlen_2d(str) + 11)
	{
		if (i <= 4 || i >= ft_strlen_2d(str) + 4)
		{
			map[i] = ft_border(str);
			if (map[i] == NULL)
				return (NULL);
		}
		else
		{
			map[i] = ft_complet(str, i - 5);
			if (map[i] == NULL)
				return (NULL);
		}
		i++;
	}
	map[i] = 0;
	return (ft_free_2d(str), map);
}
