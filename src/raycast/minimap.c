/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albetanc <albetanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 08:47:37 by albetanc          #+#    #+#             */
/*   Updated: 2025/11/19 08:27:20 by albetanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	my_mlx_pixel_put(t_display *display, int x, int y, int color)
{
	char	*dst;
	int		bpp_bytes; // bytes por pixel

	if (x < 0 || x >= display->win_w || y < 0 || y >= display->win_h)
		return ;
	bpp_bytes = display->bpp / 8;
	dst = display->addr + (y * display->line_len + x * bpp_bytes);
	*(unsigned int *)dst = color;
}

void	draw_circle(t_display *disp, int cx, int cy, int r)
{
	int	x;
	int	y;

	y = -r;
	while (y <= r)
	{
		x = -r;
		while (x <= r)
		{
			if (x * x + y * y <= r * r)
				my_mlx_pixel_put(disp, cx + x, cy + y, COLOR_PLAYER);
			x++;
		}
		y++;
	}
}

void	draw_player_minimap(t_game *game)
{
	int	px;//player position -> center of circle
	int	py;
	int	r;

	r = 3;//fixed size for player in minimap
	px = game->minimap.offset_x + 
		(int)(game->player.x * game->minimap.tile_size);
	py = game->minimap.offset_y
		+ (int)(game->player.y * game->minimap.tile_size);
	draw_circle(&game->display, px, py, r);
}

static void	draw_square(t_game *game, int x, int y, int size, int color)
{
	int	dx;//delta x
	int	dy;//delta y

	dy = 0;
	while (dy < size)
	{
		dx = 0;
		while (dx < size)
		{
			//mlx_pixel_put(game->display.mlx, game->display.win,
			//	x + dx, y + dy, color);
			my_mlx_pixel_put(&game->display, x + dx, y + dy, color);
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
			if (game->map.map[row][col] == '1') 
				color = COLOR_WALL;
			else
				color = COLOR_FLOOR;
			draw_square(game,
				game->minimap.offset_x + col * game->minimap.tile_size,
				game->minimap.offset_y + row * game->minimap.tile_size,
				game->minimap.tile_size,
				color);
			col++;
		}
		row++;
	}
}



