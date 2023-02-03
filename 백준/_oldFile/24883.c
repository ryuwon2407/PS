#include <stdio.h>

int main()
{
    char alhpa;

    scanf("%c", &alhpa);
    if(alhpa == 'N' || alhpa == 'n')
        printf("Naver D2\n");
    else
        printf("Naver Whale\n");
    
    return (0);
}