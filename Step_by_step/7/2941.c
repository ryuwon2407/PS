#include <stdio.h>

int main()
{
    int alphabet_count = 0;
    char str[100];
    
    scanf("%s", str);
    for(int i = 0; str[i]; i++)
    {
        if(str[i] == '=')
        {
           if(str[i - 1] == 'c')
                alphabet_count--; 
           if(str[i - 1] == 's') 
                alphabet_count--; 
           if(str[i - 1] == 'z') 
            { 
                alphabet_count--; 
                if(str[i - 2] == 'd') 
                    alphabet_count--; 
            } 
        }
        if(str[i] == '-') 
        {
            if(str[i-1] == 'c')
               alphabet_count--;
            if(str[i-1] == 'd')
              alphabet_count--; 
        } 
        if(str[i] == 'j') 
        {
            if(str[i-1] == 'l') 
                alphabet_count--; 
            if(str[i-1] == 'n') 
                alphabet_count--; 
        } 
        alphabet_count++;
    }
    printf("%d\n", alphabet_count);
}