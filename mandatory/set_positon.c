/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_positon.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohimi <mohimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 20:24:24 by mohimi            #+#    #+#             */
/*   Updated: 2024/03/05 23:03:49 by mohimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_positions(t_vars *arg)
{
	int	i;
	int	j;

	i = 0;
	while (arg->map[i])
	{
		j = 0;
		while (arg->map[i][j])
		{
			if (arg->map[i][j] == 'P')
			{
				arg->x = i;
				arg->y = j;
			}
			if (arg->map[i][j] == 'C')
				arg->count_c++;
			if (arg->map[i][j] == 'E')
			{
				arg->e_x = i;
				arg->e_y = j;
			}
			j++;
		}
		i++;
	}
}

void	check_map(t_vars *arg)
{
	int	i;
	int	j;

	i = 0;
	check_player_count(arg);
	while (arg->map[i])
	{
		j = 0;
		while (arg->map[i][j])
		{
			if (arg->map[i][j] != '1' && arg->map[i][j] != 'C' &&
			arg->map[i][j] != 'E' &&
			arg->map[i][j] != 'P' && arg->map[i][j] != '0')
				ft_error_message("Error: from check_map!");
			j++;
		}
		i++;
	}
}

void	check_player_count(t_vars *arg)
{
	int	count;
	int	i;
	int	j;

	count = 0;
	i = 0;
	check_exit_count(arg);
	while (i < arg->hie)
	{
		j = 0;
		while (arg->map[i][j])
		{
			if (arg->map[i][j] == 'P')
				count++;
			if (count > 1)
				ft_error_message("Error: only one player!");
			j++;
		}
		i++;
	}
}

void	check_exit_count(t_vars *arg)
{
	int	exit_count;
	int	i;
	int	j;

	exit_count = 0;
	i = 0;
	while (i < arg->hie)
	{
		j = 0;
		while (arg->map[i][j])
		{
			if (arg->map[i][j] == 'E')
				exit_count++;
			if (exit_count > 1)
				ft_error_message("Error: only one exit!");
			j++;
		}
		i++;
	}
}
