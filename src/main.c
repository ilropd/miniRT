/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irozhkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 15:34:41 by irozhkov          #+#    #+#             */
/*   Updated: 2024/09/23 14:56:55 by irozhkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	file_checker(char **argv)
{
	struct stat	st;
	int			fd;

	if (access(argv[1], F_OK) != 0)
	{
		printf("Error\nFile doesn't exist\n");
		exit(1);
	}
	if (stat(argv[1], &st) != 0)
	{
		printf("Error\nCannot retrieve file information\n");
		exit(1);
	}
	if (st.st_size == 0)
	{
		printf("Error\nFile is empty\n");
		exit(1);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		printf("Error\nCan't open or read file\n");
		exit(1);
	}
	close(fd);
}

static void	arg_checker(int argc, char **argv)
{
	int	len;

	if (argc != 2)
	{
		printf("Error\nWrong number of parameters\n");
		exit(1);
	}
	len = ft_strlen(argv[1]);
	if (len <= 3 || ft_strcmp(argv[1] + len - 3, ".rt"))
	{
		printf("Error\nIncorrect format of the file\n");
		exit(1);
	}
}

int	main(int argc, char **argv)
{
	t_scene	*scene;
	t_mrt	mrt;

	arg_checker(argc, argv);
	file_checker(argv);
	scene = (t_scene *)malloc(sizeof(t_scene));
	if (!scene)
		return (printf("Error\nScene memory allocation failed\n"), 1);
	init_scene(scene);
	if (parsing_scene(argv, scene))
		error_exit(scene);
//	render_init(mrt);
	render_init(&mrt);
//	fractal_render(&fractal);
	mlx_loop(mrt.connection);
	clear_scene(scene);
	free(scene);
	return (0);
}
