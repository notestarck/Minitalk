/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estarck <estarck@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 13:38:11 by estarck           #+#    #+#             */
/*   Updated: 2022/04/13 10:13:57 by estarck          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	retour(int sig)
{
	ft_printf("\nMessage recu !\n");
}

void	push_server(int pid, char c)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if (c >> i & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(100);
		i--;
	}
}

void	push_end(int pid)
{
	int	i;

	i = 0;
	if (signal(SIGUSR1, retour) == SIG_ERR)
		ft_printf("ok, bon erreur !");
	while (i < 8)
	{
		kill(pid, SIGUSR2);
		usleep(75);
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	i;
	int	pid;

	i = 0;
	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		while (argv[2][i] != '\0')
		{
			push_server(pid, argv[2][i]);
			i++;
		}
		push_end(pid);
	}
	else
		ft_printf("Nombre d'arguments invalide : ./client [PID] [\"MESSAGE\"]\n");
	return (0);
}
