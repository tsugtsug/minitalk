/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokamura <yokamura@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 10:43:23 by yokamura          #+#    #+#             */
/*   Updated: 2023/01/23 21:52:29 by yokamura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include "./libft/libft.h"

static void	send_char_with_bit(unsigned int c, pid_t pid)
{
	int		i;
	int		rtn;
	int		bit;

	i = 7;
	while (i >= 0)
	{
		bit = (c >> i) & 1;
		if (bit == 0)
			rtn = kill(pid, SIGUSR1);
		else
			rtn = kill(pid, SIGUSR2);
		if (rtn == -1)
			exit(1);
		usleep(100);
		i--;
	}
}

void	sighandler(int sig)
{
	if (sig == SIGUSR2)
	{
		ft_putstr_fd("You sent the message correctly!\n", 1);
		exit(0);
	}
}

int	main(int argc, char **argv)
{
	pid_t	pid;
	int		i;

	if (argc != 3)
		return (1);
	pid = ft_atoi(argv[1]);
	if (pid == 0)
		return (1);
	signal(SIGUSR1, &sighandler);
	signal(SIGUSR2, &sighandler);
	i = 0;
	while (argv[2][i] != '\0')
	{
		send_char_with_bit(argv[2][i], pid);
		i++;
	}
	send_char_with_bit(0, pid);
	while (1)
		pause();
	return (0);
}
