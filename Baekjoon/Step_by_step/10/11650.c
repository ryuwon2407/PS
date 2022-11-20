/**
 * @file 11650.c
 * @brief 11650. 좌표 정렬하기
 * @date 2022-11-20
 * 
 * @text qsort를 사용하여 compare 함수에서 x좌표가 같은 경우 y좌표도 비교하도록 작성
 * 
 */
#include <stdlib.h>
#include <stdio.h>

#define MAX 100000

typedef struct xy_array
{
    int x;
    int y;
}array;

array num[MAX];

int compare(const void* n1, const void* n2){
    array* A = (array *)n1;
    array* B = (array *)n2;

    if(A->x > B->x)
        return 1;
    else if(A->x < B->x)
        return -1;
    else{
        if(A->y > B->y)
            return 1;
        else if(A->y < B->y)
            return -1;
        else
            return 0;
    }
}

int main(){
    int N;
    
    scanf("%d", &N);
    for (int i = 0; i < N; i++){
        scanf("%d %d", &num[i].x, &num[i].y);
    }

    qsort(num, N, sizeof(array), compare);
    for(int i = 0; i < N; i++){
        printf("%d %d\n", num[i].x, num[i].y);
    }

    return 0;
}