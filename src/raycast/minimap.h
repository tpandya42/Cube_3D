/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albetanc <albetanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 08:48:33 by albetanc          #+#    #+#             */
/*   Updated: 2025/11/18 08:34:25 by albetanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

#define MINIMAP_TILE 16
#define MINIMAP_OFFSET_X 0
#define MINIMAP_OFFSET_Y 650
#define MINIMAP_TILE 16
#define MINIMAP_MARGIN 20 //from the window border

void	draw_minimap(t_game *game);
void	draw_player_minimap(t_game *game);
