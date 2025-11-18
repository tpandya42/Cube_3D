/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albetanc <albetanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 08:38:05 by albetanc          #+#    #+#             */
/*   Updated: 2025/11/18 18:05:26 by albetanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
#include "move.h" //move to cub.h
#include "rotation.h" //move this to cub.h
#define CAMERA_PLANE_X 0.66

void	setup_initial_vectors(t_player *player, char initial_dir)
{
	if (initial_dir == 'N')
    {
        player->dir_x = 0;
        player->dir_y = -1.0; // up
        player->plane_x = CAMERA_PLANE_X;
        player->plane_y = 0;
    }
    else if (initial_dir == 'S')
    {
        player->dir_x = 0;
        player->dir_y = 1.0; // down
        player->plane_x = -CAMERA_PLANE_X;
        player->plane_y = 0;
    }
    else if (initial_dir == 'E')
    {
        player->dir_x = 1.0; // right
        player->dir_y = 0;
        player->plane_x = 0;
        player->plane_y = CAMERA_PLANE_X;
    }
    else if (initial_dir == 'W')
    {
        player->dir_x = -1.0; // left
        player->dir_y = 0;
        player->plane_x = 0;
        player->plane_y = -CAMERA_PLANE_X;
    }
	else//if it's not valid initial direction -> print a message? check parsing This is a default behav
	{
		player->dir_x = 0;
        player->dir_y = -1.0; // Default: Norte
        player->plane_x = CAMERA_PLANE_X;
        player->plane_y = 0;
	}
}

int	render_scene(t_game *game)
{
	size_t buffer_size;

	buffer_size = game->display.win_w 
		* game->display.win_h * (game->display.bpp / 8);
	ft_memset(game->display.addr, 0, buffer_size);
	handle_movement(game);
	//render_raycast(game);
	draw_minimap(game);
	draw_player_minimap(game);
	//handle_movement(game);
	mlx_put_image_to_window(game->display.mlx, 
		game->display.win, game->display.img, 0, 0);
	return (0);
}

static void	close_esc(t_game *game)
{
	clean_exit(game, 0);
	exit(0);
}

int	key_release(int keycode, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (keycode == 65362 || keycode == 'w')
		game->key.forward = 0;
	else if (keycode == 65364 || keycode == 's')
		game->key.back = 0;
	else if (keycode == 65361 || keycode == 'a')
		game->key.left = 0;
	else if (keycode == 65363 || keycode == 'd')
		game->key.right = 0;
	else if (keycode == 24 || keycode == 'q')
		game->key.rot_left = 0;
	else if (keycode == 26 || keycode == 'e')
		game->key.rot_right = 0;
	return (0);
	//if (keycode == XK_Up || keycode == XK_w)
	//	game->key.forward = 0;
	//else if (keycode == XK_Down || keycode == XK_s)
	//	game->key.back = 0;
	//else if (keycode == XK_a)
	//	game->key.left = 0;
	//else if (keycode == XK_d)
	//	game->key.right = 0;
	//else if (keycode == XK_Left)
	//	game->key.rot_left = 0; 
	//else if (keycode == XK_Right)
	//	game->key.rot_right = 0; 
	//else if (keycode == XK_q)
	//	game->key.rot_left = 0;
	//else if (keycode == XK_e)
	//	game->key.rot_right = 0;
	//return (0);
}

int	key_press(int keycode, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	//MacOS keycode = 123
	if (keycode == 65361 || keycode == 'a')
		//move_left(game);
		game->key.left = 1;
	//MacOS keycode = 124
	else if (keycode == 65363 || keycode == 'd')
		//move_right(game);
		game->key.right = 1;
	//MacOS keycode = 126
	else if (keycode == 65362 || keycode == 'w')
		//move_forward(game);
		game->key.forward = 1;
	//MacOS keycode = 125
	else if (keycode == 65364 || keycode == 's')
		//move_back(game);
		game->key.back = 1;
	//MacOS keycode = 53
	if (keycode == 65307)
		close_esc(game);
	//MacOS keycode = 12
	if (keycode == 24 || keycode == 'q')
		//rotate_left(game);
		game->key.rot_left = 1;
	//MacOS keycode = 14
	if (keycode == 26 || keycode == 'e')
		//rotate_right(game);
		game->key.rot_right = 1;
	//mlx_clear_window(game->display.mlx, game->display.win);
	//render_scene(game);
	//mlx_loop_hook(game->display.mlx, render_scene, game);//new
	return (0);
}
