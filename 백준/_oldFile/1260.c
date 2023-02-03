/**
 * @file 1260.c
 * @brief 1260. DFS와 BFS
 * @date 2023-02-01
 * 
 * @text DFS, BFS 인접행렬 방식으로 접근.
 * 
 */
#include <stdio.h>
#include <stdbool.h>

#define MAX 1001

int queue[MAX];
bool graph[MAX][MAX];
bool DFS_flag[MAX];
bool BFS_flag[MAX];

void DFS(int N, int v){
    DFS_flag[v] = true;
    printf("%d ", v);

    for(int i = 1; i <= N; i++)
        if(DFS_flag[i] == false && graph[v][i] == true)
            DFS(N, i);
    
    return;
}

void BFS(int N, int v){
    int pop
    ,   rear  = 0
    ,   front = 0;

    queue[rear++] = v;
    BFS_flag[v] = true;
    printf("%d ", v);
    
    while(front < rear){
        pop = queue[front++];
        for(int i = 1; i <= N; i++)
            if(BFS_flag[i] == false && graph[pop][i] == true){
                printf("%d ", i);

                queue[rear++] = i;
                BFS_flag[i] = true;
            }
    }
}

int main(){
    int N    // 정점의 갯수
    ,   M    // 간선 개수
    ,   V    // 탐색을 시작할 정점 번호
    ,   x, y;// 임시 입력

    scanf("%d %d %d", &N, &M, &V);
    for(int i = 1; i <= M; i++){
        scanf("%d %d", &x, &y);
        graph[x][y] = true;
        graph[y][x] = true;
    }

    DFS(N, V);
    printf("\n");
    BFS(N, V);

    return 0;
}