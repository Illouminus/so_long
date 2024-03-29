/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   layer_outils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebaillot <ebaillot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 16:51:12 by edouard           #+#    #+#             */
/*   Updated: 2024/02/24 17:28:17 by ebaillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_load_first_layer(t_resources *res)
{
	int	y;
	int	x;

	y = 0;
	while (y < res->game_map->map_height)
	{
		x = 0;
		while (x < res->game_map->map_length)
		{
			mlx_put_image_to_window(res->data.mlx_ptr, res->data.win_ptr,
				res->game_map->floor, x * 64, y * 64);
			x++;
		}
		y++;
	}
}

void	*choose_texture(t_resources *res, int x, int y)
{
	if (res->game_map->map_data[y][x] == '1')
	{
		if (y == 0 || y == res->game_map->map_height - 1 || x == 0
			|| x == res->game_map->map_length - 2)
			return (res->game_map->wall);
		else
			return (res->game_map->wall_map);
	}
	if (res->game_map->map_data[y][x] == 'E' && res->sheep_count == 0)
		return (res->game_map->exit);
	return (NULL);
}

void	ft_load_second_layer(t_resources *res)
{
	int		y;
	int		x;
	void	*texture;

	y = 0;
	while (y < res->game_map->map_height)
	{
		x = 0;
		while (x < res->game_map->map_length)
		{
			texture = choose_texture(res, x, y);
			if (texture != NULL)
				mlx_put_image_to_window(res->data.mlx_ptr, res->data.win_ptr,
					texture, x * 64, y * 64);
			x++;
		}
		y++;
	}
}

void	ft_load_three_layer(t_resources *res)
{
	int	y;
	int	x;
	int	i;

	y = 0;
	i = 0;
	while (y < res->game_map->map_height)
	{
		x = 0;
		while (x < res->game_map->map_length)
		{
			if (res->game_map->map_data[y][x] == 'P')
				player_draw_layer(res, y, x);
			if (res->game_map->map_data[y][x] == 'C')
				sheep_draw_layer(res, y, x);
			x++;
		}
		y++;
	}
	while (i < res->enemy_count)
	{
		draw_enemy(res, &res->enemy[i]);
		i++;
	}
}
