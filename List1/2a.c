char tolower(char c)
{
    return c >= 'A' && c <= 'Z' ? c - 'A' + 'a' : c;
}

void _tolower(char *s)
{
    while(*s != '\0')
    {
        *s = tolower(*s);
        s ++;
    }
}
