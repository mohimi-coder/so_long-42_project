/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohimi <mohimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 18:14:31 by mohimi            #+#    #+#             */
/*   Updated: 2024/03/06 16:40:45 by mohimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_vars	arg;

	if (ac != 2)
		ft_error_message("Error: from ac!");
	arg.mlx = mlx_init();
	if (!arg.mlx)
		exit(EXIT_FAILURE);
	check_file_isvalid(av[1]);
	arg.map = read_map(av[1]);
	if (!arg.map)
		ft_error_message("Erorr: the map is empty!");
	set_hei_wid(&arg);
	arg.win = mlx_new_window(arg.mlx, arg.wid * 50, arg.hie * 50, "so_long");
	check_map(&arg);
	check_boundary(&arg);
	check_elements_presence(&arg);
	set_positions(&arg);
	flood(&arg, av[1]);
	draw_map(&arg);
	mlx_hook(arg.win, 2, 0, key_hook, &arg);
	mlx_hook(arg.win, 17, 0, ft_exit, &arg);
	mlx_loop(arg.mlx);
}
