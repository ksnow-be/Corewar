/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgigi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 13:28:04 by lgigi             #+#    #+#             */
/*   Updated: 2019/04/03 13:28:08 by lgigi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*new;
	char			*n;
	unsigned int	i;

	i = 0;
	if (!s)
		return (NULL);
	if (!s || !(new = (char *)malloc(sizeof(char) \
							* ft_strlen(s) + 1)))
		return (NULL);
	n = new;
	while (*s != '\0')
		*n++ = f(i++, *(s++));
	*n = '\0';
	return (new);
}
