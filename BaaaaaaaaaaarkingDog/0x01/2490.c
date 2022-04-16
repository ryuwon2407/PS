#include <stdio.h>

int main()
{
    int Yut[4]
    ,   zero_count;

    while(scanf("%d %d %d %d", &Yut[0], &Yut[1], &Yut[2], &Yut[3]) != EOF)
    {
        zero_count = 0;
        for (int i = 0; i < 4; i++)
            if(Yut[i] == 0)
                zero_count++;
        
        switch (zero_count)
        {
            case 0:
                printf("E\n");
                break;
            case 1:
                printf("A\n");
                break;
            case 2:
                printf("B\n");
                break;
            case 3:
                printf("C\n");
                break;
            case 4:
                printf("D\n");
                break;
        }
    }

    return (0);
}