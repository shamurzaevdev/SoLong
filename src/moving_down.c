/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving_down.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashamurz <ashamurz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 21:21:25 by ashamurz          #+#    #+#             */
/*   Updated: 2022/10/15 03:14:57 by ashamurz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "so_long.h"

void	move_down(t_game *solong)
{
	solong->x_pos++;
	if (solong->map[solong->x_pos][solong->y_pos] == 'E' && solong->collectables_n)
		solong->x_pos--;
	else if (solong->map[solong->x_pos][solong->y_pos] == 'E' && !solong->collectables_n)
	{
		free_tab(solong, 0);
		exit (0);
	}
	else if (solong->map[solong->x_pos][solong->y_pos] == '0')
	{
		solong->map[solong->x_pos][solong->y_pos] = 'P';
		solong->map[solong->x_pos - 1][solong->y_pos] = '0';
		solong->steps++;
		move_output(solong);
	}
    else if (solong->map[solong->x_pos][solong->y_pos] == '1')
		solong->x_pos--;
	else if (solong->map[solong->x_pos][solong->y_pos] == 'C')
		ft_collect_case_down(solong);
	solong->the_character = mlx_xpm_file_to_image(solong->mlx_point, solong->character_d,
			&solong->he, &solong->wi);
	ft_map_init_two(solong, solong->x_pos, solong->y_pos);
}

void ft_collect_case_down(t_game *solong)
{
		solong->collectables_n--;
		solong->map[solong->x_pos][solong->y_pos] = 'P';
    	solong->map[solong->x_pos - 1][solong->y_pos] = '0';
		solong->steps++;
		move_output(solong);
}
