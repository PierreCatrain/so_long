/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_no_nl_mid.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: picatrai <picatrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 15:03:27 by picatrai          #+#    #+#             */
/*   Updated: 2023/12/29 15:33:34 by picatrai         ###   ########.fr       */
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
