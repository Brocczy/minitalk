/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarques <amarques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 15:15:48 by amarques          #+#    #+#             */
/*   Updated: 2022/08/02 15:54:17 by amarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"
#include <stdio.h>

void    handler(int signal)
{
    static int binary[8] = {1, 2, 4, 8, 16, 32 , 64, 128};
    static int i = 0;
    static char c = 0;

    if (signal == SIGUSR1)
        c = c + binary[i++];
    if (signal == SIGUSR2)
        i++;
    printf("%i\n", c);
    if (i == 8)
    {
        write(1, &c, 1); 
        i = 0;
        c = 0;
    }
}

void    ft_putnbr(int n)
{
    if(n > 9)
        ft_putnbr(n / 10);
    write(1, &"0123456789"[n % 10], 1);
}

int     main(void)
{
    write(1, "PID: ", 5);
    ft_putnbr(getpid());
    write(1, "\n", 1);
    signal(SIGUSR1, handler);
    signal(SIGUSR2, handler);
    while (1)
        pause();
}
