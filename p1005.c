/*
A number sequence is defined as follows:
    f(1) = 1, f(2) = 1, f(n) = (A * f(n - 1) + B * f(n - 2)) mod 7.
Given A, B, and n, you are to calculate the value of f(n).
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    int A, B, n, f1, f2, fn, i;
        int g[7][7], a, b;

    
    while (1) {
        scanf("%d %d %d", &A, &B, &n);
        if (A == 0 && B == 0 && n == 0)
        {
            break;
        }


        if (n == 1 || n == 2)
        {
            return 1;
        }

        // init table
        for (a = 0; a < 7; ++a)
        {
            for (b = 0; b < 7; ++b)
            {
                g[a][b] = (A*a + B*b) % 7;
                // printf("(%d*%d + %d*%d) %% 7 = %d\n", A, a ,B ,b, g[a][b]);
            }
        }

        f1 = f2 = 1;
        for (i = 3; i <= n; ++i)
        {
            fn = g[f1][f2];
            // printf("f(%d) = (%d*%d + %d*%d) %% 7 = %d\n", i, A, f1 ,B ,f2, fn);

            f2 = f1;
            f1 = fn;
        }
        printf("%d\n", fn);
    }
    return 0;
}

