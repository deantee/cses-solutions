#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll n;
  cin >> n;
  for (ll i{}; i < 1LL << n; ++i) {
    ll x{i ^ i >> 1};
    for (ll j{n}; j--;) {
      cout << (x >> j & 1);
    }
    cout << '\n';
  }
}
