char tolower1(char c)
{
    return c >= 'A' && c <= 'Z' ? c - 'A' + 'a' : c;
}

char tolower2(char c)
{
    if(c >= 'A' && c <= 'Z')
        c += 'a' - 'A';

    return c;
}
