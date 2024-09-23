/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_figures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irozhkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 15:10:33 by irozhkov          #+#    #+#             */
/*   Updated: 2024/09/22 16:24:14 by irozhkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	init_cylinder(char **table, t_scene *scene)
{    
	t_cylinder	*cylinder;

	if (check_cylinder(table))
		return (printf("Error\nWrong arguments for cylinder\n"), 1);
	cylinder = (t_cylinder *)malloc(sizeof(t_cylinder));
	if (!cylinder)    
		return (printf("Error\nCylinder memory allocation failed\n"), 1);
	cylinder->type = table[0]; 
	cylinder->x = ft_atof(table[1]);
	cylinder->y = ft_atof(table[2]);
	cylinder->z = ft_atof(table[3]);
	cylinder->x_ov = ft_atof(table[4]);
	cylinder->y_ov = ft_atof(table[5]);
	cylinder->z_ov = ft_atof(table[6]);
	cylinder->diameter = ft_atof(table[7]);
	cylinder->height = ft_atof(table[8]);
	cylinder->r = ft_atoi(table[9]);
	cylinder->g = ft_atoi(table[10]);
	cylinder->b = ft_atoi(table[11]);
	printf("Cylinder settings:\n\ttype: %s\n\tx: %f\n\ty: %f\n\tz: %f\n\tx_ov: %f\n\ty_ov: %f\n\tz_ov: %f\n\tdiameter: %f\n\theight: %f\n\tred: %d\n\tgreen: %d\n\tblue: %d\n", cylinder->type, cylinder->x, cylinder->y, cylinder->z, cylinder->x_ov, cylinder->y_ov, cylinder->z_ov, cylinder->diameter, cylinder->height, cylinder->r, cylinder->g, cylinder->b);
	scene->cys_count++;
	return (add_cylinder(scene, cylinder));
}

int	init_plane(char **table, t_scene *scene)
{
	t_plane	*plane;

	if (check_plane(table))
		return (printf("Error\nWrong arguments for plane\n"), 1);
	plane = (t_plane *)malloc(sizeof(t_plane));
	if (!plane)
		return (printf("Error\nPlain memory allocation failed\n"), 1);
	plane->type = table[0];
	plane->x = ft_atof(table[1]);
	plane->y = ft_atof(table[2]);
	plane->z = ft_atof(table[3]);
	plane->x_ov = ft_atof(table[4]);
	plane->y_ov = ft_atof(table[5]);
	plane->z_ov = ft_atof(table[6]);
	plane->r = ft_atoi(table[7]);
	plane->g = ft_atoi(table[8]);
	plane->b = ft_atoi(table[9]);
	printf("Plane settings:\n\ttype: %s\n\tx: %f\n\ty: %f\n\tz: %f\n\tx_ov: %f\n\ty_ov: %f\n\tz_ov: %f\n\tred: %d\n\tgreen: %d\n\tblue: %d\n", plane->type, plane->x, plane->y, plane->z, plane->x_ov, plane->y_ov, plane->z_ov, plane->r, plane->g, plane->b);
    scene->pls_count++;
	return (add_plane(scene, plane));
}

int	init_sphere(char **table, t_scene *scene)
{
	t_sphere *sphere;

	if (check_sphere(table))
		return (printf("Error\nWrong arguments for sphere\n"), 1);
	sphere = (t_sphere *)malloc(sizeof(t_sphere));
	if (!sphere)
		return (printf("Error\nSphere memory allocation failed\n"), 1);
	sphere->type = table[0];
	sphere->x = ft_atof(table[1]);
	sphere->y = ft_atof(table[2]);
	sphere->z = ft_atof(table[3]);
	sphere->diameter = ft_atof(table[4]);
	sphere->r = ft_atoi(table[5]);
	sphere->g = ft_atoi(table[6]);
	sphere->b = ft_atoi(table[7]);
	printf("Sphere settings:\n\ttype: %s\n\tx: %f\n\ty: %f\n\tz: %f\n\tdiameter: %f\n\tred: %d\n\tgreen: %d\n\tblue: %d\n", sphere->type, sphere->x, sphere->y, sphere->z, sphere->diameter, sphere->r, sphere->g, sphere->b);
    scene->sps_count++;
	return (add_sphere(scene, sphere));
}
