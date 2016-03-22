char tolower1(char c)
{
    return c >= 'A' && c <= 'Z' ? c - 'A' + 'a' : c;
}

void tolower(char *s)
{
    while(*s != '\0')
    {
        *s = tolower1(*s);
        s ++;
    }
}
