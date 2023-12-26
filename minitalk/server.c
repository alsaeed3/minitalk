/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsaeed <alsaeed@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 20:26:33 by alsaeed           #+#    #+#             */
/*   Updated: 2023/06/23 21:05:32 by alsaeed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

static void	ft_btc(int sig)
{
	static int				i;
	static unsigned char	c;

	if (sig == SIGUSR1)
		c = c | 1;
	else if (sig == SIGUSR2)
		c = c | 0;
	usleep(120);
	if (++i == 8)
	{
		i = 0;
		if (!c)
		{
			c = 0;
			usleep(120);
			return ;
		}
		write (1, &c, 1);
		c = '\0';
	}
	else
		c = c << 1;
}

int	main(void)
{
	ft_printf("•SERVER ON• -> Server PID: ");
	ft_printf("» %d «", getpid());
	ft_printf("\n");
	signal(SIGUSR1, ft_btc);
	signal(SIGUSR2, ft_btc);
	while (1)
		pause();
	return (0);
}
