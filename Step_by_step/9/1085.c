#include <stdio.h>

#define MAX 1000

int main()
{
    int x, y, w, h;
    int x_min = MAX, y_min = MAX;

    scanf("%d %d %d %d", &x, &y, &w, &h);
    if(x < w - x)
        x_min = x;
    else
        x_min = w - x;
    if(y < h - y)
        y_min = y;
    else
        y_min = h - y;

    printf("%d\n", x_min > y_min ? y_min : x_min);
    return 0;
}