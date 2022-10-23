#include <stdio.h>

int main(){
    long long N1, N2;

    scanf("%lld %lld", &N1, &N2);
    printf("%lld\n", N1 >= N2 ? N1 - N2 : N2 - N1);

    return 0;
}


// 정수 범위를 제대로 확인하지 않아 틀렸었음.
