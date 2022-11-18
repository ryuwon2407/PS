#include <stdio.h>

int main()
{
    char str[16];
    int second = 0;
    
    scanf("%s", str);
    for(int i = 0; str[i]; i++)
    {
        if(str[i] == 'A' || str[i] == 'B' || str[i] == 'C')
            second += 3;
        else if(str[i] == 'D' || str[i] == 'E' || str[i] == 'F')
            second += 4;
        else if(str[i] == 'G' || str[i] == 'H' || str[i] == 'I')
            second += 5;
        else if(str[i] == 'J' || str[i] == 'K' || str[i] == 'L')
            second += 6;
        else if(str[i] == 'M' || str[i] == 'N' || str[i] == 'O')
            second += 7;
        else if(str[i] == 'P' || str[i] == 'Q' || str[i] == 'R' || str[i] == 'S')
            second += 8;
        else if(str[i] == 'T' || str[i] == 'U' || str[i] == 'V')
            second += 9;
        else if(str[i] == 'W' || str[i] == 'X' || str[i] == 'Y' || str[i] == 'Z')
            second += 10;
    }
    printf("%d\n", second);
}