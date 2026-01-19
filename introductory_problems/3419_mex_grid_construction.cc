#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll n;
  cin >> n;
  for (ll i{}; i < n; ++i) {
    for (ll j{}; j < n; ++j) {
      cout << (i ^ j) << (j + 1 < n ? ' ' : '\n');
    }
  }
}
