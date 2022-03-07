#include <stdio.h>

int main()
{
    int students, subjects;
    int score[1000] = { 0, };
    double ave, count;
    
    scanf("%d", &students);
    for (int i = 0; i < students; i++)
    {
        ave = 0;
        count = 0;
        scanf("%d", &subjects);

        for (int j = 0; j < subjects; j++)
        {
            scanf("%d", &score[j]);
            ave += score[j];
        }
        ave = ave / subjects;
        for (int j = 0; j < subjects; j++)
            if (ave < score[j])
                count++;
        printf("%.3f%%\n", (double)(count / subjects) * 100);
    }
}