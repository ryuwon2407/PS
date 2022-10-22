#include <stdio.h>

#define _USE_MATH_DEFINES
#include <math.h>

int main()
{
    int R; // 반지름 R

    scanf("%d", &R);
    printf("%lf\n", M_PI * R * R);            // 유클리드 기하학에서의 원의 넓이
    printf("%lf\n", (double)(R * R * 2));     // 택시 기하학에서의 원의 넓이

    return (0);
}


// 택시 기하학에서의 원의 넓이를 처음에 float 형으로 계속 입력했다가 틀림.
// float -> double로 변경하니까 정답.