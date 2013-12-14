/*
I have a very simple problem for you. Given two integers A and B, your job is to calculate the Sum of A + B.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BIG_NUM_LEN 2000

char * str_end_pos(char * str)
{
    char * end = str;
    while ((*end) != '\0') {
        end++;
    }
    end--;
    return end;
}

char * big_num_add(char * a, char * b, char * result)
{
    int alen, blen, carry, r, ap, bp, rp;
    alen = strlen(a);
    blen = strlen(b);
    ap = alen - 1;
    bp = blen - 1;
    carry = 0;
    rp = BIG_NUM_LEN-1;
    result[rp] = '\0';
    rp--;
    while (ap >= 0 && bp >= 0)
    {
        r = a[ap] - '0' + b[bp] - '0' + carry;
        if (r >= 10)
        {
            carry = 1;
            r -= 10;
        } else {
            carry = 0;
        }
        result[rp] = '0' + r;
        ap--;
        bp--;
        rp--;
    }
    if (ap >= 0)
    {
        while (ap >= 0) {
            r = a[ap] - '0' + carry;
            if (r > 10)
            {
                carry = 1;
                r -= 10;
            } else {
                carry = 0;
            }
            result[rp] = '0' + r;
            ap--;
            rp--;
        }
    }
    if (bp >= 0)
    {
        while (bp >= 0) {
            r = b[bp] - '0' + carry;
            if (r > 10)
            {
                carry = 1;
                r -= 10;
            } else {
                carry = 0;
            }
            result[rp] = '0' + r;
            bp--;
            rp--;
        }
    }

    return result + rp + 1;
}

int main(int argc, char const *argv[])
{
    int T, i;
    char a[BIG_NUM_LEN], b[BIG_NUM_LEN], r[BIG_NUM_LEN], * result;
    scanf("%d", &T);
    for (i = 0; i < T; ++i)
    {
        scanf("%s %s", a, b);
        printf("Case %d:\n", i+1);
        result = big_num_add(a, b, r);
        printf("%s + %s = %s\n", a, b, result);
        if (i != T-1)
        {
            printf("\n");
        }
    }
    return 0;
}

