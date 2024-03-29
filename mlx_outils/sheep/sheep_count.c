/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sheep_count.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebaillot <ebaillot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 14:30:12 by edouard           #+#    #+#             */
/*   Updated: 2024/02/24 17:32:11 by ebaillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	sheep_count(t_resources *res)
{
	int	y;
	int	x;

	res->sheep_count = 0;
	y = 0;
	while (y < res->game_map->map_height)
	{
		x = 0;
		while (x < res->game_map->map_length)
		{
			if (res->game_map->map_data[y][x] == 'C')
				res->sheep_count++;
			x++;
		}
		y++;
	}
}
