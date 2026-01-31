#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll n, x;
  cin >> n >> x;
  vector<pair<ll, ll>> vec(n);
  for (ll i{}; i < n; ++i) {
    auto& [y, j] = vec[i];
    cin >> y;
    j = i + 1;
  }
  sort(vec.begin(), vec.end());
  ll i{}, j{n - 1};
  while (i < j) {
    ll s{vec[i].first + vec[j].first};
    if (s == x) {
      cout << vec[i].second << ' ' << vec[j].second << '\n';
      return 0;
    }
    if (s < x) {
      ++i;
    } else {
      --j;
    }
  }
  cout << "IMPOSSIBLE\n";
}
