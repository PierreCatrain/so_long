/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: picatrai <picatrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 19:23:41 by picatrai          #+#    #+#             */
/*   Updated: 2023/12/29 12:01:19 by picatrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	ft_gain_place_key(t_data *data, int *count_item, int *hp)
{
	if (data->map[data->new_i][data->new_j] == 'C')
		*count_item = data->count_item + 1;
	if (data->map[data->new_i][data->new_j] == 'E')
		ft_free_and_destroy(*data);
	if (data->map[data->new_i][data->new_j] == 'A')
	{
		*hp = data->hp - 1;
		data->img[0] = data->img[*hp];
	}
	else
	{
		data->map[data->new_i][data->new_j] = \
		data->map[data->actual_i][data->actual_j];
		data->map[data->actual_i][data->actual_j] = '0';
	}
	if (*hp == 0)
		ft_free_and_destroy(*data);
}

void	ft_key_w(t_data data, int *count_item, int *count_step, int *hp)
{
	*count_step = data.count_step + 1;
	data.img[20].mlx_img = data.img[22].mlx_img;
	ft_find_player(data.map, &data.actual_i, &data.actual_j, 'P');
	data.new_i = data.actual_i - 1;
	data.new_j = data.actual_j;
	if ((data.map[data.new_i][data.new_j] != '1' \
	&& data.map[data.new_i][data.new_j] != 'E') \
	|| (data.map[data.new_i][data.new_j] == 'E' \
	&& data.count_item == data.nb_total_item))
		ft_gain_place_key(&data, count_item, hp);
}

void	ft_key_a(t_data data, int *count_item, int *count_step, int *hp)
{
	*count_step = data.count_step + 1;
	data.img[20].mlx_img = data.img[23].mlx_img;
	ft_find_player(data.map, &data.actual_i, &data.actual_j, 'P');
	data.new_i = data.actual_i;
	data.new_j = data.actual_j - 1;
	if ((data.map[data.new_i][data.new_j] != '1' \
	&& data.map[data.new_i][data.new_j] != 'E') \
	|| (data.map[data.new_i][data.new_j] == 'E' \
	&& data.count_item == data.nb_total_item))
		ft_gain_place_key(&data, count_item, hp);
}

void	ft_key_s(t_data data, int *count_item, int *count_step, int *hp)
{
	*count_step = data.count_step + 1;
	data.img[20].mlx_img = data.img[21].mlx_img;
	ft_find_player(data.map, &data.actual_i, &data.actual_j, 'P');
	data.new_i = data.actual_i + 1;
	data.new_j = data.actual_j;
	if ((data.map[data.new_i][data.new_j] != '1' \
	&& data.map[data.new_i][data.new_j] != 'E') \
	|| (data.map[data.new_i][data.new_j] == 'E' \
	&& data.count_item == data.nb_total_item))
		ft_gain_place_key(&data, count_item, hp);
}

void	ft_key_d(t_data data, int *count_item, int *count_step, int *hp)
{
	*count_step = data.count_step + 1;
	data.img[20].mlx_img = data.img[24].mlx_img;
	ft_find_player(data.map, &data.actual_i, &data.actual_j, 'P');
	data.new_i = data.actual_i;
	data.new_j = data.actual_j + 1;
	if ((data.map[data.new_i][data.new_j] != '1' \
	&& data.map[data.new_i][data.new_j] != 'E') \
	|| (data.map[data.new_i][data.new_j] == 'E' \
	&& data.count_item == data.nb_total_item))
		ft_gain_place_key(&data, count_item, hp);
}
