/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oumimoun <oumimoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 02:50:55 by oumimoun          #+#    #+#             */
/*   Updated: 2023/12/11 18:57:35 by oumimoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 2147483648
#endif

#ifndef GET_NEXT_LINE
# define GET_NEXT_LINE

#include <stddef.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <limits.h>
#include <stdio.h>

int ft_strlen(char *str);
char *ft_strjoin(char *s1, char *s2);
int flag(char *str);
char *ft_read_buffer(int fd, char *buff, char *line);
char *ft_the_next_line(char *buff);
char *get_next_line(int fd);
char *ft_substr(char *str, int start, int len);
char *ft_new_line(char *temp);
char *ft_strdup(char *str);

#endif
