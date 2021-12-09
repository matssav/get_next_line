#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1000
#endif

char	*get_next_line(int fd);
char	*ft_read_to_silo(int fd, char *silo);
char	*ft_strchr(const char *str, int c);
char	*ft_strjoin(char *silo, char *buff);
size_t	ft_strlen(char *s);
char	*ft_getline(char *silo);
char	*ft_new_silo(char *silo);

#endif
