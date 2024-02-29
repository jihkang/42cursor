#include <iostream>
#include <vector>

using namespace std;

int main() {
  int t;
  cin >> t;

  for (int i = 0; i < t; ++i) {
    int n;
    cin >> n;
    int arr[2][100001];
    int dp[2][100001];
    for (int j = 0; j < 2; ++j) {
      for (int k = 0; k < n; ++k) {
        cin >> arr[j][k];
      }
    }
    dp[0][0] = arr[0][0];
    dp[1][0] = arr[1][0];
    dp[1][1] = arr[1][1] + dp[0][0];
    dp[0][1] = arr[0][1] + dp[1][0];
    // long long max = 0;
    for (int j = 2; j < n; ++j) {
      dp[0][j] = max(dp[1][j - 1], dp[1][j - 2]) + arr[0][j];
      dp[1][j] = max(dp[0][j - 1], dp[0][j - 2]) + arr[1][j];
    }
    cout << max(dp[0][n - 1], dp[1][n - 1]) << endl;
  }
  return 0;
}