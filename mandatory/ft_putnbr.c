/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohimi <mohimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 23:06:45 by mohimi            #+#    #+#             */
/*   Updated: 2024/03/02 16:50:32 by mohimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_putchar_fd(char c)
{
	write(1, &c, 1);
}

static void	ft_putnbr_fd(int n)
{
	long	nb;

	nb = n;
	if (nb < 0)
	{
		ft_putchar_fd('-');
		nb *= -1;
	}
	if (nb < 10)
		ft_putchar_fd(nb + 48);
	else
	{
		ft_putnbr_fd(nb / 10);
		ft_putnbr_fd(nb % 10);
	}
}

void	ft_putnbr(int n)
{
	ft_putnbr_fd(n);
	ft_putchar_fd('\n');
}
