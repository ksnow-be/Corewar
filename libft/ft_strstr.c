/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgigi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 13:45:42 by lgigi             #+#    #+#             */
/*   Updated: 2019/04/05 13:20:32 by lgigi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	size_t	i;
	char	*str1;
	char	*str2;

	str1 = (char *)s1;
	str2 = (char *)s2;
	if (!*s2)
		return ((char *)s1);
	while (*str1)
	{
		i = 0;
		while (str2[i] && *(str1 + i) == str2[i])
			i++;
		if (str2[i] == '\0')
			return (str1);
		str1++;
	}
	return (NULL);
}
