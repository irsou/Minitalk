

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <signal.h>
# include "../get_next_line/get_next_line.h"
# include <sys/types.h>

typedef struct s_server_data
{
	unsigned char	current_char;
	int				*bit_count;
}	t_server_data;

typedef struct s_client_data
{
	pid_t	server_pid;
	char	*message;
}	t_client_data;

#endif