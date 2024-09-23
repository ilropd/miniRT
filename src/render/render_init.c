/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irozhkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 13:22:17 by irozhkov          #+#    #+#             */
/*   Updated: 2024/09/23 15:01:56 by irozhkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*static void	mrt_init(t_mrt *mrt)
{
}
*/
int	render_init(t_mrt *mrt)
{
	mrt->name = "mandatory";
	if ((mrt->connection = mlx_init()) == NULL)
		return (printf("Error\nMemory allocation for mlx connection failed\n"), 1);
	if ((mrt->window = mlx_new_window(mrt->connection, WIDTH, HEIGHT, mrt->name)) == NULL)
		return (printf("Error\nMemory allocation for mlx window failed\n"), mlx_destroy_window(mrt->connection, mrt->window), free(mrt->connection), 1);
	if ((mrt->img.img_ptr = mlx_new_image(mrt->connection, WIDTH, HEIGHT)) == NULL)
		return (printf("Error\nMemory allocation for mlx image failed\n"), mlx_destroy_window(mrt->connection, mrt->window), free(mrt->connection), 1);
	mrt->img.pxl_ptr = mlx_get_data_addr(mrt->connection, &mrt->img.bpp, &mrt->img.line_len, &mrt->img.endian);
	return (0);
}
