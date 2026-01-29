#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll n;
  cin >> n;
  vector<ll> a(n), b(n);
  for (ll i{}; i < n; ++i) {
    cin >> a[i] >> b[i];
  }
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  ll i{}, j{};
  ll cur{};
  ll ans{};
  while (i < n) {
    if (a[i] < b[j]) {
      ++cur;
      ++i;
    } else {
      --cur;
      ++j;
    }
    ans = max(ans, cur);
  }
  cout << ans << '\n';
}
