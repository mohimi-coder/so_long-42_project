/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_hei_wid_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohimi <mohimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 20:17:35 by mohimi            #+#    #+#             */
/*   Updated: 2024/03/08 15:14:19 by mohimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	set_hei_wid(t_vars *arg)
{
	int	i;

	i = 0;
	if (arg == NULL || arg->map == NULL || arg->map[0] == NULL)
		return ;
	arg->wid = ft_strlen(arg->map[i]);
	while (arg->map[i])
		i++;
	arg->hie = i;
}

void	set_parameter(t_vars *arg)
{
	arg->collec_caller = 0;
	arg->enemy_caller = 0;
	arg->map = 0;
	arg->count_move = 0;
	arg->win = 0;
	arg->mlx = 0;
}
