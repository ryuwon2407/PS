#include <stdio.h>

int main()
{     
	int line_check = 1, // 몇번째 라인인지 확인하는 변수
        line_num = 1;   // 라인 넘버
    int X;              // 입력 값

	scanf("%d", &X);
	while(X > line_check)
		line_check += ++line_num;
    
	if (line_num % 2 == 0)
		printf("%d/%d", line_num - (line_check - X), 1 + (line_check - X));
	else
		printf("%d/%d", 1 + (line_check - X), line_num - (line_check - X));
		
	return 0;
}

//  1   2   6   7   15  16      1/1   1/2   1/3   1/4   1/5   1/6
//  3   5   8   14  17          2/1   2/2   2/3   2/4   2/5
//  4   9   13  18              3/1   3/2   3/3   3/4
//  10  12  19                  4/1   4/2   4/3   
//  11  20                      5/1   5/2
//  21                          6/1