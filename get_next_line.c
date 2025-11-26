/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfitte <bfitte@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 15:36:20 by bfitte            #+#    #+#             */
/*   Updated: 2025/11/26 17:30:12 by bfitte           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_free_function(char *s1, char *s2)
{
	free(s1);
	if (s2)
		free(s2);
	return (NULL);
}

char	*ft_check_save(int fd, char *save)
{
	char	*s;
	int		nb_char;

	nb_char = 1;
	s = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!s)
		return (ft_free_function(save, NULL));
	while (ft_strchr(save, '\n') == -1 && nb_char != 0)
	{
		nb_char = read(fd, s, BUFFER_SIZE);
		if (nb_char == -1)
			return (ft_free_function(s, save));
		s[nb_char] = '\0';
		if (nb_char > 0)
		{
			save = ft_strjoin(save, s);
			if (!save)
				return (ft_free_function(NULL, s));
		}
	}
	free(s);
	if (nb_char == 0 && !save)
		return (NULL);
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
		s = malloc(sizeof(char) * ft_strlen(save) + 1);
		if (!s)
			return (NULL);
		while (save[++i] != '\0')
			s[i] = save[i];
	}
	else
	{
		s = malloc(sizeof(char) * index_n + 2);
		if (!s)
			return (NULL);
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

	index_n = ft_strchr(save, '\n');
	if (index_n == -1)
		return (ft_free_function(save, NULL));
	if (save[index_n + 1] == '\0')
		return (ft_free_function(save, NULL));
	s = ft_substr(save, index_n + 1, ft_strlen(save) - index_n - 1);
	if (!s)
		return (ft_free_function(save, NULL));
	free(save);
	return (s);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*save;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	save = ft_check_save(fd, save);
	if (!save)
		return (NULL);
	line = ft_get_line(save);
	if (!line)
	{
		free(save);
		save = NULL;
		return (NULL);
	}
	save = ft_new_save(save);
	return (line);
}
