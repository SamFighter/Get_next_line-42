/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salabbe <salabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 14:31:08 by salabbe           #+#    #+#             */
/*   Updated: 2024/11/12 17:36:38 by salabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>      // Pour printf
#include "get_next_line.h"

int		ft_putstr(const char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

char		*extract_line(char *stash, char *line)
{
	int		i;

	i = 0;
	line = gen_line(stash, line);
	if (!line)
		return (NULL);
	while (stash[i])
	{
		if (stash[i] == '\n')
		{
			line[i] = stash[i];
			break;
		}
		line[i] = stash[i];
		i++;
	}
	clean_stash(stash, i + 1);
	return (line);
}

void	clean_stash(char* stash, int index)
{
	int i;
	char *tmp;

	tmp = ft_calloc(sizeof(char), ft_strlen(stash) - index + 1);
	i = 0;
	while (stash[i + index])
	{
		tmp[i] = stash[i + index];
		i++;
	}
	tmp[i] = 0;
	free(stash);
	stash = ft_calloc(sizeof(char), ft_strlen(tmp) + 1);
	i = 0;
	while (tmp[i])
	{
		stash[i] = tmp[i];
		i++;
	}
	stash[i] = 0;
}

char	*gen_line(char *stash, char *line)
{
	int		i;

	i = 0;
	if (!stash || ft_strlen(stash) == 0)
		return (NULL);
	while (stash[i])
	{
		if (stash[i] == '\n')
		{
			i++;
			break;
		}
		i++;
	}
	line = ft_calloc(sizeof(char), i + 1);
	return (line);
}

static char		*gen_stash(char *stash, int  fd)
{
	char	*buff;
	int		i;

	buff = NULL;
	while (ft_strchr(stash) == 0)
	{
		buff = ft_calloc(sizeof(char), BUFFER_SIZE + 1);
		if (!buff)
			return (NULL);
		i = read(fd, buff, BUFFER_SIZE);
		if (i <= 0)
		{
			free(buff);
			return (stash);
		}
		stash = ft_strjoin(buff, stash);
		free(buff);
	}
	return (stash);
}

char	*get_next_line(int fd)
{
	static char	*stash = NULL;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = NULL;
	stash = gen_stash(stash, fd);
	if (stash == NULL || stash[0] == '\0')
	{
		free(stash);
		stash = NULL;
		return (NULL);
	}
	line = extract_line(stash, line);
	if (line == NULL || line[0] == '\0')
	{
		free(stash);
		free(line);
		line = NULL;
		return (NULL);
	}
	return (line);
}

#include <fcntl.h>      // Pour open
#include <unistd.h>     // Pour close
#include <stdlib.h>     // Pour exit


int main(int argc, char **argv)
{
    int     fd;
    char    *line;

    // Vérifie si le fichier a été passé en argument
    if (argc != 2)
    {
        printf("Usage: %s <filename>\n", argv[0]);
        return (1);
    }

    // Ouvre le fichier en mode lecture seule
    fd = open(argv[1], O_RDONLY);
    if (fd == -1)
    {
        perror("Error opening file");
        return (1);
    }

    // Lit et affiche chaque ligne jusqu'à la fin du fichier
	line = get_next_line(fd);
	int i =0;
    while (line != NULL || i != 5)
    {
		ft_putstr(line);
        free(line);  // Libère chaque ligne après l'affichage
		line = get_next_line(fd);
		i++;
    }

    // Ferme le fichier
    if (close(fd) == -1)
    {
        perror("Error closing file");
        return (1);
    }        printf("%s", line);


    return (0);
}
