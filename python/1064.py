import math


def dist(x1, y1, x2, y2):
    return math.sqrt((x1 - x2) ** 2 + (y1 - y2) ** 2)


def solve(x1, y1, x2, y2, x3, y3):
    if x2 == x1:
        grad_a = math.inf
    else:
        grad_a = (y2 - y1) / (x2 - x1)
    if x1 == x3:
        grad_b = math.inf
    else:
        grad_b = (y3 - y1) / (x3 - x1)
    if grad_a == grad_b:
        return None
    return True


def main():
    x1, y1, x2, y2, x3, y3 = map(int, input().split())
    res = solve(x1, y1, x2, y2, x3, y3)
    if res is None:
        print("-1.0")
        return
    a = dist(x1, y1, x2, y2)
    b = dist(x1, y1, x3, y3)
    c = dist(x2, y2, x3, y3)
    max_l = max(a + b, b + c, a + c)
    min_l = min(a + b, b + c, a + c)
    print(f"{round((max_l - min_l) * 2, 16)}")


if __name__ == '__main__':
    main()
