/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_update.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfitte <bfitte@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 07:11:33 by bfitte            #+#    #+#             */
/*   Updated: 2025/11/24 16:56:26 by bfitte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_update.h"

char	*ft_check_save(int fd, char *save)
{
	char	*s;
	int		nb_char;

	nb_char = 1;
	s = malloc(sizeof(char) * BUFFER_SIZE + 1);
	while (ft_strchr(save, '\n') != -1 && nb_char != 0)
	{
		nb_char = read(fd, s, BUFFER_SIZE);
		if (nb_char == -1)
		{
			free(s);
			return (NULL);
		}
		s[nb_char] = '\0';
		save = ft_strjoin(save, s);
	}
	free(s);
	return (save);
}

char	*ft_get_line(char *save)
{
	char	*s;
	int		index_n;
	int		i;

	i = -1;
	index_n = ft_strchr(save, '\n');
	if (index_n == -1)
	{
		s = malloc(sizeof(char) * ft_strlen(save));
		while (save[++i] != '\0')
			s[i] = save[i];
	}
	else
	{
		s = malloc(sizeof(char) * index_n + 2);
		while (++i <= index_n)
			s[i] = save[i];
	}
	s[i] = '\0';
	return (s);
}

char	*ft_new_save(char *save)
{
	char	*s;
	int		index_n;
	int		i;

	index_n = ft_strchr(save, '\n');
	if (index_n == -1)
	{
		free(save);
		return (NULL);
	}
	else
	{
		i = 0;
		s = malloc(sizeof(char) * ft_strlen(save) - index_n);
		while (save[++index_n] != '\0')
			s[i++] = save[index_n];
		s[i] = '\0';
	}
	return (s);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*save;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	save = ft_check_save(fd, save);
	line = ft_get_line(save);
	save = ft_new_save(save);
	return (line);
}