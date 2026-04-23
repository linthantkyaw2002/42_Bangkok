#include "minishell.h"
 
void shell_loop(t_shell *shell)
{
    char *line;
    t_token *tokens;
    t_cmd *cmds;

    while (1)
    {
        printf("\033[1;34mminishell> \033[0m");
        line = NULL;
        size_t len = 0;
        ssize_t read = getline(&line, &len, stdin);
        if (read == -1)
        {
            free(line);
            break;
        }
        if (line[read - 1] == '\n')
            line[read - 1] = '\0';
        tokens = tokenize(line);
        free(line);
        expand_list(shell);
        cmds = parse(tokens);

        // Execute commands (not implemented here)

        // Cleanup
        free_tokens(tokens);
        free_cmds(cmds);
    }
}
int main(int argc, char **argv, char **envp)
{
    t_shell shell;

    (void)argc;
    (void)argv;

    shell.env = init_env(envp);
    shell.last_exit = 0;
    shell_loop(&shell);
    t_env *curr = shell.env;
    while (curr)
    {
        t_env *next = curr->next;
        free(curr->key);
        free(curr->value);
        free(curr);
        curr = next;
    }
    return (0);
}