#include "minishell.h"

// Helper to check if a string is completely numeric
static int	is_numeric(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i])) // Assuming ft_isdigit is in your libft
			return (0);
		i++;
	}
	return (1);
}

int	mini_exit(char **args, t_shell *sh)
{
	int	status;

	if (isatty(STDIN_FILENO))
		ft_putendl_fd("exit", STDOUT_FILENO);
	if (!args[1])
		exit(sh->last_exit);
	if (!is_numeric(args[1]))
	{
		ft_putendl_fd("minishell: exit: numeric argument required", 2);
		exit(255);
	}
	if (args[2])
	{
		ft_putendl_fd("minishell: exit: too many arguments", 2);
		return (1); // Notice we return 1 here, we DO NOT call exit()
	}
	status = ft_atoi(args[1]); // Ensure ft_atoi is in your libft
	exit(status % 256); // Bash exit statuses wrap around at 256
}