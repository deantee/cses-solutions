#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll n;
  cin >> n;
  if (n == 1) {
    cout << "1\n";
    return 0;
  }
  if (n <= 3) {
    cout << "NO SOLUTION\n";
    return 0;
  }
  vector<ll> ans;
  ans.reserve(n);
  for (ll i{2}; i <= n; i += 2) {
    ans.emplace_back(i);
  }
  for (ll i{1}; i <= n; i += 2) {
    ans.emplace_back(i);
  }
  for (ll i{}; i < n; ++i) {
    cout << ans[i] << (i + 1 < n ? ' ' : '\n');
  }
}
