/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgigi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 17:36:08 by lgigi             #+#    #+#             */
/*   Updated: 2019/04/04 17:36:34 by lgigi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		count_words(char *s, char c)
{
	int		inword;
	int		words;

	words = 0;
	inword = 0;
	while (*s != '\0')
	{
		if (!inword && *s != c)
		{
			words++;
			inword = 1;
		}
		else if (inword && *s == c)
			inword = 0;
		s++;
	}
	return (words);
}

static void		free_tab(char **tab)
{
	unsigned int i;

	i = 0;
	if (tab != NULL)
	{
		while (tab[i])
			if (tab[i] != NULL)
				free(tab[i++]);
		free(tab);
	}
}

static char		**split(char *s, char c, int i, char **tab)
{
	size_t	size;
	size_t	k;
	size_t	j;

	k = 0;
	while (++i < count_words(s, c))
	{
		size = 0;
		while (*(s + k) && *(s + k) == c)
			k++;
		while (*(s + k + size) && *(s + k + size) != c)
			size++;
		if ((tab[i] = ft_strnew(size)) == NULL)
		{
			free_tab(tab);
			return (NULL);
		}
		k += size;
		j = k - 1;
		while (size && (*(s + j) != c || j != 0))
			tab[i][--size] = *(s + j--);
	}
	tab[i] = NULL;
	return (tab);
}

char			**ft_strsplit(char const *s, char c)
{
	char			**tab;
	unsigned int	size;

	if (!s || !c)
		return (NULL);
	size = count_words((char *)s, c);
	if (!(tab = (char **)malloc(sizeof(char *) * (size + 1))))
		return (NULL);
	if (!size)
	{
		tab[0] = 0;
		return (tab);
	}
	tab = split((char *)s, c, -1, tab);
	return (tab);
}
