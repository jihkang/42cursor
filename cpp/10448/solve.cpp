#include <iostream>

using namespace std;
int triangleNumbers[46];
void settingTriangleNumber() {
  for (int i = 1; i <= 45; ++i) {
    triangleNumbers[i - 1] = i * (i + 1) / 2;
  }
}

bool solve(int find, int sum, int idx) {
  if (sum > find || idx > 3) {
    return false;
  }
  if (sum == find && idx == 3) {
    return true;
  }
  for (int i = 0; i < 45; ++i) {
    if (triangleNumbers[i] > find) {
      break;
    }
    sum = sum + triangleNumbers[i];
    if (solve(find, sum, idx + 1)) {
      return true;
    }
    sum -= triangleNumbers[i];
  }
  return false;
}

int main() {
  int n;
  cin >> n;
  settingTriangleNumber();
  for (int i = 0; i < n; ++i) {
    int find;
    cin >> find;
    cout << solve(find, 0, 0) << endl;
  }
  return 0;
}