#include <stdio.h>

int main()
{
    int x[3], y[3];

    scanf("%d %d", &x[0], &y[0]);
    scanf("%d %d", &x[1], &y[1]);
    scanf("%d %d", &x[2], &y[2]);

    printf("%d %d", x[0] ^ x[1] ^ x[2], y[0] ^ y[1] ^ y[2]);
    return 0;
}


// # 기존 내 코드
// int main()
// {
//     int x[3], y[3];
//     int x_count = 0, y_count = 0;
//     int x_result, y_result;

//     for(int i = 0; i < 3; i++)
//     {
//         scanf("%d %d", &x[i], &y[i]);
//         if(x[0] == x[i])
//             x_count++;
//         else
//             x_result = x[i];
//         if(y[0] == y[i])
//             y_count++;
//         else
//             y_result = y[i];
//     }
//     if(x_count != 2)
//         x_result = x[0];
//     if(y_count != 2)
//         y_result = y[0];
//     printf("%d %d\n", x_result, y_result);
    
//     return 0;
// }