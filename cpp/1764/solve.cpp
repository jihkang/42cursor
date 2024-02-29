#include <iostream>
#include <map>
using namespace std;

int arr[21];

void setToggle(int n) { arr[n] = !arr[n]; }
void setArr(int n, int value) { arr[n] = value; }
void setAll(int value) {
  for (int i = 1; i < 21; i++) {
    setArr(i, value);
  }
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cout.tie(NULL);
  std::cin.tie(NULL);

  int n, m;
  cin >> n >> m;
  vector<string> ans;
  std::map<string, int> user;
  std::string s;
  for (int i = 0; i < n; ++i) {
    cin >> s;
    user[s] = 1;
  }
  for (int j = 0; j < m; ++j) {
    cin >> s;
    if (user[s] == 1) {
      ans.push_back(s);
    }
  }
  cout << ans.size() << '\n';
  sort(ans.begin(), ans.end());
  for (int i = 0; i < ans.size(); ++i) {
    cout << ans[i] << '\n';
  }
  return 0;
}