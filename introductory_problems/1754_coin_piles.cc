#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll t;
  cin >> t;
  while (t--) {
    ll a, b;
    cin >> a >> b;
    cout << ((a + b) % 3 == 0 && min(a, b) * 2 >= max(a, b) ? "YES\n" : "NO\n");
  }
}
