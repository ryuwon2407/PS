#include <stdio.h>

typedef struct s_people
{
    int weight;
    int height;
}t_people;

t_people list[50];

int main()
{
    int N        // 사람 수
    ,   rank = 1;// 등수
    t_people temp;

    
    scanf("%d", &N);
    for(int i = 0; i < N; i++)
        scanf("%d %d", list[i].weight, list[i].height);

    for(int i = 0; i < N; i++)
    {
        
    }
}