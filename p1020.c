/*
Given a string containing only 'A' - 'Z', we could encode it using the following method: 
1. Each sub-string containing k same characters should be encoded to "kX" where "X" is the only character in this sub-string.
2. If the length of the sub-string is 1, '1' should be ignored.
*/

#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    int N, i, n;
    char str[10000], pre, *p;
    scanf("%d", &N);
    for (i = 0; i < N; ++i)
    {
        scanf("%s", str);
        p = str;
        pre = '\0';
        n = 0;
        while ((*p) != '\0') {
            if ((*p) == pre)
            {
                n++;
            }
            else // char change
            {
                if (n > 1)
                {
                    printf("%d", n);
                }
                printf("%c", *p);
                n = 1;
            }
            pre = (*p);
            p++;
        }
        if (n > 1)
        {
            printf("%d", n);
        }
        printf("\n");
    }
    return 0;
}

