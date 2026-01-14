#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll n;
  cin >> n;
  cout << (1LL << n) - 1 << '\n';
  auto dfs = [&](auto&& self, ll n, ll src, ll dst, ll aux) -> void {
    if (n == 0) {
      return;
    }
    self(self, n - 1, src, aux, dst);
    cout << src << ' ' << dst << '\n';
    self(self, n - 1, aux, dst, src);
  };
  dfs(dfs, n, 1, 3, 2);
}
