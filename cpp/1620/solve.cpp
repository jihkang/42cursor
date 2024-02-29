#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <utility>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int N, M;
  cin >> N >> M;
  map<string, int> ms;
  map<int, string> mi;
  for (int i = 0; i < N; ++i) {
    std::string value;
    cin >> value;
    ms[value] = i + 1;
    mi[i + 1] = value;
  }
  for (int i = 0; i < M; ++i) {
    std::string value;
    cin >> value;
    if (value[0] >= '0' && value[0] <= '9') {
      cout << mi[stoi(value)] << endl;
    } else {
      cout << ms[value] << endl;
    }
  }
  return 0;
}