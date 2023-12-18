/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: picatrai <picatrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 19:23:41 by picatrai          #+#    #+#             */
/*   Updated: 2023/12/04 22:09:12 by picatrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void    ft_key_w(t_data data, int *count_item, int *count_step, int *hp)
{
    int i;
    int j;
    int buffer;
    
    buffer = data.count_step;
    *count_step = ++buffer;
    data.img[20].mlx_img = data.img[22].mlx_img;
    buffer = data.count_item;
    ft_find_player(data.map, &i, &j, 'P');
    if ((data.map[i - 1][j] != '1' && data.map[i - 1][j] != 'E') || (data.map[i - 1][j] == 'E' && data.count_item == data.nb_total_item))
    {
        if (data.map[i - 1][j] == 'C')
             *count_item = ++buffer;
        if (data.map[i - 1][j] == 'E')
            ft_free_and_destroy(data);
        if (data.map[i - 1][j] == 'A')
        {
            buffer = data.hp;
            *hp = --buffer;
            data.img[0] = data.img[*hp];
        }
        else
        {
            data.map[i - 1][j] = data.map[i][j];
            data.map[i][j] = '0';
        }
        if (*hp == 0)
            ft_free_and_destroy(data);
    }
}

void    ft_key_a(t_data data, int *count_item, int *count_step, int *hp)
{
    int i;
    int j;
    int buffer;
    
    buffer = data.count_step;
    *count_step = ++buffer;
    data.img[20].mlx_img = data.img[23].mlx_img;
    buffer = data.count_item;
    ft_find_player(data.map, &i, &j, 'P');
    if ((data.map[i][j - 1] != '1' && data.map[i][j - 1] != 'E') || (data.map[i][j - 1] == 'E' && data.count_item == data.nb_total_item))
    {
        if (data.map[i][j - 1] == 'C')
            *count_item = ++buffer;
        if (data.map[i][j - 1] == 'E')
            ft_free_and_destroy(data);
        if (data.map[i][j - 1] == 'A')
        {
            buffer = data.hp;
            *hp = --buffer;
            data.img[0] = data.img[*hp];
        }
        else
        {
            data.map[i][j - 1] = data.map[i][j];
            data.map[i][j] = '0';
        }
        if (*hp == 0)
            ft_free_and_destroy(data);
    }
}

void    ft_key_s(t_data data, int *count_item, int *count_step, int *hp)
{
    int i;
    int j;
    int buffer;
    
    buffer = data.count_step;
    *count_step = ++buffer;
    data.img[20].mlx_img = data.img[21].mlx_img;
    buffer = data.count_item;
    ft_find_player(data.map, &i, &j, 'P');
    if ((data.map[i + 1][j] != '1' && data.map[i + 1][j] != 'E') || (data.map[i + 1][j] == 'E' && data.count_item == data.nb_total_item))
    {
        if (data.map[i + 1][j] == 'C')
             *count_item = ++buffer;
        if (data.map[i + 1][j] == 'E')
            ft_free_and_destroy(data);
        if (data.map[i + 1][j] == 'A')
        {
            buffer = data.hp;
            *hp = --buffer;
            data.img[0] = data.img[*hp];
        }
        else
        {
            data.map[i + 1][j] = data.map[i][j];
            data.map[i][j] = '0';
        }
        if (*hp == 0)
            ft_free_and_destroy(data);
    }
}

void    ft_key_d(t_data data, int *count_item, int *count_step, int *hp)
{
    int i;
    int j;
    int buffer;
    
    buffer = data.count_step;
    *count_step = ++buffer;
    data.img[20].mlx_img = data.img[24].mlx_img;
    buffer = data.count_item;
    ft_find_player(data.map, &i, &j, 'P');
    if ((data.map[i][j + 1] != '1' && data.map[i][j + 1] != 'E') || (data.map[i][j + 1] == 'E' && data.count_item == data.nb_total_item))
    {
        if (data.map[i][j + 1] == 'C')
             *count_item = ++buffer;
        if (data.map[i][j + 1] == 'E')
            ft_free_and_destroy(data);
        if (data.map[i][j + 1] == 'A')
        {
            buffer = data.hp;
            *hp = --buffer;
            data.img[0] = data.img[*hp];
        }
        else
        {
            data.map[i][j + 1] = data.map[i][j];
            data.map[i][j] = '0';
        }
        if (*hp == 0)
            ft_free_and_destroy(data);
    }
}