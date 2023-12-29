/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_enemy_move_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: picatrai <picatrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 09:45:29 by picatrai          #+#    #+#             */
/*   Updated: 2023/12/29 11:26:12 by picatrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

int	ft_find_enemy(t_data data, int *i, int *j, int new)
{
	int		buffer;

	buffer = data.j_enemy;
	*j = ++buffer;
	while (data.map[*i])
	{
		if (new == 0)
		*j = 0;
		while (data.map[*i][*j])
		{
			new = 0;
			if (data.map[*i][*j] == 'A')
				return (1);
			(*j)++;
		}
		(*i)++;
	}
	return (0);
}

void	ft_add_coordonees(t_coordonees **enemy, int new_i, int new_j)
{
	if (*enemy == NULL)
	{
		*enemy = ft_lstnew(new_i, new_j);
		return ;
	}
	else
		return (ft_lstadd_back(enemy, ft_lstnew(new_i, new_j)));
}

int	ft_not_twice(t_coordonees *enemy, int new_i, int new_j)
{
	while (enemy != NULL)
	{
		if (new_i == enemy->i && new_j == enemy->j)
			return (0);
		enemy = enemy->next;
	}
	return (1);
}
