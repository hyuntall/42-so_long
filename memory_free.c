/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyuncpar <hyuncpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 17:01:26 by hyuncpar          #+#    #+#             */
/*   Updated: 2022/10/26 17:23:53 by hyuncpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	map_free(char **map)
{
	int		i;

	i = -1;
	while (map[++i])
		free(map[i]);
	free(map);
}

void	memory_free(t_game *game)
{
	map_free(game->map);
}
