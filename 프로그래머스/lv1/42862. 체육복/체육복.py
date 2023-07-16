def solution(n, lost, reserve):
    student = [1] * (n + 1)
    student[0] = 0
    for i in lost:
        student[i] -= 1
    for i in reserve:
        student[i] += 1
    
    for i in range(1,n+1):
        if (student[i] == 0 and student[i-1] == 2):
            student[i] = student[i-1] = 1
        elif (i != n and student[i] == 0 and student[i+1] == 2):
            student[i] = student[i+1] = 1
            
    return sum(1 for value in student if value >= 1)