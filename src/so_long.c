/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: picatrai <picatrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 13:54:17 by picatrai          #+#    #+#             */
/*   Updated: 2023/12/30 13:02:11 by picatrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	ft_game_suite(t_data data)
{
	int	index;

	index = -1;
	while (++index <= 34)
	{
		if (!(index == 0 || index == 20 || index == 25 \
		|| index == 31 || index == 34))
		{
			data.img[index].mlx_img = \
			mlx_xpm_file_to_image(data.mlx_ptr, data.img[index].path, \
			&data.img[index].width, &data.img[index].height);
			if (data.img[index].mlx_img == NULL)
				return ;
		}
	}
	data.img[0] = data.img[3];
	data.img[20] = data.img[21];
	data.img[25] = data.img[26];
	data.img[31] = data.img[4];
	data.img[34] = data.img[6];
}

void	ft_game(t_data data)
{
	ft_nb_total_item(data, &data.count_item, &data.nb_total_item);
	data.count_step = 0;
	data.count_move_enemy = 0;
	data.hp = 3;
	data.img = malloc(35 * sizeof(t_img));
	if (data.img == NULL)
		return ;
	ft_path_1(data);
	ft_path_2(data);
	data.mlx_ptr = mlx_init();
	if (data.mlx_ptr == NULL)
		exit(EXIT_FAILURE);
	data.win_ptr = mlx_new_window(data.mlx_ptr, WINDOW_WIDTH, \
	WINDOW_HEIGHT, "so_long");
	if (data.win_ptr == NULL)
		return ;
	ft_game_suite(data);
	mlx_loop_hook(data.mlx_ptr, &render, &data);
	mlx_hook(data.win_ptr, 17, 0, ft_free_and_destroy_2, &data);
	mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &handle_keypress, &data);
	mlx_loop(data.mlx_ptr);
	ft_free_and_destroy(data);
}

int	check_ber(int argc, char **argv)
{
	int	i;

	if (argc != 2)
		return (0);
	i = 0;
	while (argv[1][i])
		i++;
	if (i < 4)
		return (0);
	if (argv[1][i - 4] != '.' || argv[1][i - 3] != 'b' \
	|| argv[1][i - 2] != 'e' || argv[1][i - 1] != 'r')
		return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	t_data	data;
	char	**parse;
	char	*buffer;
	size_t	size;

	if (check_ber(argc, argv) == 0)
		return (ft_putstr_error("Error\nil faut un fichier .ber\n"), 0);
	buffer = malloc((8096 + 1) * sizeof(char));
	size = read(open(argv[1], O_RDONLY), buffer, 8096);
	buffer[size] = '\0';
	if (ft_strlen(buffer) == 8096)
		return (free(buffer), ft_putstr_error("Error\nla map trop grande\n"), 0);
	if (size <= 0)
		return (free(buffer), ft_putstr_error("Error\nla map est vide\n"), 0);
	if (check_no_nl_mid(buffer) == 0)
		return (free(buffer), ft_putstr_error("Error\nsaut de lignes\n"), 0);
	parse = ft_split(buffer, '\n');
	if (parse == NULL)
		return (free(buffer), 0);
	free(buffer);
	if (map_valide(parse) == 0)
		return (0);
	data.map = add_border(parse);
	ft_game(data);
}
