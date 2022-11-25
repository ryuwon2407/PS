/**
 * @brief 10039. 평균 점수
 * 
 * @return int 
 */
int main()
{
    int temp
    ,   sum  = 0;

    for (int i = 0; i < 5; i++)
    {
        scanf("%d", &temp);
        if(temp < 40)
            sum += 40;
        else
            sum += temp;
    }

    printf("%d\n", sum / 5);
    return 0;
}