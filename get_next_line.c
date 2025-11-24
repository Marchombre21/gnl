/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfitte <bfitte@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 15:19:24 by bfitte            #+#    #+#             */
/*   Updated: 2025/11/23 13:33:48 by bfitte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
	int	nb_char;
	static char	*remain;
	char	buffer[BUFFER_SIZE];
	int	index_n;
	char	*s;

	if (fd == -1)
		return (NULL);
	index_n = -1;
	nb_char = 1;
	if (!remain)
		remain = ft_substr("", 0, 1);
	else if (remain && ft_strchr(remain, '\n') != -1)
	{
		s = ft_substr(remain, 0, ft_strchr(remain, '\n') + 1);
		remain = ft_substr(remain, ft_strchr(remain, '\n') + 1, ft_strlen(remain));
	}
	while (index_n == -1 && nb_char != -1 && nb_char != 0)
	{
		nb_char = read(fd, buffer, BUFFER_SIZE);
		if (nb_char != 0)
			buffer[nb_char] = '\0';
		index_n = ft_strchr(buffer, '\n');
		s = check_results(index_n, nb_char, &remain, buffer);
	}
	return (s);
}
