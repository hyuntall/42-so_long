/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyuncpar <hyuncpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 17:01:26 by hyuncpar          #+#    #+#             */
/*   Updated: 2022/11/03 19:29:02 by hyuncpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	map_free(char **map)
{
	int		i;

	i = -1;
	while (map[++i])
	{
		free(map[i]);
		map[i] = 0;
	}
	free(map);
	map = 0;
}

void	enemy_free(t_game *game)
{
	t_list	*enemy;
	t_list	*temp;

	enemy = game->enemy_list;
	while (enemy)
	{
		temp = enemy->next;
		free(enemy);
		enemy = temp;
	}
}

void	memory_free(t_game *game)
{
	map_free(game->map);
	if (game->enemy_list)
		enemy_free(game);
	mlx_destroy_image(game->mlx, game->cherry);
	mlx_destroy_image(game->mlx, game->wall);
	mlx_destroy_image(game->mlx, game->empty);
	mlx_destroy_image(game->mlx, game->packman);
	mlx_destroy_image(game->mlx, game->packman2);
	mlx_destroy_image(game->mlx, game->exit);
}
