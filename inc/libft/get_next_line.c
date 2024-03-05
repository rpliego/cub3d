/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpliego <rpliego@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 13:21:43 by rpliego           #+#    #+#             */
/*   Updated: 2024/03/04 13:50:50 by rpliego          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_freegnl(char **clean)
{
	free(*clean);
	*clean = NULL;
	return (NULL);
}

char	*ft_clean_stash(char *stash)
{
	char	*new_stash;
	char	*ptr;
	int		len;

	ptr = ft_strchrgnl(stash, '\n');
	if (!ptr)
	{
		new_stash = NULL;
		return (ft_freegnl(&stash));
	}
	len = (ptr - stash) + 1;
	if (!stash[len])
		return (ft_freegnl(&stash));
	new_stash = ft_substrgnl(stash, len, ft_strlengnl(stash) - len);
	ft_freegnl(&stash);
	if (!new_stash)
		return (NULL);
	return (new_stash);
}

char	*ft_line_make(char *stash)
{
	char	*aux;
	int		len;
	char	*line;

	aux = ft_strchrgnl(stash, '\n');
	len = (aux - stash) + 1;
	line = ft_substrgnl(stash, 0, len);
	if (!line)
		return (NULL);
	return (line);
}

char	*ft_read(int fd, char *stash, int bytes)
{
	char	*buff;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (ft_freegnl(&stash));
	buff[0] = '\0';
	while (bytes > 0 && !ft_strchrgnl(buff, '\n'))
	{
		bytes = read(fd, buff, BUFFER_SIZE);
		if (buff[0] == '\t')
		{
			buff[bytes] = '\0';
			stash = ft_strjoingnl(stash, "    ");
		}
		else if (bytes > 0)
		{
			buff[bytes] = '\0';
			stash = ft_strjoingnl(stash, buff);
		}
	}
	free(buff);
	if (bytes == -1)
		return (ft_freegnl(&stash));
	return (stash);
}

char	*get_next_line(int fd)
{
	static char	*stash = NULL;
	char		*line;
	int			bytes;

	bytes = 69;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = ft_read(fd, stash, bytes);
	if (!stash)
		return (NULL);
	line = ft_line_make(stash);
	if (!line)
		return (ft_freegnl(&stash));
	stash = ft_clean_stash(stash);
	return (line);
}

// #include <fcntl.h>
// #include <stdio.h>

// int	main(void)
// {
// 	char	*line;
// 	int		fd1;

// 	fd1 = open("/Users/rpliego/Desktop/test.txt", O_RDONLY);

// 	line = get_next_line(fd1);
// 	printf("%s", line);
// 	line = get_next_line(fd1);
// 	printf("%s", line);

// 	close(fd1);
// 	return (0);
// }
