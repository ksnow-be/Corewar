/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferry <vferry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 12:30:40 by vferry            #+#    #+#             */
/*   Updated: 2019/07/27 16:48:01 by vferry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/corewar.h"

t_lexem	*ft_parse_file(char **file)
{
	t_lexem		*list;
	t_cursor	*cursor;

	list = NULL;
	cursor = (t_cursor*)malloc(sizeof(t_cursor));
	init_cursor(&cursor);
	while (file[cursor->line])
	{
		cursor->pos = 0;
		ft_take_lex(file, cursor, &list);
		if (file[cursor->line])
			cursor->line++;
	}
	free(cursor);
	return (list);
}

void	ft_asm(int fd, int count, char *file_name)
{
	char	**file;
	int		i;
	t_lexem	*test;

	i = 0;
	file = (char **)malloc(sizeof(char *) * (count + 1));
	while (i < count)
	{
		get_next_line(fd, &file[i]);
		i++;
	}
	file[i] = NULL;
	if (close(fd) < 0)
		error("I can't close file in f(asm) :(");
	test = ft_parse_file(file);
	if (!test)
		error("Wrong file content!");
	start_checking(test, file, i);
	ft_clean_file(file);
	bytes(test, file_name);
}

void	take_count_of_str(int fd, char *file)
{
	int		ret;
	char	c;
	int		count;

	if ((ret = read(fd, 0, 0)) == -1)
		error("This is a directory!");
	count = 1;
	while ((ret = read(fd, &c, 1)))
		if (c == '\n')
			count++;
	if (close(fd) < 0)
		error("I can't close file in f(take_count_of_str) :(");
	fd = open(file, O_RDONLY);
	if (fd < 0)
		error("Sorry, I can't open of this file :(");
	ft_asm(fd, count, file);
}

int		main(int argc, char **argv)
{
	int	fd;

	if (argc != 2)
		error("Not right count of arguments!");
	else
	{
		if (check_format(argv[1]) == 1)
			error("The file format is wrong!");
		fd = open(argv[1], O_RDONLY);
		if (fd < 0)
			error("Sorry, I can't open of this file :(");
		take_count_of_str(fd, argv[1]);
	}
	return (0);
}
