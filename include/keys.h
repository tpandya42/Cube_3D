/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albetanc <albetanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 07:51:27 by albetanc          #+#    #+#             */
/*   Updated: 2025/11/19 08:35:04 by albetanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEYS_H
# define KEYS_H

# include "cub.h"

# ifdef __APPLE__
#  define KEY_W       13
#  define KEY_A       0
#  define KEY_S       1
#  define KEY_D       2

#  define KEY_Q       12
#  define KEY_E       14

#  define KEY_LEFT    123
#  define KEY_RIGHT   124
#  define KEY_UP      126
#  define KEY_DOWN    125

#  define KEY_ESC     53
# else
#  define KEY_W       XK_w
#  define KEY_A       XK_a
#  define KEY_S       XK_s
#  define KEY_D       XK_d

#  define KEY_Q        XK_q
#  define KEY_E        XK_e

#  define KEY_LEFT    XK_Left
#  define KEY_RIGHT   XK_Right
#  define KEY_UP       XK_Up
#  define KEY_DOWN     XK_Down

#  define KEY_ESC XK_Escape
# endif

#endif
