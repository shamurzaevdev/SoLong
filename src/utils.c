/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashamurz <ashamurz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 20:06:40 by ashamurz          #+#    #+#             */
/*   Updated: 2022/10/15 03:15:31 by ashamurz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_errors(int c)
{
	if (c == 0)
		write(2, "Error!\nWrong argument number.\n", 30);
	else if (c == 1)
		write(2, "Error!\nWrong map file.\n", 23);
	else if (c == 2)
		write(2, "Error!\nMap file is a dir.\n", 26);
	else if (c == 3)
		write(2, "Error!\nFile not properly read.\n", 31);
	else if (c == 4)
		write(2, "Error!\nCouldn't read Map file.\n", 31);
	else if (c == 5)
		write(2, "Error!\nMap shape is wrong.\n", 27);
	else if (c == 6)
		write(2, "Error!\nMap file includes wrong characters.\n", 43);
	else if (c == 7)
		write(2, "Error!\nNumber of elements on the map error.\n", 44);
	else if (c == 8)
		write(2, "Error!\nWalls error on the map.\n", 31);
	exit (1);
}

void	move_output(t_game *solong)
{
	write(1, "move :", 6);
	ft_putnbr_fd(solong->steps, 1);
	write(1, "\n", 1);
	write(1, "collectible :", 13);
	ft_putnbr_fd(solong->collectables_n, 1);
	write(1, "\n", 1);
}

void	free_tab(t_game *solong, int i)
{
	while (solong->map[i])
	{
		free(solong->map[i]);
		solong->map[i] = NULL;
		i++;
	}
	free(solong->map);
}

int	ft_exit(void)
{
	exit(0);
}