#include <stdio.h>
#include <string.h>

#define MAX 10001

void str_plus_print(char num[2][MAX], int big_len, int small_len, int check);

int main()
{
    char    num[2][MAX];
    int     num_1_len, num_2_len;
    int     check;

    scanf("%s %s", num[0], num[1]);
    num_1_len = strlen(num[0]);
    num_2_len = strlen(num[1]);

    check = num_1_len > num_2_len ? 0 : 1;

    if(check == 0)
        str_plus_print(num, num_1_len, num_2_len, check);
    else if (check == 1)
        str_plus_print(num, num_2_len, num_1_len, check);
    
    return 0;
}

void str_plus_print(char num[2][MAX], int big_len, int small_len, int check)
{
    char result[MAX];
    for(int i = 0; i <= MAX; i++) result[i] = 0;

    for(int i = big_len; i != 0; i--)
    {
       if(small_len != 0)
       {
           if(result[i] + (num[check][i - 1] - '0') + (num[!(check)][small_len - 1] - '0') >= 10)
           {
                result[i - 1] += 1;
                result[i] = (result[i] + (num[check][i - 1] - '0') + (num[!(check)][small_len - 1] - '0')) % 10;
           }
           else
                result[i] = result[i] + (num[check][i - 1] - '0') + (num[!(check)][small_len - 1] - '0');
           small_len--;
       }
       else
       {
           if(result[i] + (num[check][i - 1] - '0') >= 10)
           {
               result[i - 1] += 1;
               result[i] = (result[i] + (num[check][i - 1] - '0')) % 10;
           }
           else
                result[i] = result[i] + (num[check][i - 1] - '0');
       }
    }

    if(result[0] == 0)
        for(int i = 1; i <= big_len; i++) printf("%c", result[i] + '0');
    else
        for(int i = 0; i <= big_len; i++) printf("%c", result[i] + '0');
    printf("\n");
}

// #include <stdio.h>
// #include <string.h>

// #define MAX 10001

// int main()
// {
//     int     num_1_size, num_2_size;
//     char    num_1[MAX], num_2[MAX];
//     char    result[MAX];
//     result[0] = 'x';
//     for(int i = 1; i <= MAX; i++) result[i] = 0;
    
//     scanf("%s %s", num_1, num_2);
//     num_1_size = strlen(num_1);
//     num_2_size = strlen(num_2);

//     if(num_1_size >= num_2_size)
//     {
//         for(int i = num_2_size; i != -1; i--)
//         {
//             if(result[i] + (num_1[num_1_size] - '0') + (num_2[i] - '0') >= 10)
//             {
//                 result[num_1_size] = ((num_1[num_1_size] - '0') + (num_2[i] - '0')) / 10;
//                 result[num_1_size + 1] = ((num_1[num_1_size] - '0') + (num_2[i] - '0')) % 10;
//             }
//             else
//                 result[num_1_size + 1] = (num_1[num_1_size] - '0') + (num_2[i] - '0');
//         }
//         if(result[0] == 'x')
//             for(int i = 1; i <= num_1_size + 1; i++) printf("%c", result[i] + '0');
//         else
//             for(int i = 0; i <= num_1_size + 1; i++) printf("%c", result[i] + '0');
//     }
//     else
//     {
//         for(int i = num_1_size; i != -1; i--)
//         {
//             if(result[i] + (num_1[i] - '0') + (num_2[num_2_size] - '0') >= 10)
//             {
//                 result[num_2_size] = ((num_1[i] - '0') + (num_2[num_2_size] - '0')) / 10;
//                 result[num_2_size + 1] = ((num_1[i] - '0') + (num_2[num_2_size] - '0')) % 10;
//             }
//             else
//                 result[num_2_size + 1] = (num_1[i] - '0') + (num_2[num_2_size] - '0');
//         }
//         if(result[0] == 'x')
//             for(int i = 1; i <= num_2_size + 1; i++) printf("%c", result[i] + '0');
//         else
//             for(int i = 0; i <= num_2_size + 1; i++) printf("%c", result[i] + '0');
//     }
// }

