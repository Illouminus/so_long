/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebaillot <ebaillot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 20:29:30 by edouard           #+#    #+#             */
/*   Updated: 2024/03/08 14:33:44 by ebaillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	init_resources_and_mlx(t_resources *res)
{
	res->sheep = malloc(sizeof(t_sheep));
	if (!res->sheep)
	{
		free_resources(res);
		print_errors("Error: Memory allocation failed for sheep\n");
	}
	ft_bzero(res->sheep, sizeof(t_sheep));
	res->data.mlx_ptr = mlx_init();
	if (!res->data.mlx_ptr)
	{
		free_resources(res);
		print_errors("Error: MLX initialization failed\n");
	}
}

void	setup_game_environment(t_resources *res, int argc, char **argv)
{
	int	fd;

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		free_resources(res);
		print_errors("Error: File not found\n");
	}
	if (!check_params(argc, argv, fd))
	{
		close(fd);
		free_resources(res);
		print_errors("Error: Parameters check failed\n");
	}
	init_game_map(fd, res, argv[1]);
	close(fd);
	res->data.win_ptr = mlx_new_window(res->data.mlx_ptr,
			res->game_map->map_length * 62, res->game_map->map_height * 64,
			"So Long");
	if (!res->data.win_ptr)
		free_resources(res);
	init_player(res);
	init_enemy(res);
	load_map(res);
}
