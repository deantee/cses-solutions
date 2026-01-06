#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll t;
  cin >> t;
  while (t--) {
    ll y, x;
    cin >> y >> x;
    ll mx{max(y, x)};
    if (mx & 1) {
      swap(y, x);
    }
    cout << mx * mx - (mx - y) - (x - 1) << '\n';
  }
}
