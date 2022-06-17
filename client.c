/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anne-sophie <anne-sophie@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 09:14:33 by anne-sophie       #+#    #+#             */
/*   Updated: 2022/06/17 16:15:41 by anne-sophie      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void send_message(int pid, char *str)
{
    int nb;
    int i;
    
    i = 0;
    while (str[i])
    {
        nb = (int)str[i];
        while (nb != 0)
        {
            kill(pid, SIGUSR1);
            nb--;
            usleep(100);
        }
        kill(pid, SIGUSR2);
        i++;
    }
}

int main(int ac, char **av)
{
    int pid;

    if (ac != 3)
    {
        ft_printf("Invalid Number of Arguments\n");
        return (0);
    }
    pid = ft_atoi(av[1]);
    send_message(pid, av[2]);
    return (0);
}
