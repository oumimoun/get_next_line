/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oumimoun <oumimoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 12:56:39 by oumimoun          #+#    #+#             */
/*   Updated: 2023/12/11 18:54:50 by oumimoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "get_next_line.h"

int flag(char *str)
{
    if (str == NULL)
        return (0);
    while (*str)
    {
        if ((*str) == '\n')
            return (1);
        str++;
    }
    return (0);
}

char *ft_read_buffer(int fd, char *buff, char *temp)
{
    int i;

    i = 1;
    while (flag(temp) == 0 && i > 0)
    {
        i = read(fd, buff, BUFFER_SIZE);
        if (i < 0)
            return (free(buff), free(temp), NULL);
        buff[i] = '\0';
        temp = ft_strjoin(temp, buff);
    }
    free(buff);
    if (temp && temp[0] == '\0')
        return (free(temp), NULL);
    return (temp);
}

char *ft_new_line(char *temp)
{
    int i;
    char *result;

    if (!temp)
        return (NULL);
    i = 0;
    while (temp[i] != '\n' && temp[i])
        i++;
    if (temp[i] == '\n')
        i++;
    result = ft_substr(temp, 0, i);
    return (result);
}

char *ft_the_next_line(char *temp)
{
    char *new_buff;
    int i;

    if (!temp)
        return (NULL);
    i = 0;
    while (temp[i] != '\n' && temp[i])
        i++;
    if (temp[i] == '\n')
        i++;
    new_buff = ft_strdup(&temp[i]);
    free(temp);
    return (new_buff);
}

char *get_next_line(int fd)
{
    static char *temp;
    char *buff;
    char *line;

    if (fd < 0 || BUFFER_SIZE <= 0 || fd > OPEN_MAX)
        return (NULL);
    buff = (char *)malloc(BUFFER_SIZE + 1 * sizeof(char));
    if (!buff)
        return (NULL);
    temp = ft_read_buffer(fd, buff, temp);
    line = ft_new_line(temp);
    temp = ft_the_next_line(temp);
    return (line);
}

int main()
{
    int fd = open("file.txt", O_RDONLY);

    char *line;
    // line = get_next_line(fd);
    // printf("%s", get_next_line(fd));
    // printf("%s", get_next_line(fd));
    // printf("%s", get_next_line(fd));
    // free(line);
    
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return 0;
}
