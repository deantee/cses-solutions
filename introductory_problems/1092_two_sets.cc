#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll n;
  cin >> n;
  ll sum{n * (n + 1) / 2};
  if (sum & 1) {
    cout << "NO\n";
    return 0;
  }
  vector<ll> ans0, ans1;
  ans0.reserve(n);
  ans1.reserve(n);
  for (ll i{n}, t{sum / 2}; i >= 1; --i) {
    if (t >= i) {
      t -= i;
      ans0.emplace_back(i);
    } else {
      ans1.emplace_back(i);
    }
  }
  cout << "YES\n";
  cout << ans0.size() << '\n';
  for (ll i{}; i < ll(ans0.size()); ++i) {
    cout << ans0[i] << (i + 1 < ll(ans0.size()) ? ' ' : '\n');
  }
  cout << ans1.size() << '\n';
  for (ll i{}; i < ll(ans1.size()); ++i) {
    cout << ans1[i] << (i + 1 < ll(ans1.size()) ? ' ' : '\n');
  }
}
