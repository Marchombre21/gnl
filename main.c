/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfitte <bfitte@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 09:07:21 by bfitte            #+#    #+#             */
/*   Updated: 2025/11/24 16:54:04 by bfitte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_update.h"
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int	fd;
	char	*s;

	fd = open("test.txt", O_RDONLY);
	s = get_next_line(fd);
	// printf("Premier%s", s);
	// free(s);
	// s = get_next_line(fd);
	// printf("Deuxieme%s", s);
	// free(s);
	// s = get_next_line(fd);
	// printf("Troisieme%s", s);
	// free(s);
	// s = get_next_line(fd);
	// printf("Quatrieme%s", s);
	// free(s);
	// s = get_next_line(fd);
	// printf("Cinquieme%s", s);
	// free(s);
	// s = get_next_line(fd);
	// printf("Sixieme%s", s);
	// free(s);
	// s = get_next_line(fd);
	// printf("Septieme%s", s);
	// free(s);
	// s = get_next_line(fd);
	// printf("Huitieme%s", s);
	// free(s);
	while (s)
	{
		printf("%s\n", s);
		free(s);
		s = get_next_line(fd);
	}
	close(fd);
	free(s);
	return (0);
}