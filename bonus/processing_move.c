/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processing_move.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyuncpar <hyuncpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 15:19:46 by hyuncpar          #+#    #+#             */
/*   Updated: 2022/11/02 20:40:19 by hyuncpar         ###   ########.fr       */
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
			game->cleard = 1;
		else
			game->cleard = -1;
	}
	printf("%c %d item: %d\n", game->map[game->y][game->x], game->cleard, game->item_cnt);
	game->map[game->y][game->x] = 'P';
	game->sprite = 0;
}
