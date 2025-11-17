/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albetanc <albetanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 08:47:37 by albetanc          #+#    #+#             */
/*   Updated: 2025/11/17 09:05:45 by albetanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	draw_player_minimap(t_game *game)
{
	int	px;
	int	py;

	px = game->player.x * MINI;
	py = game->player.y * MINI;
	mlx_pixel_put(game->display.mlx, game->display.win, px, py, COLOR_PLAYER);
}

static void	draw_sqare(t_game *game, int x, int y, int size, int color)
{
	int	dx;//delta x
	int	dy;//delta y

	dy = 0;
	while (dy < size)
	{
		dx = 0;
		while (dx < size)
		{
			mlx_pixel_put(game>display.mlx. game-?s_display.win,
				x + dx, y + dy, color);
			dx++;
		}
		dy++;
	}
}

void	draw_minimap(t_game *game)
{
	int	row;
	int	col;
	int	color;

	row = 0;
	while (row < game->map.rows)
	{
		col = 0;
		while (col < game->map.cols)
		{
			if (game->map.map[row][cols] == '1') 
				color = COLOR_WALL;
			else
				color = COLOR_FLOOR;
			draw_sqare(game, col * MINI, row * MINI, MINI, color);
			col++;
		}
		row++;
	}
}



