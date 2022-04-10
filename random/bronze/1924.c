#include <stdio.h>

int main()
{
    int x, y
    ,   sum = 0
    ,   month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    const char *days[7] = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};

    scanf("%d %d", &x, &y);
    for(int i = 1; i < x; i++)
        sum += month[i - 1];
    
    printf("%s\n", days[(sum + y) % 7]);

    return (0);
}