/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strjoing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouboukou <ouboukou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 16:19:44 by ouboukou          #+#    #+#             */
/*   Updated: 2024/04/21 16:27:37 by ouboukou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include<string.h>
char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t	len1;
	size_t	len2;
	char	*str;
	int		i;
	int		j;

	len1 = strlen(s1);
	len2 = strlen(s2);
	str = malloc((len1 + len2 + 1) + sizeof(char));
	if (str == NULL)
		return (NULL);
	
	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
		str[i++] = s2[j++];
	str[i] = '\0';
	return (str);
}

int main()
{
    char *s = "start from here?";
    char *x = "end Here!";
    char *res = ft_strjoin(s, x);
    printf("Output:\t-> %s\n", res);
    return 0;
}