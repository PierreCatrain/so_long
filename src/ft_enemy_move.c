/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_enemy_move.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: picatrai <picatrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 19:44:13 by picatrai          #+#    #+#             */
/*   Updated: 2023/12/17 17:36:35 by picatrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

int    ft_find_enemy(t_data data, int *i, int *j, int new)
{
    int     buffer;

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

int     ft_not_twice(t_coordonees *enemy, int new_i, int new_j)
{
    while (enemy != NULL)
    {
        if (new_i == enemy->i && new_j == enemy->j)
            return (0);
        enemy = enemy->next;
    }
    return (1);
}

void    ft_enemy_move_w(t_data data, int *hp)
{
    int buffer;
    t_coordonees *enemy;
    
    enemy = NULL;
    data.i_enemy = 0;
    data.j_enemy = -1;
    buffer = data.hp;
    data.img[25].mlx_img = data.img[27].mlx_img;
    while (ft_find_enemy(data, &data.i_enemy, &data.j_enemy, 1) == 1)
    {
        if ((data.map[data.i_enemy - 1][data.j_enemy] == '0' || data.map[data.i_enemy - 1][data.j_enemy] == 'P') && ft_not_twice(enemy, data.i_enemy, data.j_enemy))
        {
            if (data.map[data.i_enemy - 1][data.j_enemy] == 'P')
                *hp = --buffer;
            else
            {
                data.map[data.i_enemy - 1][data.j_enemy] = data.map[data.i_enemy][data.j_enemy];
                data.map[data.i_enemy][data.j_enemy] = '0';
                ft_add_coordonees(&enemy, data.i_enemy - 1, data.j_enemy);
                if (enemy == NULL)
                    return;
            }
            data.img[0] = data.img[*hp];
            if (*hp <= 0)
                ft_free_and_destroy(data);
        }
    }
    ft_free_list(enemy);
}

void    ft_enemy_move_a(t_data data, int *hp)
{
    int buffer;
    t_coordonees *enemy;

    enemy = NULL;
    data.i_enemy = 0;
    data.j_enemy = -1;
    buffer = data.hp;
    data.img[25].mlx_img = data.img[28].mlx_img;
    while (ft_find_enemy(data, &data.i_enemy, &data.j_enemy, 1) == 1)
    {
        if ((data.map[data.i_enemy][data.j_enemy - 1] == '0' || data.map[data.i_enemy][data.j_enemy - 1] == 'P') && ft_not_twice(enemy, data.i_enemy, data.j_enemy))
        {
            if (data.map[data.i_enemy][data.j_enemy - 1] == 'P')
                *hp = --buffer;
            else
            {
                data.map[data.i_enemy][data.j_enemy - 1] = data.map[data.i_enemy][data.j_enemy];
                data.map[data.i_enemy][data.j_enemy] = '0';
                ft_add_coordonees(&enemy, data.i_enemy, data.j_enemy - 1);
                if (enemy == NULL)
                    return;
            }
            data.img[0] = data.img[*hp];
            if (*hp <= 0)
                ft_free_and_destroy(data);
        }
    }
    ft_free_list(enemy);
}

void    ft_enemy_move_s(t_data data, int *hp)
{
    int buffer;
    t_coordonees *enemy;

    enemy = NULL;
    data.i_enemy = 0;
    data.j_enemy = -1;
    buffer = data.hp;
    data.img[25].mlx_img = data.img[26].mlx_img;
    while (ft_find_enemy(data, &data.i_enemy, &data.j_enemy, 1) == 1)
    {
        if ((data.map[data.i_enemy + 1][data.j_enemy] == '0' || data.map[data.i_enemy + 1][data.j_enemy] == 'P') && ft_not_twice(enemy, data.i_enemy, data.j_enemy))
        {
            if (data.map[data.i_enemy + 1][data.j_enemy] == 'P')
                *hp = --buffer;
            else
            {
                data.map[data.i_enemy + 1][data.j_enemy] = data.map[data.i_enemy][data.j_enemy];
                data.map[data.i_enemy][data.j_enemy] = '0';
                ft_add_coordonees(&enemy, data.i_enemy + 1, data.j_enemy);
                if (enemy == NULL)
                    return;
            }
            data.img[0] = data.img[*hp];
            if (*hp <= 0)
                ft_free_and_destroy(data);
        }
    }
    ft_free_list(enemy);
}

void    ft_enemy_move_d(t_data data, int *hp)
{
    int buffer;
    t_coordonees *enemy;

    enemy = NULL;
    data.i_enemy = 0;
    data.j_enemy = -1;
    buffer = data.hp;
    data.img[25].mlx_img = data.img[29].mlx_img;
    while (ft_find_enemy(data, &data.i_enemy, &data.j_enemy, 1) == 1)
    {
        if ((data.map[data.i_enemy][data.j_enemy + 1] == '0' || data.map[data.i_enemy][data.j_enemy + 1] == 'P') && ft_not_twice(enemy, data.i_enemy, data.j_enemy))
        {
            if (data.map[data.i_enemy][data.j_enemy + 1] == 'P')
                *hp = --buffer;
            else
            {
                data.map[data.i_enemy][data.j_enemy + 1] = data.map[data.i_enemy][data.j_enemy];
                data.map[data.i_enemy][data.j_enemy] = '0';
                ft_add_coordonees(&enemy, data.i_enemy, data.j_enemy + 1);
                if (enemy == NULL)
                    return;
            }
            data.img[0] = data.img[*hp];
            if (*hp <= 0)
                ft_free_and_destroy(data);
        }
    }
    ft_free_list(enemy);
}