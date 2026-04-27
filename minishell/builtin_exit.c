#include "minishell.h"

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
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

static void	clean_and_exit(t_shell *sh, int status)
{
	free_env(sh->env);
	rl_clear_history();
	exit(status);
}

int	mini_exit(char **args, t_shell *sh)
{
	int status;

	if (isatty(STDIN_FILENO))
		ft_putendl_fd("exit", STDOUT_FILENO);
	if (!args[1])
		clean_and_exit(sh, sh->last_exit);
	if (!is_numeric(args[1]))
	{
		ft_putendl_fd("minishell: exit: numeric argument required", 2);
		clean_and_exit(sh, 255);
	}
	if (args[2])
	{
		ft_putendl_fd("minishell: exit: too many arguments", 2);
		return (1);
	}
	status = ft_atoi(args[1]);
	clean_and_exit(sh, status % 256);
	return (0);
}