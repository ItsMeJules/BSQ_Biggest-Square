/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jules <jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 23:39:03 by jules             #+#    #+#             */
/*   Updated: 2022/01/13 23:39:15 by jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	line_len(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] && str[i] != 10)
		i++;
	return (i);
}

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

t_file	*gnl_lstnew(int fd)
{
	t_file	*new;

	new = malloc(sizeof(t_file));
	if (!new)
		return (0);
	new->next = 0;
	new->fd = fd;
	new->buff[0] = 0;
	return (new);
}

t_file	*get_lstelem(t_file **root, int fd)
{
	t_file	*elem;

	if (fd < 0)
		return (0);
	if (!(*root))
	{
		elem = gnl_lstnew(fd);
		if (!elem)
			return (0);
		*root = elem;
		return (elem);
	}
	elem = *root;
	while (elem->next && elem->fd != fd)
		elem = elem->next;
	if (elem->fd == fd)
		return (elem);
	return (elem->next = gnl_lstnew(fd));
}

void	ft_lstremove(t_file **root, int fd)
{
	t_file	*element;
	t_file	*temp;

	while (*root && (*root)->fd == fd)
	{
		temp = *root;
		*root = (*root)->next;
		free(temp);
	}
	element = *root;
	while (element && element->next)
	{
		if (element->next->fd == fd)
		{
			temp = element->next;
			element->next = element->next->next;
			free(temp);
		}
		element = element->next;
	}
}
