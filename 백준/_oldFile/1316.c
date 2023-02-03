#include <stdio.h>
#include <string.h>

int main()
{
    int group_word_count = 0;
    int num, word_len, check;
    char alphabet[26];
    char str[101];

    scanf("%d", &num);
    for(int i = 0; i < num ; i++)
    {
        for(int j = 0; j < 26; j++) alphabet[j] = 0;
        scanf("%s", str);
        word_len = strlen(str);
        alphabet[str[0] - 97]++;
        for(check = 0; check < word_len; check++)
        {
            if(str[check] != str[check + 1] && str[check + 1] != 0)
            {
                if(alphabet[str[check + 1] - 97] != 0)
                    break;
                else
                    alphabet[str[check] - 97]++;
            }
        }
        if(check == word_len)
            group_word_count++;
    }
    printf("%d\n", group_word_count);
}