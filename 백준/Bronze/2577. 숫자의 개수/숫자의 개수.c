#include <stdio.h>
#include <string.h>

int main()
{
    int num_1, num_2, num_3;
    char str[10];
    int num[10] = { 0, };

    scanf("%d\n%d\n%d", &num_1, &num_2, &num_3);
    sprintf(str, "%d", num_1 * num_2 * num_3);
    
    for (int i = 0; str[i] != 0; i++)
    {
        switch (str[i])
        {
            case '0':
                num[0]++;
                break;
            case '1':
                num[1]++;
                break;
            case '2':
                num[2]++;
                break;
            case '3':
                num[3]++;
                break;
            case '4':
                num[4]++;
                break;
            case '5':
                num[5]++;
                break;
            case '6':
                num[6]++;
                break;
            case '7':
                num[7]++;
                break;
            case '8':
                num[8]++;
                break;
            case '9':
                num[9]++;
                break;
        }
    }
    for(int i = 0; i < 10; i++)
        printf("%d\n",num[i]);
    return 0;
}