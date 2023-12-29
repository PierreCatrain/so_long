/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: picatrai <picatrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 14:10:00 by picatrai          #+#    #+#             */
/*   Updated: 2023/12/29 12:07:47 by picatrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	ft_get_case_possible(char **map, int i, int j, \
t_coordonees **case_possible)
{
	if (map[i][j - 1] != '1' && ft_is_new(*case_possible, i, j - 1) == 1)
	{
		ft_lstadd_back(case_possible, ft_lstnew(i, j - 1));
		ft_get_case_possible(map, i, j - 1, case_possible);
	}
	if (map[i + 1][j] != '1' && ft_is_new(*case_possible, i + 1, j) == 1)
	{
		ft_lstadd_back(case_possible, ft_lstnew(i + 1, j));
		ft_get_case_possible(map, i + 1, j, case_possible);
	}
	if (map[i - 1][j] != '1' && ft_is_new(*case_possible, i - 1, j) == 1)
	{
		ft_lstadd_back(case_possible, ft_lstnew(i - 1, j));
		ft_get_case_possible(map, i - 1, j, case_possible);
	}
	if (map[i][j + 1] != '1' && ft_is_new(*case_possible, i, j + 1) == 1)
	{
		ft_lstadd_back(case_possible, ft_lstnew(i, j + 1));
		ft_get_case_possible(map, i, j + 1, case_possible);
	}
}

int	ft_find_case(char **map, t_coordonees *case_possible, char c)
{
	int	count;

	count = 0;
	while (case_possible != NULL)
	{
		if (map[case_possible->i][case_possible->j] == c)
			count++;
		case_possible = case_possible->next;
	}
	return (count);
}

int	ft_nb_collectible(char **map)
{
	int	count;
	int	i;
	int	j;

	count = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

void	ft_free_list(t_coordonees *case_possible)
{
	t_coordonees	*tmp;

	while (case_possible != NULL)
	{
		tmp = case_possible;
		case_possible = case_possible->next;
		free(tmp);
	}
}

int	check_path(char **map)
{
	t_coordonees	*case_possible;
	int				i;
	int				j;

	ft_find_player(map, &i, &j, 'P');
	case_possible = ft_lstnew(i, j);
	if (case_possible == NULL)
		return (0);
	ft_get_case_possible(map, i, j, &case_possible);
	if (ft_find_case(map, case_possible, 'E') == 0)
		return (ft_free_list(case_possible), 0);
	if (ft_nb_collectible(map) != ft_find_case(map, case_possible, 'C'))
		return (ft_free_list(case_possible), 0);
	return (ft_free_list(case_possible), 1);
}
