#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll n;
  cin >> n;
  ll ans{1};
  while (n--) {
    ans *= 2;
    ans %= ll(1e9 + 7);
  }
  cout << ans << '\n';
}
