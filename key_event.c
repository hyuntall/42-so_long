/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyuncpar <hyuncpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 18:17:06 by hyuncpar          #+#    #+#             */
/*   Updated: 2022/11/10 14:21:33 by hyuncpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_up(t_game *game)
{
	if (game->map[game->y - 1][game->x] != '1')
	{
		if (game->cleard < 0)
		{
			game->map[game->y][game->x] = 'E';
			game->cleard = 0;
		}
		else
			game->map[game->y][game->x] = '0';
		game->y--;
		processing_move(game);
	}
}

void	move_down(t_game *game)
{
	if (game->map[game->y + 1][game->x] != '1')
	{
		if (game->cleard < 0)
		{
			game->map[game->y][game->x] = 'E';
			game->cleard = 0;
		}
		else
			game->map[game->y][game->x] = '0';
		game->y++;
		processing_move(game);
	}
}

void	move_left(t_game *game)
{
	if (game->map[game->y][game->x - 1] != '1')
	{
		if (game->cleard < 0)
		{
			game->map[game->y][game->x] = 'E';
			game->cleard = 0;
		}
		else
			game->map[game->y][game->x] = '0';
		game->x--;
		processing_move(game);
	}
}

void	move_right(t_game *game)
{
	if (game->map[game->y][game->x + 1] != '1')
	{
		if (game->cleard < 0)
		{
			game->map[game->y][game->x] = 'E';
			game->cleard = 0;
		}
		else
			game->map[game->y][game->x] = '0';
		game->x++;
		processing_move(game);
	}
}

int	key_event(int keycode, t_game *game)
{
	if (game->cleard == NORMAL || game->cleard == NOT_CLEARD)
	{
		if (keycode == KEY_W)
			move_up(game);
		else if (keycode == KEY_S)
			move_down(game);
		else if (keycode == KEY_A)
			move_left(game);
		else if (keycode == KEY_D)
			move_right(game);
	}
	if (keycode == KEY_ESC)
		game_exit(game);
	return (0);
}
