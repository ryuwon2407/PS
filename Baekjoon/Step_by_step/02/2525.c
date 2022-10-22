#include <stdio.h>

int main()
{
    int hrs, min;
    int cook_time;

    scanf("%d %d\n%d", &hrs, &min, &cook_time);
    
    hrs += cook_time / 60;
    min += cook_time % 60;

    if (min >= 60)
    {
        hrs += 1;
        min -= 60;
    }
    if (hrs > 23)
        hrs = hrs % 24;
    
    printf("%d %d\n",hrs, min);
    return 0;
}