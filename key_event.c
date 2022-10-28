/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyuncpar <hyuncpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 18:17:06 by hyuncpar          #+#    #+#             */
/*   Updated: 2022/10/28 18:31:07 by hyuncpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_up(t_game *game)
{
	int	h;
	int	w;

	h = game->y;
	w = game->x;
	if (game->map[h + 1][w] == '1')
		return ;
	else
	{
		game->y++;
		mlx_put_image_to_window(game->mlx, \
		game->win, game->packman, game->x * 64, game->y * 64);
	}
}

void	move_down(t_game *game)
{
	int	h;
	int	w;

	h = game->y;
	w = game->x;
	if (game->map[h - 1][w] == '1')
		return ;
	else
	{
		game->y--;
		mlx_put_image_to_window(game->mlx, \
		game->win, game->packman, game->x * 64, game->y * 64);
	}
}

void	move_left(t_game *game)
{
	int	h;
	int	w;

	h = game->y;
	w = game->x;
	if (game->map[h][w - 1] == '1')
		return ;
	else
	{
		game->x--;
		mlx_put_image_to_window(game->mlx, \
		game->win, game->packman, game->x * 64, game->y * 64);
	}
}

void	move_right(t_game *game)
{
	int	h;
	int	w;

	h = game->y;
	w = game->x;
	if (game->map[h][w + 1] == '1')
		return ;
	else
	{
		game->x++;
		mlx_put_image_to_window(game->mlx, \
		game->win, game->packman, game->x * 64, game->y * 64);
	}
}

int	key_event(int keycode, t_game *game)
{
	if (keycode == KEY_W)
		move_up(game);
	else if (keycode == KEY_S)
		move_down(game);
	else if (keycode == KEY_A)
		move_left(game);
	else if (keycode == KEY_D)
		move_right(game);
	else if (keycode == KEY_ESC)
		exit(0);
	printf("x: %d, y: %d\n", game->x, game->y);
	return (0);
}