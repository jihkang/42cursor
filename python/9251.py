from sys import stdin


def solve(arr, arr2):
    ret_len = 0
    dp = [[0 for _ in range(len(arr2))] for _ in range(len(arr))]
    for i in range(1, len(arr)):
        for j in range(1, len(arr2)):
            if arr2[j] == arr[i]:
                dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1)
            else:
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1])
            ret_len = max(ret_len, dp[i][j])
    # print(dp)
    return ret_len


def main():
    arr = ' ' + stdin.readline().rstrip()
    arr2 = ' ' + stdin.readline().rstrip()
    print(solve(arr, arr2))


if __name__ == '__main__':
    main()
