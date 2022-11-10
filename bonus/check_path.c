/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyuncpar <hyuncpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 13:23:57 by hyuncpar          #+#    #+#             */
/*   Updated: 2022/11/10 15:31:25 by hyuncpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	**make_visited(t_game *game)
{
	int	**map;
	int	i;
	int	j;

	i = -1;
	map = (int **)malloc(sizeof(int *) * (game->heigth));
	if (!map)
		return (0);
	while (++i < game->heigth - 1)
	{
		map[i] = (int *)malloc(sizeof(int) * (game->width + 1));
		if (!map[i])
		{
			check_map_free(map);
			return (0);
		}
		j = -1;
		while (j < game->width)
			map[i][++j] = 0;
	}
	map[i] = 0;
	return (map);
}

void	dfs(t_game *game, t_check *check, int x, int y)
{
	const int	dx[4] = {0, 0, -1, 1};
	const int	dy[4] = {-1, 1, 0, 0};
	int			nx;
	int			ny;
	int			i;

	check->visited[y][x] = 1;
	i = -1;
	if (game->map[y][x] == 'C')
		check->item_cnt -= 1;
	if (game->map[y][x] == 'E')
	{
		game->valid_path = 1;
		return ;
	}
	while (++i < 4)
	{
		nx = x + dx[i];
		ny = y + dy[i];
		if (game->map[ny][nx] != '1' && !check->visited[ny][nx])
			dfs(game, check, nx, ny);
	}
}

void	init_check(t_game *game, t_check *check)
{
	check->visited = make_visited(game);
	check->x = game->x;
	check->y = game->y;
	check->item_cnt = game->item_cnt;
}

void	check_path(t_game *game)
{
	t_check	check;

	init_check(game, &check);
	dfs(game, &check, game->x, game->y);
	if (!game->valid_path || check.item_cnt > 0)
		print_error(game, "Not valid path!\n");
	check_map_free(check.visited);
}
