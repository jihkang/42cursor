#include <algorithm>
#include <iomanip>
#include <iostream>

using namespace std;

int dx[4] = {0, -1, 0, 1};
int dy[4] = {1, 0, -1, 0};

int arr[51][6];
void change_direction(int &dir) { dir = (dir + 1) % 4; }

void move(int n, int m, int r, int c) {
  int dir = 0;
  int cnt = 1;
  int prev = 0;
  int x, y;
  x = y = 0;
  arr[x][y] = cnt;
  if (x >= n && x <= r && y >= m && y <= c) {
    arr[x - n][y - m] = cnt;
  }
  while (true) {
    if (x < -50 || y < -50 || x > 50 || y > 50)
      break;
    for (int j = 0; j < 2; ++j) {
      for (int i = 0; i <= prev; ++i) {
        x = x + dx[dir];
        y = y + dy[dir];
        ++cnt;
        if (x >= n && x <= r && y >= m && y <= c) {
          arr[x - n][y - m] = cnt;
        }
      }
      change_direction(dir);
    }
    prev++;
  }
}

int check_line(int x, int cnt) {
  if (x > 0) {
    return check_line(x / 10, ++cnt);
  }
  return cnt;
}

int main() {
  int n, m, r, c;
  cin >> n >> m >> r >> c;
  move(n, m, r, c);
  int _max = 0;
  for (int k = 0; k < 2; ++k) {
    for (int i = 0; i <= r - n; ++i) {
      for (int j = 0; j <= c - m; ++j) {
        if (k == 0) {
          int prefix = check_line(arr[i][j], 0);
          if (prefix > _max) {
            _max = prefix;
          }
        } else {
          cout << setw(_max) << arr[i][j] << " ";
        }
      }
      if (k == 1) {
        cout << '\n';
      }
    }
  }
  return 0;
}