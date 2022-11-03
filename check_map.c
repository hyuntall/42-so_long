/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyuncpar <hyuncpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 16:33:29 by hyuncpar          #+#    #+#             */
/*   Updated: 2022/11/03 21:44:42 by hyuncpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_wall(char *line)
{
	int	i;

	i = -1;
	while (line[++i])
		if (line[i] != '1')
			return (0);
	return (1);
}

void	chech_valid_path(t_game *game, int y, int x)
{
	if (y - 1 > 0 && game->map[y - 1][x] != '1')
		return ;
	else if (y + 1 < game->heigth && game->map[y + 1][x] != '1')
		return ;
	else if (x - 1 > 0 && game->map[y][x - 1] != '1')
		return ;
	else if (x + 1 < game->width && game->map[y][x + 1] != '1')
		return ;
	print_error(game, "Not valid path!\n");
}

void	find_obj(t_game *game, int y, char *line)
{
	int	i;

	i = -1;
	while (line[++i])
	{
		if (line[i] == 'C')
			game->item_cnt += 1;
		else if (line[i] == 'E')
			game->exit_cnt += 1;
		else if (line[i] == 'P')
		{
			game->y = y;
			game->x = i;
			game->start_cnt += 1;
		}
		else if (line[i] == '0' || line[i] == '1')
			;
		else
			print_error(game, "Unable component in map!!\n");
	}
}

void	check_map(t_game *game)
{
	int		i;

	i = -1;
	if (!check_wall((game->map)[0]))
		print_error(game, "Not found wall!\n");
	while ((game->map)[++i])
	{
		if (game->width != ft_strlen((game->map)[i]))
			print_error(game, "Not rectangle map!\n");
		if ((game->map)[i][0] != '1' || (game->map)[i][game->width - 1] != '1')
			print_error(game, "Not found wall!\n");
		find_obj(game, i, (game->map)[i]);
	}
	if (!game->item_cnt)
		print_error(game, "Not found item!\n");
	if (game->start_cnt != 1)
		print_error(game, "Not one start point!\n");
	if (game->exit_cnt != 1)
		print_error(game, "Not one exit!\n");
}
