/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   you_win.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohimi <mohimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 14:05:35 by mohimi            #+#    #+#             */
/*   Updated: 2024/03/03 22:09:51 by mohimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	you_win(t_vars *arg, int x, int y)
{
	if (arg->count_c == 0 && arg->map[x][y] == 'E')
	{
		ft_free_leak(arg->map);
		write(1, "you win!\n", 10);
		exit (0);
	}
}

void	ft_error_message(char *mess)
{
	int	i;

	i = 0;
	while (mess[i])
	{
		write (1, &mess[i], 1);
		i++;
	}
	write (1, "\n", 1);
	exit(1);
}

void	ft_free_leak(char **str)
{
	int	i;

	i = 0;
	if (!str)
		ft_error_message("Empty map!!");
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}
