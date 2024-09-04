/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokamura <yokamura@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 12:02:08 by yokamura          #+#    #+#             */
/*   Updated: 2023/01/23 21:53:08 by yokamura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include "libft/libft.h"

static void	handler(int sig, siginfo_t *info, void *ucontext)
{
	static int				i = 0;
	static unsigned int		c = 0;
	static pid_t			client_pid = 0;

	(void)ucontext;
	if (client_pid == 0)
		client_pid = info->si_pid;
	c = c | (sig == SIGUSR2);
	if (++i == 8)
	{
		i = 0;
		if (c == 0)
		{
			kill(client_pid, SIGUSR2);
			client_pid = 0;
			return ;
		}
		ft_putchar_fd(c, 1);
		c = 0;
		kill(client_pid, SIGUSR1);
	}
	else
		c = c << 1;
}

static void	print_pid(void)
{
	pid_t	pid;

	pid = getpid();
	if (pid == -1)
	{
		ft_putstr_fd("Error: getting pid failed\n", 2);
		exit(1);
	}
	ft_putstr_fd("Server PID: ", 1);
	ft_putnbr_fd(pid, 1);
	ft_putchar_fd('\n', 1);
}

int	main(void)
{
	struct sigaction	sa;

	print_pid();
	sigemptyset(&sa.sa_mask);
	sa.sa_sigaction = handler;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
