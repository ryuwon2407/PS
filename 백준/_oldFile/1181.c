/**
 * @file 1181.c
 * @brief 1181. 단어 정렬
 * @date 2022-11-21
 * 
 * @text 정렬과 중복제거만 신경쓰면 되서 쉽게 풀었다
 * 
 */
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define STR_MAX 50
#define WORD_MAX 20000

typedef struct WORD{
    char str[STR_MAX];
    int len;
}WORD;

WORD arr[WORD_MAX];

int compare(const void* n1, const void* n2){
    WORD* A = (WORD *)n1;
    WORD* B = (WORD *)n2;

    return A->len > B->len ? 1 : A->len < B-> len ? -1 : strcmp(A->str, B->str);
}

int main()
{
    int N
    ,   check = 0;

    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        scanf("%s", arr[i].str);
        arr[i].len = strlen(arr[i].str);
    }
    qsort(arr, N, sizeof(WORD), compare);           // 정렬

    for(int i = 1; i <= N; i++){                     // 중복제거
        if(strcmp(arr[check].str, arr[i].str)){
            printf("%s\n", arr[check].str);
            check = i;
        }
    }
    
    return 0;
}