/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albetanc <albetanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 15:08:42 by albetanc          #+#    #+#             */
/*   Updated: 2025/11/13 16:16:30 by albetanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"


int	close_winx(t_display *data)
{
	clean_exit(data, 0);
	return (0);
}

void	*create_win(t_display *data)
{
	char	*msg;

	msg = "MiniMap Debug";
	data->win = mlx_new_window(data->mlx, data->win_w, data->win_h, msg);
	if (!data->win)
	{
		print_error("Error: creating a window");
		return (NULL);
	}
	return (data->win);
}


void	ini_win(t_display *data)
{
	data->win_h = WIN_HEIGHT;
	data->win_w = WIN_WIDTH;
	data->move_count = 0;
}
