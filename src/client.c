/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isousa-s <isousa-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 17:58:52 by isousa-s          #+#    #+#             */
/*   Updated: 2025/05/10 12:16:17 by isousa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_bit(pid_t server_pid, int bit)
{
	int		signal;
	int		result;

	if (bit == 0)
		signal = SIGUSR1;
	else
		signal = SIGUSR2;
	result = kill(server_pid, signal);
	if (result == -1)
	{
		ft_printf("Failed to send signal to server\n");
		exit (1);
	}
}

void	send_char(pid_t server_pid, unsigned char c)
{
	unsigned char	bit;
	int				i;

	i = 8;
	while (i > 0)
	{
		i--;
		bit = (c >> i) & 1;
		send_bit(server_pid, bit);
		usleep(150);
	}
}

void	send_string(pid_t server_pid, char *message)
{
	int	i;

	i = 0;
	while (message[i])
	{
		send_char(server_pid, message[i]);
		i++;
	}
	send_char(server_pid, '\0');
}

int	main(int argc, char **argv)
{
	pid_t	server_pid;

	if (argc != 3)
	{
		ft_printf("Communication requires exactly two arguments\n");
		return (1);
	}
	server_pid = atoi(argv[1]);
	if (server_pid <= 0)
	{
		ft_printf("Invalid PID\n");
		return (1);
	}
	send_string(server_pid, argv[2]);
	return (0);
}
