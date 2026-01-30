#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll n;
  cin >> n;
  vector<pair<ll, ll>> vec(n);
  for (auto& [b, a] : vec) {
    cin >> a >> b;
  }
  sort(vec.begin(), vec.end());
  ll last{};
  ll ans{};
  for (auto& [b, a] : vec) {
    if (a >= last) {
      last = b;
      ++ans;
    }
  }
  cout << ans << '\n';
}
