/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouboukou <ouboukou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 12:56:55 by ouboukou          #+#    #+#             */
/*   Updated: 2024/04/22 01:34:10 by ouboukou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strchr(const char *s, int arg)
{
	if (!s)
		return (NULL);
	while (*s && *s != (char)arg)
	{
		s++;
		if (*s == (char)arg)
		{
			return ((char *)s);
		}
	}
	if (*s == (char)arg)
	{
		return ((char *)s);
	}
	return (NULL);
}

char	*ft_strdup(const char *str)
{
	size_t	len;
	char	*ptr;
	size_t	i;

	len = ft_strlen(str);
	ptr = malloc((len + 1) * (sizeof(char)));
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while (str[i])
	{
		ptr[i] = str[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	j;
	size_t	i;
	char	*str;

	i = 0;
	if (s == NULL)
		return (ft_strdup(""));
	j = ft_strlen(s);
	while (i + start < j && i < len)
		i++;
	str = malloc(i + 1);
	if (str == NULL)
		return (0);
	j = 0;
	while (i > 0)
	{
		str[j++] = s[start++];
		i--;
	}
	str[j] = '\0';
	return (str);
}


char    *ft_strjoin(const char *s1, const char *s2)
{
    size_t    total_len;
    char    *new_str;
    size_t    i;
    size_t    j;

    if (!s1 && !s2)
        return (NULL);
    if (!s1 && s2)
        return (ft_strdup(s2));
    if (!s2 && s1)
        return (ft_strdup(s1));
    total_len = ft_strlen(s1) + ft_strlen(s2);
    new_str = malloc(sizeof(char) * (total_len + 1));
    if (!new_str)
        return (NULL);
    i = -1;
    while (s1[++i] != '\0')
        new_str[i] = s1[i];
    j = 0;
    while (s2[j] != '\0')
        new_str[i++] = s2[j++];
    new_str[i] = '\0';
    return (new_str);
}


// char	*ft_strjoin(const char *s1, const char *s2)
// {
// 	size_t	len1;
// 	size_t	len2;
// 	char	*str;
// 	int		i;
// 	int		j;
	
// 	if (s1 == NULL || s2 == NULL)
// 		return (NULL);
// 	len1 = strlen(s1);
// 	len2 = strlen(s2);
// 	str = malloc((len1 + len2 + 1) + sizeof(char));
// 	if (str == NULL)
// 		return (NULL);
// 	i = 0;
// 	while (s1[i])
// 	{
// 		str[i] = s1[i];
// 		i++;
// 	}
// 	j = 0;
// 	while (s2[j])
// 		str[i++] = s2[j++];
// 	str[i] = '\0';
// 	return (str);
// }
