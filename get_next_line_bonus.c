/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijoubair <ijoubair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 11:00:48 by ijoubair          #+#    #+#             */
/*   Updated: 2024/12/09 15:52:32 by ijoubair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_leftover(char *buffer)
{
	char	*leftover;
	int		j;
	int		i;
	int		len;

	j = 0;
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
		return (free(buffer), NULL);
	len = ft_strlen(buffer) - i;
	leftover = malloc(len * sizeof(char) + 1);
	if (!leftover)
	{
		free(buffer);
		return (NULL);
	}
	i++;
	while (j < len)
		leftover[j++] = buffer[i++];
	leftover[j] = 0;
	free(buffer);
	return (leftover);
}

//get line with '\n'
char	*extract_line(char *buffer)
{
	char	*line;
	size_t		i;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line = malloc(sizeof(char) * (i + 1 + (buffer[i] == '\n')));
	if (!line)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
		line[i++] = '\n';
	line[i] = 0;
	return (line);
}

//join the leftover with the new readed line
// char	*join_free(char *buffer, char *buf)
// {
// 	char	*join;

// 	join = ft_strjoin(buffer, buf);
// 	if(!join)
// 		return (NULL);
// 	free(buffer);
// 	return (join);
// }

// fill the buf
char	*read_buff(int fd, char *buffer)
{
	char	*buf;
	int		readed;

	buf = malloc(BUFFER_SIZE * sizeof(char) + 1);
	if (!buf)
		return (free(buffer), NULL);
	// if (!buffer)
	// 	buffer = ft_calloc(1, 1);
	// if(!buffer)
	// 	return(free(buf), NULL);
	readed = 1;
	while (readed > 0)
	{
		readed = read(fd, buf, BUFFER_SIZE);
		if (readed == -1)
			return(free(buf), free(buffer), NULL); 
		buf[readed] = 0;
		buffer = ft_strjoin(buffer, buf);
		
		if (ft_strchr(buf, '\n'))
			break ;
	}
	return (free(buf), buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer[FD_SETSIZE];
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	buffer[fd] = read_buff(fd, buffer[fd]);
	if (!buffer[fd])
		return (NULL);
	if (*buffer[fd] == 0)
	{
		free(buffer[fd]);
		buffer[fd] = NULL;
		return (NULL);
	}
	line = extract_line(buffer[fd]);
	if(!line)
			{
		free(buffer[fd]);
		buffer[fd] = NULL;
		return (NULL);
	}
	buffer[fd] = get_leftover(buffer[fd]);
	return (line);
}
