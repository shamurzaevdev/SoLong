/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving_up.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashamurz <ashamurz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 20:39:28 by ashamurz          #+#    #+#             */
/*   Updated: 2022/10/15 03:06:38 by ashamurz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_up(t_game *solong)
{
	solong->x_pos--;
	if (solong->map[solong->x_pos][solong->y_pos] == 'E' && solong->collectables_n)
		solong->x_pos++;
	else if (solong->map[solong->x_pos][solong->y_pos] == 'E' && !solong->collectables_n)
	{
		free_tab(solong, 0);
		exit (0);
	}
	else if (solong->map[solong->x_pos][solong->y_pos] == '0')
	{
		solong->map[solong->x_pos][solong->y_pos] = 'P';
		solong->map[solong->x_pos + 1][solong->y_pos] = '0';
		solong->steps++;
		move_output(solong);
	}
    else if (solong->map[solong->x_pos][solong->y_pos] == '1')
		solong->x_pos++;
	else if (solong->map[solong->x_pos][solong->y_pos] == 'C')
		ft_collect_case_up(solong);
	solong->the_character = mlx_xpm_file_to_image(solong->mlx_point, solong->character_u,
			&solong->he, &solong->wi);
	ft_map_init_two(solong, solong->x_pos, solong->y_pos);
}

void ft_collect_case_up(t_game *solong)
{
    	solong->map[solong->x_pos + 1][solong->y_pos] = '0';
		solong->map[solong->x_pos][solong->y_pos] = 'P';
		solong->collectables_n--;
		solong->steps++;
		move_output(solong);
}
