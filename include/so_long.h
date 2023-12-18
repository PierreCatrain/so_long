/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: picatrai <picatrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 16:34:16 by picatrai          #+#    #+#             */
/*   Updated: 2023/12/17 18:07:59 by picatrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>

# define WINDOW_WIDTH 625
# define WINDOW_HEIGHT 425
# define TICK 500

typedef struct s_img
{
    void	*mlx_img;
    char	*addr;
    int		bpp;
    int		line_len;
    int		endian;
    int     width;
    int     height;
    char    *path;
}	t_img;

typedef struct s_data
{
    void	*mlx_ptr;
    void	*win_ptr;
    char    **map;
    int     nb_total_item;
    int     count_item;
    int     count_step;
    int     count_move_enemy;
    int     hp;
    int     i_enemy;
    int     j_enemy;
    t_img   *img;
}	t_data;

typedef struct s_coordonees
{
    int i;
    int j;
    struct s_coordonees *next;
}   t_coordonees;

// a modifier pour eviter les sauts de lignes dans la map
char	**ft_split(char *str, char c);

int map_valide(char **map);

int ft_strlen(char *str);
int ft_strlen_2d(char **str);

char    **add_border(char **str);

void    ft_print_map(t_data data);

int    ft_find_player(char **map, int *i, int *j, char c);

void    ft_key_w(t_data data, int *count_item, int *count_step, int *hp);
void    ft_key_a(t_data data, int *count_item, int *count_step, int *hp);
void    ft_key_s(t_data data, int *count_item, int *count_step, int *hp);
void    ft_key_d(t_data data, int *count_item, int *count_step, int *hp);

void    ft_nb_total_item(t_data data, int *count, int *total);

void    ft_putnbr(long nbr);
void    ft_putstr_error(char *str);

void    ft_enemy_move_w(t_data data, int *hp);
void    ft_enemy_move_a(t_data data, int *hp);
void    ft_enemy_move_s(t_data data, int *hp);
void    ft_enemy_move_d(t_data data, int *hp);

int	ft_index_max(t_coordonees *tab_struct);

int check_path(char **map);

t_coordonees	*ft_lstnew(int i, int j);
void	ft_lstadd_back(t_coordonees **lst, t_coordonees *new);
t_coordonees	*ft_lstlast(t_coordonees *lst);
void	ft_free_list(t_coordonees *case_possible);




void    ft_free_map(t_data data);
void    ft_free_and_destroy(t_data data);
void    ft_free_2d(char **str);

#endif