/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_enemy_move.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: picatrai <picatrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 19:44:13 by picatrai          #+#    #+#             */
/*   Updated: 2023/12/29 11:25:28 by picatrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	ft_gain_de_place(t_data	*data, int *hp, int new_i, int new_j)
{
	int					buffer;

	buffer = data->hp;
	if (data->map[new_i][new_j] == 'P')
		*hp = --buffer;
	else
	{
		data->map[new_i][new_j] = data->map[data->i_enemy][data->j_enemy];
		data->map[data->i_enemy][data->j_enemy] = '0';
		ft_add_coordonees(&data->enemy, new_i, new_j);
		if (data->enemy == NULL)
			return ;
	}
	data->img[0] = data->img[*hp];
	if (*hp <= 0)
	{
		ft_free_list(data->enemy);
		ft_free_and_destroy(*data);
	}
}

void	ft_enemy_move_w(t_data data, int *hp)
{
	data.enemy = NULL;
	data.i_enemy = 0;
	data.j_enemy = -1;
	data.img[25].mlx_img = data.img[27].mlx_img;
	while (ft_find_enemy(data, &data.i_enemy, &data.j_enemy, 1) == 1)
	{
		if ((data.map[data.i_enemy - 1][data.j_enemy] == '0' \
		|| data.map[data.i_enemy - 1][data.j_enemy] == 'P') \
		&& ft_not_twice(data.enemy, data.i_enemy, data.j_enemy))
			ft_gain_de_place(&data, hp, data.i_enemy - 1, data.j_enemy);
	}
	ft_free_list(data.enemy);
}

void	ft_enemy_move_a(t_data data, int *hp)
{
	data.enemy = NULL;
	data.i_enemy = 0;
	data.j_enemy = -1;
	data.img[25].mlx_img = data.img[28].mlx_img;
	while (ft_find_enemy(data, &data.i_enemy, &data.j_enemy, 1) == 1)
	{
		if ((data.map[data.i_enemy][data.j_enemy - 1] == '0' \
		|| data.map[data.i_enemy][data.j_enemy - 1] == 'P') \
		&& ft_not_twice(data.enemy, data.i_enemy, data.j_enemy))
			ft_gain_de_place(&data, hp, data.i_enemy, data.j_enemy - 1);
	}
	ft_free_list(data.enemy);
}

void	ft_enemy_move_s(t_data data, int *hp)
{
	data.enemy = NULL;
	data.i_enemy = 0;
	data.j_enemy = -1;
	data.img[25].mlx_img = data.img[26].mlx_img;
	while (ft_find_enemy(data, &data.i_enemy, &data.j_enemy, 1) == 1)
	{
		if ((data.map[data.i_enemy + 1][data.j_enemy] == '0' \
		|| data.map[data.i_enemy + 1][data.j_enemy] == 'P') \
		&& ft_not_twice(data.enemy, data.i_enemy, data.j_enemy))
			ft_gain_de_place(&data, hp, data.i_enemy + 1, data.j_enemy);
	}
	ft_free_list(data.enemy);
}

void	ft_enemy_move_d(t_data data, int *hp)
{
	data.enemy = NULL;
	data.i_enemy = 0;
	data.j_enemy = -1;
	data.img[25].mlx_img = data.img[29].mlx_img;
	while (ft_find_enemy(data, &data.i_enemy, &data.j_enemy, 1) == 1)
	{
		if ((data.map[data.i_enemy][data.j_enemy + 1] == '0' \
		|| data.map[data.i_enemy][data.j_enemy + 1] == 'P') \
		&& ft_not_twice(data.enemy, data.i_enemy, data.j_enemy))
			ft_gain_de_place(&data, hp, data.i_enemy, data.j_enemy + 1);
	}
	ft_free_list(data.enemy);
}
