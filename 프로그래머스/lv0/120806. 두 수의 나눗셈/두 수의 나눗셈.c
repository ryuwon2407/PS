#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int num1, int num2) {
    int answer = ((float)num1 / (float)num2) * 1000;
    return answer;
}