from collections import deque


# def brute(arr: [int], n: int):

def main():
    try:
        n = int(input())
        arr = [(int(v), i) for i, v in enumerate(input().split())]
        arr.sort()
        res = [0] * n
        for i in range(n):
            res[arr[i][1]] = i
        for i in range(n):
            print(res[i], end= ' ')
        # brute(arr, n)
    except KeyboardInterrupt:
        return


if __name__ == '__main__':
    main()