/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyuncpar <hyuncpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 14:59:55 by hyuncpar          #+#    #+#             */
/*   Updated: 2022/10/26 17:23:28 by hyuncpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	read_map(char *filename, t_game *game)
{
	int		fd;
	char	*line;
	char	*tmp;

	fd = open(filename, O_RDONLY);
	line = get_next_line(fd);
	game->width = ft_strlen(line) - 1;
	tmp = ft_strdup(line);
	while (line)
	{
		game->heigth += 1;
		free(line);
		line = get_next_line(fd);
		tmp = ft_strjoin(tmp, line);
	}
	free(line);
	game->map = ft_split(tmp, '\n');
	free(tmp);
}
