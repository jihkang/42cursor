#include <iostream>

#define ENDL "\n"

using namespace std;

long long solve(long long x, long long y, long long z) {
  long long child = (z * x + x - 100 * y);
  long long parent = 99 - z;
  long long alpha = ((z * x) + x - (100 * y)) / (99 - z);

  if (child % parent != 0)
    return alpha + 1;
  return alpha;
}

int main() {
  long long x, y;
  cin >> x >> y;
  long long prev = y * 100 / x;

  if (prev >= 99) {
    cout << -1 << ENDL;
    return 0;
  }
  cout << solve(x, y, prev) << ENDL;
  return 0;
}