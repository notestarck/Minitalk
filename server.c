/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estarck <estarck@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 12:06:50 by estarck           #+#    #+#             */
/*   Updated: 2022/04/12 19:27:49 by estarck          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	write_message(int handler, siginfo_t *info, void *context)
{
	static unsigned char	c = '\0';
	static int				i = 0;

	if (handler == SIGUSR1)
		c |= 1;
	i++;
	if (i == 8)
	{
		if (c != '\0')
			write(1, &c, 1);
		else
		{
			kill(info->si_pid, SIGUSR1);
			ft_putchar_fd('\n', 1);
		}
		i = 0;
		c = '\0';
	}
	else
		c <<= 1;
}

int	main(void)
{
	pid_t				pid;
	struct sigaction	saction;

	pid = getpid();
	saction.sa_sigaction = write_message;
	saction.sa_flags = SA_SIGINFO;
	ft_printf("PID : %d\n", pid);
	if (sigaction(SIGUSR1, &saction, 0))
	{
		ft_printf("Error");
		return (0);
	}
	if (sigaction(SIGUSR2, &saction, 0))
	{
		ft_printf("Error");
		return (0);
	}
	while (42)
		pause();
	return (0);
}
