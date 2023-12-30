/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_no_nl_mid.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: picatrai <picatrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 15:03:27 by picatrai          #+#    #+#             */
/*   Updated: 2023/12/30 16:16:12 by picatrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	ft_start_end(char *buffer, int *debut, int *fin)
{
	*debut = 0;
	*fin = 0;
	while (buffer[*debut] == '\n')
		(*debut)++;
	while (buffer[*fin])
		(*fin)++;
	if (*fin != 0)
		(*fin)--;
	while (buffer[*fin] == '\n')
		(*fin)--;
}

int	check_no_nl_mid(char *buffer)
{
	int	debut;
	int	fin;

	ft_start_end(buffer, &debut, &fin);
	while (debut <= fin)
	{
		if (buffer[debut] == '\n' && buffer[debut + 1] == '\n')
			return (0);
		debut++;
	}
	return (1);
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
