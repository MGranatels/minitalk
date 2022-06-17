/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anne-sophie <anne-sophie@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 09:14:33 by anne-sophie       #+#    #+#             */
/*   Updated: 2022/06/17 09:51:07 by anne-sophie      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	ft_send_msg(int pid, char *str)
{
	int	i;
	int	dif;

	i = 0;
	while (str[i])
	{
		if (str[i] != START_CHAR)
			dif = (int)str[i];
		while (dif)
		{
			kill(pid, SIGUSR1);
			dif--;
			usleep(80);
		}
		kill(pid, SIGUSR2);
		i++;
	}
}

int	main(int argc, char *argv[])
{
	int		pid;

	if (argc != 3)
	{
		ft_printf("wrong number of arguments\n");
		return (0);
	}
	pid = ft_atoi(argv[1]);
	ft_send_msg(pid, argv[2]);
	return (0);
}