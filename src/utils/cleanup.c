/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albetanc <albetanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 15:09:53 by albetanc          #+#    #+#             */
/*   Updated: 2025/11/13 16:21:53 by albetanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	clean_exit(t_game *game, int status)
{
	if (game->map && game->map->grid)
		free_array(data->map->grid, data->map->rows);
	//clean_textures(game->data);
	if (game->disp->win)
		mlx_destroy_window(game->disp->mlx, game->disp->win);
	if (data->mlx)
	{
		mlx_destroy_display(game->disp->mlx);
		free(game->disp->mlx);
	}
	if (game->map)
		free(game->map);
	exit(status);
}


void clean_exit(t_game *game, int status)
{
    clean_map(&game->map);
    clean_textures(&game->disp, &game->text);
    clean_window(&game->disp);
    clean_mlx(&game->disp);

    exit(status);
}