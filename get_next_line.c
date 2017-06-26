/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbollach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/16 13:11:04 by mbollach          #+#    #+#             */
/*   Updated: 2017/06/26 15:42:21 by mbollach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>

int		memo(int i)
{
	static int j;
	
	j = j + i;
	if (j > 0)
		j++;
	return (j);
}

int		get_next_line(const int fd, char **line)
{
	int i;
	int j;
	int ret;
	char buffer[BUFF_SIZE + 1];

	i = 0;
	i = memo(i);
	j = 0;
	ret = 0;
	line[0] = (char *)malloc(sizeof(char) * BUFF_SIZE + 1);
	while ((ret = read(fd, &buffer, BUFF_SIZE)) != 0)
		buffer[ret] = '\0';
	if (fd < 1)
	{
		ft_putstr("Fichier vide");
		return (-1);
	}
	while (buffer[i] != '\0')
	{
		if (buffer[i] != '\n')
		{
			line[0][j] = buffer[i];
			i++;
			j++;
		}
		else
		{
			memo(i);
			free(*line);
			return (1);
		}
	}
	return (0);
}

int		main(int ac, char **av)
{
	int fd;
	char *line;

	fd = open(av[1], O_RDONLY);
	while (get_next_line(fd, &line) > 0)
		ft_putendl(line);
	return (0);

}
