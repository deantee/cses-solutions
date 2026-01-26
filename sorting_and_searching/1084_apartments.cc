#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll n, m, k;
  cin >> n >> m >> k;
  vector<ll> a(n), b(m);
  for (ll& x : a) {
    cin >> x;
  }
  for (ll& x : b) {
    cin >> x;
  }
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  ll ans{};
  for (ll i{}, j{}; i < n && j < m; ++i) {
    while (j < m && a[i] - k > b[j]) {
      ++j;
    }
    if (j < m && a[i] + k >= b[j]) {
      ++j;
      ++ans;
    }
  }
  cout << ans << '\n';
}
