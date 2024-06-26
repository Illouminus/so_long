/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_resources.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebaillot <ebaillot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 17:13:23 by edouard           #+#    #+#             */
/*   Updated: 2024/03/18 14:46:44 by ebaillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	free_game_entities(t_resources *res)
{
	if (!res)
		return ;
	if (res->game_map)
	{
		ft_free_textures(res);
		free_game_map(&res->game_map);
		res->game_map = NULL;
	}
	if (res->player)
	{
		free_player(res);
		res->player = NULL;
	}
	if (res->enemy)
	{
		free_enemys_sprites(res);
		free(res->enemy);
		res->enemy = NULL;
	}
}

static void	free_graphic_and_additional_resources(t_resources *res)
{
	if (!res || !res->data.mlx_ptr)
		return ;
	if (res->sheep)
	{
		if (res->sheep->sprites)
			free_sheep_sprites(res->sheep, res->data.mlx_ptr);
		free(res->sheep);
		res->sheep = NULL;
	}
	res->sheep_count = 0;
	if (res->data.win_ptr)
		mlx_destroy_window(res->data.mlx_ptr, res->data.win_ptr);
	if(res->data.mlx_ptr)
	{
		mlx_destroy_display(res->data.mlx_ptr);
		free(res->data.mlx_ptr);
	}
}

void	free_resources(t_resources *res)
{
	free_game_entities(res);
	free_graphic_and_additional_resources(res);
}

void	end_game(t_resources *res, int win)
{
	if (win)
		ft_printf("You Win!\n");
	else
		ft_printf("Game Over!\n");
	free_resources(res);
	exit(0);
}
