/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyuncpar <hyuncpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 21:19:25 by hyuncpar          #+#    #+#             */
/*   Updated: 2022/11/02 22:07:21 by hyuncpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

t_list	*new_enemy(int x, int y)
{
	t_list	*list;

	list = (t_list *)malloc(sizeof(t_list));
	if (!list)
		return (0);
	list->pos = 0;
	list->x = x;
	list->y = y;
	list->next = 0;
	return (list);
}

void	first_enemy(t_game *game, int x, int y)
{
	t_list	*enemy;

	enemy = new_enemy(x, y);
	game->enemy_list = enemy;
	game->last_emeny = enemy;
}

void	add_enemy(t_game *game, int x, int y)
{
	t_list	*enemy;

	if (!game->enemy_list)
		first_enemy(game, x, y);
	else
	{
		enemy = new_enemy(x, y);
		game->last_emeny->next = enemy;
		game->last_emeny = game->last_emeny->next;
		game->last_emeny->next = 0;
	}
}
