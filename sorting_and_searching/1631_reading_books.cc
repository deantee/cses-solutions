#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll n;
  cin >> n;
  ll s{}, mx{};
  for (ll i{}; i < n; ++i) {
    ll x;
    cin >> x;
    s += x;
    mx = max(mx, x);
  }
  cout << max(s, mx * 2) << '\n';
}
