#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  array<string, 8> grid;
  for (auto& row : grid) {
    cin >> row;
  }
  array<bool, 8> vis0{};
  array<bool, 15> vis1{};
  array<bool, 15> vis2{};
  ll ans{};
  auto dfs = [&](auto&& self, ll i) -> void {
    if (i == 8) {
      ++ans;
      return;
    }
    for (ll j{}; j < 8; ++j) {
      if (grid[i][j] == '*') {
        continue;
      }
      if (vis0[j] || vis1[i + j] || vis2[i + (7 - j)]) {
        continue;
      }
      vis0[j] = vis1[i + j] = vis2[i + (7 - j)] = true;
      self(self, i + 1);
      vis0[j] = vis1[i + j] = vis2[i + (7 - j)] = false;
    }
  };
  dfs(dfs, 0);
  cout << ans << '\n';
}
