#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll n;
  cin >> n;
  ll ans{};
  for (ll i{}; i < n - 1; ++i) {
    ll x;
    cin >> x;
    ans ^= x;
  }
  for (ll i{1}; i <= n; ++i) {
    ans ^= i;
  }
  cout << ans << '\n';
}
