/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyuncpar <hyuncpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 15:00:06 by hyuncpar          #+#    #+#             */
/*   Updated: 2022/10/26 18:09:57 by hyuncpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <fcntl.h>
# include "./mlx/mlx.h"
# include "./gnl/get_next_line.h"

typedef struct s_game
{
	int		width;
	int		heigth;
	int		item_cnt;
	int		exit_cnt;
	int		start_cnt;
	char	**map;
	void	*packman;
	void	*cherry;
	void	*wall;
	void	*exit;
}	t_game;

void	read_map(char *filename, t_game *game);

void	check_map(t_game *game);

void	print_error(t_game *game, char *message);

void	memory_free(t_game *game);

void	setting_img(t_game *game, void *mlx);
void	overlay_img(t_game *game, void *mlx, void *win);

char	**ft_split(char const *s, char c);
#endif