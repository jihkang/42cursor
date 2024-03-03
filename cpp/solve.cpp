#include <iostream>
#define ENDL "\n"

using namespace std;

int solve(int x, int y, int prev) {
  long long result = (101 * x * y + x * x) / (100 * x - y);
  return result;
}

int main() {

  int x, y;
  cin >> x >> y;
  int prev = int((double)(y) / x * 100);

  if (prev >= 99) {
    cout << -1 << '\n';
    return 0;
  }
  cout << solve(x, y, prev) << ENDL;
  return 0;
}