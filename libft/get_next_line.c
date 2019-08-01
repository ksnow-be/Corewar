/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgigi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 16:28:00 by lgigi             #+#    #+#             */
/*   Updated: 2019/04/12 12:21:33 by lgigi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_read_fd(int fd, int *rd, char *buffer, char *cpy)
{
	char	*swp;

	if (!ft_strchr(buffer, '\n'))
	{
		if (ft_strlen(buffer) != 0)
		{
			swp = cpy;
			if ((cpy = ft_strjoin(cpy, buffer)) == NULL)
				return (NULL);
			ft_memdel((void *)&swp);
			ft_strclr(buffer);
		}
		while ((*rd = read(fd, buffer, BUFF_SIZE) > 0))
		{
			buffer[BUFF_SIZE] = '\0';
			if (ft_strchr(buffer, '\n'))
				break ;
			swp = cpy;
			if ((cpy = ft_strjoin(cpy, buffer)) == NULL)
				return (NULL);
			ft_memdel((void *)&swp);
			ft_strclr(buffer);
		}
	}
	return ((*rd < 0) ? NULL : cpy);
}

static int		get_line(int fd, size_t i, char *buf_fd, char **line)
{
	char	*cpy;
	char	*swp;
	int		rd;

	rd = 1;
	swp = NULL;
	if (!(cpy = ft_strnew(1)))
		return (-1);
	if (!ft_strchr(buf_fd, '\n'))
		if ((cpy = ft_read_fd(fd, &rd, buf_fd, cpy)) == NULL)
			return (-1);
	while (buf_fd[i] != '\0' && buf_fd[i] != '\n')
		i++;
	if (!(*line = ft_strnew(i)))
		return (-1);
	*line = ft_strncpy(*line, buf_fd, i);
	if (ft_strchr(buf_fd, '\n'))
		ft_strncpy(buf_fd, buf_fd + i + 1, ft_strlen(buf_fd));
	swp = *line;
	if (!(*line = ft_strjoin(cpy, *line)))
		return (-1);
	ft_memdel((void *)&swp);
	ft_memdel((void *)&cpy);
	return ((rd == 0 && !**line) ? 0 : 1);
}

int				get_next_line(const int fd, char **line)
{
	static char	lines[1024][BUFF_SIZE + 1];
	int			l;

	if (fd < 0 || fd > 1024 || BUFF_SIZE <= 0 ||\
			!line || (read(fd, lines[fd], 0) < 0))
		return (-1);
	if ((l = get_line(fd, 0, lines[fd], line)) == -1)
		return (-1);
	if (l == 0)
		return (0);
	return (1);
}
