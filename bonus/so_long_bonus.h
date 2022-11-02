/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyuncpar <hyuncpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 15:00:06 by hyuncpar          #+#    #+#             */
/*   Updated: 2022/11/02 22:06:23 by hyuncpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include "../mlx/mlx.h"
# include "../gnl/get_next_line.h"

# define X_EVENT_KEY_PRESS		2
# define X_EVENT_KEY_RELEASE	3

# define KEY_ESC		53
# define KEY_W			13
# define KEY_A			0
# define KEY_S			1
# define KEY_D			2

typedef struct s_list
{
	struct s_list	*next;
	int				pos;
	int				x;
	int				y;
}	t_list;

typedef struct s_game
{
	int		width;
	int		heigth;
	int		item_cnt;
	int		exit_cnt;
	int		start_cnt;
	int		img_width;
	int		img_heigth;
	void	*mlx;
	void	*win;
	char	**map;
	int		x;
	int		y;
	void	*packman;
	void	*packman2;
	void	*cherry;
	void	*empty;
	void	*wall;
	void	*exit;
	void	*ghost;
	int		move_cnt;
	t_list	*enemy_list;
	t_list	*last_emeny;
	int		cleard;
	int		sprite;
	int		time;
}	t_game;

void	read_map(char *filename, t_game *game);

void	check_map(t_game *game);

void	print_error(t_game *game, char *message);

void	map_free(char **map);
void	memory_free(t_game *game);

void	setting_img(t_game *game);
void	overlay_img(t_game *game);

int		key_event(int keycode, t_game *game);

void	processing_move(t_game *game);

void	add_enemy(t_game *game, int x, int y);

void	move_enemy(t_game *game, t_list *enemy);

void	game_exit(t_game *game);

char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);
#endif