/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpliego <rpliego@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 13:23:21 by rpliego           #+#    #+#             */
/*   Updated: 2024/03/02 20:04:04 by rpliego          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdio.h>
# include "libft.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

char		*get_next_line(int fd);
size_t		ft_strlengnl(char *s);
char		*ft_strchrgnl(char *s, int c);
char		*ft_strjoingnl(char *stash, char *buff);
size_t		ft_strlcpygnl(char *dest, char *src, unsigned int size);
char		*ft_substrgnl(char *s, unsigned int start, size_t len);
void		*ft_freegnl(char **clean);

#endif
