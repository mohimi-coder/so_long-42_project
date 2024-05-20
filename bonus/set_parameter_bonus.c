/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_parameter_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohimi <mohimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 20:27:54 by mohimi            #+#    #+#             */
/*   Updated: 2024/03/12 10:08:17 by mohimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	ft_exit(t_vars *arg)
{
	ft_free_leak(arg->map);
	mlx_destroy_window(arg->mlx, arg->win);
	exit(0);
	return (0);
}

int	count_element(t_vars *arg, char c, char **map)
{
	int	i;
	int	j;
	int	count;

	count = 0;
	i = 1;
	if (arg == NULL || arg->map == NULL || arg->map[0] == NULL)
		return (0);
	while (i < arg->hie - 1)
	{
		j = 1;
		while (map[i][j])
		{
			if (map[i][j] == c)
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

void	check_elements_presence(t_vars *arg)
{
	if (count_element(arg, 'P', arg->map) == 0)
		ft_error_message("Erorr: the map is not valid!");
	if (count_element(arg, 'E', arg->map) == 0)
		ft_error_message("Erorr: the map is not valid!");
	if (count_element(arg, 'C', arg->map) == 0)
		ft_error_message("Erorr: the map is not valid!");
	if (count_element(arg, 'N', arg->map) == 0)
		ft_error_message("Erorr: the map is not valid!");
}

static void	flood_fil(int x, int y, char **mp)
{
	if (mp[x][y] == 'J' || mp[x][y] == '1' || mp[x][y] == 'N')
		return ;
	if (mp[x][y] == 'E')
	{
		mp[x][y] = 'J';
		return ;
	}
	mp[x][y] = 'J';
	flood_fil(x - 1, y, mp);
	flood_fil(x + 1, y, mp);
	flood_fil(x, y - 1, mp);
	flood_fil(x, y + 1, mp);
}

void	flood(t_vars *arg, char *map)
{
	int		x;
	int		y;
	char	**mp;

	x = arg->x;
	y = arg->y;
	mp = read_map(map);
	if (!mp)
		ft_error_message("Error: from cp_map!");
	flood_fil(x, y, mp);
	if (count_element(arg, 'C', mp) != 0)
		ft_error_message("Erro: map is not valid!");
	if (count_element(arg, 'E', mp) != 0)
		ft_error_message("Erro: map is not valid!");
	ft_free_leak(mp);
}
