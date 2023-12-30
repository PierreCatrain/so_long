/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: picatrai <picatrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 18:53:21 by picatrai          #+#    #+#             */
/*   Updated: 2023/12/30 12:59:23 by picatrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	ft_free_2d(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
}

void	ft_free_map(t_data data)
{
	int	i;

	i = 0;
	while (data.map[i])
	{
		free(data.map[i]);
		i++;
	}
	free(data.map);
}

int	ft_free_and_destroy_2(t_data *data)
{
	int	i;

	i = 0;
	while (i <= 34)
	{
		if (!(i == 0 || i == 20 || i == 25 || i == 31 || i == 34))
			mlx_destroy_image(data->mlx_ptr, data->img[i].mlx_img);
		i++;
	}
	free(data->img);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	ft_free_map(*data);
	exit(EXIT_FAILURE);
	return (1);
}

int	ft_free_and_destroy(t_data data)
{
	int	i;

	i = 0;
	while (i <= 34)
	{
		if (!(i == 0 || i == 20 || i == 25 || i == 31 || i == 34))
			mlx_destroy_image(data.mlx_ptr, data.img[i].mlx_img);
		i++;
	}
	free(data.img);
	mlx_destroy_window(data.mlx_ptr, data.win_ptr);
	mlx_destroy_display(data.mlx_ptr);
	free(data.mlx_ptr);
	ft_free_map(data);
	exit(EXIT_FAILURE);
	return (1);
}
