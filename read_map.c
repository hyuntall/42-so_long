/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyuncpar <hyuncpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 14:59:55 by hyuncpar          #+#    #+#             */
/*   Updated: 2022/11/03 20:24:10 by hyuncpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_filename(char *filename)
{
	int	i;

	i = ft_strlen(filename);
	if (filename[--i] != 'r')
		return (0);
	if (filename[--i] != 'e')
		return (0);
	if (filename[--i] != 'b')
		return (0);
	if (filename[--i] != '.')
		return (0);
	return (1);
}

void	read_map(char *filename, t_game *game)
{
	int		fd;
	char	*line;
	char	*tmp;
	char	*backup;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		print_error(game, "Unable file!\n");
	line = get_next_line(fd);
	if (!line)
		print_error(game, "Empty file!\n");
	game->width = ft_strlen(line) - 1;
	backup = ft_strdup(line);
	while (line)
	{
		tmp = backup;
		game->heigth += 1;
		free(line);
		line = get_next_line(fd);
		backup = ft_strjoin(tmp, line);
		free(tmp);
	}
	free(line);
	game->map = ft_split(backup, '\n');
	free(backup);
}
