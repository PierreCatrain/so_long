/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: picatrai <picatrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 18:53:21 by picatrai          #+#    #+#             */
/*   Updated: 2023/12/18 14:14:16 by picatrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void    ft_free_2d(char **str)
{
    int i;
    
    i = 0;
    while (str[i])
        free(str[i++]);
    free(str);
}

void    ft_free_map(t_data data)
{
    int i;

    i = 0;
    while (data.map[i])
    {
        free(data.map[i]);
        i++;
    }
    free(data.map);
}

void    ft_free_and_destroy(t_data data)
{
    int i;
    
    mlx_destroy_window(data.mlx_ptr, data.win_ptr);
    i = 0;
    // while (i <= 34)
    // {
    //     free(data.img[i].mlx_img);
    //     i++;
    // }
    free(data.img);
    free(data.mlx_ptr);
    exit(EXIT_FAILURE);
}