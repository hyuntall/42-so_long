/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyuncpar <hyuncpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 16:56:39 by hyuncpar          #+#    #+#             */
/*   Updated: 2022/11/02 20:57:43 by hyuncpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	print_error(t_game *game, char *message)
{
	printf("Error\n");
	perror(message);
	if (game->map)
		map_free(game->map);
	exit(0);
}
