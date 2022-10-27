"""
 * @file 1271.py
 * @brief 1271. 엄청난 부자2
 * @date 2022-10-27
 * 
 * @text C로는 엄청 많은 문자열 처리가 필요해 파이썬으로 풀이.
 * 
"""
n, m = map(int, input().split())
    
print(n // m)
print(n % m)