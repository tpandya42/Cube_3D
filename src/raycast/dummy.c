/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dummy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albetanc <albetanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 18:39:29 by albetanc          #+#    #+#             */
/*   Updated: 2025/11/28 07:43:26 by albetanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
#include "dummy.h"

void	load_dummy_text(t_game *game)
{
	game->text.north = "textures/dark_north.xpm";
	game->text.south = "textures/dark_south.xpm";
	game->text.west = "textures/dark_west.xpm";
	game->text.east = "textures/dark_east.xpm";

	load_text(game, &game->text.north, game->text.north);
	load_text(game, &game->text.tex_so, game->text.south);
	load_text(game, &game->text.tex_we, game->text.west);
	load_text(game, &game->text.tex_ea, game->text.east);
}

void	fill_colors(t_game *game)
{
	// floor gray
	game->floor.floor[0] = 128;
	game->floor.floor[1] = 128;
	game->floor.floor[2] = 128;

	// ceiling light blue
	game->ceiling.ceiling[0] = 135;
	game->ceiling.ceiling[1] = 206;
	game->ceiling.ceiling[2] = 250;
}

void	dummy_map(t_game *game)
{
	static char	*dummy_map[10] = {
		"1111111111",
		"1000000001",
		"1011111101",
		"1000000001",
		"1011111101",
		"1001000001",
		"1011111101",
		"1000000001",
		"1111111111",
		"1111111111"
	};
	game->map.rows = 10;
	game->map.cols = 10;
	game->map.map = dummy_map;
}

void	dummy_player(t_game *game)
{
	game->player.ini_x = 1.5;
	game->player.ini_y = 1.5;
	game->player.x = game->player.ini_x;
	game->player.y = game->player.ini_y;
}

void	fill_dummy(t_game *game)
{
	fill_colors(game);
	dummy_map(game);
	dummy_player(game);
}
