/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyuncpar <hyuncpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 17:49:16 by hyuncpar          #+#    #+#             */
/*   Updated: 2022/11/02 20:40:28 by hyuncpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	setting_img(t_game *game)
{
	game->packman = \
	mlx_xpm_file_to_image(game->mlx, \
	"./img/man.xpm", &game->img_width, &game->img_heigth);
	game->packman2 = \
	mlx_xpm_file_to_image(game->mlx, \
	"./img/man2.xpm", &game->img_width, &game->img_heigth);
	game->cherry = \
	mlx_xpm_file_to_image(game->mlx, \
	"./img/cherry.xpm", &game->img_width, &game->img_heigth);
	game->wall = \
	mlx_xpm_file_to_image(game->mlx, \
	"./img/wall.xpm", &game->img_width, &game->img_heigth);
	game->empty = \
	mlx_xpm_file_to_image(game->mlx, \
	"./img/empty.xpm", &game->img_width, &game->img_heigth);
	game->ghost = \
	mlx_xpm_file_to_image(game->mlx, \
	"./img/ghost.xpm", &game->img_width, &game->img_heigth);
	game->exit = \
	mlx_xpm_file_to_image(game->mlx, \
	"./img/exit.xpm", &game->img_width, &game->img_heigth);
}

void	put_img(t_game *game, int h, int w)
{
	if (game->map[h][w] == '1')
		mlx_put_image_to_window(game->mlx, \
		game->win, game->wall, w * 64, h * 64);
	else if (game->map[h][w] == 'C')
		mlx_put_image_to_window(game->mlx, \
		game->win, game->cherry, w * 64, h * 64);
	else if (game->map[h][w] == '0')
		mlx_put_image_to_window(game->mlx, \
		game->win, game->empty, w * 64, h * 64);
	else if (game->map[h][w] == 'P')
	{
		if (game->sprite)
			mlx_put_image_to_window(game->mlx, \
			game->win, game->packman, w * 64, h * 64);
		else
			mlx_put_image_to_window(game->mlx, \
			game->win, game->packman2, w * 64, h * 64);
	}
	else if (game->map[h][w] == 'E')
		mlx_put_image_to_window(game->mlx, \
		game->win, game->exit, w * 64, h * 64);
	else if (game->map[h][w] == 'G')
		mlx_put_image_to_window(game->mlx, \
		game->win, game->ghost, w * 64, h * 64);
}

void	overlay_img(t_game *game)
{
	int		h;
	int		w;

	h = -1;
	while (++h < game->heigth - 1)
	{
		w = -1;
		while (++w < game->width)
		{
			mlx_put_image_to_window(game->mlx, \
			game->win, game->empty, w * 64, h * 64);
			put_img(game, h, w);
		}
	}
}
