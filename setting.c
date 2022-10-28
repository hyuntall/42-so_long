/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyuncpar <hyuncpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 17:49:16 by hyuncpar          #+#    #+#             */
/*   Updated: 2022/10/28 18:13:28 by hyuncpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	setting_img(t_game *game)
{	printf("%d %d\n", game->x, game->y);
	game->packman = \
	mlx_xpm_file_to_image(game->mlx, \
	"./img/man.xpm", &game->img_width, &game->img_heigth);
	game->cherry = \
	mlx_xpm_file_to_image(game->mlx, \
	"./img/cherry.xpm", &game->img_width, &game->img_heigth);
	game->wall = \
	mlx_xpm_file_to_image(game->mlx, \
	"./img/wall.xpm", &game->img_width, &game->img_heigth);
	game->exit = \
	mlx_xpm_file_to_image(game->mlx, \
	"./img/exit.xpm", &game->img_width, &game->img_heigth);
	printf("%d %d\n", game->x, game->y);
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
			if (game->map[h][w] == '1')
				mlx_put_image_to_window(game->mlx, \
				game->win, game->wall, w * 64, h * 64);
			else if (game->map[h][w] == 'C')
				mlx_put_image_to_window(game->mlx, \
				game->win, game->cherry, w * 64, h * 64);
			else if (game->map[h][w] == 'P')
				mlx_put_image_to_window(game->mlx, \
				game->win, game->packman, w * 64, h * 64);
			else if (game->map[h][w] == 'E')
				mlx_put_image_to_window(game->mlx, \
				game->win, game->exit, w * 64, h * 64);
		}
	}
}
