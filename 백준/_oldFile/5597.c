/**
 * @file 5597.c
 * @brief 5597. 과제 안 내신 분..?
 * @date 2022-10-28
 * 
 * @text 배열에서 단순히 없는 것만 뽑아내면 되지만.. 밑에 for문에서 MAX 값을 잘못 줘서 한번 틀렸었다.
 * 
 */
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