#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll n, x;
  cin >> n >> x;
  vector<ll> pf(n + 1);
  for (ll i{1}; i <= n; ++i) {
    cin >> pf[i];
    pf[i] += pf[i - 1];
  }
  unordered_map<ll, ll> mp;
  ll ans{};
  for (ll i{}; i <= n; ++i) {
    ans += mp[pf[i] - x];
    ++mp[pf[i]];
  }
  cout << ans << '\n';
}
