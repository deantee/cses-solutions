#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll n;
  cin >> n;
  vector<ll> vec(n);
  for (ll& x : vec) {
    cin >> x;
  }
  ll ans{LLONG_MAX};
  for (ll i{}; i < 1LL << (n - 1); ++i) {
    ll diff{};
    for (ll j{}; j < n; ++j) {
      diff += vec[j] * (i >> j & 1 ? 1 : -1);
    }
    ans = min(ans, llabs(diff));
  }
  cout << ans << '\n';
}
