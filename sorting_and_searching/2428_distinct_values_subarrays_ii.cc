#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll n, k;
  cin >> n >> k;
  vector<ll> vec(n);
  for (ll& x : vec) {
    cin >> x;
  }
  unordered_map<ll, ll> mp;
  ll ans{};
  for (ll l{}, r{}; r < n; ++r) {
    ++mp[vec[r]];
    if (k < ll(mp.size())) {
      while (--mp[vec[l++]] > 0) {
      }
      mp.erase(vec[l - 1]);
    }
    ans += r - l + 1;
  }
  cout << ans << '\n';
}
