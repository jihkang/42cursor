#include <iostream>

int getSumLine(int value) {
    int sum = value;
    while (value > 0) {
        sum += value % 10;
        value /= 10;
    }
    return sum;
}

int solution(int value) {
    std::cout << value << std::endl;
    for (int i = 1; i < value; ++i) {
        int result = getSumLine(i);
        // std::cout << i << ": " << result << std::endl;
        if (result == value) {
            return (i);
        }
    }
    return 0;
}

int main()
{
    int value;
    std::cin >> value;
    std::cout << solution(value);
    return 0;
}