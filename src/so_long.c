/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: picatrai <picatrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 13:54:17 by picatrai          #+#    #+#             */
/*   Updated: 2023/12/18 14:13:58 by picatrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

int	handle_keypress(int keysym, t_data *data)
{
    if (keysym == XK_Escape)
    {
        ft_free_and_destroy(*data);
    }
    if (keysym == 119)
        ft_key_w(*data, &data->count_item, &data->count_step, &data->hp);
    if (keysym == 97)
        ft_key_a(*data, &data->count_item, &data->count_step, &data->hp);
    if (keysym == 115)
        ft_key_s(*data, &data->count_item, &data->count_step, &data->hp);
    if (keysym == 100)
        ft_key_d(*data, &data->count_item, &data->count_step, &data->hp);
    return (0);
}

int	render(t_data *data)
{
    if (data->win_ptr == NULL)
        return (1);
    ft_print_map(*data);
    
    if (data->count_move_enemy % TICK == 0)
        data->img[31].mlx_img = data->img[4].mlx_img;
    else if (data->count_move_enemy % (TICK / 2) == 0)
        data->img[31].mlx_img = data->img[30].mlx_img;
    if (data->count_move_enemy % (2 *TICK) == TICK || data->count_move_enemy % TICK == 0)
        data->img[34].mlx_img = data->img[32].mlx_img;
    else if (data->count_move_enemy % (2 * TICK) == TICK / 2)
        data->img[34].mlx_img = data->img[6].mlx_img;
    else if (data->count_move_enemy % (2 * TICK) == TICK + (TICK / 2))
        data->img[34].mlx_img = data->img[33].mlx_img;
    if (data->count_move_enemy == 0 || data->count_move_enemy == TICK || data->count_move_enemy == 2 * TICK || data->count_move_enemy == 3 * TICK)
        ft_enemy_move_d(*data, &data->hp);
    else if (data->count_move_enemy == 4 * TICK || data->count_move_enemy == 5 * TICK || data->count_move_enemy == 6 * TICK || data->count_move_enemy == 7 * TICK)
        ft_enemy_move_s(*data, &data->hp);
    else if (data->count_move_enemy == 8 * TICK || data->count_move_enemy == 9 * TICK || data->count_move_enemy == 10 * TICK || data->count_move_enemy == 11 * TICK)
        ft_enemy_move_a(*data, &data->hp);
    else if (data->count_move_enemy == 12 * TICK || data->count_move_enemy == 13 * TICK || data->count_move_enemy == 14 * TICK || data->count_move_enemy == 15 * TICK)
        ft_enemy_move_w(*data, &data->hp);
    else if (data->count_move_enemy == 16 * TICK)
        data->count_move_enemy = -1;
    data->count_move_enemy++;
    return (0);
}

void    ft_path_1(t_data data)
{
    data.img[1].path = "./sprites/health_1.xpm";
    data.img[2].path = "./sprites/health_2.xpm";
    data.img[3].path = "./sprites/health_3.xpm";
    data.img[0].path = data.img[3].path;
    data.img[4].path = "./sprites/water.xpm";
    data.img[5].path = "./sprites/sand.xpm";
    data.img[6].path = "./sprites/item_1.xpm";
    data.img[7].path = "./sprites/exit.xpm";
    data.img[8].path = "./sprites/steps.xpm";
    data.img[9].path = "./sprites/count_empty.xpm";
    data.img[10].path = "./sprites/count_0.xpm";
    data.img[11].path = "./sprites/count_1.xpm";
    data.img[12].path = "./sprites/count_2.xpm";
    data.img[13].path = "./sprites/count_3.xpm";
    data.img[14].path = "./sprites/count_4.xpm";
    data.img[15].path = "./sprites/count_5.xpm";
    data.img[16].path = "./sprites/count_6.xpm";
    data.img[17].path = "./sprites/count_7.xpm";
    data.img[18].path = "./sprites/count_8.xpm";
    data.img[19].path = "./sprites/count_9.xpm";
}

void    ft_path_2(t_data data)
{
    data.img[21].path = "./sprites/player_front.xpm";
    data.img[22].path = "./sprites/player_back.xpm";
    data.img[23].path = "./sprites/player_left.xpm";
    data.img[24].path = "./sprites/player_right.xpm";
    data.img[20].path = data.img[21].path;
    data.img[26].path = "./sprites/enemy_front.xpm";
    data.img[27].path = "./sprites/enemy_back.xpm";
    data.img[28].path = "./sprites/enemy_left.xpm";
    data.img[29].path = "./sprites/enemy_right.xpm";
    data.img[25].path = data.img[26].path;
    data.img[30].path = "./sprites/water_2.xpm";
    data.img[31].path = data.img[4].path;
    data.img[32].path = "./sprites/item_2.xpm";
    data.img[33].path = "./sprites/item_3.xpm";
    data.img[34].path = data.img[6].path;
}

void    ft_game(t_data data)
{
    int index;
    
    ft_nb_total_item(data, &data.count_item, &data.nb_total_item);
    data.count_step = 0;
    data.count_move_enemy = 0;
    data.hp = 3;
    data.img = malloc(35 * sizeof(t_img));
    if (data.img == NULL)
        return;
    ft_path_1(data);
    ft_path_2(data);
    data.mlx_ptr = mlx_init();
    if (data.mlx_ptr == NULL)
        return;
    data.win_ptr = mlx_new_window(data.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "so_long");
    if (data.win_ptr == NULL)
        return;
    index = -1;
    while (++index <= 34)
    {
        data.img[index].mlx_img = mlx_xpm_file_to_image(data.mlx_ptr, data.img[index].path, &data.img[index].width, &data.img[index].height);
        if (data.img[index].mlx_img == NULL)
            return;
        //data.img[index].addr = mlx_get_data_addr(data.img[index].mlx_img, &data.img[index].bpp, &data.img[index].line_len, &data.img[index].endian);
    }
    mlx_loop_hook(data.mlx_ptr, &render, &data);
    mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &handle_keypress, &data);
    mlx_loop(data.mlx_ptr);
    ft_free_and_destroy(data);
}

int check_ber(int argc, char **argv)
{
    int i;
    
    if (argc != 2)
        return (0);
    i = 0;
    while (argv[1][i])
        i++;
    if (i < 4)
        return (0);
    if (argv[1][i - 4] != '.' || argv[1][i - 3] != 'b' || argv[1][i - 2] != 'e' || argv[1][i - 1] != 'r')
        return (0);
    return (1);
}

int main(int argc, char **argv)
{
    t_data  data;
    char    **parse;
    char    *buffer;
    size_t     size;

    if (check_ber(argc, argv) == 0)
        return (ft_putstr_error("Error\n vous devez utiliser un fichier .ber\n"), 0);
    buffer = malloc((8096 + 1) * sizeof(char));
    size = read(open(argv[1], O_RDONLY), buffer, 8096);
    buffer[size] = '\0';
    if (ft_strlen(buffer) == 8096)
        return (ft_putstr_error("Error\n la map est trop grande\n"), 0);
    if (size <= 0)
        return (ft_putstr_error("Error\n la map est vide\n"), 0);
    parse = ft_split(buffer, '\n');
    if (parse == NULL)
        return (0);
    if (map_valide(parse) == 0)
        return (0);
    data.map = add_border(parse);
    ft_game(data);
}