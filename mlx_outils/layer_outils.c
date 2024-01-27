/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   layer_outils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edouard <edouard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 16:51:12 by edouard           #+#    #+#             */
/*   Updated: 2024/01/27 17:21:52 by edouard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void ft_load_first_layer(t_data *data, t_game_map **map)
{
	int y;
	int x;

	y = 0;
	while (y < (*map)->map_height)
	{
		x = 0;
		while (x < (*map)->map_length)
		{
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, (*map)->floor, x * 32, y * 32);
			x++;
		}
		y++;
	}
}

void ft_load_second_layer(t_data *data, t_game_map **map)
{
	int y;
	int x;

	y = 0;
	while (y < (*map)->map_height)
	{
		x = 0;
		while (x < (*map)->map_length)
		{
			if ((*map)->map_data[y][x] == '1')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, (*map)->wall, x * 32, y * 32);
			x++;
		}
		y++;
	}
	// Загрузка других текстур...
}