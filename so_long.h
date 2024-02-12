#ifndef SO_LONG_H
#define SO_LONG_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdbool.h>
#include <time.h>

#include "mlx/mlx.h"
#include "libft/libft.h"
#include "printf/ft_printf.h"
#include "gnl/get_next_line.h"

typedef struct s_player
{
	int x;
	int y;
	void **sprites_up;
	void **sprites_down;
	void **sprites_left;
	void **sprites_right;
	int current_sprite;
	clock_t last_update;
	int frame_count;
	bool is_moving;
	char direction;
} t_player;

typedef struct s_sheep
{
	int x;
	int y;
	void **sprites;
	int current_sprite;
	clock_t last_update;
	int frame_count;
	bool is_collected;
} t_sheep;

typedef struct s_enemy
{
	int x;
	int y;
	void **sprites;
	int current_sprite;
	clock_t last_update;
} t_enemy;

typedef struct s_game_map
{
	int map_height;
	int map_length;
	int player_position_x;
	int player_position_y;
	int game_score;
	int max_score;
	char **map_data;
	int game_over;
	int steps;
	void *end_img;
	void *wall;
	void *wall_map;
	void *exit;
	t_player player;
	void *floor;
	t_sheep *sheep;
	void *enemy;
	int *enemypos;
	int usual_texture_width;
	int usual_texture_height;
} t_game_map;

typedef struct s_render_v
{
	void *mlx_ptr;
	void *win_ptr;
} t_data;

typedef struct s_resources
{
	t_game_map *game_map;
	t_data data;
	t_sheep *sheep;
	t_player *player;
} t_resources;

// INITIALIZERS MAP ARRAY
t_game_map **init_game_map(int fd, t_resources *resources, char *file_path);
void free_game_map(t_game_map **all_map);

// CHECKERS
int check_params(int argc, char **argv, int fd);
void print_errors(char *error);
int check_walls(char *line, int line_type);
int check_rectangular(char *line);
int check_game(char *line);
void reset_game_checks();

// HOOKS
int on_destroy(t_data *data);
int on_keypress(int keysym, t_resources *data);

// LOADERS AND DRAWERS MAP
void load_map(t_resources *res);

void ft_load_textures(t_resources *res);
void ft_put_textures(t_resources *res);
void ft_free_textures(t_resources *res);

void ft_load_first_layer(t_resources *res);
void ft_load_second_layer(t_resources *res);
void ft_load_three_layer(t_resources *res);

void init_and_load_sheep(t_resources *res);
void drawSheep(t_data *data, t_sheep *sheep);
void updateSheepAnimation(t_sheep *sheep, int interval, int sprite_count);

void upload_player_sprites(t_resources *s_resources);
void init_player(t_resources *resources);
void drawPlayer(t_data *data, t_player *player);

void handle_player_movement(int keysym, t_player *player, t_game_map *map);
void updatePlayerAnimation(t_player *player, int interval);

void read_and_process_lines(int fd, t_resources *resources, int num_of_lines);

void free_player(t_player *player);
void free_resources(t_resources *res);

void init_resources_and_mlx(t_resources *res);
void setup_game_environment(t_resources *res, int argc, char **argv);
#endif