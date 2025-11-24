/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_update.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfitte <bfitte@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 15:42:40 by bfitte            #+#    #+#             */
/*   Updated: 2025/11/24 15:14:20 by bfitte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_update.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		s1_len;
	int		s2_len;
	char	*new_str;
	int		i;
	int		j;

	i = -1;
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	new_str = malloc(sizeof(char) * (s1_len + s2_len) + 1);
	if (!new_str)
		return (NULL);
	while (s1[++i])
		new_str[i] = s1[i];
	j = 0;
	while (s2[j])
		new_str[i++] = s2[j++];
	new_str[i] = '\0';
	return (new_str);
}

int	ft_strchr(char *s, int c)
{
	int	i;
	int	s_len;

	if (!s)
		return (-1);
	s_len = ft_strlen(s);
	i = 0;
	while (i < s_len)
	{
		if (s[i] == (char)c)
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*new_str;
	size_t	i;
	int		size_malloc;
	unsigned int	s_len;
	
	s_len = ft_strlen(s);
	size_malloc = 0;
	if ((s_len - start) <= (unsigned int)len)
		size_malloc = s_len - start;
	else if ((s_len - start) > (unsigned int)len)
		size_malloc = len;
	i = 0;
	new_str = malloc(sizeof(char) * size_malloc + 1);
	if (!new_str)
		return (NULL);
	if (s[i] != '\0' && size_malloc != 0)
	{
		while (i < len && s[start])
			new_str[i++] = s[start++];
	}
	new_str[i] = '\0';
	return (new_str);
}

char	*check_results(int i, int n_char, char **remain, char *buffer)
{
	char	*s;

	s = NULL;
	if (i == -1 && n_char != 0 && n_char != -1)
		*remain = ft_strjoin(*remain, buffer);
	else if (n_char == 0 || n_char == -1)
	{
		if (**remain != '\0')
			s = ft_substr(*remain, 0, ft_strlen(*remain));
		if (*remain)
			free(*remain);
		*remain = NULL;
	}
	else if (i != -1)
	{
		s = ft_strjoin(*remain, ft_substr(buffer, 0, i + 1));
		*remain = ft_substr(buffer, i + 1, BUFFER_SIZE - i + 1);
	}
	return (s);
}
