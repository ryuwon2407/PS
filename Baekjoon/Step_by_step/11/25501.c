/**
 * @file 25501.c
 * @brief 25501. 재귀의 귀재
 * @date 2022-11-22
 * 
 * @text 다 주어져서 쉽게 풀었다
 * 
 */

#include <stdio.h>
#include <string.h>

#define STR_MAX 1001

int cnt;

int recursion(const char *s, int l, int r){
    if(l >= r) return 1;
    else if(s[l] != s[r]) return 0;
    else{
        cnt++;
        return recursion(s, l+1, r-1);
    }
}

int isPalindrome(const char *s){
    return recursion(s, 0, strlen(s)-1);
}

int main(){
    int  T
    ,    *num
    ,    result;
    char temp[STR_MAX];

    scanf("%d", &T);
    for(int i = 0; i < T; i++){
        scanf("%s", temp);

        cnt = 1;
        result = isPalindrome(temp);
        printf("%d %d\n", result, cnt);
    }

    return 0;
}