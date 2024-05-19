def main():
    int(input())
    arr = list(map(int, input().split()))
    n = int(input())
    min_tmp = 0
    max_tmp = 10000000
    for i in arr:
        if min_tmp <= i <= n:
            min_tmp = i
        if max_tmp >= i >= n:
            max_tmp = i
    if min_tmp == max_tmp:
        print(0)
        return
    cnt = 0
    for i in range(min_tmp + 1, n + 1):
        cnt += (max_tmp - n - int(i == n))
    print(cnt)


if __name__ == '__main__':
    main()
