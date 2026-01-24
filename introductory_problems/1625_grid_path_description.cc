#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  string str;
  cin >> str;
  array<array<bool, 9>, 9> vis{};
  vis[1][1] = true;
  for (ll i{}; i < 9; ++i) {
    vis[0][i] = vis[i][0] = vis[i][8] = vis[8][i] = true;
  }
  array<ll, 48> moves;
  for (ll i{}; i < 48; ++i) {
    switch (str[i]) {
      case 'U':
        moves[i] = 0;
        break;
      case 'R':
        moves[i] = 1;
        break;
      case 'D':
        moves[i] = 2;
        break;
      case 'L':
        moves[i] = 3;
        break;
      default:
        moves[i] = -1;
    }
  }
  array<ll, 5> del{-1, 0, 1, 0, -1};
  ll ans{};
  auto dfs = [&](auto&& self, ll i, ll x, ll y) -> void {
    if (i == 48) {
      if (x == 7 && y == 1) {
        ++ans;
      }
      return;
    }
    if (x == 7 && y == 1) {
      return;
    }
    if (48 - i < (7 - x) + (y - 1)) {
      return;
    }
    if (vis[x - 1][y] && vis[x + 1][y] && !vis[x][y - 1] && !vis[x][y + 1]) {
      return;
    }
    if (!vis[x - 1][y] && !vis[x + 1][y] && vis[x][y - 1] && vis[x][y + 1]) {
      return;
    }
    for (ll j{}; j < 4; ++j) {
      if (moves[i] == -1 || moves[i] == j) {
        ll nx{x + del[j]}, ny{y + del[j + 1]};
        if (vis[nx][ny]) {
          continue;
        }
        vis[nx][ny] = true;
        self(self, i + 1, nx, ny);
        vis[nx][ny] = false;
      }
    }
  };
  dfs(dfs, 0, 1, 1);
  cout << ans << '\n';
}
