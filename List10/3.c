unsigned int length(char *s)
{
    unsigned int length = 0;
    while (*(s ++))
        ++ length;

    return length;
}
