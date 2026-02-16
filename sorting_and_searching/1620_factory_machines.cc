#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll n, t;
  cin >> n >> t;
  vector<ll> vec(n);
  for (auto& x : vec) {
    cin >> x;
  }
  ll l{}, r{LLONG_MAX};
  while (l < r) {
    ll m{l + (r - l) / 2};
    ll s{};
    for (ll x : vec) {
      s += m / x;
      if (s >= t) {
        break;
      }
    }
    if (s >= t) {
      r = m;
    } else {
      l = m + 1;
    }
  }
  cout << l << '\n';
}
