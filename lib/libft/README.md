# libft functions

ft_atoi - The atoi()function converts the initial portion of the string pointed to by str to int representation.

ft_bzero - The bzero() function writes n zeroed bytes to the string s.If n is zero, bzero() does nothing.

ft_calloc - The calloc() function contiguously allocates enough space for count objects that are size bytes of memory each and returns a pointer to the allocated memory.The allocated memory is filled with bytes of value zero.

ft_isalnum - The isalnum() function tests for any character for which isalpha(3) or isdigit(3) is true.The value of the argument must be representable as an unsigned char or the value of EOF.

ft_isalpha - The isalpha() function tests for any character for which isupper(3) or islower(3) is true.The value of the argument must be representable as an unsigned char or the value of EOF.

ft_isascii - The isascii() function tests for an ASCII character, which is any character between 0 and octal 0177 inclusive.

ft_isdigit - The isdigit() function tests for a decimal digit character.Regardless of locale, this includes the following characters only:

ft_isprint - The isprint() function tests for any printing character, including space (` ').The value of the argument must be representable as an unsigned char or the value of EOF.

ft_itoa - Allocates and returns a string representing the integer received as an argument, including negative numbers.

ft_lstadd_back - Adds the element ‘new’ at the end of the list

ft_lstadd_front - Adds the element ‘new’ at the beginning of the list.

ft_lstclear - Deletes and frees the given element and every successor of that element, using the function ‘del’ and free. Finally the pointer to the list is set to NULL.

ft_lstdelone - Takes as a parameter an element and frees the memory of the elements content using the function ‘del’ given as a parameter and free the element. The memory of next is not freed.

ft_lstiter - Iterates the list ‘list’ and applies the function ‘f’ to the content of each element..

ft_lstlast - Returns the last element in the list

ft_lstmap - Iterates the list ‘list’ and applies the function ‘f’ to the content of each element. Creates a new list resulting of the successive applications of the function ‘f’. The ‘del’ function is used to delete the content of an element if needed.

ft_lstnew - Allocates and returns a new element. The variable ‘content’ is initialized with the value of the parameter ‘content’. The variable ‘next’ is initialized too NULL.

ft_lstsize - Counts the numbers in the list

ft_memccpy - The memccpy() function copies bytes from string src to string dst.If the character c (as converted to an unsigned char) occurs in the string src, the copy stops and a pointer to the byte after the copy of c in the string dst is returned.Otherwise, n bytes are copied, and a NULL pointer is returned.

ft_memchr - The memchr() function locates the first occurrence of c (converted to an unsigned char) in string s.

ft_memcmp - The memcmp() function compares byte string s1 against byte string s2.Both strings are assumed to be n bytes long.

ft_memcpy - The memcpy() function copies n bytes from memory area src to memory area dst.If dst and src overlap, behavior is undefined.Applications in which dst and src might overlap should use memmove(3) instead.

ft_memmove - The memmove() function copies len bytes from string src to string dst.The two strings may overlap; the copy is always done in a non-destructive manner.

ft_memset - The memset() function writes len bytes of value c (converted to an unsigned char) to the string b.

ft_putchar_fd - Outputs the character ‘c’ to the given fie descriptor.

ft_putendl_fd - Outputs the string ’s’ to the given file descriptor, followed by a new line.

ft_putnbr_fd - Outputs the integer ’n’ to the given file descriptor

ft_putstr_fd - Outputs the string ’s’ to the given file descriptor

ft_split - Allocates and returns an array of strings obtained by splitting ’s’ using the character ‘c’ as a delimiter. The array ends with a NULL pointer.

ft_strchr - The strchr() function locates the first occurrence of c (converted to a char) in the string pointed to by s.The terminating null character is considered to be part of the string; therefore if c is `\0', the functions locate the terminating `\0'. The strrchr() function is identical to strchr(), except it locates the last occurrence of c.

ft_strdup - The strdup() function allocates sufficient memory for a copy of the string s1, does the copy, and returns a pointer to it.The pointer may subsequently be used as an argument to the function free(3). If insufficient memory is available, NULL is returned and errno is set to ENOMEM. The strndup() function copies at most n characters from the string s1 always NUL terminating the copied string.

ft_strjoin - Allocates and returns a new string, which is the result of the concatenation of ‘s1’ and ‘s2’.

ft_strlcat - strlcat() appends string src to the end of dst.It will append at most dstsize - strlen(dst) - 1 characters.It will then NUL-terminate, unless dstsize is 0 or the original dst string was longer than dstsize (in practice this should not happen as it means that either dstsize is incorrect or that dst is not a proper string).

ft_strlcpy - strlcpy() copies up to dstsize - 1 characters from the string src to dst, NUL-terminating the result if dstsize is not 0.

ft_strlen - The strlen() function computes the length of the string s.The strnlen() function attempts to compute the length of s, but never scans beyond the first maxlen bytes of s.

ft_strmapi - Applies the function (f) to each character of the string ’s’ to create a new string resulting from successive application of ‘f’

ft_strncmp - The strcmp() and strncmp() functions lexicographically compare the null-terminated strings s1 and s2. The strncmp() function compares not more than n characters.Because strncmp() is designed for comparing strings rather than binary data, characters that appear after a `\0' character are not compared.

ft_strnstr - The strnstr() function locates the first occurrence of the null-terminated string needle in the string haystack, where not more than len characters are searched.Characters that appear after a `\0' character are not searched.

ft_strrchr - The strchr() function locates the first occurrence of c (converted to a char) in the string pointed to by s.The terminating null character is considered to be part of the string; therefore if c is `\0', the functions locate the terminating `\0'. The strrchr() function is identical to strchr(), except it locates the last occurrence of c.

ft_strtrim - Allocates and returns a copy of ’s1’ with the characters specified in ‘set’ removed from the beginning and the end of the string.

ft_substr - Allocates and returns a substring from the string ’s’. The substring begins at index ‘start’ and is of maximum length ‘len’.

ft_tolower - The tolower() function converts an upper-case letter to the corresponding lower-case letter.The argument must be representable as an unsigned char or the value of EOF.

ft_toupper - The toupper() function converts a lower-case letter to the corresponding upper-case letter.The argument must be representable as an unsigned char or the value of EOF.
