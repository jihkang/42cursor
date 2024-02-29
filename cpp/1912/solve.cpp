
#include <iostream>
#include <vector>

using namespace std;

#define MIN -2147483648

int solution(int *input, int n) {
  int result = MIN;
  int sum = 0;
  for (int i = 0; i < n; ++i) {
    int temp_sum = sum + input[i];
    if (temp_sum > input[i]) {
      sum = temp_sum;
    } else {
      sum = input[i];
    }
    if (sum > result) {
      result = sum;
    }
  }
  return result;
}

int main() {
  int n;
  cin >> n;
  int *input = new int[n];

  for (int i = 0; i < n; ++i) {
    cin >> input[i];
  }
  cout << solution(input, n);
  return 0;
}