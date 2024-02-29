#include <iostream>
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

  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    std::string s;
    cin >> s;
    if (s == "all") {
      setAll(1);
      continue;
    } else if (s == "empty") {
      setAll(0);
      continue;
    }
    int value;
    cin >> value;
    if (s == "add") {
      setArr(value, 1);
    } else if (s == "remove") {
      setArr(value, 0);
    } else if (s == "check") {
      cout << arr[value] << '\n';
    } else if (s == "toggle") {
      setToggle(value);
    }
  }
  return 0;
}