/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: picatrai <picatrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 16:55:16 by picatrai          #+#    #+#             */
/*   Updated: 2023/12/04 21:35:15 by picatrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

int    ft_find_player(char **map, int *i, int *j, char c)
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

int ft_nbr_len(int nbr)
{
    int len;

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

void    ft_putnbr_steps(t_data data)
{
    int size;
    int pixel;

    pixel = 585;
    size = ft_nbr_len(data.count_step);
    while (size < 5)
    {
        mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.img[9].mlx_img, pixel, 325);
        pixel -= 40;
        size++;
    }
    if (data.count_step == 0)
        mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.img[10].mlx_img, pixel, 325);
    while (data.count_step > 0)
    {
        mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.img[(data.count_step % 10) + 10].mlx_img, pixel, 325);
        pixel -= 40;
        data.count_step /= 10;
    }
    
}

void    ft_print_map(t_data data)
{
    int player_i;
    int player_j;
    int index_i;
    int index_j;
    int pixel_i;
    int pixel_j;

    pixel_i = 0;
    ft_find_player(data.map, &player_i, &player_j, 'P');
    index_i = player_i - 6;
    while (index_i <= player_i + 6)
    {
        index_j = player_j - 12;
        pixel_j = 0;
        while (index_j <= player_j + 12)
        {
            if (data.map[index_i][index_j] == '0')
                mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.img[5].mlx_img, pixel_j, pixel_i);
            else if (data.map[index_i][index_j] == '1')
                mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.img[31].mlx_img, pixel_j, pixel_i);
            else if (data.map[index_i][index_j] == 'C')
                mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.img[34].mlx_img, pixel_j, pixel_i);
            else if (data.map[index_i][index_j] == 'E')
                mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.img[7].mlx_img, pixel_j, pixel_i);
            else if (data.map[index_i][index_j] == 'P')
                mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.img[20].mlx_img, pixel_j, pixel_i);
            else if (data.map[index_i][index_j] == 'A')
                mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.img[25].mlx_img, pixel_j, pixel_i);
            index_j++;
            pixel_j += 25;
        }
        index_i++;
        pixel_i += 25;
    }
    mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.img[0].mlx_img, 0, 325);
    mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.img[8].mlx_img, 225, 325);
    ft_putnbr_steps(data);
}