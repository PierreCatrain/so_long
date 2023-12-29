/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: picatrai <picatrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 16:34:16 by picatrai          #+#    #+#             */
/*   Updated: 2023/12/29 16:12:06 by picatrai         ###   ########.fr       */
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

typedef struct s_utils
{
	int	index_i;
	int	index_j;
	int	pixel_i;
	int	pixel_j;
}	t_utils;

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	char	*path;
	int		bpp;
	int		line_len;
	int		endian;
	int		width;
	int		height;
}	t_img;

typedef struct s_coordonees
{
	struct s_coordonees	*next;
	int					i;
	int					j;
}	t_coordonees;

typedef struct s_data
{
	t_coordonees	*enemy;
	t_img			*img;
	void			*mlx_ptr;
	void			*win_ptr;
	char			**map;
	int				nb_total_item;
	int				count_item;
	int				count_step;
	int				count_move_enemy;
	int				hp;
	int				i_enemy;
	int				j_enemy;
	int				new_i;
	int				new_j;
	int				actual_i;
	int				actual_j;
}	t_data;

t_coordonees	*ft_lstnew(int i, int j);
t_coordonees	*ft_lstlast(t_coordonees *lst);

char			**ft_split(char *str, char c);
char			**add_border(char **str);

void			ft_print_map(t_data data);
void			ft_key_w(t_data data, int *count_item, \
		int *count_step, int *hp);
void			ft_key_a(t_data data, int *count_item, \
		int *count_step, int *hp);
void			ft_key_s(t_data data, int *count_item, \
		int *count_step, int *hp);
void			ft_key_d(t_data data, int *count_item, \
		int *count_step, int *hp);
void			ft_nb_total_item(t_data data, int *count, int *total);
void			ft_add_coordonees(t_coordonees **enemy, int new_i, int new_j);
void			ft_putstr_error(char *str);
void			ft_enemy_move_w(t_data data, int *hp);
void			ft_enemy_move_a(t_data data, int *hp);
void			ft_enemy_move_s(t_data data, int *hp);
void			ft_enemy_move_d(t_data data, int *hp);
void			ft_free_list(t_coordonees *case_possible);
void			ft_lstadd_back(t_coordonees **lst, t_coordonees *new);
void			ft_path_1(t_data data);
void			ft_path_2(t_data data);
void			ft_free_map(t_data data);
void			ft_free_and_destroy(t_data data);
void			ft_free_2d(char **str);

int				check_no_nl_mid(char *buffer);
int				map_valide(char **map);
int				ft_strlen(char *str);
int				ft_strlen_2d(char **str);
int				ft_find_player(char **map, int *i, int *j, char c);
int				ft_find_enemy(t_data data, int *i, int *j, int new);
int				ft_not_twice(t_coordonees *enemy, int new_i, int new_j);
int				check_path(char **map);
int				ft_is_new(t_coordonees *case_possible, int i, int j);
int				handle_keypress(int keysym, t_data *data);
int				render(t_data *data);

#endif
