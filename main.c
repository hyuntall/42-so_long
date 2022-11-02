/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyuncpar <hyuncpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 19:35:46 by hyuncpar          #+#    #+#             */
/*   Updated: 2022/11/02 20:45:15 by hyuncpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>
#include <stdlib.h>

void	init_game(t_game *game)
{
	game->width = 1;
	game->heigth = 1;
	game->map = 0;
	game->item_cnt = 0;
	game->start_cnt = 0;
	game->exit_cnt = 0;
	game->x = 0;
	game->y = 0;
	game->move_cnt = 0;
	game->cleard = 0;
}

int	game_start(t_game *game)
{
	int i = -1;
	while (game->map[++i])
		printf("%s\n", game->map[i]);
	overlay_img(game);
	mlx_string_put(game->mlx, game->win, 64, 64, 222, "MOVE COUNT: ");
	mlx_string_put(game->mlx, game->win, 150, 64, 222, ft_itoa(game->move_cnt));
	if (game->cleard > 0)
		mlx_string_put(game->mlx, game->win, 64, 32, 222, "GAME CLEAR!");
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	game;
	void	*img;

	if (argc != 2)
		return (0);
	init_game(&game);
	read_map(argv[1], &game);
	check_map(&game);
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, game.width * 64, \
	(game.heigth - 1) * 64, "my_mlx");
	setting_img(&game);
	overlay_img(&game);
	mlx_hook(game.win, X_EVENT_KEY_RELEASE, 0, &key_event, &game);
	mlx_loop_hook(game.mlx, game_start, &game);
	mlx_loop(game.mlx);
}
