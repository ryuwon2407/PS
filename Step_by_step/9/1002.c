#include <stdio.h>
#include <math.h>

int main()
{
    int     x_1, x_2;
    int     y_1, y_2;
    int     r_1, r_2;
    int     testcase_num;
    double  point_to_point, compare;

    scanf("%d", &testcase_num);
    for(int i = 0; i < testcase_num; i++)
    {
        scanf("%d %d %d %d %d %d", &x_1, &y_1, &r_1, &x_2, &y_2, &r_2);
        point_to_point = sqrt(pow(x_2 - x_1, 2) + pow(y_2 - y_1, 2));
        compare = r_1 > r_2 ? r_1 - r_2: r_2 - r_1;

        if(x_1 == x_2 && y_1 == y_2 && r_1 == r_2)
            printf("-1\n");
        else if(compare < point_to_point && point_to_point < r_1 + r_2)
            printf("2\n");
        else if(compare == point_to_point || point_to_point == r_1 + r_2)
            printf("1\n");
        else
            printf("0\n");
    }
    return (0);
}

// 계속 point_to_point, compare 변수를 int형으로 지정해두고 있었음.
// int형이라 소수점 단위를 계산이 무시되어 값이 다르게 출력됨.
// double로 수정하니 통과.
