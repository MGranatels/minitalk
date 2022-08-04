/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anne-sophie <anne-sophie@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 14:02:33 by anne-sophie       #+#    #+#             */
/*   Updated: 2022/08/04 22:41:31 by anne-sophie      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void    handl_signal(int nub)
{
    write(STDOUT_FILENO, "I WON'T DIE!!\n", 15);
}

int main (int ac, char **av)
{
    signal(SIGINT, handl_signal);
    signal(SIGTERM, handl_signal);
    while (1)
    {
        printf("Some Text %d\n", getpid());
        sleep(1);
    }
}




