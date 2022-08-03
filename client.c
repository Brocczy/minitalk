/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarques <amarques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 15:15:46 by amarques          #+#    #+#             */
/*   Updated: 2022/08/02 16:57:19 by amarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"
#include <stdio.h>

void    ft_putnbr(int n)
{
    if(n > 9)
        ft_putnbr(n / 10);
    write(1, &"0123456789"[n % 10], 1);
}

void binary_conv(char c, int pid)
{
    int i;
    int s;

    i = -1;
    
    while (++i < 8)
    {
        s = (c << i) & 1;
        if (s)
        {
            kill(pid, SIGUSR1);
            usleep(100);
        }
        else
        {
            kill(pid, SIGUSR2);
            usleep(100);
        }
    }
}

int ft_atoi(const char *str)
{
    int i;
    long num;
    long signal;
    
    i = 0;
    num = 0;
    signal = 1;
    while ((str[i] > 8 && str[i] < 14) || str[i] == 32)
        i++;
    if (str[i] == '+' || str[i] == '-')
        if (str[i++] == '-')
            signal = -1;
    while (str[i] >= '0' && str[i] <= '9')
    {
        num = (num * 10) + signal * (str[i++] - '0');
        if ((num < 0) || num > INT_MAX)
            return (-1);
    }
    return (num);
}

int main(int ac, char **av)
{
    int i;
    int pid;
    
    if (ac != 3)
        return (write(1, "Wrong number of arguments\n", 26));
    pid = ft_atoi(av[1]);
    if (pid <= 0)
        write(1, "Invalid PID\n", 12);
    i = -1;
    while (av[2][++i])
        binary_conv(av[2][i], pid);
    binary_conv('\0', pid);
}
