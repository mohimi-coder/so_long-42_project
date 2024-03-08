/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_hei_wid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohimi <mohimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 20:17:35 by mohimi            #+#    #+#             */
/*   Updated: 2024/03/08 14:15:54 by mohimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_hei_wid(t_vars *arg)
{
	int	i;

	i = 0;
	arg->wid = ft_strlen(arg->map[i]);
	while (arg->map[i])
		i++;
	arg->hie = i;
}

void	set_parameter(t_vars *arg)
{
	arg->count_c = 0;
	arg->x = 0;
	arg->y = 0;
	arg->e_x = 0;
	arg->e_y = 0;
	arg->count_move = 0;
}
