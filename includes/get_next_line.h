/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jules <jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 23:16:20 by jules             #+#    #+#             */
/*   Updated: 2022/01/13 23:38:37 by jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# define BUFFER_SIZE 4096

typedef struct s_file
{
	int				fd;
	char			buff[BUFFER_SIZE > 0 ? BUFFER_SIZE : 1];
	struct s_file	*next;
}					t_file;

size_t				line_len(char *str);
size_t				ft_strlen(char *str);
t_file				*gnl_lstnew(int fd);
t_file				*get_lstelem(t_file **root, int fd);
void				ft_lstremove(t_file **root, int fd);
int					get_line_from_buff(char **line, t_file *elem);
char				*concat(char *ret, t_file *elem, ssize_t bytes);
int					manage_exit(t_file **root, t_file *elem, int bytes,
						char **line);
int					find_endl(char *buff, int size);
int					get_next_line(int fd, char **line);

#endif