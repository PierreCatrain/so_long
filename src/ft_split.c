/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: picatrai <picatrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 15:27:39 by picatrai          #+#    #+#             */
/*   Updated: 2023/12/29 14:46:19 by picatrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	ft_free_split(char **split, int j)
{
	j--;
	while (j >= 0)
		free(split[j--]);
	free(split);
}

int	ft_mega_malloc(char *str, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] != '\0' && str[i] != c \
		&& (str[i + 1] == '\0' || str[i + 1] == c))
			count++;
		i++;
	}
	return (count);
}

int	ft_mini_malloc(char *str, char c, int i)
{
	int	count;

	count = 0;
	while (str[i] != '\0' && str[i] != c)
	{
		i++;
		count++;
	}
	return (count);
}

char	*ft_remplissage(char *str, char c, int i)
{
	char	*mini_split;
	int		j;

	mini_split = malloc((ft_mini_malloc(str, c, i) + 1) * sizeof(char));
	if (mini_split == NULL)
		return (NULL);
	j = 0;
	while (str[i + j] != '\0' && str[i + j] != c)
	{
		mini_split[j] = str[i + j];
		j++;
	}
	mini_split[j] = '\0';
	return (mini_split);
}

char	**ft_split(char *str, char c)
{
	char	**split;
	int		index[2];
	int		new;

	split = malloc((ft_mega_malloc(str, c) + 1) * sizeof(char *));
	if (split == NULL)
		return (NULL);
	index[0] = -1;
	index[1] = -1;
	new = 1;
	while (str[++index[0]])
	{
		if (new == 1 && str[index[0]] != c)
		{
			split[++index[1]] = ft_remplissage(str, c, index[0]);
			if (split[index[1]] == NULL)
				return (ft_free_split(split, index[1]), NULL);
			new = 0;
		}
		else if (new == 0 && str[index[0]] == c \
		&& str[index[0] + 1] != c && str[index[0] + 1] != '\0')
			new = 1;
	}
	split[++index[1]] = 0;
	return (split);
}
