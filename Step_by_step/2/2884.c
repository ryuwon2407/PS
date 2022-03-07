#include <stdio.h>

int main()
{
    int h,m;

    scanf("%d %d", &h, &m);
    
    if (m - 45 < 0)
    {
        m = m + 60 - 45;
        h -= 1;
    }
    else
        m = m - 45;
    if (h < 0)
        h = 23;
    printf("%d %d\n", h, m);

    return 0;
}