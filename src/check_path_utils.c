/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: picatrai <picatrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 12:03:31 by picatrai          #+#    #+#             */
/*   Updated: 2023/12/29 12:05:00 by picatrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

t_coordonees	*ft_lstlast(t_coordonees *lst)
{
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

void	ft_lstadd_back(t_coordonees **lst, t_coordonees *new)
{
	if (*lst == NULL)
		*lst = new;
	else
		ft_lstlast(*lst)->next = new;
}

t_coordonees	*ft_lstnew(int i, int j)
{
	t_coordonees	*new;

	new = malloc(sizeof(t_coordonees));
	if (new == NULL)
		return (NULL);
	new->i = i;
	new->j = j;
	new->next = NULL;
	return (new);
}

int	ft_is_new(t_coordonees *case_possible, int i, int j)
{
	while (case_possible != NULL)
	{
		if (i == case_possible->i && j == case_possible->j)
			return (0);
		case_possible = case_possible->next;
	}
	return (1);
}
