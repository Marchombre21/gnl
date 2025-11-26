/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfitte <bfitte@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 15:36:43 by bfitte            #+#    #+#             */
/*   Updated: 2025/11/26 17:11:46 by bfitte           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*new_str;
	int		i;
	int		j;
	int		s2_len;

	s2_len = ft_strlen(s2);
	i = -1;
	if (!s1)
		return (ft_substr(s2, 0, s2_len));
	new_str = malloc(sizeof(char) * (ft_strlen(s1) + s2_len) + 1);
	if (!new_str)
		return (ft_free_function(s1, NULL));
	while (s1[++i])
		new_str[i] = s1[i];
	j = 0;
	while (s2[j])
		new_str[i++] = s2[j++];
	new_str[i] = '\0';
	free(s1);
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
	char			*new_str;
	size_t			i;
	size_t				size_malloc;
	unsigned int	s_len;

	s_len = ft_strlen(s);
	size_malloc = 0;
	if (start >= s_len)
		size_malloc = 0;
	else if ((s_len - start) <= (unsigned int)len)
		size_malloc = s_len - start;
	else if ((s_len - start) > (unsigned int)len)
		size_malloc = len;
	i = 0;
	new_str = malloc(sizeof(char) * size_malloc + 1);
	if (!new_str)
		return (NULL);
	while (i < size_malloc)
		new_str[i++] = s[start++];
	// if (s[i] != '\0' && size_malloc != 0)
	// {
	// 	// while (i < len && s[start])
	// 	while (i < size_malloc && s[start])
	// 		new_str[i++] = s[start++];
	// }
	new_str[i] = '\0';
	return (new_str);
}
