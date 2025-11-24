/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfitte <bfitte@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 11:04:34 by bfitte            #+#    #+#             */
/*   Updated: 2025/11/21 15:27:04 by bfitte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*get_next_line(int fd)
{
	t_line	*str;
	t_line	*node;
	int	readed_char;
	char	buffer[BUFFER_SIZE];

	if(fd == -1)
		return (NULL);
	str = malloc(sizeof(t_line));
	if(!str)
		return (NULL);
	while (buffer[0] != '\n')
	{
		readed_char = read(fd, buffer, 1);
		node = ft_lstnew((void *)buffer[0]);
		if (!node)
			return (NULL);
	}
	return (NULL);
}

int	main(void)
{
	get_next_line(1);
	return (0);
}