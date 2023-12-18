/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_item.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: picatrai <picatrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 20:06:18 by picatrai          #+#    #+#             */
/*   Updated: 2023/11/29 22:05:35 by picatrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void    ft_nb_total_item(t_data data, int *count, int *total)
{
    int i;
    int j;
    int buffer;
    
    *count = 0;
    buffer = 0;
    i = 0;
    while (data.map[i])
    {
        j = 0;
        while (data.map[i][j])
        {
            if (data.map[i][j] == 'C')
                buffer++;
            j++;
        }
        i++;
    }
    *total = buffer;
}