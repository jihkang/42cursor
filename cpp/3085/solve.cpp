#include <iostream>

using namespace std;

char map[52][52];
int visited[50][50];
char mx[4] = {0, 0, 1, -1};
char my[4] = {1, -1, 0, 0};

int calculate(int x, int y, int n) {
  //   cout << "calculate: " << endl;
  int cnt = 0;
  int max = 0;
  char color = map[x][y];
  for (int i = 0; i < n; ++i) {
    if (max < cnt) {
      max = cnt;
    }
    if (map[i + 1][y] == color) {
      ++cnt;
    } else {
      cnt = 0;
    }
  }
  if (max < cnt) {
    max = cnt;
  }
  cnt = 0;
  for (int i = 0; i < n; ++i) {
    if (max < cnt) {
      max = cnt;
    }
    if (map[x][i + 1] == color) {
      ++cnt;
    } else {
      cnt = 0;
    }
  }
  if (max < cnt) {
    max = cnt;
  }
  //   cout << max << endl;
  return max;
}

int bp(int x, int y, int n) {
  int cnt = 0;
  int max = 0;
  for (int i = 0; i < 4; ++i) {
    int nx = x + mx[i];
    int ny = y + my[i];
    if (nx > 0 && nx <= n && ny > 0 && ny <= n) {
      //   if (map[nx][ny] != map[x][y]) {
      char tmp = map[nx][ny];
      map[nx][ny] = map[x][y];
      map[x][y] = tmp;
      int result = calculate(x, y, n);
      if (result > max) {
        max = result;
      }
      tmp = map[nx][ny];
      map[nx][ny] = map[x][y];
      map[x][y] = tmp;
      //   }
    }
  }
  return max;
}

int solve(int n) {
  int max = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      //   if (map[0][i] == '1') {
      // visited[0][i] = 1;
      int result = bp(i + 1, j + 1, n);
      if (max < result) {
        max = result;
      }
      //   }
    }
  }
  return max;
}

int main() {
  int n;
  std::cin >> n;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      std::cin >> map[i + 1][j + 1];
    }
  }
  cout << solve(n) << endl;
  return 0;
}
