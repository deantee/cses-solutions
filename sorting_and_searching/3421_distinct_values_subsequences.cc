#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll n;
  cin >> n;
  unordered_map<ll, ll> mp;
  const ll MOD(1e9 + 7);
  while (n--) {
    ll x;
    cin >> x;
    ++mp[x];
  }
  ll ans{1};
  for (auto& [k, v] : mp) {
    ans *= v + 1;
    ans %= MOD;
  }
  cout << (ans + MOD - 1) % MOD << '\n';
}
