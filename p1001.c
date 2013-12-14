/*
In this problem, your task is to calculate SUM(n) = 1 + 2 + 3 + ... + n.
*/

#include <stdio.h>

int main(int argc, char const *argv[])
{
    int n;
    while (scanf("%d", &n) > 0) {
        printf("%d\n\n", (1 + n) * n / 2);
    }
    return 0;
}
