/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processing_move.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyuncpar <hyuncpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 15:19:46 by hyuncpar          #+#    #+#             */
/*   Updated: 2022/11/03 20:54:47 by hyuncpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	processing_move(t_game *game)
{
	game->move_cnt += 1;
	if (game->map[game->y][game->x] == 'C')
		game->item_cnt--;
	else if (game->map[game->y][game->x] == 'E')
	{
		if (!game->item_cnt)
			game->cleard = GAME_CLEAR;
		else
			game->cleard = NOT_CLEARD;
	}
	else if (game->map[game->y][game->x] == 'G')
	{
		game->cleard = GAME_OVER;
		return ;
	}
	game->map[game->y][game->x] = 'P';
}
