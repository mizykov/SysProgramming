const char CANARY = '$';
const char FIRST_LETTER = 'a';
const char LAST_LETTER = 'z';
const char FIRST_LETTER_2 = 'A';
const char LAST_LETTER_2 = 'Z';

bool keepIn(char val) {
        return (val >= FIRST_LETTER && val <= LAST_LETTER) || 
                (val >= FIRST_LETTER_2 && val <= LAST_LETTER_2);
}

bool dontKeepIn(char val) {
        return (val < FIRST_LETTER || val > LAST_LETTER) && 
                (val < FIRST_LETTER_2 || val > LAST_LETTER_2);
}

char* directStep(char *p)
{
        while (!(keepIn(*p) || (*p == CANARY)))
        {
                ++p;
        }
        return p;
}

int direct_compare(const Line a, const Line b)
{
        char *buf_a = new char[a.size + 1];
        char *buf_b = new char[b.size + 1];
        readStr(a.fd, a.offset, a.size, buf_a);
        readStr(a.fd, b.offset, b.size, buf_b);
        buf_a[a.size] = CANARY;
        buf_b[b.size] = CANARY;
        int res = -1;
        bool check = true;

        buf_a=directStep(buf_a);
        buf_b=directStep(buf_b);
        do
        {
                if (dontKeepIn(*buf_a) &&
                         dontKeepIn(*buf_b)) {
                        directStep(buf_a);
                        directStep(buf_b);
                }
                if (*buf_a == CANARY || *buf_b == CANARY)
                        break;

                if (*buf_a != *buf_b)
                {
                        if (dontKeepIn(*buf_a)) {
                                res = 1;
                        }
                        else if (dontKeepIn(*buf_b))
                                res = 0;
                        else {
                                res = *buf_a < *buf_b;
                        }
                        check = false;
                        break;
                }
                ++buf_a;
                ++buf_b;
        } while (*buf_a != CANARY && *buf_b != CANARY);

        if (check)
        {
                if (*buf_b == CANARY)
                    res = 0;
                else if (*buf_a == CANARY)
                    res = 1;
        }

        return res;
}

int reverseStep(char *p, int len, int size)
{
        int len_new = len;
        while (!(keepIn(*p) || (len_new < size)))
        {
                --p;
                ++len_new;
        }
        return len_new;
}

char* reverseStep2(char *p, int size)
{
        for (size_t i = 0; i < size; i++)
        {
                --p;
        }
        return p;
}

int reverse_compare(const Line a, const Line b)
{
        char *buf_a = new char[a.size + 1];
        char *buf_b = new char[b.size + 1];

        readStr(a.fd, a.offset, a.size, buf_a);
        readStr(a.fd, b.offset, b.size, buf_b);

        int res = -1;
        bool check = true;

        int len1 = 0, len2 = 0;
        int count = reverseStep(buf_a, len1, a.size);
        buf_a = reverseStep2(buf_a, count-len1);
        len1 = count;
        count = reverseStep(buf_b, len2, b.size);
        buf_b = reverseStep2(buf_b, count-len2);
        len2 = count;

        do
        {
                len1 = reverseStep(buf_a, len1, a.size);
                len2 = reverseStep(buf_b, len2, b.size);

                if (len1 >= a.size || len2 >= b.size)
                    break;

                if (*(buf_a + a.size - 1) != *(buf_b + b.size - 1))
                {
                    res = *(buf_a + a.size - 1) < *(buf_b + b.size - 1);
                    check = false;
                    break;
                }
                --buf_a;
                --buf_b;
                ++len1;
                ++len2;
        } while (len1 < a.size && len2 < b.size);

        if (check)
        {
                if (len1 >= a.size)
                    res = 0;
                else
                    res = 1;
        }

        return res;
}