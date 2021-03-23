#ifndef LIBFT_H
# define LIBFT_H
# include <stdbool.h>
# include <limits.h>
# include <string.h>
# include <stdlib.h>
#include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# define BUF_SIZE 10
typedef struct 	s_lst
{
	char		*content;
	struct s_lst *next;
}				t_lst;

t_lst		*ft_lstnew(void *content);
bool		ft_isdigit(char c);
bool		is_integer(double n);
char		*ft_strchr(char *s, char delim);
int			ft_strncmp(char *s1, char *s2, int len);
void		ft_strcat(char *dst, char *src, int len);
size_t		ft_strlen(const char *s);
t_lst		*ft_lstlast(t_lst *head);
void		ft_lstadd_back(t_lst **head, t_lst *new);
void		free_lst(t_lst *head);
t_lst		*get_lst(int fd, t_lst **alst);
char		*ft_substr(char const *s, unsigned int start, size_t len);
size_t		ft_strlcat(char *dst, const char *src, size_t dstsize);
char		*ft_strdup(const char *s1);
void		*ft_calloc(size_t count, size_t size);
void		ft_bzero(void *s, size_t n);
void		*ft_memset(void *b, int c, size_t len);
int			get_next_line(int fd, char **line);
int			ft_strcmp(const char *s1, const char *s2);
double		atod(char **s);

#endif