#include <stdio.h>

int main() 
{
	int N;

	scanf("%d", &N);
    
    //앞
	for (int i = 1; i <= N; i++) 
    {
		for (int j = N - i; j > 0; j--)
            printf(" ");
		for (int k = (2 * i) - 1; k > 0; k--)
            printf("*");
		printf("\n");
	}

    //뒤
	for (int i = N - 1; i > 0; i--) 
    {
		for (int j = N - i; j > 0; j--)
            printf(" ");
		for (int k = (2 * i) - 1; k > 0; k--)
            printf("*");
		printf("\n");
	}

	return (0);
}