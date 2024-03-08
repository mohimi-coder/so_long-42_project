/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohimi <mohimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 19:40:08 by mohimi            #+#    #+#             */
/*   Updated: 2024/03/08 15:22:09 by mohimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	collect_images(t_vars *arg, int *dm)
{
	arg->c_g = mlx_xpm_file_to_image(arg->mlx, "./textures/gold.xpm", dm, dm);
	if (!arg->c_g)
		ft_error_message("Error image not found!");
	arg->c_gr = mlx_xpm_file_to_image(arg->mlx, "./textures/green.xpm", dm, dm);
	if (!arg->c_gr)
		ft_error_message("Error image not found!");
	arg->c_b = mlx_xpm_file_to_image(arg->mlx, "./textures/blue.xpm", dm, dm);
	if (!arg->c_b)
		ft_error_message("Error image not found!");
	arg->c_r = mlx_xpm_file_to_image(arg->mlx, "./textures/red.xpm", dm, dm);
	if (!arg->c_r)
		ft_error_message("Error image not found!");
}

static void	player_movemant(t_vars *arg, int *dm)
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
}

void	set_images(t_vars *arg, int *dm)
{
	player_movemant(arg, dm);
	collect_images(arg, dm);
	arg->w = mlx_xpm_file_to_image(arg->mlx, "./textures/wall.xpm", dm, dm);
	if (!arg->w)
		ft_error_message("Error: image wall not found!");
	arg->l = mlx_xpm_file_to_image(arg->mlx, "./textures/land.xpm", dm, dm);
	if (!arg->l)
		ft_error_message("Error: image land not found!");
	arg->e = mlx_xpm_file_to_image(arg->mlx, "./textures/exit.xpm", dm, dm);
	if (!arg->e)
		ft_error_message("Error: image exit not found!");
	arg->n_d = mlx_xpm_file_to_image(arg->mlx, "./textures/enmy_d.xpm", dm, dm);
	if (!arg->n_d)
		ft_error_message("Error: image enmy not found!");
	arg->n_u = mlx_xpm_file_to_image(arg->mlx, "./textures/enmy_u.xpm", dm, dm);
	if (!arg->n_u)
		ft_error_message("Error: image enmy not found!");
	arg->n_l = mlx_xpm_file_to_image(arg->mlx, "./textures/enmy_r.xpm", dm, dm);
	if (!arg->n_l)
		ft_error_message("Error: image enmy not found!");
	arg->n_r = mlx_xpm_file_to_image(arg->mlx, "./textures/enmy_l.xpm", dm, dm);
	if (!arg->n_r)
		ft_error_message("Error: image enmy not found!");
}

void	images_elements(t_vars *arg, int i, int j)
{
	if (arg->map[i][j] == '1')
		mlx_put_image_to_window(arg->mlx, arg->win, arg->w, j * 50, i * 50);
	if (arg->map[i][j] == 'P')
		mlx_put_image_to_window(arg->mlx, arg->win, arg->p_d, j * 50, i * 50);
	if (arg->map[i][j] == 'C')
		mlx_put_image_to_window(arg->mlx, arg->win, arg->c_g, j * 50, i * 50);
	if (arg->map[i][j] == '0')
		mlx_put_image_to_window(arg->mlx, arg->win, arg->l, j * 50, i * 50);
	if (arg->map[i][j] == 'E')
		mlx_put_image_to_window(arg->mlx, arg->win, arg->e, j * 50, i * 50);
	if (arg->map[i][j] == 'N')
		mlx_put_image_to_window(arg->mlx, arg->win, arg->n_u, j * 50, i * 50);
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
