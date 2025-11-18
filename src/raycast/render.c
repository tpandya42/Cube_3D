/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albetanc <albetanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 08:38:05 by albetanc          #+#    #+#             */
/*   Updated: 2025/11/18 08:49:11 by albetanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static int	render_scene(t_game *game)
{
	//render_raycast(game);
	draw_minimap(game);
	draw_player_minimap(game);
	return (0);
}

static void	close_esc(t_game *game)
{
	clean_exit(&game->display, 0);
	exit(0);
}

int	key_press(int keycode, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	//MacOS keycode = 123
	if (keycode == 65361 || keycode == 'a')
		move_left(game);
	//MacOS keycode = 124
	else if (keycode == 65363 || keycode == 'd')
		move_right(game);
	//MacOS keycode = 126
	else if (keycode == 65362 || keycode == 'w')
		move_forward(game);
	//MacOS keycode = 125
	else if (keycode == 65364 || keycode == 's')
		move_back(game);
	//MacOS keycode = 53
	if (keycode == 65307)
		close_esc(game);
	//MacOS keycode = 12
	if (keycode == 24 || keycode == 'q')
		rotate_left(game);
	//MacOS keycode = 14
	if (keycode == 26 || keycode == 'e')
		rotate_right(game);
	//mlx_clear_window(game->display.mlx, game->display.win);
	//render_scene(game);
	mlx_loop_hook(game->display.mlx, render_scene, game);//new
	return (0);
}
