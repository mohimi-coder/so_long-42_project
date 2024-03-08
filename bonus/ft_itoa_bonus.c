/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohimi <mohimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 23:06:45 by mohimi            #+#    #+#             */
/*   Updated: 2024/03/07 18:37:51 by mohimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

char	*ft_itoa(int n, t_vars *arg)
{
	long	b;
	int		i;

	b = n;
	if (n == 0)
		return ("0");
	if (b < 0)
		b *= -1;
	arg->divisor = 1000000000;
	arg->arr[0] = '0';
	i = 0;
	while (++i <= 10)
	{
		arg->arr[i] = b / arg->divisor + '0';
		b %= arg->divisor;
		arg->divisor /= 10;
	}
	i = 0;
	while (arg->arr[i] == '0')
		i++;
	if (n < 0)
		arg->arr[--i] = '-';
	arg->strd = ft_strdup(&arg->arr[i]);
	return (arg->arr[11] = '\0', arg->strd);
}
