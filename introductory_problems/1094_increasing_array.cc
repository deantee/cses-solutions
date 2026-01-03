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
  ll ans{};
  ll cur{vec[0]};
  for (ll i{1}; i < n; ++i) {
    ans += max(cur - vec[i], 0LL);
    cur = max(cur, vec[i]);
  }
  cout << ans << '\n';
}
