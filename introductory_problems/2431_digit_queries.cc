#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll q;
  cin >> q;
  while (q--) {
    ll k;
    cin >> k;
    --k;
    ll base{1};
    ll digit{1};
    while (true) {
      ll t{base * digit * 9};
      if (k < t) {
        break;
      }
      k -= t;
      base *= 10;
      ++digit;
    }
    cout << to_string(base + k / digit)[k % digit] << '\n';
  }
}
