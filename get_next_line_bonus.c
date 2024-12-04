/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijoubair <ijoubair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 17:26:29 by ijoubair          #+#    #+#             */
/*   Updated: 2024/12/04 17:48:10 by ijoubair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char    *get_leftover(char *buffer)
{
    int i;
    int j;
    char    *leftover;
    int len;

    j = 0;
    i = 0;
    while(buffer[i] && buffer[i] != '\n')
        i++;
    if(!buffer[i])
        return(free(buffer), NULL);
    len = ft_strlen(buffer) - i;
    leftover = malloc(len * sizeof(char) + 1);
    if(!leftover)
    {
        free(buffer);
        return(NULL);
    }
    i++;
    while(j < len)
        leftover[j++] = buffer[i++];
    leftover[j] = 0;
    free(buffer);
    return(leftover);
}
//get line with '\n'
char    *extract_line(char *buffer)
{
    int i;
    char *line;
    
    i = 0;
    while (buffer[i] && buffer[i] != '\n')
        i++;
    line = malloc(i * sizeof(char) + 2);
    if(!line)
        return(NULL);
    i = 0;
    while(buffer[i] && buffer[i] != '\n')
    {
        line[i] = buffer[i];
        i++;
    }
    if(buffer[i] == '\n')
        line[i++] = '\n';
    line[i] = 0;
    return(line);
}

//join the leftover with the new readed line
char    *join_free(char *buffer, char *buf)
{
    char *join;
    join = ft_strjoin(buffer, buf);
    free(buffer);
    buffer = NULL;
    // free(buf);
    // buf = NULL;
    return(join);
}

// fill the buf
char    *read_buff(int fd, char * buffer)
{
    char* buf;
    int readed;
    
    buf = malloc(BUFFER_SIZE * sizeof(char) + 1);
    if(!buffer)
        buffer = ft_calloc(1, 1);
    readed = 1;
    while(readed > 0)
    {
        readed = read(fd, buf, BUFFER_SIZE);
        if(readed == -1)
        {
            free(buffer);
            return(NULL);
        }
        buf[readed] = 0;
        buffer = join_free(buffer, buf);
        if(ft_strchr(buf, '\n'))
            break;
    }
    free(buf);
    return(buffer);
}

char *get_next_line(int fd)
{
    static char *buffer[1024];
    char *line;

    buffer[fd] = read_buff(fd, buffer[fd]);
    if(!buffer[fd] || *buffer[fd] == 0)
        return(free(buffer[fd]), NULL);
    line = extract_line(buffer[fd]);
    buffer[fd] = get_leftover(buffer[fd]);
    return(line);
}