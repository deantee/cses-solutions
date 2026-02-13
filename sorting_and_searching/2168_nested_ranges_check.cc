#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct BIT {
  ll n;
  vector<ll> bit;
  BIT(ll n) : n(n), bit(n + 1) {}
  void update(ll i, ll x) {
    for (; i <= n; i += i & -i) {
      bit[i] += x;
    }
  }
  ll query(ll i) const {
    ll x{};
    for (; i >= 1; i -= i & -i) {
      x += bit[i];
    }
    return x;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll n;
  cin >> n;
  vector<tuple<ll, ll, ll>> vec(n);
  vector<ll> ends;
  ends.reserve(n);
  for (ll i{}; i < n; ++i) {
    auto& [l, r, j] = vec[i];
    cin >> l >> r;
    j = i;
    ends.emplace_back(r);
  }
  sort(ends.begin(), ends.end());
  ends.erase(unique(ends.begin(), ends.end()), ends.end());
  auto end_rank = [&](ll x) -> ll {
    return lower_bound(ends.begin(), ends.end(), x) - ends.begin() + 1;
  };
  sort(vec.begin(), vec.end(), [](auto& a, auto& b) -> bool {
    auto& [l0, r0, i0] = a;
    auto& [l1, r1, i1] = b;
    return l0 != l1 ? l0 > l1 : r0 < r1;
  });
  BIT bit0(n), bit1(n);
  vector<bool> ans0(n), ans1(n);
  for (auto& [l, r, i] : vec) {
    ll rank{end_rank(r)};
    ans0[i] = bit0.query(rank);
    bit0.update(rank, 1);
  }
  reverse(vec.begin(), vec.end());
  for (auto& [l, r, i] : vec) {
    ll rank(ends.size() - end_rank(r) + 1);
    ans1[i] = bit1.query(rank);
    bit1.update(rank, 1);
  }
  for (ll i{}; i < n; ++i) {
    cout << ans0[i] << (i + 1 < n ? ' ' : '\n');
  }
  for (ll i{}; i < n; ++i) {
    cout << ans1[i] << (i + 1 < n ? ' ' : '\n');
  }
}
