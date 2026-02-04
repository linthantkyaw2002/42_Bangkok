*This project has been created as part of the 42 curriculum by lkyaw.*
# Pipex

## Description

This project focuses on the implementation of a UNIX mechanism for handling pipes. The program simulates the behavior of the shell pipe operator, allowing data to be redirected from one command to another. This implementation covers the creation of child processes, inter-process communication via pipes, and the execution of commands using system environment paths.

The project addresses the following functionalities:

*
**Mandatory**: Redirection for two commands: `< file1 cmd1 | cmd2 > file2`.


* **Bonus**: Support for multiple pipes: `< file1 cmd1 | cmd2 | [cite_start]... | cmdn > file2`.


*
**Bonus**: Support for `<<` and `>>` when the first parameter is `here_doc`.



---

## Instructions

### Compilation

The project is compiled using a Makefile which must include the rules `all`, `clean`, `fclean`, and `re`. The source files are compiled using `cc` with the flags `-Wall -Wextra -Werror`.

To compile the program:

```bash
make

```

### Execution

The program requires at least 4 arguments for the mandatory part and can handle additional arguments for the bonus part.

**Standard Usage:**

```bash
./pipex infile "ls -l" "wc -l" outfile

```

This execution is equivalent to the shell command: `< infile ls -l | wc -l > outfile`.

**Multiple Pipes (Bonus):**

```bash
./pipex file1 cmd1 cmd2 cmd3 ... cmdn file2

```

This execution is equivalent to the shell command: `< file1 cmd1 | cmd2 | cmd3 | [cite_start]... | cmdn > file2`.

**Here_Doc (Bonus):**

```bash
./pipex here_doc LIMITER cmd1 cmd2 file

```

This execution is equivalent to the shell command: `cmd1 << LIMITER | cmd2 >> file`.

---

## Technical Details

### Core System Calls

The implementation relies on the following authorized external functions:

* **Process Management**: `fork`, `wait`, `waitpid`, `exit`.
* **File Descriptor Manipulation**: `pipe`, `dup`, `dup2`, `open`, `close`.
* **Command Execution**: `execve`, `access`.
* **Error Handling**: `perror`, `strerror`.

### Implementation Logic

* **Pipeline Management**: The program iterates through the provided commands, creating a pipe for each link in the chain.
* **Redirection**: For the first command, input is redirected from the specified `infile`. For the final command, output is redirected to the `outfile`. For intermediate commands, `dup2` is utilized to connect the read-end of the previous pipe to `STDIN` and the write-end of the current pipe to `STDOUT`.
* **Heredoc Logic**: When `here_doc` is specified, the program reads from the standard input until the delimiter is reached, utilizing a temporary pipe to feed this data to the first command. The output file is opened in append mode (`O_APPEND`) to satisfy subject requirements.
* **Path Discovery**: The program parses the `PATH` variable from the `envp` array to locate command binaries, ensuring it handles both absolute paths and environment-based commands.

---

## Resources

*
**System Documentation**: Manual pages for `pipe(2)`, `fork(2)`, `execve(2)`, and `dup2(2)`.


* **AI Usage Disclosure**:
*
**Technical Explanation**: AI was utilized to clarify the behavior of the `waitpid` function regarding the cleanup of multiple child processes to prevent zombie processes.


*
**Logic Visualization**: AI assisted in creating a mental model of file descriptor swapping during the piping loop.


*
**Documentation Assistance**: AI was used to structure and format this README in accordance with the project subject requirements and visualiztion for logic

**Error Testing**: AI helped identify edge cases, such as handling commands that do not exist and managing multiple child process cleanup by giving test cases.
