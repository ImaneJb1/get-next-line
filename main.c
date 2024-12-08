#include "get_next_line.h"
#include "stdio.h"

int main ()
{
     int fd = open("empty.txt", O_RDONLY);
     printf("%s",get_next_line(fd));

     
}