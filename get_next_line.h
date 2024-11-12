/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salabbe <salabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 14:30:24 by salabbe           #+#    #+#             */
/*   Updated: 2024/11/12 16:00:10 by salabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef	BUFFER_SIZE
#  define 	BUFFER_SIZE 5
# endif

//\\=========================LIBRARY=========================//

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

//\\=======================FUNCTION=========================//

size_t			ft_strlen(const char *str);
char			*get_next_line(int fd);
int				ft_strchr(const char *s);
char			*ft_strjoin(char const *s1, char const *s2);
char			*gen_line(char *stash, char *line);
char			*extract_line(char *stash, char *line);
void			*ft_calloc(size_t nmemb, size_t size);
void	clean_stash(char* stash, int index);
#endif