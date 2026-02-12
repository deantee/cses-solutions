#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct BIT {
  ll n;
  vector<ll> bit;
  BIT(ll n) : n(n), bit(n + 1) {};
  void update(ll i, ll x) {
    for (; i <= n; i += i & -i) {
      bit[i] += x;
    }
  }
  ll lower_bound(ll x) const {
    ll i{};
    ll msk{1LL << (CHAR_BIT * sizeof n - __builtin_clzll(n) - 1)};
    while (msk) {
      ll j{i + msk};
      if (j <= n && bit[j] < x) {
        x -= bit[j];
        i = j;
      }
      msk /= 2;
    }
    return i + 1;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll n, k;
  cin >> n >> k;
  BIT bit(n);
  for (ll i{1}; i <= n; ++i) {
    bit.update(i, 1);
  }
  ll i{};
  while (n) {
    i += k;
    i %= n;
    ll j{bit.lower_bound(i + 1)};
    bit.update(j, -1);
    cout << j << (--n ? ' ' : '\n');
  }
}
