/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashamurz <ashamurz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 18:51:11 by ashamurz          #+#    #+#             */
/*   Updated: 2022/10/15 03:19:55 by ashamurz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <stdio.h>
# include <mlx.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <fcntl.h>
# include "../libft/libft.h"
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# define W_MOVE 13
# define S_MOVE 1
# define A_MOVE 0
# define D_MOVE 2
# define ESC 53

typedef struct s_game
{
    int         collected;
    int         map_lines;
    char        **map;
    char        x_pos;
    char        y_pos;
    int        collectables_n;
    int         map_columns;
    int         steps;
    
    char        *character_d;
    char        *character_u;
    char        *character_r;
    char        *character_l;
    char        *border;
    char        *exit;
    char        *background;
    char        *collectable;
    
    int         he;
    int         wi;

    void        *the_character;
    void        *the_background;
    void        *the_border;
    void        *the_exit;
    void        *the_collectable;
    void        *window;
    void        *mlx_point;
}           t_game;

int     main(int argc, char **argv);
void	pars_init_map(t_game *solong, char *av1);
int ft_draw_vec_two(t_game *solong, char c, int i, int j);
int ft_draw_vec(t_game *solong, char c, int i, int j);
void ft_map_init_one(t_game *solong);
void init_map(t_game *solong, char *av1);
void	ft_check_form_chars(t_game *solong, int tmp);
void ft_check_char(t_game *solong);
void	ft_items_position_count(t_game *solong, int p, int e, int c);
void	ft_borders(t_game *solong, int i, int j);
int parsing(int ac, char *av);
void	ft_errors(int c);
void	free_tab(t_game *solong, int i);
void	move_output(t_game *solong);
void		ft_collect_case_down(t_game *solong);
void	ft_collect_case_up(t_game *solong);
void	ft_collect_case_left(t_game *solong);
void	ft_collect_case_right(t_game *solong);
int		assign_key(int key, t_game *solong);
int		ft_exit(void);
void	move_down(t_game *solong);
void	move_up(t_game *solong);
void	move_left(t_game *solong);
void	move_right(t_game *solong);
static void	ft_win_init(t_game *solong);
void ft_map_init_two( t_game *solong, int x_pos, int y_pos);

size_t	ft_strlen(const char *str);
char	*ft_substr(const char *s, unsigned int start, size_t len);
char	*ft_strchr(const char *str, int c);
char	*ft_strdup(const char *src);
char	*get_next_line(int fd);

#endif
