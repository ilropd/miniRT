/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irozhkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 15:34:32 by irozhkov          #+#    #+#             */
/*   Updated: 2024/09/23 14:41:14 by irozhkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <ctype.h>
# include <fcntl.h>
# include <stddef.h>
# include <stdio.h> 
# include <stdlib.h>
# include <sys/stat.h>
# include <unistd.h>

# include "libft.h"
# include "mlx.h"

# include "check.h"
# include "init.h"
# include "parsing_scene.h"
# include "structures.h"
# include "utils.h"

int	render_init(t_mrt *mrt);

#endif
