"""
logic
a b c d e f g h i j ....
starting 0, n
checking first in array, and next array first,

"""
from sys import stdin


read = stdin.readline


def main():
    n, d, k, c = map(int, read().split())
    arr = [0] * (n + 1)
    check = [0] * (d + 1)
    cnt = 1
    check[c] = 1
    for i in range(n):
        arr[i] = int(read())
    for i in range(k):
        check[arr[i]] += 1
        if check[arr[i]] == 1:
            cnt += 1
    _max = cnt
    for i in range(n - 1):
        check[arr[i]] -= 1
        if check[arr[i]] == 0:
            cnt -= 1
        check[arr[(i + k) % n]] += 1
        if check[arr[(i + k) % n]] == 1:
            cnt += 1
        _max = max(_max, cnt)
    print(_max)


if __name__ == '__main__':
    main()
