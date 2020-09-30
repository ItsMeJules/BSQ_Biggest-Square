/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rblondel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 15:58:31 by rblondel          #+#    #+#             */
/*   Updated: 2020/09/30 16:31:57 by rblondel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_MAP_H
# define GET_MAP_H

# include <sys/uio.h>
# include <sys/types.h>
# include <unistd.h>
# include <fcntl.h>
# define BUF_SIZE 16384
# include <stdlib.h>
# include "map.h"

int		count_size(char *filename);
char	*map_to_str(char *filename, int sizeof_file);
t_map	*get_map(char *file_path);
int		get_nbr_line(char *str);
char	get_blank(char *str);
char	get_obs(char *str);
char	get_sq(char *str);
int		get_len(char *str);

#endif
