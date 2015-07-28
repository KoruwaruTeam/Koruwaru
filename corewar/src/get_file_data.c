/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmielcza <tmielcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/28 15:37:28 by tmielcza          #+#    #+#             */
/*   Updated: 2015/07/28 15:45:31 by tmielcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void		*get_file_data(char const *name, size_t *size)
{
	char		*buff;
	int			fd;

	fd = open(name, O_RDONLY);
	if (fd < 0)
	{
		perror("Bad file");
		return (NULL);
	}
	*size = lseek(fd, 0, SEEK_END);
	lseek(fd, 0, SEEK_SET);
	buff = (char *)malloc(*size);
	if (buff == NULL)
	{
		perror("Malloc error");
		return (NULL);
	}
	if (read(fd, buff, *size) < 0)
	{
			free(buff);
			perror("Naughty file");
			return (NULL);
	}
	close(fd);
	return (buff);
}