/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isousa-s <isousa-s@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 17:58:52 by isousa-s          #+#    #+#             */
/*   Updated: 2025/05/09 19:47:52 by isousa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static t_client_data	g_client;

void	send_char(unsigned char c)
{
	int								i;
	unsigned char		bit;

	i = 8;
	while (i > 0)
	{
		i--;
		bit = (c >> i) & 1;
		if (bit == 0)
			kill(g_client.server_pid, SIGUSR1);
		else
			kill(g_client.server_pid, SIGUSR2);
		usleep(100);
	}
}

void	send_string(void)
{
	int	i;

	i = 0;
	while (g_client.message[i])
	{
		send_char(g_client.message[i]);
		i++;
	}
	send_char('\0');
}

int	main(int argc, char **argv)
{
	if (argc != 3)
	{
		ft_printf("Communication requires exactly two arguments\n");
		return (1);
	}
	g_client.server_pid = atoi(argv[1]);
	if (g_client.server_pid <= 0)
	{
		ft_printf("Invalid PID");
		return (1);
	}
	g_client.message = argv[2];
	send_string();
	return (0);
}
