#include "minitalk.h"

void	send_char(int pid, char a)
{
	printf("c: send %c\n", a);
	int i;

	i = 7;
	if(pid == -1 || pid == 0)
		exit(1);
	if (kill(pid, 0) == -1)
		exit(1);
	while (i >= 0)
	{
		if (a >> i & 1)
			kill(pid, SIGUSR1);	
		else
			kill(pid, SIGUSR2);	
		usleep(1000);
		i--;
	}
}

void	send_str(char **argv)
{
	int	pid;

	pid = ft_atoi(argv[1]);
	printf("s: send %s\n", argv[2]);
	while (*argv[2])
	{
		send_char(pid, *argv[2]);
		++(argv[2]);
	}
	send_char(pid, '\n');
}

int main(int argc, char **argv)
{
	if (argc != 3)
		exit(1);
	send_str(argv);
}