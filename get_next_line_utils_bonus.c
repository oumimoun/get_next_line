/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oumimoun <oumimoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 12:00:30 by oumimoun          #+#    #+#             */
/*   Updated: 2023/12/14 13:02:28 by oumimoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_substr(char *str, int start, int len)
{
	char	*result;
	int		i;

	if (!str || start < 0)
		return (NULL);
	if (start >= ft_strlen(str))
		return (NULL);
	if (len <= 0 || start + len > ft_strlen(str))
		return (NULL);
	result = malloc(len + 1);
	if (!result)
		return (NULL);
	i = 0;
	while (i < len && str[start + i])
	{
		result[i] = str[start + i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

char	*ft_strdup(char *str)
{
	char	*result;
	int		i;

	if (!str)
		return (NULL);
	i = 0;
	result = malloc(ft_strlen(str) + 1);
	if (!result)
		return (NULL);
	while (str[i])
	{
		result[i] = str[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*result;
	int		i;

	i = -1;
	if (s1 && s2)
	{
		result = malloc(((ft_strlen(s2) + ft_strlen(s1)) + 1));
		if (!result)
			return (NULL);
		while (s1[++i])
			result[i] = s1[i];
		i = -1;
		while (s2[++i])
			result[ft_strlen(s1) + i] = s2[i];
		result[i + ft_strlen(s1)] = '\0';
		return (result);
	}
	return (NULL);
}
