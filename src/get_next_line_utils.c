/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: picatrai <picatrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 10:39:31 by picatrai          #+#    #+#             */
/*   Updated: 2023/11/29 09:56:55 by picatrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

size_t	ft_strlen(char *str)
{
	size_t	i;

	if (str == NULL)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_check_line(char *stockage)
{
	int	i;

	if (stockage == NULL)
		return (0);
	i = 0;
	while (stockage[i])
	{
		if (stockage[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_clean(char *stockage, int i, int j)
{
	char	*str;

	if (stockage[0] == '\0')
	{
		free(stockage);
		return (NULL);
	}
	while (stockage[i] && stockage[i] != '\n')
		i++;
	str = malloc((ft_strlen(stockage) - i + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	if (stockage[i] != '\0')
		i++;
	while (stockage[i])
	{
		str[j] = stockage[i];
		i++;
		j++;
	}
	str[j] = '\0';
	free(stockage);
	return (str);
}

char	*ft_cut(char *stockage)
{
	char	*str;
	int		i;

	if (stockage[0] == '\0')
		return (free(stockage), NULL);
	i = 0;
	while (stockage[i] && stockage[i] != '\n')
		i++;
	if (stockage[i] == '\n')
		i++;
	str = malloc((i + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (stockage[i] && stockage[i] != '\n')
	{
		str[i] = stockage[i];
		i++;
	}
	if (stockage[i] == '\n')
		str[i++] = '\n';
	str[i] = '\0';
	if (str[0] == 0)
		return (NULL);
	return (str);
}
