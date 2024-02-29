#include <iostream>

using namespace std;

int main() {
  int cnt = 0;
  while (true) {
    int L, P, V;
    cin >> L >> P >> V;
    if (L == 0 && P == 0 && V == 0) {
      break;
    }
    int ans = (V / P) * L;
    ans += V % P > L ? L : V % P;
    cout << "Case " << ++cnt << ": " << ans << endl;
  }
  return 0;
}