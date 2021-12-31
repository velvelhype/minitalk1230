#include "minitalk.h"

void	send_char(int pid, char a)
{
	printf("c: send %c\n", a);
	int i;

	i = 7;
	if (kill(pid, 0) == -1)
		exit(1);
	while (i >= 0)
	{
		if (a >> i & 1)
			kill(pid, SIGUSR1);	
		else
			kill(pid, SIGUSR2);	
		usleep(100);
		i--;
	}
}

void	send_str(char **argv)
{
	printf("s: send %s\n", argv[2]);
	while (*argv[2])
	{
		send_char(atoi(argv[1]), *argv[2]);
		++(argv[2]);
	}
}

void	send_strlen(size_t	len)
{
	printf("strlen %ld\n", len);
	len = 18446744073709551615;
	int i = 64;
	while (i >= 0)
	{
		if (len >> i & 1)
			write(1, "1 ", 2);
		else
			write(1, "0 ", 2);
		printf("%d\n", i);
		usleep(100);
		i--;
	}
}

int main(int argc, char **argv)
{
	if (argc != 3)
		exit(1);
	send_strlen(ft_strlen(argv[2]));
	send_str(argv);
}