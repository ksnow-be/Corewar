/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgigi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 13:46:53 by lgigi             #+#    #+#             */
/*   Updated: 2019/04/03 14:19:54 by lgigi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*str;
	char	*str2;
	char	*n;

	if (!s || ((n = (char *)malloc(sizeof(char) * len + 1)) == NULL))
		return (NULL);
	str = (char *)s + start;
	str2 = n;
	while (len--)
		*str2++ = *str++;
	*str2 = '\0';
	return (n);
}
