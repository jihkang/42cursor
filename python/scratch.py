
n, a, b = map(int, input().split())

if a > b:
    tmp = a
    a = b
    b = tmp
cnt = 1
while True:
    if (a % 2 == 1 and a + 1 == b) or a == b:
        print(cnt)
        break
    a = int((a + 1) / 2)
    b = int((b + 1) / 2)
    cnt += 1