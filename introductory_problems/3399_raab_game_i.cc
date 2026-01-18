#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll t;
  cin >> t;
  while (t--) {
    ll n, a, b;
    cin >> n >> a >> b;
    if (a + b > n || (a == 0 && b > 0) || (b == 0 && a > 0)) {
      cout << "NO\n";
      continue;
    }
    vector<ll> ans0(n), ans1(n);
    iota(ans0.begin(), ans0.end(), 1LL);
    for (ll i{}; i < b; ++i) {
      ans1[i] = i + a + 1;
    }
    for (ll i{b}; i < a + b; ++i) {
      ans1[i] = i - b + 1;
    }
    for (ll i{a + b}; i < n; ++i) {
      ans1[i] = i + 1;
    }
    cout << "YES\n";
    for (ll i{}; i < n; ++i) {
      cout << ans0[i] << (i + 1 < n ? ' ' : '\n');
    }
    for (ll i{}; i < n; ++i) {
      cout << ans1[i] << (i + 1 < n ? ' ' : '\n');
    }
  }
}
