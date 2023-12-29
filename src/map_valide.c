/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_valide.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: picatrai <picatrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 11:39:21 by picatrai          #+#    #+#             */
/*   Updated: 2023/12/29 14:51:59 by picatrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

int	check_rectangle(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (ft_strlen(map[i]) != ft_strlen(map[0]))
			return (0);
		i++;
	}
	return (1);
}

int	check_bordure(char **map)
{
	int	i;
	int	j;
	int	bord_right;
	int	bord_bottom;

	i = 0;
	bord_bottom = ft_strlen(*map);
	bord_right = ft_strlen(map[0]);
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if ((i == 0 || i == bord_bottom || j == 0 \
			|| j == bord_right) && map[i][j] != '1')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_element_inconnu(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != '0' && map[i][j] != '1' && map[i][j] != 'C' \
			&& map[i][j] != 'P' && map[i][j] != 'E' && map[i][j] != 'A')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_element(char **map, int nb_collectible, int nb_player, int nb_exit)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				nb_collectible++;
			else if (map[i][j] == 'P')
				nb_player++;
			else if (map[i][j] == 'E')
				nb_exit++;
			j++;
		}
		i++;
	}
	if (nb_collectible < 1 || nb_player != 1 || nb_exit != 1)
		return (0);
	return (1);
}

int	map_valide(char **map)
{
	if (check_rectangle(map) == 0)
		return (ft_putstr_error("Error\npas un recangle\n"), 0);
	if (check_bordure(map) == 0)
		return (ft_putstr_error("Error\nabsence de mur\n"), 0);
	if (check_element_inconnu(map) == 0)
		return (ft_putstr_error("Error\nelements inconnus\n"), 0);
	if (check_element(map, 0, 0, 0) == 0)
		return (ft_putstr_error("Error\nelements attendu manquant\n"), 0);
	if (check_path(map) == 0)
		return (ft_putstr_error("Error\npas de chemin vers la sortie\n"), 0);
	return (1);
}
