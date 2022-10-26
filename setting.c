/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyuncpar <hyuncpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 17:49:16 by hyuncpar          #+#    #+#             */
/*   Updated: 2022/10/26 18:15:05 by hyuncpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	setting_img(t_game *game, void *mlx)
{
	game->packman = \
	mlx_xpm_file_to_image(mlx, "./img/man.xpm", &game->width, &game->heigth);
	game->cherry = \
	mlx_xpm_file_to_image(mlx, "./img/cherry.xpm", &game->width, &game->heigth);
	game->wall = \
	mlx_xpm_file_to_image(mlx, "./img/wall.xpm", &game->width, &game->heigth);
	game->exit = \
	mlx_xpm_file_to_image(mlx, "./img/exit.xpm", &game->width, &game->heigth);
}

void	overlay_img(t_game *game, void *mlx, void *win)
{
	int		h;
	int		w;

	h = 0;
	while (h < game->heigth)
	{
		w = 0;
		while (game->width)
		{
			if (game->map[h][w] == '1')
				;
			else if (game->map[h][w] == 'C')
				mlx_put_image_to_window(mlx, win, game->cherry, w * 64, h * 64);
		}
		w++;
	}
	h++;
}
