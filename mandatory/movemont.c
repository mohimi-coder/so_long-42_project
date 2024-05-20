/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movemont.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohimi <mohimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 19:49:03 by mohimi            #+#    #+#             */
/*   Updated: 2024/03/09 11:51:13 by mohimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_up(t_vars *arg)
{
	you_win(arg, arg->x - 1, arg->y);
	if (arg->map[arg->x - 1][arg->y] != '1'
			&& arg->map[arg->x - 1][arg->y] != 'E')
	{
		arg->count_move++;
		ft_putnbr(arg->count_move);
		if (arg->map[arg->x - 1][arg->y] == 'C')
		{
			arg->count_c--;
			mlx_put_image_to_window(arg->mlx, arg->win,
				arg->l, arg->y * 50, (arg->x - 1) * 50);
			arg->map[arg->x - 1][arg->y] = '0';
		}
		mlx_put_image_to_window(arg->mlx, arg->win,
			arg->l, arg->y * 50, arg->x * 50);
		arg->map[arg->x][arg->y] = '0';
		arg->x -= 1;
		mlx_put_image_to_window(arg->mlx, arg->win,
			arg->p_up, arg->y * 50, arg->x * 50);
	}
}

void	move_right(t_vars *arg)
{
	you_win(arg, arg->x, arg->y + 1);
	if (arg->map[arg->x][arg->y + 1] != '1'
		&& arg->map[arg->x][arg->y + 1] != 'E')
	{
		arg->count_move++;
		ft_putnbr(arg->count_move);
		if (arg->map[arg->x][arg->y + 1] == 'C')
		{
			arg->count_c--;
			mlx_put_image_to_window(arg->mlx, arg->win,
				arg->l, (arg->y + 1) * 50, arg->x * 50);
			arg->map[arg->x][arg->y + 1] = '0';
		}
		mlx_put_image_to_window(arg->mlx, arg->win,
			arg->l, arg->y * 50, arg->x * 50);
		arg->map[arg->x][arg->y] = '0';
		arg->y += 1;
		mlx_put_image_to_window(arg->mlx, arg->win,
			arg->p_r, arg->y * 50, arg->x * 50);
	}
}

void	move_down(t_vars *arg)
{
	you_win(arg, arg->x + 1, arg->y);
	if (arg->map[arg->x + 1][arg->y] != '1' &&
		arg->map[arg->x + 1][arg->y] != 'E')
	{
		arg->count_move++;
		ft_putnbr(arg->count_move);
		if (arg->map[arg->x + 1][arg->y] == 'C')
		{
			arg->count_c--;
			mlx_put_image_to_window(arg->mlx, arg->win,
				arg->l, arg->y * 50, (arg->x + 1) * 50);
			arg->map[arg->x + 1][arg->y] = '0';
		}
		mlx_put_image_to_window(arg->mlx, arg->win,
			arg->l, arg->y * 50, arg->x * 50);
		arg->map[arg->x][arg->y] = '0';
		arg->x += 1;
		mlx_put_image_to_window(arg->mlx, arg->win,
			arg->p_d, arg->y * 50, arg->x * 50);
	}
}

void	move_left(t_vars *arg)
{
	you_win(arg, arg->x, arg->y - 1);
	if (arg->map[arg->x][arg->y - 1] != '1' &&
	arg->map[arg->x][arg->y - 1] != 'E')
	{
		arg->count_move++;
		ft_putnbr(arg->count_move);
		if (arg->map[arg->x][arg->y - 1] == 'C')
		{
			arg->count_c--;
			mlx_put_image_to_window(arg->mlx, arg->win,
				arg->l, (arg->y - 1) * 50, arg->x * 50);
			arg->map[arg->x][arg->y - 1] = '0';
		}
		mlx_put_image_to_window(arg->mlx, arg->win,
			arg->l, arg->y * 50, arg->x * 50);
		arg->map[arg->x][arg->y] = '0';
		arg->y -= 1;
		mlx_put_image_to_window(arg->mlx, arg->win,
			arg->p_l, arg->y * 50, arg->x * 50);
	}
}

int	key_hook(int keycode, t_vars *vars)
{
	if (keycode == 126 || keycode == 13)
		move_up(vars);
	else if (keycode == 124 || keycode == 2)
		move_right(vars);
	else if (keycode == 125 || keycode == 1)
		move_down(vars);
	else if (keycode == 123 || keycode == 0)
		move_left(vars);
	else if (keycode == 53)
	{
		ft_free_leak(vars->map);
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	return (0);
}
