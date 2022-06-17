/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anne-sophie <anne-sophie@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 09:20:00 by anne-sophie       #+#    #+#             */
/*   Updated: 2022/06/17 10:23:19 by anne-sophie      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	g_c = START_CHAR;

static void	ft_recieve_msg(int sig)
{
	
    if (sig == SIGUSR1)
		g_c++;
	else
	{
		ft_putchar_fd(g_c, 1);
		g_c = START_CHAR;
	}
}

int	main(void)
{	
	ft_printf("Server PID: %u\n", getpid());
	signal(SIGUSR1, ft_recieve_msg);
	signal(SIGUSR2, ft_recieve_msg);
	while (1)
		pause();
	return (0);
}