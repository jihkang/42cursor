#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int solve(vector<int> &hole, int line) {
  int ans = 0;
  int saved = 0;
  for (int i = 0; i < hole.size(); ++i) {
    if (saved < hole[i]) {
      saved = hole[i] + line - 0.5;
      ++ans;
    }
  }

  return ans;
}

int main() {
  int n, l;

  cin >> n >> l;
  vector<int> hole(n);
  for (int i = 0; i < n; ++i) {
    cin >> hole[i];
  }
  sort(hole.begin(), hole.end());
  cout << solve(hole, l) << endl;
  return 0;
}