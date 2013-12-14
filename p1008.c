/*
The highest building in our city has only one elevator. A request list is made up with N positive numbers. The numbers denote at which floors the elevator will stop, in specified order. It costs 6 seconds to move the elevator up one floor, and 4 seconds to move down one floor. The elevator will stay for 5 seconds at each stop.

For a given request list, you are to compute the total time spent to fulfill the requests on the list. The elevator is on the 0th floor at the beginning and does not have to return to the ground floor when the requests are fulfilled.
*/

#include <stdio.h>

int main(int argc, char const *argv[])
{
    int N, f, p, t, i;

    while (1)
    {
        scanf("%d", &N);
        if (N == 0)
        {
            break;
        }

        p = 0;
        t = 0;
        for (i = 0; i < N; ++i)
        {
            scanf("%d", &f);
            if (f > p)
            {
                // printf("up %d to %d\n", p, f);
                t += 6 * (f - p) + 5;
            }
            else
            {
                // printf("down %d to %d\n", f, p);
                t += 4 * (p - f) + 5;
            }
            p = f;
        }
        printf("%d\n", t);
        
    }
    return 0;
}

