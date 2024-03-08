/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_collec_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohimi <mohimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 10:43:07 by mohimi            #+#    #+#             */
/*   Updated: 2024/03/08 16:46:32 by mohimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	ft_move_collec(t_vars *args, int i, int j)
{
	if (args->collec_switch_img == 0)
		mlx_put_image_to_window(args->mlx, args->win,
			args->c_g, j * 50, i * 50);
	else if (args->collec_switch_img == 1)
		mlx_put_image_to_window(args->mlx, args->win,
			args->c_r, j * 50, i * 50);
	else if (args->collec_switch_img == 2)
		mlx_put_image_to_window(args->mlx, args->win,
			args->c_b, j * 50, i * 50);
	else if (args->collec_switch_img == 3)
		mlx_put_image_to_window(args->mlx, args->win,
			args->c_gr, j * 50, i * 50);
	if (args->collec_switch_img < 3)
		args->collec_switch_img++;
	else
		args->collec_switch_img = 0;
}

int	ft_collect(t_vars *args)
{
	int			i;
	int			j;

	i = -1;
	args->collec_caller++;
	if (args->collec_caller == 4000)
	{
		while (args->map[++i])
		{
			j = -1;
			while (args->map[i][++j])
			{
				if (args->map[i][j] == 'C')
					ft_move_collec(args, i, j);
			}
		}
		args->collec_caller = 0;
	}
	return (0);
}
