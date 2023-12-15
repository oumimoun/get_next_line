/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oumimoun <oumimoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 12:00:27 by oumimoun          #+#    #+#             */
/*   Updated: 2023/12/14 14:39:15 by oumimoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H

# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE 
#  define BUFFER_SIZE 13
# endif

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <fcntl.h>

int		flag(char *str);
int		ft_strlen(char *str);
char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_read_buffer(int fd, char *buff, char *line);
char	*ft_the_next_line(char *buff);
char	*ft_substr(char *str, int start, int len);
char	*ft_new_line(char *temp);
char	*ft_strdup(char *str);

#endif