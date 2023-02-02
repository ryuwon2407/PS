/**
 * @file 27294.c
 * @brief 27294. 몇개고?
 * @date 2023-02-02
 * 
 * @text 
 * 
 */
#include <stdio.h>

int main()
{
    int T
    ,   S;

    scanf("%d %d", &T, &S);
    if(S == 1 || T < 12 || T > 16)
        printf("280");
    else
        printf("320");
    
    return 0;
}