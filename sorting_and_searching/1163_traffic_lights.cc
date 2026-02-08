#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll x, n;
  cin >> x >> n;
  set<ll> lights{0, x};
  multiset<ll> lengths{x};
  while (n--) {
    ll y;
    cin >> y;
    auto r = lights.lower_bound(y);
    auto l = prev(r);
    lengths.erase(lengths.find(*r - *l));
    lengths.insert(*r - y);
    lengths.insert(y - *l);
    lights.insert(y);
    cout << *lengths.rbegin() << (n ? ' ' : '\n');
  }
}
