/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albetanc <albetanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 15:44:06 by albetanc          #+#    #+#             */
/*   Updated: 2025/11/13 16:18:13 by albetanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void init_colors(t_game *game)//dummy colors
{
	// Floor color: medium gray
	game->floor.r = 128;
	game->floor.g = 128;
	game->floor.b = 128;
	game->floor.hex = (game->floor.r << 16)
		| (game->floor.g << 8) | game->floor.b;

	// Ceiling color: light blue
	game->ceiling.r = 135;
	game->ceiling.g = 206;
	game->ceiling.b = 250;
	game->ceiling.hex = (game->ceiling.r << 16) | (game->ceiling.g << 8) | game->ceiling.b;
}

void	init_player(t_player *player)//dummy data
{
	player->ini_x = 1.0;
	player->ini_y = 1.0;
	player->x = player->ini_x;
	player->y = player->ini_y;
	player->dir_x = 1.0;   // looking to the right initially
	player->dir_y = 0.0;
	player->plane_x = 0.0; // width of vision plane
	player->plane_y = 0.66;
	player->move_speed = 0.05;
	player->rot_speed = 0.05;
}
int	init_map(t_map *map)//dummy data
{
	int	i;
	int	j;
//falta incluir handling error para enviarlo a t_game
	map->rows = 10;
	map->cols = 10;
	map->grid = malloc(sizeof(char *) * map->rows);
	i = 0;
	while (i < map->rows)
	{
		map->grid[i] = malloc(sizeof(char) * map->cols);
		j = 0;
		while (j < map->cols)
		{
			map->grid[i][j] = '0'; // empty space
			j++;
		}
		i++;
	}
	return (0);
}

/*
* Initializes mlx, sets up the game window (win)
* and prepares display-related fields in the game structure.
 */
int	init_display(t_game *game)
{
	game->display.mlx = mlx_init();
	if (!game->display.mlx)
	{
		print_error("Error: Unable to initialize mlx\n");
		return (1); //check exit status
	}
	ini_win(&game->display);
	//data->map = malloc(sizeof(t_map));
	//if (!data->map)
	//{
	//	malloc_error();
	//	return ;
	//}
	//data->map->data = data;
	//if (load_map(argv, data->map) == 0)
	//{
	//	ft_printf("Not possible to load map\n");
	//	exit(1);
	//}
	data->win_w = data->map->cols * TILE_SIZE;
	data->win_h = data->map->rows * TILE_SIZE;
}
