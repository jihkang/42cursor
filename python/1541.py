import collections


def numeric(strs: str) -> collections:
    num = 0
    for i in strs:
        if '0' <= i <= '9':
            num = num * 10 + int(i)
        else:
            yield num
            num = 0
    yield num


def signs(strs: str) -> collections:
    for i in strs:
        if not i.isdigit():
            yield i


def recursive(arr: [int], arr_sign: [str], used: [bool], ind: int, sum: int) -> int:
    if used[ind] is True:
        return sum
    if arr_sign[ind] == '-':
        used[ind] = True
        return recursive(arr, arr_sign, used, ind + 1, sum - arr[ind + 1])
    if arr_sign[ind] == '+':
        return sum


def solve(arr: [int], arr_sign: [str]) -> int:
    res = 0
    num_len = len(arr)
    used = [False] * (num_len - 1)
    for i in range(num_len):
        if i == num_len - 1:
            continue
        if arr_sign[i] == '-':
            price = recursive(arr, arr_sign, used, i, 0)
            res += arr[i] + price
        else:
            res += arr[i] + arr[i + 1]

    return res


def main():
    strs = input()
    gen = numeric(strs)
    gen_sign = signs(strs)
    arr = list(i for i in gen)
    sign = list(i for i in gen_sign)
    solve(arr, sign)


if __name__ == '__main__':
    main()
