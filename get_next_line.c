/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijoubair <ijoubair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 11:00:48 by ijoubair          #+#    #+#             */
/*   Updated: 2024/12/08 19:36:35 by ijoubair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	if (!buffer[i])
		return (NULL);
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
char	*join_free(char *buffer, char *buf)
{
	char	*join;

	join = ft_strjoin(buffer, buf);
	if(!join)
		return (NULL);
	free(buffer);
	return (join);
}

// fill the buf
char	*read_buff(int fd, char *buffer)
{
	char	*buf;
	int		readed;

	buf = malloc(BUFFER_SIZE * sizeof(char) + 1);
	if (!buf)
		return (NULL);
	if (!buffer)
		buffer = ft_calloc(1, 1);
	if(buffer == NULL)
		return(freer(&buf));
	readed = 1;
	while (readed > 0)
	{
		readed = read(fd, buf, BUFFER_SIZE);
		if (readed == -1)
			return(free(buf), free(buffer), NULL); 
		buf[readed] = 0;
		buffer = join_free(buffer, buf);
		if (ft_strchr(buf, '\n'))
			break ;
	}
	return (free(buf), buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	buffer = read_buff(fd, buffer);
	if (!buffer)
		return (NULL);
	if(*buffer == 0)
		return(free(buffer), NULL);
	line = extract_line(buffer);
	if(!line)
		return(free(buffer), NULL);
	buffer = get_leftover(buffer);
	if(!buffer)
		free(buffer);
	return (line);
}
