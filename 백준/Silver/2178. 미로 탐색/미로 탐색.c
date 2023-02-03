/**
 * @file 2178. 미로탐색
 * @brief 
 * @date 2023-02-04
 * 
 * @text 2차원에서 이동을 구현하는 것에 대해 좀 많이 오래걸림.
 * 
 */
#include <stdbool.h>
#include <stdio.h>

#define X 0
#define Y 1
#define MAX 101
#define CASEMAX 10001

int map[MAX][MAX];
int q[CASEMAX][2];

void bfs(int n, int m){
    int x, y
    ,   nx, ny
    ,   front = 0
    ,   rear  = 1
    ,   dx[4] = {1, -1, 0, 0}
    ,   dy[4] = {0, 0, -1, 1};    // 동서남북
    
    q[front][X] = q[front][Y] = 1;// 초기값 세팅

    while(front < rear){
        x = q[front][X];
        y = q[front][Y];
        front++;

        // 상하좌우 탐색
        for(int i = 0; i < 4; i++){
            // 이동
            nx = x + dx[i];
            ny = y + dy[i];

            // 길X or 범위 벗어나는 경우 
            if(nx < 1 || ny < 1 || nx > n || ny > m || map[nx][ny] != 1)
                continue;
            
            map[nx][ny] = map[x][y] + 1;

            q[rear][X] = nx;
            q[rear][Y] = ny;
            rear++;
        }
    }

    printf("%d", map[n][m]);
}

int main()
{
    int N    // x
    ,   M    // y
    ,   temp;

    scanf("%d %d", &N, &M);
    for(int i = 1; i <= N; i++)
        for(int j = 1; j <= M; j++)
            scanf("%1d", &map[i][j]);
        
    bfs(N, M);

    return 0;
}