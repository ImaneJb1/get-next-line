
char *ft_strjoin(char *s1, char *s2)
{
    int len1 = 0;
    int len2 = 0;

    if (s1 != NULL)
        len1 = strlen(s1);
    if (s2 != NULL)
        len2 = strlen(s2);
    char *string = malloc(len1 + len2 + 1);
    if (string == NULL)
        return(NULL);
    int i = 0;
    while (s1 && *s1)
    {
        s3[i] = *s1;
        i++;
        s1++;
    }
    while (s2 && *s2)
    {
        s3[i] = *s2;
        i++;
        s2++;
    }
    s3[i] = 0;
    return(s3);
}