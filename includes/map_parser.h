/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rblondel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 15:58:31 by rblondel          #+#    #+#             */
/*   Updated: 2020/09/29 19:42:58 by jpeyron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_PARSER_H
# define MAP_PARSER_H

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
