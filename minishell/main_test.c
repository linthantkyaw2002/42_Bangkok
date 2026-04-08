#include "minishell.h"

void print_cmds(t_cmd *cmds)
{
    int i = 0;
    while (cmds)
    {
        printf("\n  --- Command Node %d ---\n", i++);
        if (cmds->args)
        {
            for (int j = 0; cmds->args[j]; j++)
                printf("    Arg[%d]: %s\n", j, cmds->args[j]);
        }
        else
            printf("    (No Arguments)\n");
        printf("    FD In:  %d\n", cmds->infile);
        printf("    FD Out: %d\n", cmds->outfile);
        cmds = cmds->next;
    }
}

int main(void)
{
    t_shell shell;
    t_token *tokens;
    t_cmd   *cmds;
    int     i;

    // 1. Define test cases to verify Lexer, Expander, and Parser
    char *inputs[] = {
        "ls -l>file|grep\"a\">out",             // Attached operators (Lexer test)
        "ls      -l  |  grep   \"a\"",         // Excessive whitespace (Lexer test)
        "echo \"hello > world\" | cat",        // Operators inside quotes (Lexer/Parser test)
        "ls \"\" '' \" \"",                    // Empty and spaced quotes (Lexer test)
        "echo $USER '$USER' \"$USER\"",        // Expansion rules (Expander test)
        "cat < file1 < file2 > out1 > out2",   // Multiple redirections (Parser test)
        "echo Hello > test.txt World",         // Middle redirection (Parser test)
        "ls | | wc",                           // Consecutive pipes (Parser test)
        NULL                                   // Terminator
    };

    // 2. Initialize mock environment for the Expander
    shell.env = malloc(sizeof(t_env));
    if (!shell.env)
        return (1);
    shell.env->key = ft_strdup("USER");
    shell.env->value = ft_strdup("lkyaw");
    shell.env->next = NULL;
    shell.last_exit = 0;

    i = 0;
    while (inputs[i])
    {
        printf("\n\033[1;32m[TEST %d] Input: %s\033[0m\n", i + 1, inputs[i]);

        // --- STAGE 1: Tokenize ---
        // Breaks the string into a linked list of tokens
        tokens = tokenize(inputs[i]);

        // --- STAGE 2: Expand ---
        // Processes $VARIABLES while respecting quote rules
        t_token *tmp = tokens;
        while (tmp)
        {
            char *expanded = expand_string(tmp->value, &shell);
            free(tmp->value);
            tmp->value = expanded;
            tmp = tmp->next;
        }

        // --- STAGE 3: Parse ---
        // Groups tokens into command structures and handles redirections
        cmds = parse_tokens(tokens);

        // --- STAGE 4: Verify Results ---
        print_cmds(cmds);

        // --- STAGE 5: Cleanup ---
        // In a real project, you'd call free_tokens(tokens) and free_cmds(cmds)
        // here to prevent memory buildup between tests.

        i++;
    }

    // Free the mock environment before exiting
    free(shell.env->key);
    free(shell.env->value);
    free(shell.env);

    return (0);
}
