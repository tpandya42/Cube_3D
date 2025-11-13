/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albetanc <albetanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 14:52:28 by albetanc          #+#    #+#             */
/*   Updated: 2025/11/13 16:18:54 by albetanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

/* Initialize map, player, textures, 
*  colors (dummy values for now) 
*/
int	init_game(t_game *game)
{
	if (init_display(&game->display))
		return (1);
	if (init_map(&game->map))
		return (1);
	if (init_player(&game->player))
		return (1);
	//if (init_text(&game->textures))
	//	return (1);
	init_text(&game->textures);//only initizaling
	if (init_colors(&game->colors))
		return (1);
	return (0);
}

//int	main(int argc, char **argv)
int	main(void)//tmp for initial phase
{
	t_game	game;

	//PARSING
	if(init_game(&game)) //init mlx and win
	{
		print_error("Error: Game init failed");
		return (1);
	}
	if (!create_win(&game.display))
		return (1);
	//render_scene(&data);
	//mlx_hook(data.win, 17, 0, close_winx, &data);//events
	//mlx_key_hook(data.win, key_handle, &data);//events
	DEBUG_LOG("Player position: (%.2f, %.2f)", game.player.x, game.player.y);
	DEBUG_LOG("Window size: %dx%d", WIN_WIDTH, WIN_HEIGHT);
	mlx_loop(game.display.mlx);
	return (0);
}
