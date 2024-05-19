
while True:
    arr = [int(i) for i in input()]
    if len(arr) == 1 and arr[0] == 0:
        break
    n = len(arr)
    flag = False
    for i in range(int(n / 2)):
        if arr[i] != arr[n - i - 1]:
            flag = True
            break
    if flag:
        print('no')
    else:
        print('yes')