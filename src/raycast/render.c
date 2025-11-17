/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albetanc <albetanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 08:38:05 by albetanc          #+#    #+#             */
/*   Updated: 2025/11/17 08:46:58 by albetanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	render_scene(t_game *game)
{
	//render_raycast(game);
	draw_minimap(game);
	draw_player_minimap(game);
	return (0);
}
