/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_scene.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irozhkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 16:17:21 by irozhkov          #+#    #+#             */
/*   Updated: 2024/09/22 16:01:13 by irozhkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_SCENE_H
# define PARSING_SCENE_H

# include "structures.h"

# define TABLE_SIZE 13

/* parcing_scene.c */
//char	*get_token(char **table, int counter, char **str);
//int		parse_string(char **table, char *str);
int		parsing_scene(char **argv, t_scene *scene);
//char 	*grow_buffer(char *buffer, size_t new_size, int index);
//char	*get_next_line(int fd);

/* parsing_table.c*/
void	free_parsing_table(char **table);
char	**parsing_table(void);

#endif


