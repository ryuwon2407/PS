#include <stdio.h>

int main()
{
    int test_num;
    int result, score;

    scanf("%d", &test_num);
    char OX[test_num];
    for (int i = 0; i < test_num; i++)
    {
        result = 0;
        score = 1;
        scanf("%s", OX);
        for(int j = 0; OX[j] != 0; j++)
        {
            if(OX[j] == 'O')
            {
                result += score;
                score++;
            }
            else
                score = 1;
        }
        printf("%d\n", result);
    }
    return 0;
}