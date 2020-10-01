/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rblondel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 15:58:31 by rblondel          #+#    #+#             */
/*   Updated: 2020/10/01 12:26:53 by rblondel         ###   ########.fr       */
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
int		map_error(t_map map, int *ac);
int		check_len(char *str, int len);
int		check_char(char *str, char blk, char obs, char sq);
int		check_line(char *str);
int		len(char *str);

#endif
