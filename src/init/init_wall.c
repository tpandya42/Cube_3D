/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albetanc <albetanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 14:54:09 by albetanc          #+#    #+#             */
/*   Updated: 2025/11/28 14:55:10 by albetanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	init_wall_data(t_wall_data *wdata)
{
	wdata->img_ptr = NULL;
	wdata->addr = NULL;
	wdata->bpp = 0;
	wdata->line_len = 0;
	wdata->endian = 0;
	wdata->width = 0;
	wdata->height = 0;
}

void	init_render_tex(t_render_tex *rtex)
{
	init_wall_data(&rtex->north);
	init_wall_data(&rtex->south);
	init_wall_data(&rtex->west);
	init_wall_data(&rtex->east);
}
