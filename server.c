/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anne-sophie <anne-sophie@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 09:20:00 by anne-sophie       #+#    #+#             */
/*   Updated: 2022/08/04 22:41:33 by anne-sophie      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char    g_c = START_CHAR;

static void rec_message(int sig)
{
    if (sig == 30)
        g_c++;
    else
    {
        ft_putchar(g_c);
        g_c = START_CHAR;
    }
}

int main (void)
{
    ft_printf("Server PID: %u\n", getpid());
    signal(SIGUSR1, rec_message);
    signal(SIGUSR2, rec_message);
    while (1)
        pause();
    return (0);
}

