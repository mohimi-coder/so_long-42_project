/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohimi <mohimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 18:14:31 by mohimi            #+#    #+#             */
/*   Updated: 2024/03/13 14:18:17 by mohimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	ft_check(t_vars *arg)
{
	set_hei_wid(arg);
	check_map(arg);
	check_boundary(arg);
	check_elements_presence(arg);
}

int	main(int ac, char **av)
{
	t_vars	arg;
	int		i;

	i = 0;
	if (ac != 2)
		ft_error_message("error from ac!");
	set_parameter(&arg);
	check_file_isvalid(av[1]);
	arg.map = read_map(av[1]);
	if (!arg.map)
		ft_error_message("Error: the map is empty!");
	ft_check(&arg);
	set_positions(&arg, i, i);
	arg.mlx = mlx_init();
	if (!arg.mlx)
		ft_error_message("Erorr: from mlx_init!");
	arg.win = mlx_new_window(arg.mlx, arg.wid * 50, arg.hie * 50, "so_long");
	if (!arg.win)
		ft_error_message("Erorr: from mlx!");
	flood(&arg, av[1]);
	draw_map(&arg);
	mlx_loop_hook(arg.mlx, ft_enemy, &arg);
	mlx_hook(arg.win, 2, 0, key_hook, &arg);
	mlx_hook(arg.win, 17, 0, ft_exit, &arg);
	mlx_loop(arg.mlx);
}
