#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll n;
  cin >> n;
  queue<pair<ll, ll>> q;
  q.emplace(0, 0);
  array<ll, 9> del{-2, -1, 2, 1, -2, 1, 2, -1, -2};
  vector ans(n, vector<ll>(n, -1));
  ans[0][0] = 0;
  while (!q.empty()) {
    auto [x, y] = q.front();
    q.pop();
    for (ll i{}; i < 8; ++i) {
      ll nx{x + del[i]}, ny{y + del[i + 1]};
      if (nx < 0 || nx >= n || ny < 0 || ny >= n) {
        continue;
      }
      if (ans[nx][ny] != -1) {
        continue;
      }
      ans[nx][ny] = ans[x][y] + 1;
      q.emplace(nx, ny);
    }
  }
  for (ll i{}; i < n; ++i) {
    for (ll j{}; j < n; ++j) {
      cout << ans[i][j] << (j + 1 < n ? ' ' : '\n');
    }
  }
}
