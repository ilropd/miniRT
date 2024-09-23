/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irozhkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 15:08:11 by irozhkov          #+#    #+#             */
/*   Updated: 2024/09/23 14:36:35 by irozhkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

/* define size of rendering window */

# define WIDTH 600
# define HEIGHT 600

/* structures for parsing */

typedef struct s_amb_light
{
	char			*type;
	float			ratio;
	unsigned int	r;
	unsigned int	g;
	unsigned int	b;
}	t_amb_light;

typedef struct s_light
{
	char			*type;
	float			x;
	float			y;
	float			z;
	float			brightness;
	unsigned int	r;
	unsigned int	g;
	unsigned int	b;
}	t_light;

typedef struct s_camera
{
	char			*type;
	float			x;
	float			y;
	float			z;
	float			x_ov;
	float			y_ov;
	float			z_ov;
	unsigned int	fov;
}	t_camera;

typedef struct s_sphere
{
	char			*type;
	float			x;
	float			y;
	float			z;
	float			diameter;
	unsigned int	r;
	unsigned int	g;
	unsigned int	b;
} t_sphere;

typedef struct s_plane
{
	char			*type;
	float			x;
	float			y;
	float			z;
	float			x_ov;
	float			y_ov;
	float			z_ov;
	unsigned int	r;
	unsigned int	g;
	unsigned int	b;
}	t_plane;

typedef struct s_cylinder
{
	char			*type;
	float			x;
	float			y;
	float			z;
	float			x_ov;
	float			y_ov;
	float			z_ov;
	float			diameter;
	float			height;
	unsigned int	r;
	unsigned int	g;
	unsigned int	b;
}	t_cylinder;

typedef struct s_sps_node
{
	t_sphere			*sphere;
	struct s_sps_node	*next;
}	t_sps_node;

typedef struct s_pls_node
{
	t_plane				*plane;
	struct s_pls_node	*next;
}	t_pls_node;

typedef struct s_cys_node
{
	t_cylinder			*cylinder;
	struct s_cys_node	*next;
}	t_cys_node;

typedef struct s_scene
{
	t_amb_light	*ambient;
	t_light		*light;
	t_camera	*camera;
	t_sps_node	*sps;
	t_pls_node	*pls;
	t_cys_node	*cys;
	int			sps_count;
	int			pls_count;
	int			cys_count;
}	t_scene;

/* structures for rendering */

typedef struct s_img
{
	void	*img_ptr;
	char	*pxl_ptr;
	int		bpp;
	int		endian;
	int		line_len;
}	t_img;

typedef struct s_mrt
{
	char	*name;
	void	*connection;
	void	*window;
	t_img	img;
}	t_mrt;

#endif
