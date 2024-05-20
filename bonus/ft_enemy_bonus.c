/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_enemy_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohimi <mohimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 16:04:27 by mohimi            #+#    #+#             */
/*   Updated: 2024/03/12 11:22:03 by mohimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	ft_move_enmy(t_vars *args, int i, int j)
{
	if (args->enemy_switch_img == 0)
		mlx_put_image_to_window(args->mlx, args->win,
			args->n_d, j * 50, i * 50);
	else if (args->enemy_switch_img == 1)
		mlx_put_image_to_window(args->mlx, args->win,
			args->n_u, j * 50, i * 50);
	else if (args->enemy_switch_img == 2)
		mlx_put_image_to_window(args->mlx, args->win,
			args->n_l, j * 50, i * 50);
	else if (args->enemy_switch_img == 3)
		mlx_put_image_to_window(args->mlx, args->win,
			args->n_r, j * 50, i * 50);
	if (args->enemy_switch_img < 3)
		args->enemy_switch_img++;
	else
		args->enemy_switch_img = 0;
}

int	ft_enemy(t_vars *args)
{
	int			i;
	int			j;

	ft_collect(args);
	i = -1;
	args->enemy_caller++;
	if (args->enemy_caller == 9000)
	{
		while (args->map[++i])
		{
			j = -1;
			while (args->map[i][++j])
			{
				if (args->map[i][j] == 'N')
					ft_move_enmy(args, i, j);
			}
		}
		args->enemy_caller = 0;
	}
	return (0);
}
