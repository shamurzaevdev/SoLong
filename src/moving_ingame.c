/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving_ingame.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashamurz <ashamurz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 20:19:42 by ashamurz          #+#    #+#             */
/*   Updated: 2022/10/14 23:27:38 by ashamurz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	assign_key(int key, t_game *solong)
{
	if (key == ESC)
		exit(0);
	if (key == S_MOVE)
		move_down(solong);
	if (key == W_MOVE)
		move_up(solong);
	if (key == D_MOVE)
		move_right(solong);
	if (key == A_MOVE)
		move_left(solong);
	return (0);
}

