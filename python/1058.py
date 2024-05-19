import math

n = int(input())

arr = [[1 if j == 'Y' else 0 for j in input()] for _ in range(n)]
for i in range(n):
    for j in range(n):
        if i != j and arr[i][j] == 0:
            arr[i][j] = math.inf

for i in range(n):
    for j in range(n):
        for k in range(n):
            arr[j][k] = min(arr[j][k], arr[j][i] + arr[i][k])
_max = 0
for i in arr:
    cnt = 0
    for j in i:
        if 0 < j < 3:
            cnt += 1
    _max = max(_max, cnt)

print(_max)