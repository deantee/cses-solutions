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
    auto& [x, j] = vec[i];
    cin >> x;
    j = i + 1;
  }
  sort(vec.begin(), vec.end());
  for (ll i{}; i < n; ++i) {
    for (ll j{i + 1}; j < n; ++j) {
      ll l{j + 1};
      ll r{n - 1};
      while (l < r) {
        ll s{vec[i].first + vec[j].first + vec[l].first + vec[r].first};
        if (s == x) {
          cout << vec[i].second << ' ' << vec[j].second << ' ' << vec[l].second
               << ' ' << vec[r].second << '\n';
          return 0;
        }
        if (s < x) {
          ++l;
        } else {
          --r;
        }
      }
    }
  }
  cout << "IMPOSSIBLE\n";
}
