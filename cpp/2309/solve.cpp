#include <algorithm>
#include <iostream>

using namespace std;

int *solution(int *input, int sum) {
  int *result = new int[7];
  int cnt = 0;
  for (int i = 0; i < 9; ++i) {
    for (int j = 0; j < 9; ++j) {
      if (!(i == j) && sum - input[i] - input[j] == 100) {
        result[0] = input[i];
        result[1] = input[j];
        for (int k = 0; k < 9; ++k) {
          if (!(k == i || k == j))
          result[cnt++] = input[k];
        }
        return result;
      }
    }
  }
  return result;
}

int main() {
  int arr[9];
  int *result;
  int sum = 0;
  for (int i = 0; i < 9; ++i) {
    cin >> arr[i];
    sum += arr[i];
  }
  result = solution(arr, sum);
  sort(result, result + 7);
  for (int i = 0; i < 7; ++i) {
    cout << result[i] << endl;
  }
  delete result;
  return 0;
}
