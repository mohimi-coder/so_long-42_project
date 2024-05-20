/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohimi <mohimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 19:05:04 by mohimi            #+#    #+#             */
/*   Updated: 2024/03/11 15:42:21 by mohimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**read_map(char	*str)
{
	char	*join_line;
	char	*read_line;
	char	**splt_map;
	int		fd;
	char	*tmp;

	join_line = NULL;
	read_line = NULL;
	fd = open(str, O_RDWR);
	if (fd < 0)
		ft_error_message("Error: from fd!");
	read_line = get_next_line(fd);
	while (read_line)
	{
		if (*read_line == '\n' || *read_line == ' ')
			ft_error_message("Error: map not valid!");
		tmp = join_line;
		join_line = ft_strjoin(join_line, read_line);
		free(tmp);
		free(read_line);
		read_line = get_next_line(fd);
	}
	splt_map = ft_split(join_line, '\n');
	free(join_line);
	return (close (fd), splt_map);
}

void	check_boundary(t_vars *arg)
{
	int	i;

	i = 0;
	check_length_map(arg);
	while (arg->map[0][i])
	{
		if (arg->map[0][i] != '1')
			ft_error_message("Error: map is not valid!");
		i++;
	}
	i = 0;
	while (arg->map[arg->hie - 1][i])
	{
		if (arg->map[arg->hie - 1][i] != '1')
			ft_error_message("Error: map is not valid!");
		i++;
	}
}

void	check_length_map(t_vars *arg)
{
	int	first_line_length;
	int	i;
	int	line_length;

	check_lines_of_map(arg);
	first_line_length = 0;
	while (arg->map[0][first_line_length])
		first_line_length++;
	i = 1;
	while (i < arg->hie)
	{
		line_length = 0;
		while (arg->map[i][line_length])
			line_length++;
		i++;
		if (line_length != first_line_length)
			ft_error_message("Error: in length of the map!");
	}
}

void	check_lines_of_map(t_vars *arg)
{
	int	i;
	int	length;

	i = 0;
	while (i < arg->hie)
	{
		length = 0;
		while (arg->map[i][length])
			length++;
		if (arg->map[i][0] != '1')
			ft_error_message("Error: map is not valid!");
		if (arg->map[i][length - 1] != '1')
			ft_error_message("Error: map is not valid!");
		i++;
	}
}
