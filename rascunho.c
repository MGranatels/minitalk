//Global Variable is used because the funcition ft_rec. is running constantly
// This means the variable will always reset to 0 if we don't declare
// it as a global variable. 
char	g_c = START_CHAR;

// SIGUSR1 takes the int value of 30 while SIGUSR2 is 31
// Knowing this we can now use this in our favour because while our
// client program runs SIGUSR1 g_c will keep incrementing until 
// we use SIGUSR2 means we have decrementend until 0 our variable in the client program
// thus the global variable in the server will be the value we want it to be, so we print it.

static void	ft_recieve_msg(int sig)
{
    if (sig == SIGUSR1)
		g_c++;
	else
	{
		ft_putchar_fd(g_c, 1);
		g_c = START_CHAR;
	}
}

int	main(void)
{	
	ft_printf("Server PID: %u\n", getpid());
	signal(SIGUSR1, ft_recieve_msg);
	signal(SIGUSR2, ft_recieve_msg);
	while (1)
		pause();
	return (0);
}

//SIGUSR1 and SIGUSR2 are user defined operations for transmiting signals.
// Usleep handles micro secound - 1 sec == 1 million of a sec

static void	ft_send_msg(int pid, char *str)
{
	int	i;
	int	dif;

	i = 0;
	while (str[i])
	{
		dif = (int)str[i];
		while (dif)
		{
			kill(pid, SIGUSR1);
			dif--;
			usleep(80);
		}
		kill(pid, SIGUSR2);
		i++;
	}
}

int	main(int ac, char **av)
{
	int		pid;

	if (ac != 3)
	{
		ft_printf("wrong number of arguments\n");
		return (0);
	}
	pid = ft_atoi(av[1]);
	ft_send_msg(pid, av[2]);
	return (0);
}