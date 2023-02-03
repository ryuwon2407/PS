#include <stdio.h>
#include <math.h>

#define A 1
#define B 2
#define C 3

void recursive_hanoi(int N, int from, int to, int temp);
void hanoi_move(int from, int to);

int main()
{
    int N; // 원판의 개수

    scanf("%d", &N);
    printf("%d\n", (int)pow(2, N) - 1);

    recursive_hanoi(N, A, C, B);

    return (0);
}

void recursive_hanoi(int N, int from, int to, int temp)
{
    if (N == 1) // 탈출구문
        hanoi_move(from, to);
    else
    {
        recursive_hanoi(N - 1, from, temp, to);
        hanoi_move(from, to);
        recursive_hanoi(N - 1, temp, to, from);
    }
}

void hanoi_move(int from, int to)
{
    printf("%d %d\n", from, to);
}