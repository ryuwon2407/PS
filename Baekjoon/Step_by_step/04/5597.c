#include <stdio.h>

#define INPUT_MAX   28
#define STUDENT_MAX 30

int student[STUDENT_MAX];

int main()
{
    int temp
    ,   i = INPUT_MAX;
    
    while(i--){
        scanf("%d", &temp);
        student[temp - 1]++;
    }

    for(i = 0; i < STUDENT_MAX; i++)
        if(student[i] == 0)
            printf("%d\n", i + 1);

    return 0;
}