int step(char *p, int size, int pos)
{
    int pos_new = pos;
    while (!(*p > 'a' && *p < 'z'))
    {
        pos_new++;
        p++;
        if (pos <= size)
        {
            return -1;
        }
    }
    return pos_new;
}

int direct_compare(const Line a, const Line b)
{
    char *buf_a = new char[a.size + 1];
    char *buf_b = new char[b.size + 1];

    readStr(a.fd, a.offset, a.size, buf_a);
    readStr(a.fd, b.offset, b.size, buf_b);
    buf_a[a.size] = '$';
    buf_b[b.size] = '$';

    do
    {
        if (*buf_a != *buf_b)
        {
            return *buf_a < *buf_b;
        }
        ++buf_a;
        ++buf_b;
    } while (*buf_a != '$' && *buf_b != '$');

    delete buf_a;
    delete buf_b;

    return false;
}

int reverse_compare(const Line a, const Line b)
{
    char *buf_a = new char[a.size + 1];
    char *buf_b = new char[b.size + 1];

    readStr(a.fd, a.offset, a.size, buf_a);
    readStr(a.fd, b.offset, b.size, buf_b);

    int len = 0;
    do
    {
        if (*(buf_a + a.size - 1) != *(buf_b + b.size - 1))
        {
            return *(buf_a + a.size - 1) < *(buf_b + b.size - 1);
        }
        --buf_a;
        --buf_b;
        len++;
    } while (len < a.size && len < b.size);

    delete buf_a;
    delete buf_b;

    return false;
}