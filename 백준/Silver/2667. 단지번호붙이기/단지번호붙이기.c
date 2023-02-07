/**
 * @file 2667.c
 * @brief 2667. 단지번호붙이기
 * @date 2023-02-06
 * 
 * @text DFS를 활용한 풀이
 * 
 */
#include <stdlib.h>
#include <stdio.h>

#define MAX 25
#define EL_MAX 625

int map[MAX][MAX];
int result[EL_MAX];
int dx[4] = {1, -1, 0, 0}
,   dy[4] = {0, 0, -1, 1};

int compare(const void *a, const void *b)
{
    int num1 = *(int *)a;
    int num2 = *(int *)b;

    if (num1 < num2)
        return -1;
    else if (num1 > num2) 
        return 1;
    else
        return 0;
}

void DFS(int x, int y, int N, int *cnt){
    int nx, ny;
    map[x][y] = 0;         

    for(int i = 0; i < 4; i++){
        nx = x + dx[i];
        ny = y + dy[i];

        if(nx < 0 || ny < 0 || nx >= N || ny >= N)
            continue;

        if(map[nx][ny] != 0){
            DFS(nx, ny, N, cnt);
            (*cnt)++;
        }
    }

    return;
}

int main()
{
    int N
    ,   cnt
    ,   size = 0;

    scanf("%d", &N);
    for(int x = 0; x < N; x++)
        for(int y = 0; y < N; y++)
            scanf("%1d", &map[x][y]);
    
    for(int x = 0; x < N; x++){
        for(int y = 0; y < N; y++){
            cnt = 1;
            if(map[x][y] != 0){
                DFS(x, y, N, &cnt);
                result[size++] = cnt;
            }
        }
    }

    qsort(result, size, sizeof(int), compare);
    printf("%d\n", size);
    for(int i = 0; i < size; i++)
        printf("%d\n", result[i]);

    return 0;
}