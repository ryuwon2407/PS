/**
 * @file 18870.c
 * @brief 18870. 좌표 압축
 * @date 2022-11-20
 * 
 * @text 제한 값이 100만. 제한 시간 2초여서 n^2 알고리즘은 나오면 초과가 나오기때문에 이진 탐색 사용
 *       백만으로 배열 2개를 선언하려니 메모리 부담 될까봐 우선 동적할당.
 */
#include <stdlib.h>
#include <stdio.h>

// 비교
int compare(const void *a, const void *b){
    return *(int*)a - *(int*)b;
}

// 이진탐색
int binary_search(int data[], int n, int key){
    int mid
    ,   low = 0
    ,   high = n - 1;

    while(low <= high){
        mid = (low + high) / 2;
        if(key == data[mid])
            return mid;
        else if(key < data[mid])
            high = mid - 1;
        else if(key > data[mid])
            low = mid + 1;
    }

    return -1; //탐색 실패
}

// 배열 숫자 중복제거
int Integration(int* arr, int N){
    int i
    ,   j = 0;
    
    for(i = 1; i < N; i++){
        if(arr[j] == arr[i]) continue;
        arr[++j] = arr[i];
    }

    return ++j;
}

int main()
{
    int N
    ,   len;

    scanf("%d", &N);
    int *arr = (int*)malloc(sizeof(int) * N);
    int *sub_arr = (int*)malloc(sizeof(int) * N);

    for(int i = 0; i < N; i++){
        scanf("%d", &arr[i]);
        sub_arr[i] = arr[i];
    }
    qsort(sub_arr, N, sizeof(int), compare); //정렬

    len = Integration(sub_arr, N); //중복제거
    for(int i = 0; i < N; i++)
        printf("%d ", binary_search(sub_arr, len, arr[i])); //탐색
    
    free(arr); free(sub_arr);
    return 0;
}