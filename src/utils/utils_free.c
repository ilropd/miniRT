/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irozhkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 13:27:47 by irozhkov          #+#    #+#             */
/*   Updated: 2024/09/22 15:11:36 by irozhkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	clear_sps_node(t_sps_node *node)
{
	t_sps_node	*current;
	t_sps_node	*next;

	current = node;
	while (current != NULL)
	{
		next = current->next;
		free(current->sphere);
		free(current);
		current = next;
	}
}

void	clear_pls_node(t_pls_node *node)
{
	t_pls_node	*current;
	t_pls_node	*next;

	current = node;
	while (current != NULL)
	{
		next = current->next;
		free(current->plane);
		free(current);
		current = next;
	}
}

void	clear_cys_node(t_cys_node *node)
{
	t_cys_node	*current;
	t_cys_node	*next;

	current = node;
	while (current != NULL)
	{
		next = current->next;
		free(current->cylinder);
		free(current);
		current = next;
	}
}

void	clear_scene(t_scene *scene)
{
	printf("Clear scene function called\n");
	if (scene->ambient)
		free(scene->ambient);
	if (scene->light)
		free(scene->light);
	if (scene->camera)
		free(scene->camera);
	clear_sps_node(scene->sps);
	clear_pls_node(scene->pls);
	clear_cys_node(scene->cys);
	scene->ambient = NULL;
	scene->light = NULL;
	scene->camera = NULL;
	scene->sps = NULL;
	scene->pls = NULL;
	scene->cys = NULL;
	scene->sps_count = 0;
	scene->pls_count = 0;
	scene->cys_count = 0;
}

