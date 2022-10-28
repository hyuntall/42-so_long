/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyuncpar <hyuncpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 19:35:46 by hyuncpar          #+#    #+#             */
/*   Updated: 2022/10/28 18:21:07 by hyuncpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>
#include <stdlib.h>

/*
typedef struct s_param{
	int		x;
	int		y;
}				t_param;

void	param_init(t_param *param)
{
	param->x = 3;
	param->y = 4;
}
*/

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
}

int	main(void)
{
	t_game	game;
	void	*img;

	init_game(&game);
	read_map("./map.ber", &game);
	check_map(&game);
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, 1000, 1000, "my_mlx");
	setting_img(&game);
	overlay_img(&game);
	mlx_hook(game.win, X_EVENT_KEY_RELEASE, 0, &key_event, &game);
	mlx_loop(game.mlx);
}
