/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: picatrai <picatrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 19:17:07 by picatrai          #+#    #+#             */
/*   Updated: 2023/11/29 09:57:04 by picatrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

char	*ft_strjoin_suite(char *stockage, char *buffer, char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (stockage[i])
	{
		str[i] = stockage[i];
		i++;
	}
	while (buffer[j])
	{
		str[i + j] = buffer[j];
		j++;
	}
	str[i + j] = '\0';
	return (str);
}

char	*ft_strjoin(char *stockage, char *buffer)
{
	char	*str;

	if (stockage == NULL)
	{
		stockage = malloc(1 * sizeof(char));
		if (stockage == NULL)
			return (NULL);
		stockage[0] = '\0';
	}
	if (stockage == NULL || buffer == NULL)
	{
		free(stockage);
		return (NULL);
	}
	str = malloc((ft_strlen(stockage) + ft_strlen(buffer) + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	str = ft_strjoin_suite(stockage, buffer, str);
	free(stockage);
	return (str);
}

char	*ft_remplissage(int fd, char *stockage)
{
	char	*buffer;
	int		size;

	size = 1;
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (buffer == NULL)
		return (NULL);
	buffer[0] = '\0';
	while (ft_check_line(buffer) == 0 && size > 0)
	{
		size = read(fd, buffer, BUFFER_SIZE);
		if ((size == 0 && stockage == NULL) || size < 0)
		{
			free(buffer);
			return (NULL);
		}
		buffer[size] = '\0';
		stockage = ft_strjoin(stockage, buffer);
		if (stockage == NULL)
			return (NULL);
	}
	free(buffer);
	return (stockage);
}

char	*get_next_line(int fd)
{
	static char	*stockage = NULL;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stockage = ft_remplissage(fd, stockage);
	if (stockage == NULL)
		return (NULL);
	line = ft_cut(stockage);
	if (line == NULL)
	{
		free(line);
		return (NULL);
	}
	stockage = ft_clean(stockage, 0, 0);
	return (line);
}
