/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_enemy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyuncpar <hyuncpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 21:12:15 by hyuncpar          #+#    #+#             */
/*   Updated: 2022/11/03 20:52:34 by hyuncpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	up_enemy(t_game *game, t_list *enemy)
{
	if (game->map[enemy->x - 1][enemy->y] == '0')
	{
		game->map[enemy->x][enemy->y] = '0';
		game->map[enemy->x - 1][enemy->y] = 'G';
		enemy->x--;
	}
	else if (game->map[enemy->x - 1][enemy->y] == 'P')
	{
		game->cleard = -1;
		game->map[enemy->x][enemy->y] = '0';
		game->map[enemy->x - 1][enemy->y] = 'G';
		enemy->x--;
	}
	else
		enemy->pos++;
}

void	down_enemy(t_game *game, t_list *enemy)
{
	if (game->map[enemy->x + 1][enemy->y] == '0')
	{
		game->map[enemy->x][enemy->y] = '0';
		game->map[enemy->x + 1][enemy->y] = 'G';
		enemy->x++;
	}
	else if (game->map[enemy->x + 1][enemy->y] == 'P')
	{
		game->cleard = -1;
		game->map[enemy->x][enemy->y] = '0';
		game->map[enemy->x + 1][enemy->y] = 'G';
		enemy->x++;
	}
	else
		enemy->pos++;
}

void	left_enemy(t_game *game, t_list *enemy)
{
	if (game->map[enemy->x][enemy->y - 1] == '0')
	{
		game->map[enemy->x][enemy->y] = '0';
		game->map[enemy->x][enemy->y - 1] = 'G';
		enemy->y--;
	}
	else if (game->map[enemy->x][enemy->y - 1] == 'P')
	{
		game->cleard = -1;
		game->map[enemy->x][enemy->y] = '0';
		game->map[enemy->x][enemy->y - 1] = 'G';
		enemy->y--;
	}
	else
		enemy->pos++;
}

void	right_enemy(t_game *game, t_list *enemy)
{
	if (game->map[enemy->x][enemy->y + 1] == '0')
	{
		game->map[enemy->x][enemy->y] = '0';
		game->map[enemy->x][enemy->y + 1] = 'G';
		enemy->y++;
	}
	else if (game->map[enemy->x][enemy->y + 1] == 'P')
	{
		game->cleard = -1;
		game->map[enemy->x][enemy->y] = '0';
		game->map[enemy->x][enemy->y + 1] = 'G';
		enemy->y++;
	}
	else
		enemy->pos++;
}

void	move_enemy(t_game *game, t_list *enemy)
{
	if (enemy->pos == 0)
		up_enemy(game, enemy);
	else if (enemy->pos == 1)
		down_enemy(game, enemy);
	else if (enemy->pos == 2)
		left_enemy(game, enemy);
	else if (enemy->pos == 3)
		right_enemy(game, enemy);
	if (enemy->pos > 3)
		enemy->pos = 0;
}
