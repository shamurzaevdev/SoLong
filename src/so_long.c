/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashamurz <ashamurz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 18:50:46 by ashamurz          #+#    #+#             */
/*   Updated: 2022/10/15 03:15:26 by ashamurz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int parsing(int ac, char *av)
{
    int i;
	
    i = 0;
    if (ac == 2)
    {
		while (av[i] != '\0')
		{
			if (av[i] == '.' && av[i + 1] == 'b' && av[i + 2] == 'e'
				&& av[i + 3] == 'r' && av[i + 4] == '\0')
            	return (1);
			i++;
		}
        ft_errors(1);
	}
    else
		ft_errors(0);
	return (0);
}

// CHANGE THIS ONEITS NOT CORRECT
void	ft_borders(t_game *solong, int i, int c)
{
	i = 0;
	c = 0;
	solong->map_columns = (ft_strlen(&solong->map[i][0]));
	while (solong->map[0][c] != '\0')
	{
		if (solong->map[0][c++] != '1')
			ft_errors(8);
	}
	while (i < solong->map_lines)
	{
		if (solong->map[i][0] != '1'
			|| solong->map[i][solong->map_columns - 1] != '1')
			ft_errors(8);
		i++;
	}
	c = 0;
	while (solong->map[0][c] != '\0')
	{
		if (solong->map[solong->map_lines - 1][c++] != '1')
			ft_errors(8);
	}
}

void	ft_items_position_count(t_game *solong, int p, int e, int c)
{
	int		i;
	int		j;

	i = 0;
	while (solong->map[i])
	{
		j = 0;
		while (solong->map[i][j])
		{
			if (solong->map[i][j] == 'P')
			{
				solong->x_pos = i;
				solong->y_pos = j;
				p++;
			}
			if (solong->map[i][j] == 'E')
				e++;
			if (solong->map[i][j] == 'C')
				c++;
			j++;
		}
		i++;
	}
	solong->collectables_n = c;
	if (p != 1 || e != 1 || solong->collectables_n <= 0)
	{
		ft_errors(7);
	}
}

void ft_check_char(t_game *solong)
{
	int		i;
	int		j;

	i = 0;
	while (solong->map[i])
	{
		j = 0;
		while (solong->map[i][j])
		{
			if (solong->map[i][j] != 'P' && solong->map[i][j] != 'E'
				&& solong->map[i][j] != '1' && solong->map[i][j] != '0'
				&& solong->map[i][j] != 'C')
			{
				ft_errors(6);
			}
			j++;
		}
		i++;
	}
}

void	ft_check_form_chars(t_game *solong, int tmp)
{
	int	i;

	i = 0;
	tmp = ft_strlen(solong->map[0]);
	while (solong->map[i])
	{
		if ((tmp != ft_strlen(solong->map[i])))
			ft_errors(5);
		i++;
	}
}

void init_map(t_game *solong, char *av1)
{
	int	i;
	int	fd;
	int	c;

	i = 0;
	c = solong->map_lines;
	solong->map = malloc(sizeof(char *) * solong->map_lines + 1);
	fd = open(av1, O_RDONLY);
	while (c > 0)
	{
		solong->map[i] = get_next_line(fd);
		i++;
		solong->map[i] = 0;
		c--;

	}
	solong->map[i] = 0;
	close (fd);
	solong->steps = 0;
}

void ft_map_init_one(t_game *solong)
{

	solong->mlx_point = mlx_init();
	solong->character_u = "graphics/go_up.xpm";
	solong->exit = "graphics/exit.xpm";
	solong->collectable = "graphics/collectable.xpm";
	solong->character_d = "graphics/go_down.xpm";
	solong->character_l = "graphics/go_left.xpm";
	solong->character_r = "graphics/go_right.xpm";
	solong->border = "graphics/border.xpm";
	solong->background = "graphics/background.xpm";
}

static void	ft_win_init(t_game *solong)
{
	solong->window = mlx_new_window(solong->mlx_point, solong->map_columns * 32,
		solong->map_lines * 32, "SoLong");
	solong->the_collectable = mlx_xpm_file_to_image(solong->mlx_point, solong->collectable,
			&solong->he, &solong->wi);
	solong->the_character = mlx_xpm_file_to_image(solong->mlx_point, solong->character_d,
			&solong->he, &solong->wi);
	solong->the_background = mlx_xpm_file_to_image(solong->mlx_point, solong->background,
			&solong->he, &solong->wi);
	solong->the_border = mlx_xpm_file_to_image(solong->mlx_point, solong->border,
			&solong->he, &solong->wi);
	solong->the_exit = mlx_xpm_file_to_image(solong->mlx_point, solong->exit,
			&solong->he, &solong->wi);
}

void	ft_map_init_two(t_game *solong, int i, int j)
{
	i = 0;
	while (solong->map[i])
	{
		j = 0;
		while (solong->map[i][j])
		{
			if (solong->map[i][j] == '1')
				ft_draw_vec(solong, '1', i, j);
			else if (solong->map[i][j] == '0')
				ft_draw_vec(solong, '0', i, j);
			else if (solong->map[i][j] == 'P')
				ft_draw_vec(solong, 'P', i, j);
			else if (solong->map[i][j] == 'C')
				ft_draw_vec(solong, 'C', i, j);
			else if (solong->map[i][j] == 'E')
				ft_draw_vec_two(solong, 'E', i, j);
			j++;
		}
		i++;
	}
}

int ft_draw_vec(t_game *solong, char c, int i, int j)
{
	if (c == '1')
		mlx_put_image_to_window(solong->mlx_point, solong->window,
			solong->the_border, j * 32, i * 32);
	else if (c == '0')
		mlx_put_image_to_window(solong->mlx_point, solong->window,
			solong->the_background, j * 32, i * 32);
	else if (c == 'P')
	{
		mlx_put_image_to_window(solong->mlx_point, solong->window,
			solong->the_background, j * 32, i * 32);
		mlx_put_image_to_window(solong->mlx_point, solong->window,
			solong->the_character, j * 32, i * 32);
	}
	else if (c == 'C')
	{
		mlx_put_image_to_window(solong->mlx_point, solong->window,
			solong->the_background, j * 32, i * 32);
		mlx_put_image_to_window(solong->mlx_point, solong->window,
			solong->the_collectable, j * 32, i * 32);
	}
		return (0);
}

int ft_draw_vec_two(t_game *solong, char c, int i, int j)
{
		mlx_put_image_to_window(solong->mlx_point, solong->window,
			solong->the_background, j * 32, i * 32);
		mlx_put_image_to_window(solong->mlx_point, solong->window,
			solong->the_exit, j * 32, i * 32);
	return (0);
}

void	pars_init_map(t_game *solong, char *av1)
{
	int fd;
	int	i;
	
	i = 0;
	solong->map_lines = 0;
	solong->collected = 0;
	fd = open(av1, O_DIRECTORY);
	if (fd != -1)
		ft_errors(2);
	else
	{
		fd = open(av1, O_RDONLY);
		if (fd == -1)
			ft_errors(4);
	}
	while (get_next_line(fd))
		solong->map_lines++;
	//free (line);
}

int main(int argc, char **argv)
{
    t_game      solong;
	
	solong.map = NULL;
	solong.collectables_n = 0;
    parsing(argc, argv[1]);
    pars_init_map(&solong, argv[1]);
	init_map(&solong, argv[1]);
	ft_check_form_chars(&solong, 0);
	ft_check_char(&solong);
	ft_borders(&solong, 0, 0);
	ft_items_position_count(&solong, 0, 0, 0);
	ft_map_init_one(&solong);
	ft_win_init(&solong);
	ft_map_init_two(&solong, 0, 0);
	mlx_hook(solong.window, 2, 0, assign_key, &solong);
	mlx_hook(solong.window, 17, 0, ft_exit, &solong);
	mlx_loop(solong.mlx_point);	
	return (0);
}