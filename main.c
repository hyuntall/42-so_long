/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyuncpar <hyuncpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 19:35:46 by hyuncpar          #+#    #+#             */
/*   Updated: 2022/11/07 17:46:37 by hyuncpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	game->valid_path = 0;
}

int	game_start(t_game *game)
{
	char	*move_cnt;

	move_cnt = ft_itoa(game->move_cnt);
	overlay_img(game);
	mlx_string_put(game->mlx, game->win, 64, 64, 999999999, "MOVE COUNT: ");
	mlx_string_put(game->mlx, game->win, 150, 64, 999999999, move_cnt);
	if (game->cleard == GAME_CLEAR)
		mlx_string_put(game->mlx, game->win, 64, 32, 999999999, "GAME CLEAR!");
	free(move_cnt);
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	game;
	void	*img;

	init_game(&game);
	if (argc != 2)
		print_error(&game, "Please one parameter!\n");
	if (!check_filename(argv[1]))
		print_error(&game, "Unable filename!\n");
	read_map(argv[1], &game);
	check_map(&game);
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, game.width * 64, \
	(game.heigth - 1) * 64, "my_mlx");
	setting_img(&game);
	overlay_img(&game);
	mlx_hook(game.win, X_EVENT_KEY_RELEASE, 0, &key_event, &game);
	mlx_hook(game.win, 17, 0, game_exit, &game);
	mlx_loop_hook(game.mlx, game_start, &game);
	mlx_loop(game.mlx);
}
