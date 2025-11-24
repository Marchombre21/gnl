/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfitte <bfitte@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 11:11:59 by bfitte            #+#    #+#             */
/*   Updated: 2025/11/21 15:40:42 by bfitte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
# define BUFFER_SIZE 1
# endif

# include <stdlib.h>

typedef struct s_line
{
	void	*content;
	t_line	*next;
}	t_line;

char	*get_next_line(int fd);
void	ft_lstadd_back(t_line **lst, t_line *new);
t_line	*ft_lstnew(void *content);
t_line	*ft_lstlast(t_line *lst);


#endif