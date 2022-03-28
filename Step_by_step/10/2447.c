#include <stdio.h> 

void recursive_star(int N, int col, int row);

int main(void) 
{ 
    int N    // N의 패턴
    ,   col  // 열
    ,   row; // 행

    scanf("%d", &N); 
    for (col = 0; col < N; col++) 
    { 
        for (row = 0; row < N; row++) 
            recursive_star(N, col, row); 
        printf("\n"); 
    } 

    return (0); 
} 

void recursive_star(int N, int col, int row)
{ 
    if ((col / N) % 3 == 1 && (row / N) % 3 == 1) 
        printf(" "); 
    else 
        if (N / 3 == 0) 
            printf("*"); 
        else 
            recursive_star(N / 3, col, row); 
}