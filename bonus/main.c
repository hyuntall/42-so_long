/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyuncpar <hyuncpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 19:35:46 by hyuncpar          #+#    #+#             */
/*   Updated: 2022/11/03 21:22:25 by hyuncpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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
	game->enemy_list = 0;
	game->cleard = 0;
	game->sprite = 1;
}

void	game_loop(t_game *game)
{
	t_list		*enemy;
	static int	time;

	enemy = game->enemy_list;
	if (time == 10)
	{
		while (enemy)
		{
			move_enemy(game, enemy);
			enemy = enemy->next;
		}
		game->sprite = !game->sprite;
		time = 0;
	}
	time++;
}

int	game_start(t_game *game)
{
	char	*game_cnt;

	game_cnt = ft_itoa(game->move_cnt);
	overlay_img(game);
	mlx_string_put(game->mlx, game->win, 64, 64, 999999999, "MOVE COUNT: ");
	mlx_string_put(game->mlx, game->win, 150, 64, 999999999, game_cnt);
	if (game->cleard == NORMAL || game->cleard == NOT_CLEARD)
		game_loop(game);
	else if (game->cleard == GAME_CLEAR)
		mlx_string_put(game->mlx, game->win, 64, 32, 999999999, "GAME CLEAR!");
	else if (game->cleard == GAME_OVER)
		mlx_string_put(game->mlx, game->win, 64, 32, 999999999, "GAME OVER!");
	free(game_cnt);
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
	mlx_hook(game.win, X_EVENT_KEY_RELEASE, 0, &key_event, &game);
	mlx_hook(game.win, 17, 0, game_exit, &game);
	mlx_loop_hook(game.mlx, game_start, &game);
	mlx_loop(game.mlx);
}
