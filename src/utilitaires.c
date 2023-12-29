/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilitaires.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: picatrai <picatrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 11:42:25 by picatrai          #+#    #+#             */
/*   Updated: 2023/12/29 15:19:46 by picatrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

int	ft_strlen(char *str)
{
	int	count;

	if (str == NULL)
		return (0);
	count = 0;
	while (str[count])
		count++;
	return (count);
}

int	ft_strlen_2d(char **str)
{
	int	count;

	if (str == NULL)
		return (0);
	count = 0;
	while (str[count])
		count++;
	return (count);
}

void	ft_putstr_error(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		write(2, &str[i++], 1);
}
