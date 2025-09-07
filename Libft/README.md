#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>

* Conversion *

int	ft_atoi(const char *str);
- Converts the initial portion of the string 'str' to an integer.
- Parameters: str - string to convert.
- Return: integer value represented by the string.
- External functions: none.
 
char	*ft_itoa(int n);
- Converts integer 'n' to a null-terminated string.
- Parameters: n - integer to convert.
- Return: pointer to string representing the integer, or NULL if allocation fails.
- External functions: malloc.


* Memory *

void	ft_bzero(void *s, unsigned long n);
- Sets the first 'n' bytes of the memory area pointed to by 's' to zero.
- Parameters: s - memory area, n - number of bytes.
- Return: void.
- External functions: none.

void	*ft_calloc(long nelem, long elsize);
- Allocates memory for an array of 'nelem' elements of 'elsize' bytes each and initialises all bytes to zero.
- Parameters: nelem - number of elements, elsize - size of each element.
- Return: pointer to allocated memory, or NULL if allocation fails.
- External functions: malloc.

void	*ft_memchr(const void *s, int c, unsigned long n);
- Scans the first 'n' bytes of memory area 's' for the character 'c'.
- Parameters: s - memory area, c - character to search, n - number of bytes.
- Return: pointer to first occurrence of c, or NULL if not found.
- External functions: none.

int	ft_memcmp(const void *s1, const void *s2, unsigned long n);
- Compares the first 'n' bytes of memory areas 's1' and 's2'.
- Parameters: s1, s2 - memory areas, n - number of bytes to compare.
- Return: integer <0, 0, >0 depending on comparison.
- External functions: none.

void	*ft_memcpy(void *dest, const void *src, unsigned long n);
- Copies 'n' bytes from memory area 'src' to memory area 'dest'.
- Parameters: dest - destination, src - source, n - number of bytes.
- Return: pointer to dest.
- External functions: none.

void	*ft_memmove(void *dest, const void *src, unsigned long n);
- Copies 'n' bytes from 'src' to 'dest', handling overlapping memory areas.
- Parameters: dest - destination, src - source, n - number of bytes.
- Return: pointer to dest.
- External functions: none.

void	*ft_memset(void *s, int c, unsigned long n);
- Fills the first 'n' bytes of memory area 's' with byte 'c'.
- Parameters: s - memory area, c - value, n - number of bytes.
- Return: pointer to s.
- External functions: none.


* Character checks *

int	ft_isalnum(int c)
- Checks if the character 'c' is alphanumeric (letter or digit).
- Parameters: c - character to check.
- Return: non-zero if true, 0 if false.
- External functions: none.

int	ft_isalpha(int c);
- Checks if the character 'c' is alphabetic.
- Parameters: c - character to check.
- Return: non-zero if true, 0 if false.
- External functions: none.

int	ft_isascii(int c);
- Checks if the character 'c' is an ASCII character (0-127).
- Parameters: c - character to check.
- Return: non-zero if true, 0 if false.
- External functions: none.

int	ft_isdigit(int c);

- Checks if the character 'c' is a decimal digit (0-9).
- Parameters: c - character to check.
- Return: non-zero if true, 0 if false.
- External functions: none.

int	ft_isprint(int c);

- Checks if the character 'c' is printable, including space.
- Parameters: c - character to check.
- Return: non-zero if true, 0 if false.
- External functions: none.


* Character conversion *

int	ft_toupper(int c);
- Converts lowercase character 'c' to uppercase.
- Parameters: c - character.
- Return: uppercase character if c is lowercase, else c unchanged.
- External functions: none.

int	ft_tolower(int c);
- Converts uppercase character 'c' to lowercase.
- Parameters: c - character.
- Return: lowercase character if c is uppercase, else c unchanged.
- External functions: none.


* String manipulation *

unsigned long	ft_strlen(const char *str);  
- Computes the length of string 'str' (excluding null terminator).
- Parameters: str - string.
- Return: length.
- External functions: none.

char	*ft_strchr(const char *s, int c);
- Locates the first occurrence of character 'c' in string 's'.
- Parameters: s - string, c - character to search.
- Return: pointer to first occurrence, or NULL if not found.
- External functions: none.

char	*ft_strrchr(const char *s, int c);
- Locates the last occurrence of character 'c' in string 's'.
- Parameters: s - string, c - character to search.
- Return: pointer to last occurrence, or NULL if not found.
- External functions: none.

char	*ft_strdup(const char *src);
- Allocates memory and returns a duplicate of the string 'src'.
- Parameters: src - string to duplicate.
- Return: pointer to new string, or NULL if allocation fails.
- External functions: malloc.

unsigned long	ft_strlcpy(char *dst, const char *src, unsigned long size);
- Copies up to 'size - 1' characters from 'src' to 'dst', null-terminated.
- Parameters: dst - destination, src - source, size - buffer size.
- Return: length of src.
- External functions: none.

unsigned long	ft_strlcat(char *dst, const char *src, unsigned long size);
- Appends 'src' to the end of 'dst' of total size 'size', null-terminated.
- Parameters: dst - destination, src - source, size - total buffer size.
- Return: total length tried (initial dst length + src length).
- External functions: none.

int	ft_strncmp(const char *s1, const char *s2, unsigned long n);
- Compares up to 'n' characters of strings 's1' and 's2'.
- Parameters: s1, s2 - strings, n - max characters to compare.
- Return: <0, 0, >0 depending on comparison.
- External functions: none.

char	*ft_strnstr(const char *big, const char *little, unsigned long len);]
- Locates the first occurrence of 'little' in 'big', not exceeding 'len' characters.
- Parameters: big - string to search, little - substring, len - max characters.
- Return: pointer to start of 'little' in 'big', or NULL if not found.
- External functions: none.

char	*ft_strjoin(char const *s1, char const *s2);
- Allocates and returns a new string, the result of concatenating 's1' and 's2'.
- Parameters: s1, s2 - strings to join.
- Return: pointer to new string, or NULL if allocation fails.
- External functions: malloc.

char	*ft_substr(char const *s, unsigned int start, unsigned long len);
- Allocates and returns a substring from 's', starting at index 'start', length 'len'.
- Parameters: s - source string, start - start index, len - max length.
- Return: pointer to new string, or NULL if allocation fails.
- External functions: malloc.

char	*ft_strtrim(char const *s1, char const *set);
- Allocates and returns a copy of 's1' with all characters in 'set' removed from the beginning and end.
- Parameters: s1 - string to trim, set - characters to remove.
- Return: pointer to new string, or NULL if allocation fails.
- External functions: malloc.

char	**ft_split(char const *s, char c);
- Splits the string 's' into an array of strings, using 'c' as a delimiter.
- Parameters: s - string to split, c - delimiter.
- Return: NULL-terminated array of strings, or NULL if allocation fails.
- External functions: malloc, free.

void	ft_striteri(char *s, void (*f)(unsigned int, char *));
- Applies function 'f' to each character of string 's', passing index as first argument.
- Parameters: s - string, f - function to apply.
- Return: void.
- External functions: none.
  
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
- Creates a new string by applying the function 'f' to each character of 's'.
- Parameters: s - source string, f - function to apply.
- Return: pointer to new string, or NULL if allocation fails.
- External functions: malloc.


* File descriptor output *

void	ft_putchar_fd(char c, int fd);
- Writes character 'c' to the file descriptor 'fd'.
- Parameters: c - character, fd - file descriptor.
- Return: void.
- External functions: write.

void	ft_putstr_fd(char *s, int fd);
- Writes the string 's' to the file descriptor 'fd'.
- Parameters: s - string, fd - file descriptor.
- Return: void.
- External functions: write.

void	ft_putendl_fd(char *s, int fd);
- Writes string 's' followed by a newline to file descriptor 'fd'.
- Parameters: s - string, fd - file descriptor.
- Return: void.
- External functions: write.

void	ft_putnbr_fd(int n, int fd);
- Writes integer 'n' to the file descriptor 'fd'.
- Parameters: n - integer, fd - file descriptor.
- Return: void.
- External functions: write.


* Linked list *

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

t_list	*ft_lstnew(void *content);
- Allocates and returns a new list node.
- Parameters: content - pointer to node content.
- Return: pointer to new node, or NULL if allocation fails.
- External functions: malloc.

void	ft_lstadd_front(t_list **lst, t_list *new);
- Adds node 'new' at the beginning of list 'lst'.
- Parameters: lst - pointer to first node, new - node to add.
- Return: void.
- External functions: none.

int	ft_lstsize(t_list *lst);
- Counts the number of nodes in list 'lst'.
- Parameters: lst - first node.
- Return: number of nodes.
- External functions: none.

t_list	*ft_lstlast(t_list *lst);
- Returns the last node of list 'lst'.
- Parameters: lst - first node.
- Return: pointer to last node, or NULL if empty.
- External functions: none.

void	ft_lstadd_back(t_list **lst, t_list *new);
- Adds node 'new' at the end of list 'lst'.
- Parameters: lst - pointer to first node, new - node to add.
- Return: void.
- External functions: none.

void	ft_lstdelone(t_list *lst, void (*del)(void *));
- Deletes a node using 'del' and frees memory.
- Parameters: lst - node to delete, del - function to free content.
- Return: void.
- External functions: free.

void	ft_lstclear(t_list **lst, void (*del)(void *));
- Deletes and frees all nodes of list 'lst' using 'del'.
- Parameters: lst - pointer to first node, del - function to free content.
- Return: void.
- External functions: free.

void	ft_lstiter(t_list *lst, void (*f)(void *));
- Applies function 'f' to the content of each node in list 'lst'.
- Parameters: lst - first node, f - function to apply.
- Return: void.
- External functions: none.

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
- Creates a new list by applying 'f' to each node of 'lst'.
- If allocation fails, it deletes all created nodes using 'del'.
- Parameters: lst - first node, f - function to apply, del - function to free content.
- Return: pointer to new list, or NULL if allocation fails.
- External functions: malloc, free.

#endif

