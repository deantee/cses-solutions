#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  string str;
  cin >> str;
  ll n(str.size());
  ll cur{1};
  ll ans{1};
  for (ll i{1}; i < n; ++i) {
    if (str[i] == str[i - 1]) {
      ++cur;
    } else {
      cur = 1;
    }
    ans = max(ans, cur);
  }
  cout << ans << '\n';
}
