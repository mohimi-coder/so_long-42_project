/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohimi <mohimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 19:40:08 by mohimi            #+#    #+#             */
/*   Updated: 2024/03/07 22:50:11 by mohimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_images(t_vars *arg, int *dm)
{
	arg->p_up = mlx_xpm_file_to_image(arg->mlx, "./textures/p_up.xpm", dm, dm);
	if (!arg->p_up)
		ft_error_message("Error image up not found!");
	arg->p_d = mlx_xpm_file_to_image(arg->mlx, "./textures/p_down.xpm", dm, dm);
	if (!arg->p_d)
		ft_error_message("Error image p_down not found!");
	arg->p_r = mlx_xpm_file_to_image(arg->mlx, "./textures/p_rit.xpm", dm, dm);
	if (!arg->p_r)
		ft_error_message("Error image p_right not found!");
	arg->p_l = mlx_xpm_file_to_image(arg->mlx, "./textures/p_left.xpm", dm, dm);
	if (!arg->p_l)
		ft_error_message("Error image p_left not found!");
	arg->w = mlx_xpm_file_to_image(arg->mlx, "./textures/wall.xpm", dm, dm);
	if (!arg->w)
		ft_error_message("Error image wall not found!");
	arg->l = mlx_xpm_file_to_image(arg->mlx, "./textures/land.xpm", dm, dm);
	if (!arg->l)
		ft_error_message("Error image land not found!");
	arg->e = mlx_xpm_file_to_image(arg->mlx, "./textures/exit.xpm", dm, dm);
	if (!arg->e)
		ft_error_message("Error image exit not found!");
	arg->c = mlx_xpm_file_to_image(arg->mlx, "./textures/collect.xpm", dm, dm);
	if (!arg->c)
		ft_error_message("Error image collect not found!");
}

void	images_elements(t_vars *arg, int i, int j)
{
	if (arg->map[i][j] == '1')
		mlx_put_image_to_window(arg->mlx, arg->win, arg->w, j * 50, i * 50);
	if (arg->map[i][j] == 'P')
		mlx_put_image_to_window(arg->mlx, arg->win, arg->p_d, j * 50, i * 50);
	if (arg->map[i][j] == 'C')
		mlx_put_image_to_window(arg->mlx, arg->win, arg->c, j * 50, i * 50);
	if (arg->map[i][j] == '0')
		mlx_put_image_to_window(arg->mlx, arg->win, arg->l, j * 50, i * 50);
	if (arg->map[i][j] == 'E')
		mlx_put_image_to_window(arg->mlx, arg->win, arg->e, j * 50, i * 50);
}

void	draw_map(t_vars *arg)
{
	int	i;
	int	j;
	int	size;

	size = 50;
	set_images(arg, &size);
	i = 0;
	while (arg->map[i])
	{
		j = 0;
		while (arg->map[i][j])
		{
			images_elements(arg, i, j);
			j++;
		}
		i++;
	}
}
