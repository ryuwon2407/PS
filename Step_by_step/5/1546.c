#include <stdio.h>

int main()
{
    int subject;
    float max = 0, ave = 0;
    
    scanf("%d", &subject);
    float score[subject];
    for(int i = 0; i < subject; i++)
    {
        scanf("%f", &score[i]);
        if(max < score[i])
            max = score[i];
    }
    for(int i = 0; i < subject; i++)
        ave += score[i] / max * 100;
    ave = ave / subject;
    printf("%g\n", ave);
}