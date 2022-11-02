/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyuncpar <hyuncpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 17:01:26 by hyuncpar          #+#    #+#             */
/*   Updated: 2022/11/02 20:40:03 by hyuncpar         ###   ########.fr       */
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

void	memory_free(t_game *game)
{
	map_free(game->map);
	mlx_destroy_image(game->mlx, game->cherry);
	mlx_destroy_image(game->mlx, game->wall);
	mlx_destroy_image(game->mlx, game->empty);
	mlx_destroy_image(game->mlx, game->packman);
	mlx_destroy_image(game->mlx, game->packman2);
	mlx_destroy_image(game->mlx, game->exit);
}
