/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: picatrai <picatrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 16:55:16 by picatrai          #+#    #+#             */
/*   Updated: 2023/12/29 11:17:00 by picatrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

int	ft_find_player(char **map, int *i, int *j, char c)
{
	*i = 0;
	while (map[*i])
	{
		*j = 0;
		while (map[*i][*j])
		{
			if (map[*i][*j] == c)
				return (1);
			(*j)++;
		}
		(*i)++;
	}
	return (0);
}

int	ft_nbr_len(int nbr)
{
	int	len;

	len = 0;
	if (nbr == 0)
		return (1);
	while (nbr > 0)
	{
		len++;
		nbr /= 10;
	}
	return (len);
}

void	ft_putnbr_steps(t_data data)
{
	int	size;
	int	pixel;

	pixel = 585;
	size = ft_nbr_len(data.count_step);
	while (size < 5)
	{
		mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, \
		data.img[9].mlx_img, pixel, 325);
		pixel -= 40;
		size++;
	}
	if (data.count_step == 0)
		mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, \
		data.img[10].mlx_img, pixel, 325);
	while (data.count_step > 0)
	{
		mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, \
		data.img[(data.count_step % 10) + 10].mlx_img, pixel, 325);
		pixel -= 40;
		data.count_step /= 10;
	}
}

void	ft_put_my_images(t_data *data, t_utils *utils)
{
	if (data->map[utils->index_i][utils->index_j] == '0')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, \
		data->img[5].mlx_img, utils->pixel_j, utils->pixel_i);
	else if (data->map[utils->index_i][utils->index_j] == '1')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, \
		data->img[31].mlx_img, utils->pixel_j, utils->pixel_i);
	else if (data->map[utils->index_i][utils->index_j] == 'C')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, \
		data->img[34].mlx_img, utils->pixel_j, utils->pixel_i);
	else if (data->map[utils->index_i][utils->index_j] == 'E')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, \
		data->img[7].mlx_img, utils->pixel_j, utils->pixel_i);
	else if (data->map[utils->index_i][utils->index_j] == 'P')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, \
		data->img[20].mlx_img, utils->pixel_j, utils->pixel_i);
	else if (data->map[utils->index_i][utils->index_j] == 'A')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, \
		data->img[25].mlx_img, utils->pixel_j, utils->pixel_i);
	utils->index_j++;
	utils->pixel_j += 25;
}

void	ft_print_map(t_data data)
{
	t_utils	utils;
	int		player_i;
	int		player_j;

	utils.pixel_i = 0;
	ft_find_player(data.map, &player_i, &player_j, 'P');
	utils.index_i = player_i - 6;
	while (utils.index_i <= player_i + 6)
	{
		utils.index_j = player_j - 12;
		utils.pixel_j = 0;
		while (utils.index_j <= player_j + 12)
			ft_put_my_images(&data, &utils);
		utils.index_i++;
		utils.pixel_i += 25;
	}
	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, \
	data.img[0].mlx_img, 0, 325);
	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, \
	data.img[8].mlx_img, 225, 325);
	ft_putnbr_steps(data);
}
