/**
 * @file 1012.c
 * @brief 1012. 유기농 배추
 * @date 2023-02-04
 * 
 * @text 
 * 
 */
#include <stdio.h>

#define MAX 51

int farm[MAX][MAX];
int dx[4] = {1, -1, 0, 0}
,   dy[4] = {0, 0, -1, 1};


void farm_init(){
    for(int i = 0; i < MAX; i++)
        for(int j = 0; j < MAX; j++)
            farm[i][j] = 0;
        
    return;
}

void DFS(int x, int y, int M, int N){
    int nx, ny;
    farm[x][y] = 0;             // 방문한 곳 0

    for(int i = 0; i < 4; i++){ // 상하좌우
        nx = x + dx[i];
        ny = y + dy[i];

        if(nx < 0 || ny < 0 || nx >= M || ny >= N)
            continue;

        if(farm[nx][ny] != 0)
            DFS(nx, ny, M, N);
    }

    return;
}

int main()
{
    int T // 테스트 케이스 갯수
    ,   M // 배추밭의 가로 길이
    ,   N // 배추밭의 세로 길이
    ,   K // 배추의 갯수
    ,   x, y, cnt;

    scanf("%d", &T);
    for(int i = 0; i < T; i++){
        scanf("%d %d %d", &M, &N, &K);
        farm_init(); // 배추밭 초기화
        cnt = 0;

        while(K--){
            scanf("%d %d", &x, &y);
            farm[x][y] = 1;
        }

        // 배추 흰지렁이 탐색 함수
        for(int j = 0; j < M; j++){
            for(int k = 0; k < N; k++){
                if(farm[j][k] != 0){
                    DFS(j, k, M, N);
                    cnt++;
                }
            }
        }

        printf("%d\n", cnt);
    }

    return 0;
}