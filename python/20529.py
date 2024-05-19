from collections import deque


def calc(a, b):
    cnt = 0
    for i in range(4):
        if a[i] != b[i]:
            cnt += 1
    return cnt


def brute_force(a, deq, n, visited, c=0):
    _min = 100000

    if c == 3:
        return calc(a[deq[0]], a[deq[1]]) + \
            calc(a[deq[0]], a[deq[2]]) + calc(a[deq[1]], a[deq[2]])
    for i in range(n):
        if visited[i] != 0:
            continue
        visited[i] = 1
        deq[c] = i
        _min = min(brute_force(a, deq, n, visited, c + 1), _min)
        visited[i] = 0
    return _min


T = int(input())
while T > 0:
    N = int(input())
    T -= 1
    arr = input().split()
    remain_arr = []
    dicts = {
    }
    selects = [0] * 3
    flag = False
    for i in arr:
        if i in dicts:
            dicts[i] += 1
            if dicts[i] >= 3:
                flag = True
                break
        else:
            dicts[i] = 1
    if flag:
        print(0)
        continue
    for i in dicts.keys():
        for j in range(dicts[i]):
            remain_arr.append(i)
    visited = [0] * len(remain_arr)
    # print(remain_arr)
    # print(len(remain_arr))
    print(brute_force(remain_arr, selects, len(remain_arr), visited))
