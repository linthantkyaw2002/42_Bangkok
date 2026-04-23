#include "minishell.h"

void handle_sigint(int sig)
{
    (void)sig;
    printf("\n\033[1;31m[Signal] SIGINT received. Interrupting current command.\033[0m\n");
    sint_exit(1);
}
