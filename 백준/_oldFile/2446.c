/**
 * @file 2446.c
 * @brief 2446. 별 찍기 - 9
 * @date 2022-10-31
 * 
 * @text for문 2개를 통해 위 아래 출력
 * 
 */
#include <stdio.h>

int main() 
{
	int N;

	scanf("%d", &N);
	for (int i = 1; i <= N; i++) 
    {
		for (int j = i-1; j > 0; j--) 
            printf(" ");
		for (int k = (2 * N) - (i * 2) + 1; k > 0; k--) 
            printf("*");
		printf("\n");
	}
	for (int i = N-1; i > 0; i--) 
    {
		for (int j = i - 1; j > 0; j--) 
            printf(" ");
		for (int k = (2 * N) - (2 * i) + 1; k > 0; k--) 
            printf("*");
		printf("\n");
	}

	return 0;
}