/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salabbe <salabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 14:30:24 by salabbe           #+#    #+#             */
/*   Updated: 2024/11/14 11:40:20 by salabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

//\\=========================LIBRARY=========================//

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

//\\=======================FUNCTION=========================//

int				ft_strlen(const char *str);
int				ft_isnewline(const char *s);
char			*get_next_line(int fd);
char			*clean_stash(char *stash);
char			*gen_stash(char *stash, int fd);
char			*gen_line(char *stash, char *line);
char			*extract_line(char *stash, char *line);
char			*ft_strjoin(char *s1, char const *s2);
void			*ft_calloc(size_t nmemb, size_t size);

#endif