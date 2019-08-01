/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgigi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 13:48:42 by lgigi             #+#    #+#             */
/*   Updated: 2019/04/04 17:10:34 by lgigi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_ws(char c)
{
	if (!c)
		return (0);
	if (c == ' ' || c == '\t' || c == '\n')
		return (1);
	return (0);
}

char		*ft_strtrim(char const *s)
{
	char	*n;
	char	*str;
	int		size;

	if (s == NULL)
		return (NULL);
	size = ft_strlen(s);
	if ((!is_ws(*s) && !is_ws(*(s + size - 1))) || !ft_strlen(s))
		return (ft_strdup(s));
	while (is_ws(*(s + size - 1)))
		size--;
	while (is_ws(*s))
	{
		size--;
		s++;
	}
	if (!size || !*s)
		return (ft_strdup(s));
	if ((n = (char *)malloc(sizeof(char) * size + 1)) == NULL)
		return (NULL);
	str = n;
	while (*s != '\0' && size--)
		*str++ = *s++;
	*str = '\0';
	return (n);
}
