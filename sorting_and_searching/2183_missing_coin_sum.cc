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
  sort(vec.begin(), vec.end());
  ll ans{1};
  for (ll x : vec) {
    if (ans < x) {
      break;
    }
    ans += x;
  }
  cout << ans << '\n';
}
